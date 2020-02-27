#include "PcbEditor.h"
#include "Scene.h"

#include <iostream>
#include <fmt/format.h>

#define LEFT_BUTTON               0x01u
#define RIGHT_BUTTON              0x02u
#define MIDDLE_BUTTON             0x04u

using namespace std;

PcbEditor::PcbEditor(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder) :
    Gtk::DrawingArea{ cobject }
{
    add_events(Gdk::BUTTON_MOTION_MASK |
                       Gdk::POINTER_MOTION_MASK |
                       Gdk::KEY_PRESS_MASK  |
                       Gdk::KEY_RELEASE_MASK |
                       Gdk::BUTTON_PRESS_MASK |
                       Gdk::BUTTON_RELEASE_MASK |
                       Gdk::SCROLL_MASK);

    set_can_focus();
}

bool PcbEditor::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    // draw background
    cr->save();
    cr->set_source_rgb(0, 0, 0);
    cr->paint();
    cr->restore();

    // draw grid
    cr->save();
    cr->set_source_rgba(0.8, 0.8, 0.8, 0.3);
    cr->set_dash(_grid, 0);
    cr->set_line_width(1);
    auto x = 0.5;
    while (x <= width) {
        cr->move_to(x, 0);
        cr->line_to(x, height);
        x += _gridSize;
    }
    cr->stroke();
    cr->restore();

    // draw elements
    for (const auto &item : _model.items()) {
        item->viewItem()->draw(cr, _scene, item.get());
    }

    // draw mouse helpers
    auto formattedMousePointer = _mousePointer + 0.5;
    cr->save();
    cr->set_line_width(1);
    cr->set_source_rgba(0.8, 0.8, 0.8, 0.3);
    cr->move_to(formattedMousePointer.x, 0);
    cr->line_to(formattedMousePointer.x, height);
    cr->move_to(0, formattedMousePointer.y);
    cr->line_to(width, formattedMousePointer.y);
    cr->stroke();
    cr->restore();

    if (_mousePressPoint.has_value()) {
        cr->save();
        cr->set_line_width(1);
        cr->set_source_rgba(0.8, 0.8, 0.8, 0.3);
        cr->move_to(_mousePressPoint.value().x, _mousePressPoint.value().y);
        cr->line_to(formattedMousePointer.x, formattedMousePointer.y);
        cr->stroke();
        cr->restore();

        cr->save();
        auto diff = _mousePointer - _mousePressPoint.value();
        cr->set_source_rgb(1.0, 1.0, 0);
        cr->move_to(formattedMousePointer.x + 30, formattedMousePointer.y + 30);
        cr->show_text(fmt::format("x: {:.3f}", diff.x));
        cr->move_to(formattedMousePointer.x + 30, formattedMousePointer.y + 45);
        cr->show_text(fmt::format("y: {:.3f}", diff.y));
        cr->move_to(formattedMousePointer.x + 30, formattedMousePointer.y + 60);
        cr->show_text(fmt::format("dist: {:.3f}", _mousePointer.distanceTo(_mousePressPoint.value())));
        cr->restore();
    }

    //draw HUD
    cr->save();
    cr->set_line_width(1);
    cr->set_source_rgb(0, 0, 0);
    cr->rectangle(width - 150, 0, 150, 20);
    cr->fill_preserve();
    cr->set_source_rgb(1.0, 1.0, 0);
    cr->move_to(width - 145, 15);
    auto txt = fmt::format("x: {:.3f} y: {:.3f} sc:{:.1f}", _mousePointer.x, _mousePointer.y, _scene.scale);
    cr->show_text(txt);
    cr->restore();

    return false;
}

bool PcbEditor::on_scroll_event(GdkEventScroll *scroll_event) {
    _scene.scale *= scroll_event->direction == GDK_SCROLL_DOWN ? 0.75 : 1.25;
    redraw();

    return Widget::on_scroll_event(scroll_event);
}

bool PcbEditor::on_button_press_event(GdkEventButton *button_event) {

    _mousePressPoint.emplace(
            static_cast<int>(button_event->x / _gridSize) * _gridSize,
            static_cast<int>(button_event->y / _gridSize) * _gridSize);

    switch (button_event->button) {
        case 1: // left click
        {
            _mouseButtonState |= LEFT_BUTTON;
            if (_brushItem.has_value()) {
                auto newItem = _modelFactory.build(_brushItem.value());
                newItem->position.x = _mousePressPoint->x * (1 / _scene.scale);
                newItem->position.y = _mousePressPoint->y * (1 / _scene.scale);
                newItem->viewItem()->selected = true;
                _model.addItem(newItem);
            } else {
                Point<double> clickPoint{ button_event->x, button_event->y };
                for (auto &item : _model.items()) {
                    item->viewItem()->selected = item->viewItem()->getBoundingRect(item.get(), _scene).contains(clickPoint);
                }
            }
            redraw();
            break;
        }

        case 3: // right click
        {
            _mouseButtonState |= RIGHT_BUTTON;
            if (_brushItem.has_value()) {
                _brushItem.reset();
            }
            resetSelected();
            break;
        }

        default:
            return Widget::on_button_press_event(button_event);
    }

    return Widget::on_button_press_event(button_event);
}

bool PcbEditor::on_button_release_event(GdkEventButton *release_event) {
    switch (release_event->button) {
        case 1: // left click
        {
            _mouseButtonState &= ~LEFT_BUTTON;
            if (!_mousePressPoint.has_value()) {
                break;
            }
            if (_mousePointer != _mousePressPoint.value()) {
                auto diff = _mousePointer - _mousePressPoint.value();
                for (auto &item : _model.items()) {
                    if (item->viewItem()->selected) {
                        item->position += diff * (1 / _scene.scale);
                    }
                }
                redraw();
            }
            break;
        }

        case 3: // right click
        {
            _mouseButtonState &= ~RIGHT_BUTTON;
            break;
        }

        default:
            return Widget::on_button_release_event(release_event);
    }

    _mousePressPoint.reset();
    redraw();

    return Widget::on_button_release_event(release_event);
}

bool PcbEditor::on_motion_notify_event(GdkEventMotion *motion_event) {
    _mousePointer.x = static_cast<int>(motion_event->x / _gridSize) * _gridSize;
    _mousePointer.y = static_cast<int>(motion_event->y / _gridSize) * _gridSize;

    if (_mouseButtonState & LEFT_BUTTON) {
        for (auto &item : _model.items()) {

        }
    }

    redraw();

    return Widget::on_motion_notify_event(motion_event);
}

bool PcbEditor::on_key_press_event(GdkEventKey *key_event) {
    switch (key_event->keyval) {
        case 26:
            break;
    }
    return Widget::on_key_press_event(key_event);
}

bool PcbEditor::on_key_release_event(GdkEventKey *key_event) {
    return Widget::on_key_release_event(key_event);
}

void PcbEditor::redraw() {
    auto win = get_window();
    if (win)
    {
        Gtk::Allocation allocation = get_allocation();
        const int width = allocation.get_width();
        const int height = allocation.get_height();
        Gdk::Rectangle r(0, 0, width, height);
        win->invalidate_rect(r, false);
    }
}

void PcbEditor::resetSelected() {
    for (auto &item : _model.items()) {
        item->viewItem()->selected = false;
    }
}

void PcbEditor::selectBrush(ModelFactory::Model modelType) {
    _brushItem = modelType;
    resetSelected();
}


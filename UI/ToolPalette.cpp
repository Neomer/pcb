//
// Created by kir on 16.02.2020.
//

#include <stdexcept>

#include <glib/gi18n.h>

#include "ToolPalette.h"
#include "../Models/HoleItem.h"

using namespace std;

ToolPalette::ToolPalette(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder) :
    Gtk::ToolPalette{cobject}
{
    loadPalette();
}

void ToolPalette::loadPalette() {
    Gtk::ToolItemGroup* group = Gtk::manage(new Gtk::ToolItemGroup(_("Соединители")));
    add(*group);
    
    auto button = Gtk::manage(new Gtk::ToggleToolButton(_("Дорожка")));
    button->set_tooltip_text(_("Дорожка"));
    group->insert(*button);
    
    group = Gtk::manage(new Gtk::ToolItemGroup(_("Контакты")));
    add(*group);
    button = Gtk::manage(new Gtk::ToggleToolButton(_("Сквозное отверстие")));
    button->set_tooltip_text(_("Сквозное отверстие"));
    button->signal_toggled().connect(bind(&ToolPalette::selectItem, this, button, ModelFactory::Model::HoleItem));
    group->insert(*button);
    
    button = Gtk::manage(new Gtk::ToggleToolButton(_("SMD-контакт")));
    button->set_tooltip_text(_("SMD-контакт"));
    button->signal_toggled().connect(bind(&ToolPalette::selectItem, this, button, ModelFactory::Model::SMDContact));
    group->insert(*button);
}

void ToolPalette::onToolSelected(const std::function<void(ModelFactory::Model)> &listener)
{
    _toolSelectedListener = listener;
}

void ToolPalette::selectItem(const Gtk::ToggleToolButton *button, ModelFactory::Model modelType) {
    flushAllToggleButtons(this, button);
    if (_toolSelectedListener.has_value()) {
        _toolSelectedListener.value()(modelType);
    }
}

void ToolPalette::flushAllToggleButtons(Gtk::Container *container, const Gtk::ToggleToolButton *clicked) {
    container->foreach([&](Widget& w) {
        if (&w != clicked) {
            auto b = dynamic_cast<Gtk::ToggleToolButton *>(&w);
            if (b != nullptr) {
                b->set_active(false);
            } else {
                auto c = dynamic_cast<Gtk::Container *>(&w);
                if (c != nullptr) {
                    flushAllToggleButtons(c, clicked);
                }
            }
        }
    });
}
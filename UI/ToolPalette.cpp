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
    button->signal_toggled().connect(bind(&ToolPalette::selectItem, this, std::make_shared<HoleItem>()));
    group->insert(*button);
    
    button = Gtk::manage(new Gtk::ToggleToolButton(_("SMD-контакт")));
    button->set_tooltip_text(_("SMD-контакт"));
    group->insert(*button);
}

void ToolPalette::onToolSelected(const std::function<void(std::shared_ptr<SchemeItem>)> &listener)
{
    _toolSelectedListener = listener;
}

void ToolPalette::selectItem(const std::shared_ptr<SchemeItem> &item) {
    if (_toolSelectedListener.has_value()) {
        _toolSelectedListener.value()(item);
    }
}

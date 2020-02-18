//
// Created by kir on 16.02.2020.
//

#include <stdexcept>

#include <glib/gi18n.h>

#include "ToolPalette.h"

ToolPalette::ToolPalette(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder) :
    Gtk::ToolPalette{cobject}
{
    loadPalette();
}

void ToolPalette::loadPalette() {
    Gtk::ToolItemGroup* group = Gtk::manage(new Gtk::ToolItemGroup(_("Соединители")));
    add(*group);
    
    auto button = Gtk::make_managed<Gtk::ToggleToolButton>(_("Дорожка"));
    button->set_tooltip_text(_("Дорожка"));
    group->insert(*button);
    
    group = Gtk::manage(new Gtk::ToolItemGroup(_("Контакты")));
    add(*group);
    button = Gtk::make_managed<Gtk::ToggleToolButton>(_("Сквозное отверстие"));
    button->set_tooltip_text(_("Сквозное отверстие"));
    group->insert(*button);
    
    button = Gtk::make_managed<Gtk::ToggleToolButton>(_("SMD-контакт"));
    button->set_tooltip_text(_("SMD-контакт"));
    group->insert(*button);
}


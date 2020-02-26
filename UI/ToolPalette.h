//
// Created by kir on 16.02.2020.
//

#ifndef PCB_TOOLPALETTE_H
#define PCB_TOOLPALETTE_H

#include <functional>
#include <optional>
#include <gtkmm.h>
#include "../Models/ModelFactory.h"

class ToolPalette : public Gtk::ToolPalette {
    std::optional<std::function<void(ModelFactory::Model)>> _toolSelectedListener{ std::nullopt };

    void loadPalette();
    
public:
    ToolPalette(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> &builder);

    void onToolSelected(const std::function<void(ModelFactory::Model)> &listener);

protected:
    void selectItem(const Gtk::ToggleToolButton *button, ModelFactory::Model modelType);

private:
    void flushAllToggleButtons(Gtk::Container *container, const Gtk::ToggleToolButton *clicked);
};


#endif //PCB_TOOLPALETTE_H

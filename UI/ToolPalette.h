//
// Created by kir on 16.02.2020.
//

#ifndef PCB_TOOLPALETTE_H
#define PCB_TOOLPALETTE_H

#include <functional>
#include <optional>
#include <gtkmm.h>
#include "../Models/SchemeItem.h"

class ToolPalette : public Gtk::ToolPalette {
    std::optional<std::function<void(std::shared_ptr<SchemeItem>)>> _toolSelectedListener{ std::nullopt };

    void loadPalette();
    
public:
    ToolPalette(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> &builder);

    void onToolSelected(std::function<void(std::shared_ptr<SchemeItem>)> listener);

protected:
    void selectItem(const std::shared_ptr<SchemeItem> &item);
};


#endif //PCB_TOOLPALETTE_H

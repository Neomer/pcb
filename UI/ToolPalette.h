//
// Created by kir on 16.02.2020.
//

#ifndef PCB_TOOLPALETTE_H
#define PCB_TOOLPALETTE_H

#include <gtkmm.h>

class ToolPalette : public Gtk::ToolPalette {
    void loadPalette();
    
public:
    ToolPalette(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> &builder);
};


#endif //PCB_TOOLPALETTE_H

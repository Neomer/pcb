//
// Created by kir on 14.02.2020.
//

#ifndef PCB_PCBEDITOR_H
#define PCB_PCBEDITOR_H

#include <optional>
#include <gtkmm.h>

#include "../Core/Rect.h"
#include "../ViewItems/ViewItem.h"
#include "../Models/SchemeModel.h"

class PcbEditor : public Gtk::DrawingArea
{
public:
    PcbEditor(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> &builder);
};


#endif //PCB_PCBEDITOR_H

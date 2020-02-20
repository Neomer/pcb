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
    std::optional<std::unique_ptr<ViewItem>> _brushItem;
    Point<double> _mousePointer;
    double _gridSize;
    std::vector<double> _grid;
    SchemeModel _model;

public:
    PcbEditor(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> &builder);

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

    bool on_button_press_event(GdkEventButton *button_event) override;

    bool on_button_release_event(GdkEventButton *release_event) override;

    bool on_motion_notify_event(GdkEventMotion *motion_event) override;

    bool on_key_press_event(GdkEventKey *key_event) override;

    bool on_key_release_event(GdkEventKey *key_event) override;
};


#endif //PCB_PCBEDITOR_H

//
// Created by kir on 14.02.2020.
//

#ifndef PCB_PCBEDITOR_H
#define PCB_PCBEDITOR_H

#include <cinttypes>
#include <optional>
#include <gtkmm.h>

#include "../Core/Rect.h"
#include "../ViewItems/ViewItem.h"
#include "../Models/SchemeModel.h"
#include "../Models/ModelFactory.h"
#include "Scene.h"

class PcbEditor : public Gtk::DrawingArea
{
    std::optional<ModelFactory::Model> _brushItem{ std::nullopt };
    Point<double> _mousePointer{};
    std::optional<Point<double>> _mousePressPoint{ std:: nullopt };
    double _gridSize{10};
    std::vector<double> _grid{1, 9};
    SchemeModel _model{};
    uint8_t _mouseButtonState{0};
    bool _ignoreGrid{false};
    ModelFactory _modelFactory;
    Scene _scene;

public:
    PcbEditor(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> &builder);

    void selectBrush(ModelFactory::Model modelType);

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

    bool on_button_press_event(GdkEventButton *button_event) override;

    bool on_button_release_event(GdkEventButton *release_event) override;

    bool on_motion_notify_event(GdkEventMotion *motion_event) override;

    bool on_key_press_event(GdkEventKey *key_event) override;

    bool on_key_release_event(GdkEventKey *key_event) override;

private:
    void redraw();
    void resetSelected();
};


#endif //PCB_PCBEDITOR_H

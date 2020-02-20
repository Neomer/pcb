//
// Created by kir on 21.01.2020.
//

#ifndef PCB_MAINWINDOW_H
#define PCB_MAINWINDOW_H

#include <memory>

#include <gtkmm.h>

#include "PcbEditor.h"
#include "ToolPalette.h"

class MainWindow : public Gtk::Window {
    ToolPalette *_palette;
    PcbEditor *_pcbEditor;
    Gtk::Paned *_paned;
    
public:
    MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> &builder);
    ~MainWindow() override;

protected:
    void setTool(std::shared_ptr<SchemeItem> item);
};


#endif //PCB_MAINWINDOW_H

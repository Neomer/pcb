//
// Created by kir on 21.01.2020.
//

#include <glib/gi18n.h>
#include "MainWindow.h"
#include "../ViewItems/HoleViewItem.h"

using namespace std;

MainWindow::~MainWindow()  = default;

MainWindow::MainWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder) :
    Gtk::Window{cobject},
    _palette{nullptr},
    _pcbEditor{nullptr},
    _paned{nullptr}
{
    
    builder->get_widget_derived("toolPalette", _palette);
    builder->get_widget_derived("drawingArea", _pcbEditor);
    builder->get_widget("contentPaned", _paned);
    _paned->set_position(100);
    
    maximize();
}

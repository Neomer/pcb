#include <glib/gi18n.h>
#include "UI/MainWindow.h"

int main(int argc, char **argv) {
    auto app = Gtk::Application::create(argc, argv, "org.neomer.pcb");
    
    
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("/home/kir/projects/pcb/pcb.xml");
    
    MainWindow *wnd = nullptr;
    builder->get_widget_derived("mainWindow", wnd);
    if (wnd == nullptr) {
        g_error(_("Не удалось загрузить основное окно приложения."));
    }
    wnd->show_all();
    return app->run(*wnd);
}

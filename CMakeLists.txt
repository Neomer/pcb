cmake_minimum_required(VERSION 3.15)
project(pcb)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK3 REQUIRED gtkmm-3.0)

include_directories( ${GTK3_INCLUDE_DIRS} /usr/local/include/)
link_directories(${GTK3_LIBRARY_DIRS} /usr/local/lib/)

add_executable(pcb main.cpp UI/MainWindow.cpp UI/MainWindow.h UI/PcbEditor.cpp UI/PcbEditor.h Core/Point.h Core/Size.h Core/Rect.h ViewItems/ViewItem.cpp ViewItems/ViewItem.h ViewItems/HoleViewItem.cpp ViewItems/HoleViewItem.h Models/SchemeModel.cpp Models/SchemeModel.h Models/SchemeItem.cpp Models/SchemeItem.h Models/HoleItem.cpp Models/HoleItem.h UI/SettingsBox.cpp UI/SettingsBox.h UI/ToolPalette.cpp UI/ToolPalette.h Models/ModelFactory.cpp Models/ModelFactory.h)

target_link_libraries(pcb ${GTK3_LIBRARIES} fmt)
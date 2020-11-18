cmake_minimum_required(VERSION 3.16.3)

# project name
project("part_1")

# find includes in the corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# run moc automatically
set(CMAKE_AUTOMOC ON)

message("Looking for Qt...")
# Qt modules (https://doc.qt.io/qt-5/qtmodules.html) you're using in your application
find_package(Qt5 REQUIRED Widgets)
if (${Qt5_FOUND})
    message("Found Qt " ${Qt5_VERSION})
else()
    message("Couldn't find Qt")
endif()

# source files
set(sources
    MainWindow.h
    MainWindow.cpp
    main.cpp
    ArbreB.cpp
    ArbreB.h
    Sommet.h
    Sommet.cpp
)
# The list of things to compile
add_executable(${CMAKE_PROJECT_NAME} ${sources})

# also tell CMake to link with the libraries from the line 14
# otherwise it'll think that you wanted to find those just for fun and won't link them
target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    Qt5::Widgets
    )
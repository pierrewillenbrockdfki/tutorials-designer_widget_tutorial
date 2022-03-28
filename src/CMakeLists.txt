rock_find_qt5(Core Gui Widgets UiPlugin REQUIRED)

INCLUDE_DIRECTORIES(${QT5_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${Qt5Core_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${Qt5Gui_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${QT5UiPlugin_INCLUDE_DIRS})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(MOC_HDRS
    MyWidget.h
    MyWidgetPlugin.h
)

SET(HDRS
    MyWidget.h
)

FILE(GLOB SRCS
    *.cc
)

SET(QtApp_RCCS resources.qrc)
QT5_ADD_RESOURCES(QtApp_RCC_SRCS ${QtApp_RCCS})

rock_vizkit_widget(MyWidget
    SOURCES ${SRCS} ${QtApp_RCC_SRCS} 
    HEADERS ${HDRS}
    MOC ${MOC_HDRS}
    DEPS Qt5::Core Qt5::Gui Qt5::Widgets
    DEPS_PKGCONFIG base-types base-lib
    DEPS_CMAKE
    LIBS ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${QT_QTDESIGNER_LIBRARY} 
)

rock_executable(mywidgetTest
                main.cpp
                DEPS MyWidget)

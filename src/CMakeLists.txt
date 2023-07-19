rock_find_qt4(OPTIONAL QtOpenGL QtDesigner)
rock_find_qt5(OPTIONAL Widgets UiPlugin OpenGL Designer)

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
if (ROCK_QT_VERSION_4)
QT4_ADD_RESOURCES(QtApp_RCC_SRCS ${QtApp_RCCS})
rock_vizkit_widget(MyWidget
    SOURCES ${SRCS} ${QtApp_RCC_SRCS}
    HEADERS ${HDRS}
    MOC ${MOC_HDRS}
    DEPS_PKGCONFIG base-types base-lib
    LIBS Qt4::QtCore Qt4::QtGui
)

rock_executable(mywidgetTest
                main.cpp
                DEPS MyWidget)
endif()

if (ROCK_QT_VERSION_5)
QT5_ADD_RESOURCES(QtApp5_RCC_SRCS ${QtApp_RCCS})
rock_vizkit_widget(MyWidget-qt5
    SOURCES ${SRCS} ${QtApp5_RCC_SRCS}
    HEADERS ${HDRS}
    MOC5 ${MOC_HDRS}
    DEPS_PKGCONFIG base-types base-lib
    DEPS_CMAKE
    LIBS Qt5::Core Qt5::Gui Qt5::Widgets
)

rock_executable(mywidgetTest-qt5
                main.cpp
                DEPS MyWidget-qt5)
endif()

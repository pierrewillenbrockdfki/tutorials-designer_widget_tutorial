rock_library(MyWidget
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(MyWidget_bin Main.cpp
    DEPS MyWidget)


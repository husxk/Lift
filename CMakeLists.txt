cmake_minimum_required(VERSION 3.22.1)
project(lift_simulator)

set(CMAKE_CXX_STANDARD 20)

#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Src/settings.txt
#                ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(lift_simulator
        Src/main.cpp
        Src/Settings/Settings.h
        Src/Settings/Settings.cpp
        Src/Simulator/Simulator.cpp
        Src/Simulator/Simulator.h
        Src/Lift/Lift.cpp
        Src/Lift/Lift.h
        Src/Floor/Floor.cpp
        Src/Floor/Floor.h
        Src/Person/Person.h
        Src/Person/Person.cpp
        Src/Person/Male/Male.cpp
        Src/Person/Male/Male.h
        Src/Person/Female/Female.cpp
        Src/Person/Female/Female.h
        Src/Person/Kid/Kid.cpp
        Src/Person/Kid/Kid.h)

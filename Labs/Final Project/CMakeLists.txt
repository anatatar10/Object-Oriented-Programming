cmake_minimum_required(VERSION 3.24)
project(milestone_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(milestone_project
        filerepository.cpp
        filerepository.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        repository.cpp
        repository.h
        song.cpp
        song.h
        songcontroller.cpp
        songcontroller.h
        songexception.cpp
        songexception.h)

#cmake file
cmake_minimum_required(VERSION 3.0.0)

# project
project (WindowManager)

# include folder
set(INCLUDE_DIR "./inc/")

# add window library
add_library(window_lib
    "./src/Window.cpp")
target_include_directories(window_lib PUBLIC
    "${INCLUDE_DIR}")

# add screen library
add_library(screen_lib
    "./src/Screen.cpp")
target_include_directories(screen_lib PUBLIC
    "${INCLUDE_DIR}")

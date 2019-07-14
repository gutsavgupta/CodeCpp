#cmake file
cmake_minimum_required(VERSION 3.0.0)

# project
project (person)

# include folder
set(INCLUDE_DIR "./inc/")

# add person library
add_library(person_lib
    "./src/Person.cpp")
target_include_directories(person_lib PUBLIC
    "${INCLUDE_DIR}")

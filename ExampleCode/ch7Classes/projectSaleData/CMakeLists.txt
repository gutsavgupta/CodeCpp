cmake_minimum_required (VERSION 3.0.0)

# project name
project (saleItem)

# Include directories
set (INCLUDES ./)

# Source files
file (GLOB SOURCES "./*.cpp")

# set global include dir
include_directories(${INCLUDES})

# target executable
add_executable(saleItem
    ${SOURCES})
    


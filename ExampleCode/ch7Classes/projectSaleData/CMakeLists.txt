cmake_minimum_required (VERSION 3.0.0)

# project name
project (saleItem)

# target main library
add_library(saleData
    "./src/MySaleData.cpp")
target_include_directories(saleData PUBLIC
    "${CMAKE_CURRECT_SOURCE_DIR}/inc"
    "./inc/")

# target main executable
add_executable(mainProgram
    "./src/main.cpp")
target_link_libraries(mainProgram
    saleData)
    


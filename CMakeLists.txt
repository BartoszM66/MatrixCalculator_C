cmake_minimum_required(VERSION 3.10)
project(MatrixCalculator C)
set(CMAKE_C_STANDARD 11)


add_executable(MatrixCalculator
        main.c
        matrix_operations.c
        memory_operations.c
        io_operations.c)

target_include_directories(MatrixCalculator PUBLIC File)
target_link_libraries(MatrixCalculator m)
project( csv_reader )

# CMake 3.* necessario per Qt
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set (CMAKE_CXX_STANDARD 11)

# ottengo tutti i sorgenti
file(GLOB my_sources *.h *.cpp)

# aggiungo eseguibile
add_executable(csv_reader ${my_sources})

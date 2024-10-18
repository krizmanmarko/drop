cmake_minimum_required(VERSION 3.16.3)

project(drop)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Gui)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(drop
	main.cpp
)

target_include_directories(drop PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(drop PRIVATE Qt5::Core)
target_link_libraries(drop PRIVATE Qt5::Gui)
target_link_libraries(drop PRIVATE Qt5::Widgets)

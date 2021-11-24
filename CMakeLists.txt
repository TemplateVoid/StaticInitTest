cmake_minimum_required(VERSION 3.18)

project(StaticInitTest)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 14)

add_library(Lib1 SHARED lib1.h lib1.cpp)
target_include_directories(Lib1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Lib2 STATIC lib2_1.cpp lib2_2.cpp lib2.h)
target_include_directories(Lib2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
if(APPLE)
	target_link_options(Lib1 PRIVATE -force_load $<TARGET_FILE:Lib2>)
elseif(UNIX)
	target_link_options(Lib1 PRIVATE -Wl,--whole-archive $<TARGET_FILE:Lib2> -Wl,--no-whole-archive)
endif()

add_dependencies(Lib1 Lib2)

add_executable(Exe main.cpp)
target_link_libraries(Exe PRIVATE Lib1)

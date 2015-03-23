cmake_minimum_required(VERSION 2.8)
project(opencvsifttest)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(opencvsifttest main.cpp)
target_link_libraries( opencvsifttest ${OpenCV_LIBS} )

install(TARGETS opencvsifttest RUNTIME DESTINATION bin)

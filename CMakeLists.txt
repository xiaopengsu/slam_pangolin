cmake_minimum_required( VERSION 2.8 )
project( show )

set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )



# 寻找G2O Cholmod eigen3
list(APPEND CMAKE_MODULE_PATH  /home/ubuntu/Qt_program/slam/3rdparty/g2o/cmake_modules)
set(G2O_ROOT /home/ubuntu/Qt_program/slam/3rdparty/g2o)

#find_package( G2O REQUIRED )
#find_package( Cholmod )

find_package(OpenCV REQUIRED)

include_directories(
        ${G2O_INCLUDE_DIRS}
        "/usr/include/eigen3"
)

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules )
# sophus
find_package( Sophus REQUIRED )
include_directories( ${Sophus_INCLUDE_DIRS} )

find_package( Pangolin REQUIRED)
include_directories( ${Pangolin_INCLUDE_DIRS} )

add_executable( draw draw.cpp )

target_link_libraries( draw
        ${CHOLMOD_LIBRARIES}
        ${Sophus_LIBRARIES}
        ${Pangolin_LIBRARIES}
        ${OpenCV_LIBS}
        )
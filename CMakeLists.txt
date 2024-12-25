cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

aux_source_directory(. DIR_SRC)
aux_source_directory(./controller DIR_CON)
aux_source_directory(./router DIR_ROU)
aux_source_directory(./framework DIR_FMW)
aux_source_directory(./data DIR_DAT)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(Server ${DIR_SRC} ${DIR_CON} ${DIR_ROU} ${DIR_FMW} ${DIR_DAT})
target_link_libraries(Server ws2_32)
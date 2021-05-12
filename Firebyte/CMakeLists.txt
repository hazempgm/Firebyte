set(PROGRAM_NAME terminal)

set(HEADER_PATH include)
set(HEADER_SOURCE src)

file(GLOB_RECURSE MODULE_PATH ${HEADER_PATH}/*.hpp)
file(GLOB_RECURSE MODULE_SOURCE ${HEADER_SOURCE}/*.cpp)


include_directories(${HEADER_PATH})

add_compile_options(-O3)
add_link_options()

add_executable(${PROGRAM_NAME} ${MODULE_SOURCE})
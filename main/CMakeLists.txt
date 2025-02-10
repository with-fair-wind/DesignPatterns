project(main)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp inc/*.h)
add_executable(${PROJECT_NAME} ${srcs})
target_include_directories(main PUBLIC inc)

target_link_libraries(${PROJECT_NAME} PUBLIC model)
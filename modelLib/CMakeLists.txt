project(model)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp inc/*.h)
add_library(${PROJECT_NAME} STATIC ${srcs})

target_include_directories(${PROJECT_NAME} PUBLIC inc)

if(MSVC)
    target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE _UNICODE)
    target_precompile_headers(${PROJECT_NAME} PRIVATE inc/stdafx.h)
elseif(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT_NAME} PRIVATE -fpch-preprocess)
    target_precompile_headers(${PROJECT_NAME} PRIVATE inc/stdafx.h)
else()
    message(WARNING "Unsupported compiler for precompiled headers or definitions!")
endif()
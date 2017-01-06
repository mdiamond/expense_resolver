cmake_minimum_required(VERSION 2.8.12)

add_compile_options(-std=c++11)
add_compile_options(-Wall)
add_compile_options(-fdiagnostics-color=always)
if(APPLE)
    add_compile_options(-stdlib=libc++)
endif()

project(expense_resolver)

file(GLOB expense_resolver_SRC
     "*.cpp"
     "*.hpp")

add_executable(expense_resolver ${expense_resolver_SRC})

target_include_directories(expense_resolver PUBLIC ${expense_resolver_SOURCE_DIR})


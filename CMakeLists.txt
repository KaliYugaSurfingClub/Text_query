cmake_minimum_required(VERSION 3.28)
project(query)

set(CMAKE_CXX_STANDARD 14)
include_directories(includes)

add_executable(query
        main.cpp
        source/Text_query.cpp
        source/Result_query.cpp
        source/Query_base.cpp
        source/Query.cpp
        source/Word_query.cpp
        source/Not_query.cpp
        source/And_query.cpp
        source/Or_query.cpp
)

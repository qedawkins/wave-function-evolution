cmake_minimum_required(VERSION 2.8)

add_executable(evolve evolve.cpp)
target_link_libraries(evolve -lm)

#install(TARGETS evolve DESTINATION bin)

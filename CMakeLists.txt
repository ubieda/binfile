cmake_minimum_required(VERSION 3.20.0)
project(app)
add_executable(binfile)

target_sources(binfile PRIVATE
    src/main.c
)

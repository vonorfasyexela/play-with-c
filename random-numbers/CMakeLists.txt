cmake_minimum_required(VERSION 3.10)
project(random-numbers)

add_executable(rand-with-no-srand rand-with-no-srand.c
        rand-with-srand.c)
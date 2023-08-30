set(CMAKE_MINIMUM_REQUIRED_VERSION 3.23)
project("Laboratory Work 4")

set(METHODS_PREFIX_PATH source/methods)

set(CMAKE_C_STANDARD 99)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY path/to/build)

add_library(
        Methods
        SHARED
        ${METHODS_PREFIX_PATH}eighth.c
        ${METHODS_PREFIX_PATH}fifth.c
        ${METHODS_PREFIX_PATH}first.c
        ${METHODS_PREFIX_PATH}fourth.c
        ${METHODS_PREFIX_PATH}fourth_modified.c
        ${METHODS_PREFIX_PATH}ninth.c
        ${METHODS_PREFIX_PATH}second.c
        ${METHODS_PREFIX_PATH}seventh.c
        ${METHODS_PREFIX_PATH}sixth.c
        ${METHODS_PREFIX_PATH}tenth.c
        ${METHODS_PREFIX_PATH}third.c
)

add_library(
        Menu
        SHARED
        source/menu.c
)

add_executable(
        ${PROJECT_NAME}
        source/main.c
        headers/sosoqe.h
)

target_link_libraries(${PROJECT_NAME} PUBLIC Methods)
target_link_libraries(${PROJECT_NAME} PUBLIC Menu)
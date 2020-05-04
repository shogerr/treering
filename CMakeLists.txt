cmake_minimum_required (VERSION 3.16 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR/cmake}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(treering LANGUAGES CXX)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR} CACHE PATH "INSTALL_PREFIX is bin/" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# Tests
enable_testing()
add_subdirectory(${PROJECT_SOURCE_DIR}/test)

find_package(glm CONFIG REQUIRED)

set(SOURCE
    src/main.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCE})

target_compile_options(${PROJECT_NAME}
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:CXX,Clang>:
            -stdlib=libc++
            -Wall
            -Wextra
            -v
            >
    )

target_link_options(${PROJECT_NAME}
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:CXX,Clang>:
            -lc++
            >
    )

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        glm
    )

#target_include_directories(${PROJECT_NAME}
#	PUBLIC
#	)

install(
    TARGETS
        ${PROJECT_NAME}
    DESTINATION
        bin/$<CONFIG>
    )
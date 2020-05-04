cmake_minimum_required (VERSION 3.16 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR/cmake}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING ""
    )
endif()

enable_testing()
find_package(GTest CONFIG REQUIRED)

set(SOURCE
    main.cpp
    entity_test.cpp
    tree_test.cpp
    agent_test.cpp
    $<$<AND:$<CXX_COMPILER_ID:Clang>,$<COMPILE_FEATURES:cxx_std_20>>:
        span_test.cpp
        >
    )

add_executable(gtest_project ${SOURCE})

target_compile_options(gtest_project
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:CXX,Clang>:
            -stdlib=libc++
            -Wall
            -Wextra
            -v
            >
    )

target_link_options(gtest_project
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:CXX,Clang>:
            -lc++
            >
    )

target_link_libraries(gtest_project
    PRIVATE
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main
    )

add_test(gtest gtest_project)

#target_include_directories(${PROJECT_NAME}
#	PUBLIC
#	)

#target_link_libraries(${PROJECT_NAME}
#	PUBLIC
#	)
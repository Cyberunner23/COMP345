cmake_minimum_required(VERSION 3.0)

#------------------------------------------------------------------------------
# CMake Policies
#------------------------------------------------------------------------------

if(POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()


#------------------------------------------------------------------------------
# Hunter & Project
#
# Note: I am using the Hunter package manager for cmake
# This is an external project that I am using exclusively
# as a utility for my cmake build file. For those interested,
# it can be found at https://github.com/ruslo/hunter
#
# I am using this since I do not want to assume that the markers
# have the libraries preinstalled on their system as well as I do not
# want to assume the operating system they are using.
#------------------------------------------------------------------------------

include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.245.tar.gz"
    SHA1 "34c8f443ef188adc5b3f0106ec5b06999164e1c8"
)

project(SmallWorld)

#Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)


#------------------------------------------------------------------------------
# Hunter Packages
#------------------------------------------------------------------------------

hunter_add_package(Boost COMPONENTS graph serialization)
find_package(Boost CONFIG REQUIRED graph serialization)

#------------------------------------------------------------------------------
# Source files
#------------------------------------------------------------------------------

set(SRCS
    src/Map.hpp
    src/Map.cpp
    src/RegionNode.hpp
)


#------------------------------------------------------------------------------
# Doxygen
#------------------------------------------------------------------------------

find_package(Doxygen)
if (DOXYGEN_FOUND)

    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    add_custom_target(doc
        ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating documentation with Doxygen"
        VERBATIM
    )

    add_custom_target(doc-clean
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_BINARY_DIR}/doc/
        COMMENT "Cleaning up documentation"
        VERBATIM
    )

else(DOXYGEN_FOUND)
    message("Doxygen must be installed in order to generate the documentation")
endif(DOXYGEN_FOUND)


#------------------------------------------------------------------------------
# Executables
#------------------------------------------------------------------------------

add_executable(${PROJECT_NAME} ${SRCS} src/main.cpp)
target_link_libraries(${PROJECT_NAME}
    Boost::boost
    Boost::graph
    Boost::serialization
)


# TESTS
add_executable(SerializationTest src/tests/SerializationTest.cpp ${SRCS})
target_link_libraries(SerializationTest
    Boost::boost
    Boost::graph
    Boost::serialization
)
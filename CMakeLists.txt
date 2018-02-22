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

#Boost serialization
hunter_add_package(Boost COMPONENTS graph serialization)
find_package(Boost CONFIG REQUIRED graph serialization)


#------------------------------------------------------------------------------
# Other dependencies
#------------------------------------------------------------------------------

# Qt5Core and Qt5Widgets
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Svg REQUIRED)

set(CMAKE_AUTOMOC ON)


# GraphViz
include("cmake/FindGraphViz.cmake")

if (NOT GRAPHVIZ_FOUND)
    message(FATAL_ERROR "GraphViz must be installed on the system!!")
endif()

include_directories(${GRAPHVIZ_INCLUDE_DIRS})


#------------------------------------------------------------------------------
# Source files
#------------------------------------------------------------------------------

set(SRCS
    src/DiceRollingFacility.hpp
    src/DiceRollingFacility.cpp
    src/GameDeck.hpp
    src/GameDeck.cpp
    src/GraphView.hpp
    src/GraphView.cpp
    src/Map.hpp
    src/Map.cpp
    src/Player.hpp
    src/Player.cpp
    src/RegionNode.hpp
    src/Tokens.hpp
)

set(LIBS
    Boost::boost
    Boost::graph
    Boost::serialization
    ${GRAPHVIZ_CGRAPH_LIBRARY}
    ${GRAPHVIZ_GVC_LIBRARY}
    ${GRAPHVIZ_CDT_LIBRARY}
    Qt5::Core
    Qt5::Widgets
    Qt5::Svg
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
target_link_libraries(${PROJECT_NAME} ${LIBS})

# TESTS
add_executable(SerializationTest src/tests/SerializationTest.cpp ${SRCS})
target_link_libraries(SerializationTest ${LIBS})

add_executable(MapTest src/tests/MapTest.cpp ${SRCS})
target_link_libraries(MapTest ${LIBS})

add_executable(MapLoadingTest src/tests/MapLoadingTest.cpp ${SRCS})
target_link_libraries(MapLoadingTest ${LIBS})

add_executable(DiceRollingFacilityTest src/tests/DiceRollingFacilityTest.cpp ${SRCS})
target_link_libraries(DiceRollingFacilityTest ${LIBS})

add_executable(TokenTest src/tests/TokenTest.cpp ${SRCS})
target_link_libraries(TokenTest ${LIBS})

add_executable(PlayerTest src/tests/PlayerTest.cpp ${SRCS})
target_link_libraries(PlayerTest ${LIBS})

add_executable(MapGen src/tests/MapGen.cpp ${SRCS})
target_link_libraries(MapGen ${LIBS})

#------------------------------------------------------------------------------
# Test Data
#------------------------------------------------------------------------------

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/TestData)
configure_file(src/tests/data/InvalidSchema.map TestData/InvalidSchema.map COPYONLY)
configure_file(src/tests/data/2player.map TestData/2player.map COPYONLY)
configure_file(src/tests/data/2player.viz TestData/2player.viz COPYONLY)
configure_file(src/tests/data/2player_invalid.map TestData/2player_invalid.map COPYONLY)
configure_file(src/tests/data/2player_invalid.viz TestData/2player_invalid.viz COPYONLY)

configure_file(data/2player.map data/2player.map COPYONLY)
configure_file(data/2player.viz data/2player.viz COPYONLY)
configure_file(data/3player.map data/3player.map COPYONLY)
configure_file(data/3player.viz data/3player.viz COPYONLY)
configure_file(data/4player.map data/4player.map COPYONLY)
configure_file(data/4player.viz data/4player.viz COPYONLY)

configure_file(docs/sw_help_en.pdf sw_help_en.pdf COPYONLY)

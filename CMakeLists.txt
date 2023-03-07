cmake_minimum_required(VERSION 3.4)

set(PROJECT_NAME "SnowrunnerSavegameManager")
project(${PROJECT_NAME})

set(PROJECT_BIN_DIR "bin")

set(QT_ROOT_DIRECTORY "" CACHE STRING "")
if (EXISTS ${QT_ROOT_DIRECTORY})
    get_filename_component(TMP_QT_ROOT_DIRECTORY ${QT_ROOT_DIRECTORY} ABSOLUTE)
    set(CMAKE_PREFIX_PATH ${TMP_QT_ROOT_DIRECTORY})
endif()

set(CMAKE_CXX_STANDARD 17)

# update output directories, see http://stackoverflow.com/questions/7229571/cmake-visual-studio-debug-folder
# First for the generic no-config case (e.g. with mingw)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_BIN_DIR})
# Second, for multi-config builds (e.g. msvc)
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
  string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/${PROJECT_BIN_DIR})
endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)

find_package(Qt5 COMPONENTS Core Qml Quick REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(${PROJECT_NAME}
    src/main.cpp)

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Qml
    Qt5::Quick)

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

cmake_minimum_required(VERSION 3.20)
project(Mediator VERSION 1.0 LANGUAGES CXX)

add_library(chat_room STATIC 
    src/chat_room/chat_room.cpp
    src/chat_room/person.cpp
)

target_include_directories(chat_room PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_executable(chat_room_app app/chat_room.cpp)
target_link_libraries(chat_room_app PRIVATE chat_room)

# Install headers and libraries
install(TARGETS chat_room
    EXPORT chat_room-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include
)

install(DIRECTORY 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/chat_room
    DESTINATION include
)

# Generate a package configuration file
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    chat_room-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/chat_room-config.cmake.in
    chat_room-config.cmake
    INSTALL_DESTINATION lib/cmake/chat_room
)

# Export the targets for use by other projects
install(EXPORT chat_room-config
    DESTINATION lib/cmake/chat_room
    NAMESPACE chat_room::
    FILE chat_room-config.cmake
)
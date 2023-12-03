cmake_minimum_required(VERSION 3.12)

project(EcsSerializerLib
    VERSION 0.0.1
    LANGUAGES C CXX
    DESCRIPTION "a serializer and wrapper for the entt ecs library"
    )

set (CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} 
                PRIVATE src/ComponentFactory.cpp
                        src/Entity.cpp
                        src/World.cpp
                        include/EcsSerializer/Component.h
                        include/EcsSerializer/ComponentFactory.h
                        include/EcsSerializer/EngineComponents.h
                        include/EcsSerializer/Entity.h
                        include/EcsSerializer/World.h )

add_subdirectory(external/entt)
add_subdirectory(external/guid)
add_subdirectory(external/nlohmann_json)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/EcsSerializer>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(${PROJECT_NAME}
            PUBLIC EnTT::EnTT)

target_link_libraries(${PROJECT_NAME}
            PUBLIC crossguid)

set(JSON_BuildTests OFF CACHE INTERNAL "")
target_link_libraries(${PROJECT_NAME}
           PUBLIC nlohmann_json::nlohmann_json)


add_subdirectory(examples)

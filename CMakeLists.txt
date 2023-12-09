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



target_include_directories(
    ${PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/EcsSerializer>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

add_subdirectory(external)



target_link_libraries(${PROJECT_NAME}
            PUBLIC crossguid)


target_link_libraries(${PROJECT_NAME}
           PUBLIC nlohmann_json::nlohmann_json)

target_link_libraries(${PROJECT_NAME}
           PUBLIC EnTT::EnTT)

add_subdirectory(examples)

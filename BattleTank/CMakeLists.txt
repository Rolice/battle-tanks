cmake_minimum_required (VERSION 2.6)
project (UE4)
set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_USE_RESPONSE_FILE_FOR_OBJECTS 1 CACHE BOOL "" FORCE)
SET(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES 1 CACHE BOOL "" FORCE)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_C_COMPILER "/usr/bin/clang")

include("/Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank/Intermediate/ProjectFiles/IncludeDirectories.cmake")
include("/Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank/Intermediate/ProjectFiles/Definitions.cmake")
include("/Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank/Intermediate/ProjectFiles/BattleTankEditor.cmake")

set(MONO_ROOT_PATH "/Users/Shared/Epic Games/UE_4.18/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

# Custom target for BattleTankEditor project, Development configuration
add_custom_target(BattleTankEditor-Development ${BUILD} && mono UnrealBuildTool.exe BattleTankEditor Mac Development -project="/Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank/BattleTank.uproject" -game -progress)
add_custom_target(BattleTankEditor-Development-CLEAN ${BUILD} && mono UnrealBuildTool.exe BattleTankEditor Mac Development -project="/Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank/BattleTank.uproject" -clean)

add_executable(PleaseIgnoreMe ${BattleTankEditor_FILES})
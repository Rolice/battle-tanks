# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank/cmake-build-debug

# Utility rule file for BattleTankEditor-Development.

# Include the progress variables for this target.
include CMakeFiles/BattleTankEditor-Development.dir/progress.make

CMakeFiles/BattleTankEditor-Development:
	cd /Users/Shared/Epic\ Games/UE_4.17/Engine/Binaries/DotNET && mono UnrealBuildTool.exe BattleTankEditor Mac Development -project="/Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank/BattleTank.uproject" -game -progress

BattleTankEditor-Development: CMakeFiles/BattleTankEditor-Development
BattleTankEditor-Development: CMakeFiles/BattleTankEditor-Development.dir/build.make

.PHONY : BattleTankEditor-Development

# Rule to build all files generated by this target.
CMakeFiles/BattleTankEditor-Development.dir/build: BattleTankEditor-Development

.PHONY : CMakeFiles/BattleTankEditor-Development.dir/build

CMakeFiles/BattleTankEditor-Development.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BattleTankEditor-Development.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BattleTankEditor-Development.dir/clean

CMakeFiles/BattleTankEditor-Development.dir/depend:
	cd /Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank /Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank /Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank/cmake-build-debug /Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank/cmake-build-debug /Users/rolice/Development/Game/Unreal/04_BattleTank/BattleTank/cmake-build-debug/CMakeFiles/BattleTankEditor-Development.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BattleTankEditor-Development.dir/depend


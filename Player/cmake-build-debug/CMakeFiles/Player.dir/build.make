# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/taranraina/CLionProjects/Player

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/taranraina/CLionProjects/Player/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Player.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Player.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Player.dir/flags.make

CMakeFiles/Player.dir/Player.cpp.o: CMakeFiles/Player.dir/flags.make
CMakeFiles/Player.dir/Player.cpp.o: ../Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/taranraina/CLionProjects/Player/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Player.dir/Player.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Player.dir/Player.cpp.o -c /Users/taranraina/CLionProjects/Player/Player.cpp

CMakeFiles/Player.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Player.dir/Player.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taranraina/CLionProjects/Player/Player.cpp > CMakeFiles/Player.dir/Player.cpp.i

CMakeFiles/Player.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Player.dir/Player.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taranraina/CLionProjects/Player/Player.cpp -o CMakeFiles/Player.dir/Player.cpp.s

CMakeFiles/Player.dir/Test.cpp.o: CMakeFiles/Player.dir/flags.make
CMakeFiles/Player.dir/Test.cpp.o: ../Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/taranraina/CLionProjects/Player/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Player.dir/Test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Player.dir/Test.cpp.o -c /Users/taranraina/CLionProjects/Player/Test.cpp

CMakeFiles/Player.dir/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Player.dir/Test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taranraina/CLionProjects/Player/Test.cpp > CMakeFiles/Player.dir/Test.cpp.i

CMakeFiles/Player.dir/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Player.dir/Test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taranraina/CLionProjects/Player/Test.cpp -o CMakeFiles/Player.dir/Test.cpp.s

CMakeFiles/Player.dir/playerDriver.cpp.o: CMakeFiles/Player.dir/flags.make
CMakeFiles/Player.dir/playerDriver.cpp.o: ../playerDriver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/taranraina/CLionProjects/Player/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Player.dir/playerDriver.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Player.dir/playerDriver.cpp.o -c /Users/taranraina/CLionProjects/Player/playerDriver.cpp

CMakeFiles/Player.dir/playerDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Player.dir/playerDriver.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/taranraina/CLionProjects/Player/playerDriver.cpp > CMakeFiles/Player.dir/playerDriver.cpp.i

CMakeFiles/Player.dir/playerDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Player.dir/playerDriver.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/taranraina/CLionProjects/Player/playerDriver.cpp -o CMakeFiles/Player.dir/playerDriver.cpp.s

# Object files for target Player
Player_OBJECTS = \
"CMakeFiles/Player.dir/Player.cpp.o" \
"CMakeFiles/Player.dir/Test.cpp.o" \
"CMakeFiles/Player.dir/playerDriver.cpp.o"

# External object files for target Player
Player_EXTERNAL_OBJECTS =

Player: CMakeFiles/Player.dir/Player.cpp.o
Player: CMakeFiles/Player.dir/Test.cpp.o
Player: CMakeFiles/Player.dir/playerDriver.cpp.o
Player: CMakeFiles/Player.dir/build.make
Player: CMakeFiles/Player.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/taranraina/CLionProjects/Player/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Player"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Player.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Player.dir/build: Player

.PHONY : CMakeFiles/Player.dir/build

CMakeFiles/Player.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Player.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Player.dir/clean

CMakeFiles/Player.dir/depend:
	cd /Users/taranraina/CLionProjects/Player/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/taranraina/CLionProjects/Player /Users/taranraina/CLionProjects/Player /Users/taranraina/CLionProjects/Player/cmake-build-debug /Users/taranraina/CLionProjects/Player/cmake-build-debug /Users/taranraina/CLionProjects/Player/cmake-build-debug/CMakeFiles/Player.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Player.dir/depend


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
CMAKE_COMMAND = /cygdrive/c/Users/sucon/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/sucon/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/f/03_workspace/Practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/f/03_workspace/Practice/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Practice.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Practice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Practice.dir/flags.make

CMakeFiles/Practice.dir/main.cpp.o: CMakeFiles/Practice.dir/flags.make
CMakeFiles/Practice.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/f/03_workspace/Practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Practice.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Practice.dir/main.cpp.o -c /cygdrive/f/03_workspace/Practice/main.cpp

CMakeFiles/Practice.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Practice.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/f/03_workspace/Practice/main.cpp > CMakeFiles/Practice.dir/main.cpp.i

CMakeFiles/Practice.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Practice.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/f/03_workspace/Practice/main.cpp -o CMakeFiles/Practice.dir/main.cpp.s

CMakeFiles/Practice.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Practice.dir/main.cpp.o.requires

CMakeFiles/Practice.dir/main.cpp.o.provides: CMakeFiles/Practice.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Practice.dir/build.make CMakeFiles/Practice.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Practice.dir/main.cpp.o.provides

CMakeFiles/Practice.dir/main.cpp.o.provides.build: CMakeFiles/Practice.dir/main.cpp.o


CMakeFiles/Practice.dir/strings/strings_algo.cpp.o: CMakeFiles/Practice.dir/flags.make
CMakeFiles/Practice.dir/strings/strings_algo.cpp.o: ../strings/strings_algo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/f/03_workspace/Practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Practice.dir/strings/strings_algo.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Practice.dir/strings/strings_algo.cpp.o -c /cygdrive/f/03_workspace/Practice/strings/strings_algo.cpp

CMakeFiles/Practice.dir/strings/strings_algo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Practice.dir/strings/strings_algo.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/f/03_workspace/Practice/strings/strings_algo.cpp > CMakeFiles/Practice.dir/strings/strings_algo.cpp.i

CMakeFiles/Practice.dir/strings/strings_algo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Practice.dir/strings/strings_algo.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/f/03_workspace/Practice/strings/strings_algo.cpp -o CMakeFiles/Practice.dir/strings/strings_algo.cpp.s

CMakeFiles/Practice.dir/strings/strings_algo.cpp.o.requires:

.PHONY : CMakeFiles/Practice.dir/strings/strings_algo.cpp.o.requires

CMakeFiles/Practice.dir/strings/strings_algo.cpp.o.provides: CMakeFiles/Practice.dir/strings/strings_algo.cpp.o.requires
	$(MAKE) -f CMakeFiles/Practice.dir/build.make CMakeFiles/Practice.dir/strings/strings_algo.cpp.o.provides.build
.PHONY : CMakeFiles/Practice.dir/strings/strings_algo.cpp.o.provides

CMakeFiles/Practice.dir/strings/strings_algo.cpp.o.provides.build: CMakeFiles/Practice.dir/strings/strings_algo.cpp.o


# Object files for target Practice
Practice_OBJECTS = \
"CMakeFiles/Practice.dir/main.cpp.o" \
"CMakeFiles/Practice.dir/strings/strings_algo.cpp.o"

# External object files for target Practice
Practice_EXTERNAL_OBJECTS =

Practice.exe: CMakeFiles/Practice.dir/main.cpp.o
Practice.exe: CMakeFiles/Practice.dir/strings/strings_algo.cpp.o
Practice.exe: CMakeFiles/Practice.dir/build.make
Practice.exe: CMakeFiles/Practice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/f/03_workspace/Practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Practice.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Practice.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Practice.dir/build: Practice.exe

.PHONY : CMakeFiles/Practice.dir/build

CMakeFiles/Practice.dir/requires: CMakeFiles/Practice.dir/main.cpp.o.requires
CMakeFiles/Practice.dir/requires: CMakeFiles/Practice.dir/strings/strings_algo.cpp.o.requires

.PHONY : CMakeFiles/Practice.dir/requires

CMakeFiles/Practice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Practice.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Practice.dir/clean

CMakeFiles/Practice.dir/depend:
	cd /cygdrive/f/03_workspace/Practice/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/f/03_workspace/Practice /cygdrive/f/03_workspace/Practice /cygdrive/f/03_workspace/Practice/cmake-build-debug /cygdrive/f/03_workspace/Practice/cmake-build-debug /cygdrive/f/03_workspace/Practice/cmake-build-debug/CMakeFiles/Practice.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Practice.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vasia/repos/get-out-of-my-yard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vasia/repos/get-out-of-my-yard/build

# Include any dependencies generated for this target.
include CMakeFiles/getout.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/getout.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/getout.dir/flags.make

CMakeFiles/getout.dir/getout.cpp.o: CMakeFiles/getout.dir/flags.make
CMakeFiles/getout.dir/getout.cpp.o: ../getout.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vasia/repos/get-out-of-my-yard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/getout.dir/getout.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/getout.dir/getout.cpp.o -c /home/vasia/repos/get-out-of-my-yard/getout.cpp

CMakeFiles/getout.dir/getout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getout.dir/getout.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vasia/repos/get-out-of-my-yard/getout.cpp > CMakeFiles/getout.dir/getout.cpp.i

CMakeFiles/getout.dir/getout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getout.dir/getout.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vasia/repos/get-out-of-my-yard/getout.cpp -o CMakeFiles/getout.dir/getout.cpp.s

CMakeFiles/getout.dir/getout.cpp.o.requires:

.PHONY : CMakeFiles/getout.dir/getout.cpp.o.requires

CMakeFiles/getout.dir/getout.cpp.o.provides: CMakeFiles/getout.dir/getout.cpp.o.requires
	$(MAKE) -f CMakeFiles/getout.dir/build.make CMakeFiles/getout.dir/getout.cpp.o.provides.build
.PHONY : CMakeFiles/getout.dir/getout.cpp.o.provides

CMakeFiles/getout.dir/getout.cpp.o.provides.build: CMakeFiles/getout.dir/getout.cpp.o


# Object files for target getout
getout_OBJECTS = \
"CMakeFiles/getout.dir/getout.cpp.o"

# External object files for target getout
getout_EXTERNAL_OBJECTS =

getout: CMakeFiles/getout.dir/getout.cpp.o
getout: CMakeFiles/getout.dir/build.make
getout: /usr/lib/x86_64-linux-gnu/libGLU.so
getout: /usr/lib/x86_64-linux-gnu/libGL.so
getout: /usr/local/lib/libglfw3.a
getout: /usr/lib/x86_64-linux-gnu/libfreetype.so
getout: /usr/lib/x86_64-linux-gnu/libGLEW.so
getout: /usr/lib/x86_64-linux-gnu/librt.so
getout: /usr/lib/x86_64-linux-gnu/libm.so
getout: /usr/lib/x86_64-linux-gnu/libX11.so
getout: /usr/lib/x86_64-linux-gnu/libXrandr.so
getout: /usr/lib/x86_64-linux-gnu/libXinerama.so
getout: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
getout: /usr/lib/x86_64-linux-gnu/libXcursor.so
getout: CMakeFiles/getout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vasia/repos/get-out-of-my-yard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable getout"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/getout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/getout.dir/build: getout

.PHONY : CMakeFiles/getout.dir/build

CMakeFiles/getout.dir/requires: CMakeFiles/getout.dir/getout.cpp.o.requires

.PHONY : CMakeFiles/getout.dir/requires

CMakeFiles/getout.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/getout.dir/cmake_clean.cmake
.PHONY : CMakeFiles/getout.dir/clean

CMakeFiles/getout.dir/depend:
	cd /home/vasia/repos/get-out-of-my-yard/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vasia/repos/get-out-of-my-yard /home/vasia/repos/get-out-of-my-yard /home/vasia/repos/get-out-of-my-yard/build /home/vasia/repos/get-out-of-my-yard/build /home/vasia/repos/get-out-of-my-yard/build/CMakeFiles/getout.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/getout.dir/depend


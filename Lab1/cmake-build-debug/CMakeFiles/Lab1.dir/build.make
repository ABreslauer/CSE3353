# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Andrew\CLionProjects\3353Labs\Lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Andrew\CLionProjects\3353Labs\Lab1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab1.dir/flags.make

CMakeFiles/Lab1.dir/main.cpp.obj: CMakeFiles/Lab1.dir/flags.make
CMakeFiles/Lab1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andrew\CLionProjects\3353Labs\Lab1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab1.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab1.dir\main.cpp.obj -c C:\Users\Andrew\CLionProjects\3353Labs\Lab1\main.cpp

CMakeFiles/Lab1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab1.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Andrew\CLionProjects\3353Labs\Lab1\main.cpp > CMakeFiles\Lab1.dir\main.cpp.i

CMakeFiles/Lab1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab1.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Andrew\CLionProjects\3353Labs\Lab1\main.cpp -o CMakeFiles\Lab1.dir\main.cpp.s

CMakeFiles/Lab1.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Lab1.dir/main.cpp.obj.requires

CMakeFiles/Lab1.dir/main.cpp.obj.provides: CMakeFiles/Lab1.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Lab1.dir\build.make CMakeFiles/Lab1.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Lab1.dir/main.cpp.obj.provides

CMakeFiles/Lab1.dir/main.cpp.obj.provides.build: CMakeFiles/Lab1.dir/main.cpp.obj


# Object files for target Lab1
Lab1_OBJECTS = \
"CMakeFiles/Lab1.dir/main.cpp.obj"

# External object files for target Lab1
Lab1_EXTERNAL_OBJECTS =

Lab1.exe: CMakeFiles/Lab1.dir/main.cpp.obj
Lab1.exe: CMakeFiles/Lab1.dir/build.make
Lab1.exe: CMakeFiles/Lab1.dir/linklibs.rsp
Lab1.exe: CMakeFiles/Lab1.dir/objects1.rsp
Lab1.exe: CMakeFiles/Lab1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Andrew\CLionProjects\3353Labs\Lab1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab1.dir/build: Lab1.exe

.PHONY : CMakeFiles/Lab1.dir/build

CMakeFiles/Lab1.dir/requires: CMakeFiles/Lab1.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Lab1.dir/requires

CMakeFiles/Lab1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab1.dir/clean

CMakeFiles/Lab1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Andrew\CLionProjects\3353Labs\Lab1 C:\Users\Andrew\CLionProjects\3353Labs\Lab1 C:\Users\Andrew\CLionProjects\3353Labs\Lab1\cmake-build-debug C:\Users\Andrew\CLionProjects\3353Labs\Lab1\cmake-build-debug C:\Users\Andrew\CLionProjects\3353Labs\Lab1\cmake-build-debug\CMakeFiles\Lab1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab1.dir/depend


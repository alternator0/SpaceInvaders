# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Konrad\Desktop\code\spaceinvaders

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Konrad\Desktop\code\spaceinvaders\build

# Include any dependencies generated for this target.
include src/CMakeFiles/Spaceship.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/Spaceship.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Spaceship.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Spaceship.dir/flags.make

src/CMakeFiles/Spaceship.dir/Spaceship.cpp.obj: src/CMakeFiles/Spaceship.dir/flags.make
src/CMakeFiles/Spaceship.dir/Spaceship.cpp.obj: src/CMakeFiles/Spaceship.dir/includes_CXX.rsp
src/CMakeFiles/Spaceship.dir/Spaceship.cpp.obj: C:/Users/Konrad/Desktop/code/spaceinvaders/src/Spaceship.cpp
src/CMakeFiles/Spaceship.dir/Spaceship.cpp.obj: src/CMakeFiles/Spaceship.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Konrad\Desktop\code\spaceinvaders\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Spaceship.dir/Spaceship.cpp.obj"
	cd /d C:\Users\Konrad\Desktop\code\spaceinvaders\build\src && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Spaceship.dir/Spaceship.cpp.obj -MF CMakeFiles\Spaceship.dir\Spaceship.cpp.obj.d -o CMakeFiles\Spaceship.dir\Spaceship.cpp.obj -c C:\Users\Konrad\Desktop\code\spaceinvaders\src\Spaceship.cpp

src/CMakeFiles/Spaceship.dir/Spaceship.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Spaceship.dir/Spaceship.cpp.i"
	cd /d C:\Users\Konrad\Desktop\code\spaceinvaders\build\src && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Konrad\Desktop\code\spaceinvaders\src\Spaceship.cpp > CMakeFiles\Spaceship.dir\Spaceship.cpp.i

src/CMakeFiles/Spaceship.dir/Spaceship.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Spaceship.dir/Spaceship.cpp.s"
	cd /d C:\Users\Konrad\Desktop\code\spaceinvaders\build\src && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Konrad\Desktop\code\spaceinvaders\src\Spaceship.cpp -o CMakeFiles\Spaceship.dir\Spaceship.cpp.s

# Object files for target Spaceship
Spaceship_OBJECTS = \
"CMakeFiles/Spaceship.dir/Spaceship.cpp.obj"

# External object files for target Spaceship
Spaceship_EXTERNAL_OBJECTS =

src/libSpaceship.a: src/CMakeFiles/Spaceship.dir/Spaceship.cpp.obj
src/libSpaceship.a: src/CMakeFiles/Spaceship.dir/build.make
src/libSpaceship.a: src/CMakeFiles/Spaceship.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Konrad\Desktop\code\spaceinvaders\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libSpaceship.a"
	cd /d C:\Users\Konrad\Desktop\code\spaceinvaders\build\src && $(CMAKE_COMMAND) -P CMakeFiles\Spaceship.dir\cmake_clean_target.cmake
	cd /d C:\Users\Konrad\Desktop\code\spaceinvaders\build\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Spaceship.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Spaceship.dir/build: src/libSpaceship.a
.PHONY : src/CMakeFiles/Spaceship.dir/build

src/CMakeFiles/Spaceship.dir/clean:
	cd /d C:\Users\Konrad\Desktop\code\spaceinvaders\build\src && $(CMAKE_COMMAND) -P CMakeFiles\Spaceship.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/Spaceship.dir/clean

src/CMakeFiles/Spaceship.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Konrad\Desktop\code\spaceinvaders C:\Users\Konrad\Desktop\code\spaceinvaders\src C:\Users\Konrad\Desktop\code\spaceinvaders\build C:\Users\Konrad\Desktop\code\spaceinvaders\build\src C:\Users\Konrad\Desktop\code\spaceinvaders\build\src\CMakeFiles\Spaceship.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Spaceship.dir/depend


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
include src/CMakeFiles/Shield.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/Shield.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Shield.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Shield.dir/flags.make

src/CMakeFiles/Shield.dir/Shield.cpp.obj: src/CMakeFiles/Shield.dir/flags.make
src/CMakeFiles/Shield.dir/Shield.cpp.obj: src/CMakeFiles/Shield.dir/includes_CXX.rsp
src/CMakeFiles/Shield.dir/Shield.cpp.obj: C:/Users/Konrad/Desktop/code/spaceinvaders/src/Shield.cpp
src/CMakeFiles/Shield.dir/Shield.cpp.obj: src/CMakeFiles/Shield.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Konrad\Desktop\code\spaceinvaders\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Shield.dir/Shield.cpp.obj"
	cd /d C:\Users\Konrad\Desktop\code\spaceinvaders\build\src && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Shield.dir/Shield.cpp.obj -MF CMakeFiles\Shield.dir\Shield.cpp.obj.d -o CMakeFiles\Shield.dir\Shield.cpp.obj -c C:\Users\Konrad\Desktop\code\spaceinvaders\src\Shield.cpp

src/CMakeFiles/Shield.dir/Shield.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shield.dir/Shield.cpp.i"
	cd /d C:\Users\Konrad\Desktop\code\spaceinvaders\build\src && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Konrad\Desktop\code\spaceinvaders\src\Shield.cpp > CMakeFiles\Shield.dir\Shield.cpp.i

src/CMakeFiles/Shield.dir/Shield.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shield.dir/Shield.cpp.s"
	cd /d C:\Users\Konrad\Desktop\code\spaceinvaders\build\src && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Konrad\Desktop\code\spaceinvaders\src\Shield.cpp -o CMakeFiles\Shield.dir\Shield.cpp.s

# Object files for target Shield
Shield_OBJECTS = \
"CMakeFiles/Shield.dir/Shield.cpp.obj"

# External object files for target Shield
Shield_EXTERNAL_OBJECTS =

src/libShield.a: src/CMakeFiles/Shield.dir/Shield.cpp.obj
src/libShield.a: src/CMakeFiles/Shield.dir/build.make
src/libShield.a: src/CMakeFiles/Shield.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Konrad\Desktop\code\spaceinvaders\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libShield.a"
	cd /d C:\Users\Konrad\Desktop\code\spaceinvaders\build\src && $(CMAKE_COMMAND) -P CMakeFiles\Shield.dir\cmake_clean_target.cmake
	cd /d C:\Users\Konrad\Desktop\code\spaceinvaders\build\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Shield.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Shield.dir/build: src/libShield.a
.PHONY : src/CMakeFiles/Shield.dir/build

src/CMakeFiles/Shield.dir/clean:
	cd /d C:\Users\Konrad\Desktop\code\spaceinvaders\build\src && $(CMAKE_COMMAND) -P CMakeFiles\Shield.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/Shield.dir/clean

src/CMakeFiles/Shield.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Konrad\Desktop\code\spaceinvaders C:\Users\Konrad\Desktop\code\spaceinvaders\src C:\Users\Konrad\Desktop\code\spaceinvaders\build C:\Users\Konrad\Desktop\code\spaceinvaders\build\src C:\Users\Konrad\Desktop\code\spaceinvaders\build\src\CMakeFiles\Shield.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Shield.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/arthur/Projects/TREEKING2K24/Visao/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arthur/Projects/TREEKING2K24/Visao/build

# Include any dependencies generated for this target.
include visao/CMakeFiles/teste.dir/depend.make

# Include the progress variables for this target.
include visao/CMakeFiles/teste.dir/progress.make

# Include the compile flags for this target's objects.
include visao/CMakeFiles/teste.dir/flags.make

visao/CMakeFiles/teste.dir/src/Segmento.cpp.o: visao/CMakeFiles/teste.dir/flags.make
visao/CMakeFiles/teste.dir/src/Segmento.cpp.o: /home/arthur/Projects/TREEKING2K24/Visao/src/visao/src/Segmento.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arthur/Projects/TREEKING2K24/Visao/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object visao/CMakeFiles/teste.dir/src/Segmento.cpp.o"
	cd /home/arthur/Projects/TREEKING2K24/Visao/build/visao && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/teste.dir/src/Segmento.cpp.o -c /home/arthur/Projects/TREEKING2K24/Visao/src/visao/src/Segmento.cpp

visao/CMakeFiles/teste.dir/src/Segmento.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/teste.dir/src/Segmento.cpp.i"
	cd /home/arthur/Projects/TREEKING2K24/Visao/build/visao && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arthur/Projects/TREEKING2K24/Visao/src/visao/src/Segmento.cpp > CMakeFiles/teste.dir/src/Segmento.cpp.i

visao/CMakeFiles/teste.dir/src/Segmento.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/teste.dir/src/Segmento.cpp.s"
	cd /home/arthur/Projects/TREEKING2K24/Visao/build/visao && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arthur/Projects/TREEKING2K24/Visao/src/visao/src/Segmento.cpp -o CMakeFiles/teste.dir/src/Segmento.cpp.s

# Object files for target teste
teste_OBJECTS = \
"CMakeFiles/teste.dir/src/Segmento.cpp.o"

# External object files for target teste
teste_EXTERNAL_OBJECTS =

/home/arthur/Projects/TREEKING2K24/Visao/devel/lib/libteste.so: visao/CMakeFiles/teste.dir/src/Segmento.cpp.o
/home/arthur/Projects/TREEKING2K24/Visao/devel/lib/libteste.so: visao/CMakeFiles/teste.dir/build.make
/home/arthur/Projects/TREEKING2K24/Visao/devel/lib/libteste.so: visao/CMakeFiles/teste.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arthur/Projects/TREEKING2K24/Visao/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/arthur/Projects/TREEKING2K24/Visao/devel/lib/libteste.so"
	cd /home/arthur/Projects/TREEKING2K24/Visao/build/visao && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/teste.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
visao/CMakeFiles/teste.dir/build: /home/arthur/Projects/TREEKING2K24/Visao/devel/lib/libteste.so

.PHONY : visao/CMakeFiles/teste.dir/build

visao/CMakeFiles/teste.dir/clean:
	cd /home/arthur/Projects/TREEKING2K24/Visao/build/visao && $(CMAKE_COMMAND) -P CMakeFiles/teste.dir/cmake_clean.cmake
.PHONY : visao/CMakeFiles/teste.dir/clean

visao/CMakeFiles/teste.dir/depend:
	cd /home/arthur/Projects/TREEKING2K24/Visao/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arthur/Projects/TREEKING2K24/Visao/src /home/arthur/Projects/TREEKING2K24/Visao/src/visao /home/arthur/Projects/TREEKING2K24/Visao/build /home/arthur/Projects/TREEKING2K24/Visao/build/visao /home/arthur/Projects/TREEKING2K24/Visao/build/visao/CMakeFiles/teste.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : visao/CMakeFiles/teste.dir/depend


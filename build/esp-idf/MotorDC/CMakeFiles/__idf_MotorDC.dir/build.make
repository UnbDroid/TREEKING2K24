# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arthur/Projects/DROID/TREKKING-2024-2025

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arthur/Projects/DROID/TREKKING-2024-2025/build

# Include any dependencies generated for this target.
include esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/compiler_depend.make

# Include the progress variables for this target.
include esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/flags.make

esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.obj: esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/flags.make
esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.obj: /home/arthur/Projects/DROID/TREKKING-2024-2025/components/MotorDC/MotorDC.cpp
esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.obj: esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/arthur/Projects/DROID/TREKKING-2024-2025/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.obj"
	cd /home/arthur/Projects/DROID/TREKKING-2024-2025/build/esp-idf/MotorDC && /home/arthur/.espressif/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.obj -MF CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.obj.d -o CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.obj -c /home/arthur/Projects/DROID/TREKKING-2024-2025/components/MotorDC/MotorDC.cpp

esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.i"
	cd /home/arthur/Projects/DROID/TREKKING-2024-2025/build/esp-idf/MotorDC && /home/arthur/.espressif/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arthur/Projects/DROID/TREKKING-2024-2025/components/MotorDC/MotorDC.cpp > CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.i

esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.s"
	cd /home/arthur/Projects/DROID/TREKKING-2024-2025/build/esp-idf/MotorDC && /home/arthur/.espressif/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arthur/Projects/DROID/TREKKING-2024-2025/components/MotorDC/MotorDC.cpp -o CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.s

# Object files for target __idf_MotorDC
__idf_MotorDC_OBJECTS = \
"CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.obj"

# External object files for target __idf_MotorDC
__idf_MotorDC_EXTERNAL_OBJECTS =

esp-idf/MotorDC/libMotorDC.a: esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/MotorDC.cpp.obj
esp-idf/MotorDC/libMotorDC.a: esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/build.make
esp-idf/MotorDC/libMotorDC.a: esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/arthur/Projects/DROID/TREKKING-2024-2025/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libMotorDC.a"
	cd /home/arthur/Projects/DROID/TREKKING-2024-2025/build/esp-idf/MotorDC && $(CMAKE_COMMAND) -P CMakeFiles/__idf_MotorDC.dir/cmake_clean_target.cmake
	cd /home/arthur/Projects/DROID/TREKKING-2024-2025/build/esp-idf/MotorDC && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_MotorDC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/build: esp-idf/MotorDC/libMotorDC.a
.PHONY : esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/build

esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/clean:
	cd /home/arthur/Projects/DROID/TREKKING-2024-2025/build/esp-idf/MotorDC && $(CMAKE_COMMAND) -P CMakeFiles/__idf_MotorDC.dir/cmake_clean.cmake
.PHONY : esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/clean

esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/depend:
	cd /home/arthur/Projects/DROID/TREKKING-2024-2025/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arthur/Projects/DROID/TREKKING-2024-2025 /home/arthur/Projects/DROID/TREKKING-2024-2025/components/MotorDC /home/arthur/Projects/DROID/TREKKING-2024-2025/build /home/arthur/Projects/DROID/TREKKING-2024-2025/build/esp-idf/MotorDC /home/arthur/Projects/DROID/TREKKING-2024-2025/build/esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : esp-idf/MotorDC/CMakeFiles/__idf_MotorDC.dir/depend


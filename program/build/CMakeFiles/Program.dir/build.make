# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/magnuschristiansen/desktop/P1/program

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/magnuschristiansen/desktop/P1/program/build

# Include any dependencies generated for this target.
include CMakeFiles/Program.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Program.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Program.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Program.dir/flags.make

CMakeFiles/Program.dir/codegen:
.PHONY : CMakeFiles/Program.dir/codegen

CMakeFiles/Program.dir/main.c.o: CMakeFiles/Program.dir/flags.make
CMakeFiles/Program.dir/main.c.o: /Users/magnuschristiansen/desktop/P1/program/main.c
CMakeFiles/Program.dir/main.c.o: CMakeFiles/Program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/magnuschristiansen/desktop/P1/program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Program.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Program.dir/main.c.o -MF CMakeFiles/Program.dir/main.c.o.d -o CMakeFiles/Program.dir/main.c.o -c /Users/magnuschristiansen/desktop/P1/program/main.c

CMakeFiles/Program.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Program.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/magnuschristiansen/desktop/P1/program/main.c > CMakeFiles/Program.dir/main.c.i

CMakeFiles/Program.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Program.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/magnuschristiansen/desktop/P1/program/main.c -o CMakeFiles/Program.dir/main.c.s

CMakeFiles/Program.dir/data_to_graph.c.o: CMakeFiles/Program.dir/flags.make
CMakeFiles/Program.dir/data_to_graph.c.o: /Users/magnuschristiansen/desktop/P1/program/data_to_graph.c
CMakeFiles/Program.dir/data_to_graph.c.o: CMakeFiles/Program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/magnuschristiansen/desktop/P1/program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Program.dir/data_to_graph.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Program.dir/data_to_graph.c.o -MF CMakeFiles/Program.dir/data_to_graph.c.o.d -o CMakeFiles/Program.dir/data_to_graph.c.o -c /Users/magnuschristiansen/desktop/P1/program/data_to_graph.c

CMakeFiles/Program.dir/data_to_graph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Program.dir/data_to_graph.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/magnuschristiansen/desktop/P1/program/data_to_graph.c > CMakeFiles/Program.dir/data_to_graph.c.i

CMakeFiles/Program.dir/data_to_graph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Program.dir/data_to_graph.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/magnuschristiansen/desktop/P1/program/data_to_graph.c -o CMakeFiles/Program.dir/data_to_graph.c.s

CMakeFiles/Program.dir/traverse.c.o: CMakeFiles/Program.dir/flags.make
CMakeFiles/Program.dir/traverse.c.o: /Users/magnuschristiansen/desktop/P1/program/traverse.c
CMakeFiles/Program.dir/traverse.c.o: CMakeFiles/Program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/magnuschristiansen/desktop/P1/program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Program.dir/traverse.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Program.dir/traverse.c.o -MF CMakeFiles/Program.dir/traverse.c.o.d -o CMakeFiles/Program.dir/traverse.c.o -c /Users/magnuschristiansen/desktop/P1/program/traverse.c

CMakeFiles/Program.dir/traverse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Program.dir/traverse.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/magnuschristiansen/desktop/P1/program/traverse.c > CMakeFiles/Program.dir/traverse.c.i

CMakeFiles/Program.dir/traverse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Program.dir/traverse.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/magnuschristiansen/desktop/P1/program/traverse.c -o CMakeFiles/Program.dir/traverse.c.s

CMakeFiles/Program.dir/min_heap/min_heap.c.o: CMakeFiles/Program.dir/flags.make
CMakeFiles/Program.dir/min_heap/min_heap.c.o: /Users/magnuschristiansen/desktop/P1/program/min_heap/min_heap.c
CMakeFiles/Program.dir/min_heap/min_heap.c.o: CMakeFiles/Program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/magnuschristiansen/desktop/P1/program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Program.dir/min_heap/min_heap.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Program.dir/min_heap/min_heap.c.o -MF CMakeFiles/Program.dir/min_heap/min_heap.c.o.d -o CMakeFiles/Program.dir/min_heap/min_heap.c.o -c /Users/magnuschristiansen/desktop/P1/program/min_heap/min_heap.c

CMakeFiles/Program.dir/min_heap/min_heap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Program.dir/min_heap/min_heap.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/magnuschristiansen/desktop/P1/program/min_heap/min_heap.c > CMakeFiles/Program.dir/min_heap/min_heap.c.i

CMakeFiles/Program.dir/min_heap/min_heap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Program.dir/min_heap/min_heap.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/magnuschristiansen/desktop/P1/program/min_heap/min_heap.c -o CMakeFiles/Program.dir/min_heap/min_heap.c.s

CMakeFiles/Program.dir/shortest_path.c.o: CMakeFiles/Program.dir/flags.make
CMakeFiles/Program.dir/shortest_path.c.o: /Users/magnuschristiansen/desktop/P1/program/shortest_path.c
CMakeFiles/Program.dir/shortest_path.c.o: CMakeFiles/Program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/magnuschristiansen/desktop/P1/program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Program.dir/shortest_path.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Program.dir/shortest_path.c.o -MF CMakeFiles/Program.dir/shortest_path.c.o.d -o CMakeFiles/Program.dir/shortest_path.c.o -c /Users/magnuschristiansen/desktop/P1/program/shortest_path.c

CMakeFiles/Program.dir/shortest_path.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Program.dir/shortest_path.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/magnuschristiansen/desktop/P1/program/shortest_path.c > CMakeFiles/Program.dir/shortest_path.c.i

CMakeFiles/Program.dir/shortest_path.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Program.dir/shortest_path.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/magnuschristiansen/desktop/P1/program/shortest_path.c -o CMakeFiles/Program.dir/shortest_path.c.s

# Object files for target Program
Program_OBJECTS = \
"CMakeFiles/Program.dir/main.c.o" \
"CMakeFiles/Program.dir/data_to_graph.c.o" \
"CMakeFiles/Program.dir/traverse.c.o" \
"CMakeFiles/Program.dir/min_heap/min_heap.c.o" \
"CMakeFiles/Program.dir/shortest_path.c.o"

# External object files for target Program
Program_EXTERNAL_OBJECTS =

Program: CMakeFiles/Program.dir/main.c.o
Program: CMakeFiles/Program.dir/data_to_graph.c.o
Program: CMakeFiles/Program.dir/traverse.c.o
Program: CMakeFiles/Program.dir/min_heap/min_heap.c.o
Program: CMakeFiles/Program.dir/shortest_path.c.o
Program: CMakeFiles/Program.dir/build.make
Program: CMakeFiles/Program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/magnuschristiansen/desktop/P1/program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable Program"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Program.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Program.dir/build: Program
.PHONY : CMakeFiles/Program.dir/build

CMakeFiles/Program.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Program.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Program.dir/clean

CMakeFiles/Program.dir/depend:
	cd /Users/magnuschristiansen/desktop/P1/program/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/magnuschristiansen/desktop/P1/program /Users/magnuschristiansen/desktop/P1/program /Users/magnuschristiansen/desktop/P1/program/build /Users/magnuschristiansen/desktop/P1/program/build /Users/magnuschristiansen/desktop/P1/program/build/CMakeFiles/Program.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Program.dir/depend


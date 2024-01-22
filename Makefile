# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/htnek/Documentos/repos/data-structure-and-algorithm-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/htnek/Documentos/repos/data-structure-and-algorithm-cpp

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running tests..."
	/usr/local/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "No interactive CMake dialog available..."
	/usr/local/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/htnek/Documentos/repos/data-structure-and-algorithm-cpp/CMakeFiles /home/htnek/Documentos/repos/data-structure-and-algorithm-cpp//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/htnek/Documentos/repos/data-structure-and-algorithm-cpp/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named data_structure_and_algorithm_cpp_lib

# Build rule for target.
data_structure_and_algorithm_cpp_lib: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 data_structure_and_algorithm_cpp_lib
.PHONY : data_structure_and_algorithm_cpp_lib

# fast build rule for target.
data_structure_and_algorithm_cpp_lib/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/data_structure_and_algorithm_cpp_lib.dir/build.make CMakeFiles/data_structure_and_algorithm_cpp_lib.dir/build
.PHONY : data_structure_and_algorithm_cpp_lib/fast

#=============================================================================
# Target rules for targets named data_structure_and_algorithm_cpp

# Build rule for target.
data_structure_and_algorithm_cpp: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 data_structure_and_algorithm_cpp
.PHONY : data_structure_and_algorithm_cpp

# fast build rule for target.
data_structure_and_algorithm_cpp/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/data_structure_and_algorithm_cpp.dir/build.make CMakeFiles/data_structure_and_algorithm_cpp.dir/build
.PHONY : data_structure_and_algorithm_cpp/fast

#=============================================================================
# Target rules for targets named cpp_test

# Build rule for target.
cpp_test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 cpp_test
.PHONY : cpp_test

# fast build rule for target.
cpp_test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cpp_test.dir/build.make CMakeFiles/cpp_test.dir/build
.PHONY : cpp_test/fast

#=============================================================================
# Target rules for targets named cpp_test_2

# Build rule for target.
cpp_test_2: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 cpp_test_2
.PHONY : cpp_test_2

# fast build rule for target.
cpp_test_2/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cpp_test_2.dir/build.make CMakeFiles/cpp_test_2.dir/build
.PHONY : cpp_test_2/fast

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/data_structure_and_algorithm_cpp.dir/build.make CMakeFiles/data_structure_and_algorithm_cpp.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/data_structure_and_algorithm_cpp.dir/build.make CMakeFiles/data_structure_and_algorithm_cpp.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/data_structure_and_algorithm_cpp.dir/build.make CMakeFiles/data_structure_and_algorithm_cpp.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

tests/test-2.o: tests/test-2.cpp.o
.PHONY : tests/test-2.o

# target to build an object file
tests/test-2.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cpp_test_2.dir/build.make CMakeFiles/cpp_test_2.dir/tests/test-2.cpp.o
.PHONY : tests/test-2.cpp.o

tests/test-2.i: tests/test-2.cpp.i
.PHONY : tests/test-2.i

# target to preprocess a source file
tests/test-2.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cpp_test_2.dir/build.make CMakeFiles/cpp_test_2.dir/tests/test-2.cpp.i
.PHONY : tests/test-2.cpp.i

tests/test-2.s: tests/test-2.cpp.s
.PHONY : tests/test-2.s

# target to generate assembly for a file
tests/test-2.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cpp_test_2.dir/build.make CMakeFiles/cpp_test_2.dir/tests/test-2.cpp.s
.PHONY : tests/test-2.cpp.s

tests/test.o: tests/test.cpp.o
.PHONY : tests/test.o

# target to build an object file
tests/test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cpp_test.dir/build.make CMakeFiles/cpp_test.dir/tests/test.cpp.o
.PHONY : tests/test.cpp.o

tests/test.i: tests/test.cpp.i
.PHONY : tests/test.i

# target to preprocess a source file
tests/test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cpp_test.dir/build.make CMakeFiles/cpp_test.dir/tests/test.cpp.i
.PHONY : tests/test.cpp.i

tests/test.s: tests/test.cpp.s
.PHONY : tests/test.s

# target to generate assembly for a file
tests/test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cpp_test.dir/build.make CMakeFiles/cpp_test.dir/tests/test.cpp.s
.PHONY : tests/test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... cpp_test"
	@echo "... cpp_test_2"
	@echo "... data_structure_and_algorithm_cpp"
	@echo "... data_structure_and_algorithm_cpp_lib"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... tests/test-2.o"
	@echo "... tests/test-2.i"
	@echo "... tests/test-2.s"
	@echo "... tests/test.o"
	@echo "... tests/test.i"
	@echo "... tests/test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nv/ice/xli449/6122Test/socket-master/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nv/ice/xli449/6122Test/socket-master/server

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/server.cc.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server.cc.o: server.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /nv/ice/xli449/6122Test/socket-master/server/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/server.dir/server.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/server.cc.o -c /nv/ice/xli449/6122Test/socket-master/server/server.cc

CMakeFiles/server.dir/server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/server.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nv/ice/xli449/6122Test/socket-master/server/server.cc > CMakeFiles/server.dir/server.cc.i

CMakeFiles/server.dir/server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/server.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nv/ice/xli449/6122Test/socket-master/server/server.cc -o CMakeFiles/server.dir/server.cc.s

CMakeFiles/server.dir/server.cc.o.requires:
.PHONY : CMakeFiles/server.dir/server.cc.o.requires

CMakeFiles/server.dir/server.cc.o.provides: CMakeFiles/server.dir/server.cc.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/server.cc.o.provides.build
.PHONY : CMakeFiles/server.dir/server.cc.o.provides

CMakeFiles/server.dir/server.cc.o.provides.build: CMakeFiles/server.dir/server.cc.o

CMakeFiles/server.dir/imagTrans.cc.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/imagTrans.cc.o: imagTrans.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /nv/ice/xli449/6122Test/socket-master/server/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/server.dir/imagTrans.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/imagTrans.cc.o -c /nv/ice/xli449/6122Test/socket-master/server/imagTrans.cc

CMakeFiles/server.dir/imagTrans.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/imagTrans.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nv/ice/xli449/6122Test/socket-master/server/imagTrans.cc > CMakeFiles/server.dir/imagTrans.cc.i

CMakeFiles/server.dir/imagTrans.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/imagTrans.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nv/ice/xli449/6122Test/socket-master/server/imagTrans.cc -o CMakeFiles/server.dir/imagTrans.cc.s

CMakeFiles/server.dir/imagTrans.cc.o.requires:
.PHONY : CMakeFiles/server.dir/imagTrans.cc.o.requires

CMakeFiles/server.dir/imagTrans.cc.o.provides: CMakeFiles/server.dir/imagTrans.cc.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/imagTrans.cc.o.provides.build
.PHONY : CMakeFiles/server.dir/imagTrans.cc.o.provides

CMakeFiles/server.dir/imagTrans.cc.o.provides.build: CMakeFiles/server.dir/imagTrans.cc.o

CMakeFiles/server.dir/process.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/process.cpp.o: process.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /nv/ice/xli449/6122Test/socket-master/server/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/server.dir/process.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/process.cpp.o -c /nv/ice/xli449/6122Test/socket-master/server/process.cpp

CMakeFiles/server.dir/process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/process.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /nv/ice/xli449/6122Test/socket-master/server/process.cpp > CMakeFiles/server.dir/process.cpp.i

CMakeFiles/server.dir/process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/process.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /nv/ice/xli449/6122Test/socket-master/server/process.cpp -o CMakeFiles/server.dir/process.cpp.s

CMakeFiles/server.dir/process.cpp.o.requires:
.PHONY : CMakeFiles/server.dir/process.cpp.o.requires

CMakeFiles/server.dir/process.cpp.o.provides: CMakeFiles/server.dir/process.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/process.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/process.cpp.o.provides

CMakeFiles/server.dir/process.cpp.o.provides.build: CMakeFiles/server.dir/process.cpp.o

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/server.cc.o" \
"CMakeFiles/server.dir/imagTrans.cc.o" \
"CMakeFiles/server.dir/process.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/server.cc.o
server: CMakeFiles/server.dir/imagTrans.cc.o
server: CMakeFiles/server.dir/process.cpp.o
server: CMakeFiles/server.dir/build.make
server: /usr/local/pacerepov1/cuda/9.1/lib64/libcudart.so
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server
.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/requires: CMakeFiles/server.dir/server.cc.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/imagTrans.cc.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/process.cpp.o.requires
.PHONY : CMakeFiles/server.dir/requires

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /nv/ice/xli449/6122Test/socket-master/server && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nv/ice/xli449/6122Test/socket-master/server /nv/ice/xli449/6122Test/socket-master/server /nv/ice/xli449/6122Test/socket-master/server /nv/ice/xli449/6122Test/socket-master/server /nv/ice/xli449/6122Test/socket-master/server/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

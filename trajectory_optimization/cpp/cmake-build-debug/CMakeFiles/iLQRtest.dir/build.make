# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/nick/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6015.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nick/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6015.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/iLQRtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/iLQRtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/iLQRtest.dir/flags.make

CMakeFiles/iLQRtest.dir/iLQR.cpp.o: CMakeFiles/iLQRtest.dir/flags.make
CMakeFiles/iLQRtest.dir/iLQR.cpp.o: ../iLQR.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/iLQRtest.dir/iLQR.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iLQRtest.dir/iLQR.cpp.o -c /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/iLQR.cpp

CMakeFiles/iLQRtest.dir/iLQR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iLQRtest.dir/iLQR.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/iLQR.cpp > CMakeFiles/iLQRtest.dir/iLQR.cpp.i

CMakeFiles/iLQRtest.dir/iLQR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iLQRtest.dir/iLQR.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/iLQR.cpp -o CMakeFiles/iLQRtest.dir/iLQR.cpp.s

CMakeFiles/iLQRtest.dir/SatelliteTest.cpp.o: CMakeFiles/iLQRtest.dir/flags.make
CMakeFiles/iLQRtest.dir/SatelliteTest.cpp.o: ../SatelliteTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/iLQRtest.dir/SatelliteTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iLQRtest.dir/SatelliteTest.cpp.o -c /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/SatelliteTest.cpp

CMakeFiles/iLQRtest.dir/SatelliteTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iLQRtest.dir/SatelliteTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/SatelliteTest.cpp > CMakeFiles/iLQRtest.dir/SatelliteTest.cpp.i

CMakeFiles/iLQRtest.dir/SatelliteTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iLQRtest.dir/SatelliteTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/SatelliteTest.cpp -o CMakeFiles/iLQRtest.dir/SatelliteTest.cpp.s

CMakeFiles/iLQRtest.dir/utils.cpp.o: CMakeFiles/iLQRtest.dir/flags.make
CMakeFiles/iLQRtest.dir/utils.cpp.o: ../utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/iLQRtest.dir/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iLQRtest.dir/utils.cpp.o -c /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/utils.cpp

CMakeFiles/iLQRtest.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iLQRtest.dir/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/utils.cpp > CMakeFiles/iLQRtest.dir/utils.cpp.i

CMakeFiles/iLQRtest.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iLQRtest.dir/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/utils.cpp -o CMakeFiles/iLQRtest.dir/utils.cpp.s

# Object files for target iLQRtest
iLQRtest_OBJECTS = \
"CMakeFiles/iLQRtest.dir/iLQR.cpp.o" \
"CMakeFiles/iLQRtest.dir/SatelliteTest.cpp.o" \
"CMakeFiles/iLQRtest.dir/utils.cpp.o"

# External object files for target iLQRtest
iLQRtest_EXTERNAL_OBJECTS =

iLQRtest: CMakeFiles/iLQRtest.dir/iLQR.cpp.o
iLQRtest: CMakeFiles/iLQRtest.dir/SatelliteTest.cpp.o
iLQRtest: CMakeFiles/iLQRtest.dir/utils.cpp.o
iLQRtest: CMakeFiles/iLQRtest.dir/build.make
iLQRtest: CMakeFiles/iLQRtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable iLQRtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iLQRtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/iLQRtest.dir/build: iLQRtest

.PHONY : CMakeFiles/iLQRtest.dir/build

CMakeFiles/iLQRtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/iLQRtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/iLQRtest.dir/clean

CMakeFiles/iLQRtest.dir/depend:
	cd /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/cmake-build-debug /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/cmake-build-debug /home/nick/Documents/AA236/GNC/trajectory_optimization/cpp/cmake-build-debug/CMakeFiles/iLQRtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/iLQRtest.dir/depend

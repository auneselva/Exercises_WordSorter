﻿# CMakeList.txt : CMake project for CMakeWordExercise, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CMakeWordExercise "CMakeWordExerciseMain.cpp" "CMakeWordExerciseMain.h"  "WordSorterTest.h" "WordSorter.h" "WordSorter.cpp" "Timer.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeWordExercise PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

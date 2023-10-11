# CMakeList.txt : CMake project for RandomShuffle, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (RandomShuffle "RandomShuffle.cpp"   "Shuffler.h" "Shuffler.cpp" "ShufflerWrapper.h" "ShufflerWrapper.cpp" "Card.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RandomShuffle PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

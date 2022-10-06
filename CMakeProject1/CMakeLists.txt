# CMakeList.txt : CMake project for CMakeProject1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories("$ENV{JAVA_HOME}/include" "$ENV{JAVA_HOME}/include/win32" "$ENV{CUDA_PATH}/include")
link_directories(${OpenCL_LIBRARY} "$ENV{CUDA_PATH}/lib/x64")
set(CMAKE_LIBRARY_PATH "$ENV{CUDA_PATH}/lib/x64")
#LINK_DIRECTORIES("$ENV{CUDA_PATH}/lib/x64")

# Add source to this project's executable.
#set_source_files_properties(CMakeProject1.cpp PROPERTIES COMPILE_FLAGS " /LIBPATH:$ENV{CUDA_PATH}/lib/x86 /DYNAMICBASE OpenCL.lib" )
#set_source_files_properties(CMakeProject1.cpp PROPERTIES COMPILE_FLAGS "/DYNAMICBASE OpenCL.lib" )
add_executable (CMakeProject1 "CMakeProject1.cpp" "CMakeProject1.h")
target_link_libraries (CMakeProject1 ${OpenCL_LIBRARY})

# TODO: Add tests and install targets if needed.

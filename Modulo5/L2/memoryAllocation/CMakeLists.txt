cmake_minimum_required(VERSION 3.12)
project(MemoryAllocationExample LANGUAGES CXX)

# Set C++ standard (C++11 or higher)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configure debug symbols
set(CMAKE_BUILD_TYPE Debug)  # Change to Release for production

# Add executable
add_executable(memoryAllocation
    main.cpp
)

# Include current directory for headers
target_include_directories(memoryAllocation PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Enable better warnings (optional)
if(MSVC)
    target_compile_options(memoryAllocation PRIVATE /W4 /WX)
else()
    target_compile_options(memoryAllocation PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

# Install target (optional)
install(TARGETS memoryAllocation DESTINATION bin)
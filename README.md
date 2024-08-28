# JSON-Parser

A simple C++ JSON-Parser project.

## Compiled and Tested On

- [Clang 14.0.3 x86_64-apple-darwin22.4.0]

- [GCC 11.4.0 x86_64-linux-gnu]

- [GCC 13.2.0 x86_64-w64-mingw32 (ucrt64)]

## Project Description

This project provides a JSON parser written in C++. It supports parsing, manipulating, and saving JSON data.

## Features

- Parse JSON files and strings
- Modify JSON data
- Save JSON data to files
- Supports various JSON data types (objects, arrays, strings, numbers, booleans, null)

## Installation

This project uses CMake for building. To compile and install the JSON Parser, follow these steps:

### Clone the repository
git clone https://github.com/totoo7/JSON-Parser.git  
cd JSON-Parser

### Create a build directory
mkdir build  
cd build  

### Run CMake to configure the project
cmake -S .. -B .

### Build the project
cmake --build .
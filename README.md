# 🕵️‍ She-Plus-Plus

_Because it's hard to understand her, I'll try to understand C++ instead_

## 📚 Knowledge Gained

### 1️⃣ Build C++

There are 3 options to compile and run C++ file(s)

- Using command line
- Using Makefile
- **Using CMake**

Maybe there's another options, but all I know for now are those 3 options.

1. **CMake**

   To build C++ file using CMake, create a `CMakeLists.txt` inside the top level of the directory.
   After that run

   ```cmake
   cmake [options] -S <path-to-source> -B <path-to-build>
   ```

   ```cmake
   cmake -S . -B build
   ```

   run cmake based on configuration file located inside **.** (current directory) and placed the result inside **build**
   directory

   or sometime people used to use this kind of setup

   Create a directory called **build** and `cd` into it

   ```shell
   mkdir build
   cd build
   ```

   Run `cmake`. **..** means, run cmake with source file (CMakeLists.txt) is located in previous directory and placed
   the
   result inside this directory

   ```cmake
   cmake ..
   ```

2. **CMake Syntax**

   The hard part are the **cmake syntax** and **connect multiple C++ files**
   [CMake CheatSheet](https://usercontent.one/wp/cheatsheet.czutro.ch/wp-content/uploads/2020/09/CMake_Cheatsheet.pdf)

   **Must** have configurations in **CMakeLists.txt** file:
    - `cmake_minimum_required(VERSION 3.10)`
    - `project(project_name)`
    - `add_executable(project_name, list_of_cpp_source_file)`
    - `target_include_directories(project_name visibility list_of_directory)`: use this so that we can use *#include <
      directory_name>* instead of normal double quotes
    - `target_link_directories(project_name visibility list_of_directory)`
    - `target_link_libraries(project_name, list_of_library)`
    - `add_library(library_name list_of_cpp_file)`: use this inside the sub folder to make this sub folder as a library
      so that the parent cmake can connect it

3. **CMake Levels**

   What happen if we want to link our executables that placed in a different folder/sub folder? Basically, we need to **
   create a CMakeLists.txt** inside that sub folder.

   **In root CMakeLists.txt** add this:
    - `add_subdirectory()`
    - `target_include_directories()`
    - `target_link_directories()`
    - `target_link_libraries()`

   **In the sub folder CMakeLists.txt** add this:
    - `add_library()`

### 2️⃣ Basic C++

### 3️⃣ Object Oriented C++

### 4️⃣ Testing C++

### 5️⃣ Modern C++

1. **Map**

   Maps are always sorted according to the **key**. It means that even we randomly insert our key-value pairs, the C++
   map will automatically sort it based on the key.
   In modern C++ (C++11), we can define and access elements inside map using different signature as follows:
    - **Define**
       ```c++
       map<string, string> person { { "name", "johny depp"}, { "born", "1919" } };
       ```
    - **Access**
       ```c++
       cout << my_map.at("name");
       ```
      will result
       ```shell
       "johny depp"
       ```

2. **Vector**

   In vector, we have 2 important term to know, which are **size** and **capacity**
    - **Size**: How many element already filled inside this vector
    - **Capacity**: The maximum number of elements this vector can handle

   Before the capacity reach it's maximum number, C++ will automatically expand it. To prevent this kind of behaviour,
   we
   can use **vector.reserve(int size)**

   **C++11**: To insert a new element into a vector we can use: `vector.emplace_back()`

3. **Unordered Map**

   Faster than std::map. Implemented using **hashtable** and key type must be _hashable_
    - `map.first`: same as take the key
    - `map.second`: same as take the value

4. **STL Algorithm**

   It's a lot and you can [reference it here!](https://en.cppreference.com/w/cpp/algorithm)

## 💡 Acknowledgments

Thanks to these awesome resources:

- [Nodeflux](https://www.nodeflux.io)
- [The Cherno](https://www.youtube.com/c/TheChernoProject)
- [Modern C++ Lecture](https://www.youtube.com/playlist?list=PLgnQpQtFTOGRM59sr3nSL8BmeMZR9GCIA)
- [CMake Dude](https://www.youtube.com/watch?v=nlKcXPUJGwA&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4&index=1&t=0s)
- [CLion](https://www.jetbrains.com/clion/)

# raylib CMake first person

[CMake](https://cmake.org).
[RayLib](https://www.raylib.com/)

Version compiled for web:
[behova.net](https://behova.net/)

## Usage

To compile the example, use one of the following dependending on your build target...

### Desktop

Use the following to build for desktop:

``` bash
cmake -B build
cmake --build build
```

### Cmake build options

For wayland build on desktop:

``` bash
cmake -B build -DGLFW_BUILD_WAYLAND=TRUE
```

### Web

Compiling for the web requires the [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html):

``` bash
mkdir build
cd build
emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXECUTABLE_SUFFIX=".html"
emmake make
```

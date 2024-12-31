Minimal project to test Orbit's dependencies with Conan 2 and CMake

## Build

```
conan install . --build=missing
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=generators/conan_toolchain.cmake ..
cmake --build . --config Release
```

## NOTE

On Windows, conan uses the C++ 14 versions of abseil, grpc and protobuf by default, which is incompatible with the C++ 17 project. We need to explicitly tell Conan to build these those libraries: 

conan install . --build="abseil/*"
conan install . --build="protobuf/*"
conan install . --build="grpc/*"
conan install . --build=missing

or 

conan install . --build="abseil/*" --build="protobuf/*" --build="grpc/*" --build=missing

To visualize the Conan dependency graph:

conan graph info . --format=html > graph.htm

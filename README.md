This is a sample project of how to compile OpenCL C++ programs for Windows 11 using `CMAKE` and `VC` as a compiler. 
It also contains an example of how to use Java JNI in the `cmake` files. 

### How to build?

This project has been tested with Visual Studio 2022 and CLion 2022.2

1. Open a shell "Developer PowerShell for VS 2022" 

*Important* To compile and run this project, it requires OpenCL (e.g., using CUDA SDK) and Java `jni.h`.
To get access to the JNI headers, set the `JAVA_HOME` in the env variables of Windows system. 

```shell
cd <workdir>
mkdir build
cd build
cmake ..
cmake --build . --config Release 
```

2. Run an example

```shell
.\CMakeProject1\Release\CMakeProject1.exe

Hello CMake.
Detected: 1
Platform: 0
        Vendor: NVIDIA Corporation
Using platform: 0 --> NVIDIA Corporation
```

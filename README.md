static lib:

- create a project with header + cpp files
- project -> properties -> configuration type -> static lib (all platforms)
- build static library project
- create gtest project
- link: gtest project -> properties -> c/c++ -> additional include dir -> $(SolutionDir)... location.
- build solution
- run gtest: local windows debugger -> conf startup -> choose gtest.

dll:

- create a project with header + cpp files
- project -> properties -> configuration type -> dynamic lib (all platforms)
- build DLL project
- C:\Users\dolev\source\repos\ConsoleApplication1\x64\Debug\SumArrayDynamicLib.lib must be created
- if not, change to extern "C" __declspec(dllexport) without the define and ifs
- create gtest project
- gtest project -> properties -> linker -> input -> C:\Users\dolev\source\repos\ConsoleApplication1\x64\Debug\SumArrayDynamicLib.lib
- full solution build -> run

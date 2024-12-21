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


links:
Threading:
•	https://www.youtube.com/watch?v=TPVH_coGAQs&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp
Threads, Mutex (Playlist)
•	https://www.youtube.com/watch?v=3ZxZPeXPaM4
C++ Threading #3: Data Race and Mutex
Shows how to create an std::thread and use an std::mutex (manual and with std::lock_guard) to protect data access.

Unit tests:
•	https://learn.microsoft.com/en-us/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2019
•	https://learn.microsoft.com/en-us/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2022 
How to use Google Test for C++ in Visual Studio
•	https://www.youtube.com/watch?v=bfCYGmWoIgQ
Using Google Tests in VS 2019 for C++
•	https://www.youtube.com/watch?v=e7EStbS1TWk
How To Create A Unit Test Visual Studio 2019
Microsoft Testing Framework
•	https://www.youtube.com/watch?v=Ek5JL1790pQ
Google Test - gtest setup for unit testing in C++ on windows 10 Using Visual Studio
•	https://www.youtube.com/watch?v=YiBepqOvL8E
Google C++ Test Framework - Introduction - Assertions Types and Test Fixtures for latest C++ Specs
Google Test more in depth

Static libraries:
•	https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-170
Walkthrough: Create and use a static library (C++) | Microsoft Learn
•	https://www.youtube.com/watch?v=Wt4dxDNmDA8
Creating Static Library and consuming it in a console application using C++

Dynamic libraries:
•	https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170
Walkthrough: Create and use your own Dynamic Link Library (C++)
•	https://www.youtube.com/watch?v=ZPss6v6vMwc
How to Create a C++ dll in visual studio 2019

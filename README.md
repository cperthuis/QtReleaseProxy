# QtReleaseProxy
Proxy for Qt operations which would otherwise prevent the use of the Qt release DLLs in a debug executable with Visual Studio.

This project is meant to be compiled as a Release DLL and used in a Debug application linked with the Qt Release DLLs. 
It's also compatible with Release application but not required then.

## Compilation
- Get a copy of cmake, make sure it's in your PATH or copy it under src/external/cmake. The bat file will try to find src/external/cmake/bin/cmake.exe.
- Run generateProject.bat
- Open the Visual Studio solution and compile the Release target.
- It should generate:
  - lib/QtReleaseProxy.dll
  - lib/QtReleaseProxy.lib
- In your application, use #include < QtReleaseProxy >

## Details
On Windows, certain Qt operations will crash if the configurations of the Qt dlls and of the user executable are not matched.
This isn't ideal for the debug target, there's no reason to pay the cost of the debug version of a middleware when working on your application. This project provides some sample code showing how to bypass the issue.

A common scenario, not specific to QT, where such a problem would occur is when some memory allocated in the Qt DLL and freed in the user DLL. Another scenario is different structures used in debug and release and a partial inlining, which could cause a part of an operation to be done in the Qt dll with the release data structures, and part of the operation to be done inline in the user executable using the debug structures.

The following functions are supported:

QModelIndexList QItemSelection::indexes() const; //QModelIndexList creates memory in the Qt dlls and frees it in the user dll

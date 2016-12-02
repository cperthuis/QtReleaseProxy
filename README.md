# QtReleaseProxy
Proxy for Qt operations which would otherwise prevent the use of Qt Release in debug with Visual Studio.

On Windows, certain Qt operations will crash if the configurations of the Qt dlls and of the user executable are not matched.
This isn't ideal for the debug target, there's no reason to pay the cost of the debug version of a middleware when working on your application. This project provides some sample code showing how to bypass the issue.

A common scenario, not specific to QT, where such a problem would occur is when some memory allocated in the Qt DLL and freed in the user DLL. Another scenario is different structures used in debug and release and a partial inlining, which could cause a part of an operation to be done in the Qt dll with the release data structures, and part of the operation to be done inline in the user executable using the debug structures.

The following functions are supported:

QModelIndexList QItemSelection::indexes() const; //QModelIndexList creates memory in the Qt dlls and frees it in the user dll

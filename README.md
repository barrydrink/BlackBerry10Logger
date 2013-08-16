The Penrillian BlackBerry 10 logging library v1.0

The Penrillian logging library allows BB10 apps to write log statements to the file system. This will assist in debugging apps away from the development environment. This has been tested with SDK 10.1 and is thread safe.

For full instructions and screen shots, see docs/PenrillianLoggingLibrary.pdf

Instructions for building and including into other projects:
1 - Import the logger project into your IDE and export a release build, or build from the command line if you prefer.
2 - Copy libCascadesLoggerLib.so and CascadesLoggerLib.hpp into a folder in the project’s (the project which will be using the logger) file structure. Using the IDE (v10.2 is used in this example), right click the project, select "Configure" then "Add Library". Choose "External Library" then select libCascadesLoggerLib.so for the "Device Library" and the folder containing CascadesLoggerLib.hpp as the "Include Folder".


To direct all qDebug()(C++) and console.debug()(QML) statements to the console and file system:
1 - in main.cpp, add #include "CascadesLoggerLib.hpp"
2 - in the main() method, add CascadesLoggerLib::init()

This will automatically enable logging to console. To also enable logging to the file system, add a folder with the name of the app to /shared/documents (your project will need the "access_shared" permission).


To perform ad-hoc logging:
1 - add #include "CascadesLoggerLib.hpp" to the .cpp file whether logging is to be performed
2 - call CascadesLoggerLib::sharedInstance()->log("logging statement") when required
2 - an optional tag can also be included to make reading the log file easier: CascadesLoggerLib::sharedInstance()->log("logging statement", "A TAG")
 

To disable logging to the file system, simply delete the folder with the app's name from /shared/documents.

************************************************************
Created by Penrillian - www.penrillian.com

For support contact barry@penrillian.com/sami@penrillian.com
************************************************************

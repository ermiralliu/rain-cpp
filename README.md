## RainSimulator in C++

### Specs:
- A rendition of "Rain Simulator" that better utilizes the features of C++.
- Using std::future and async to allow the user to work on the console without interrupting the application.
- Using wrapper classes that work like unique pointers.

### Commands:

```vertical rain speed
Press 'r' for vertical rain speed
```
```horizontal rain speed
Press 't' for horizontal rain speed
```
In both cases the console will appear and ask for user input

```
You can press somewhere with the mouse, then the points will follow the direction the cursor goes, and will speed up based on the distance from the initial clicking point. 
You can click again and they will maintain the same movement as before clicking. 
```

### Future:
Other features will be added later on.

### Build:
To build the app, we're using CMake.
- Install vcpkg and enter its root folder on CMakeUserPresets.
- For MingW, run the command:
```
cmake --preset=mingw
```
- For Visual Studio, run:
```
cmake --preset=default
```
- Then run:
```
cmake --build build
```
- Finally
```
Paste the assets folder to build
```
- Now you can run the executable
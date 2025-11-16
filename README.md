# ASCII Cube Rotation Project

## Overview
This is a C++ console program that visualizes a 3D cube using ASCII characters and allows it to rotate along all three axes. The cube is rendered using simple perspective projection.

## Features
- Displays a 3D cube in the console using ASCII characters.
- Rotates the cube along X, Y, and Z axes simultaneously.
- Uses perspective projection to give a sense of depth.
- Adjustable cube size and rotation speed.

## Usage
1. **Compile the program**:

```bash
g++ rot_cube.c++ -o cube -std=c++11 -pthread
````

2. **Run the program**:

```bash
./cube
```

3. **View the cube**:
   The cube rotates automatically in the console window. Press `Ctrl+C` to stop the program.

## Notes

* The program uses ANSI escape codes to clear the console and redraw the cube each frame.
* Rotation is implemented with simple 3D rotation matrices for X, Y, and Z axes.
* The perspective projection is applied using a simple depth-based scaling factor.
* Requires a C++ compiler with C++11 support or later.

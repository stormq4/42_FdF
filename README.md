# FdF

## Introduction
This project modelizes a 3D "fil de fer" or "wireframe" from a map of raw data which can be found in the test_maps folder inside of the repository. It parses through a map of coordinates and places a model derived from that data on the screen. 

## Running the program
First Download the repository with the following command and change directory to the FdF repository with the following commands.
```
git clone https://github.com/stormq4/FdF.git
cd FdF
```

In order to compile the program, run the following command in the home directory of the fdf repository:
```
make
```

In order to run the fdf program and pass a map in the test_maps folder as argument in the command line, which is as follows:
```
./fdf test_maps/(example_map).fdf
```

## Basic Instructions
While the program is loaded and a 3D map is displayed on the screen in isometric view, the user can press the following keys in order to alter the maps coordinates and heights. 

### Changing the angle on the X Axis
To change the angle on the x axis press the following buttons
- Press and hold **Q** to increment the angle
- Press and hold **A** to decrement the angle

### Changing the angle on the Y axis
To change the angle on the y axis press the following buttons
- Press and hold **W** to increment the angle
- Press and hold **S** to decrement the angle

### Changing the angle on the Z axis
To change the angle on the z axis press the following buttons
- Press and hold **E** to increment the angle
- Press and hold **D** to decrement the angle

### Amplifying The Z Coordinates in the map
In order to amplify the z coordinates on the wireframe press the follwing buttons
- Press and hold **Z** to increase the z values on the map
- Press and hold **X** to decrease the z values on the map

### Zooming in and out
- **Scroll up** for zooming in
- **Scroll down** for zooming out

### Cleaning Up instructions
In order to remove the objectfiles from the mlx and libft libraries fill in the following commands in the command line in the homedirectory:
```
make clean
```

For removing the executables and object files execute the following command:
```
make fclean
```

For re-compiling the entire program the following command is used:
```
make re
```

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
      <li>
      <a href="#note-about-the-requirements">Note About The Requirements</a>
    </li>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#license">License</a></li>
  </ol>
</details>

<!-- NOTE ABOUT THE REQUIREMENTS-->
## Note About The Requirements
1. The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units.
2. There are no other obstructions on the table surface. 
3. The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. 
4. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

*Create a console application that can read in commands of the following form*  
`PLACE X,Y,F`  
`MOVE`  
`LEFT`  
`RIGHT`  
`REPORT`  

1. `PLACE` will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST. 
2. The origin (0,0) can be considered to be the SOUTH WEST most corner. 
3. It is required that the first command to the robot is a PLACE command, after that, any sequence of commands may be issued, in any order, including another `PLACE` command. 
4. The application should discard all commands in the sequence until a valid `PLACE` command has been executed.
5. `MOVE` will move the toy robot one unit forward in the direction it is currently facing.
6. `LEFT` and `RIGHT` will rotate the robot 90 degrees in the specified direction without changing the position of the robot.
7. `REPORT` will announce the X,Y and F of the robot. This can be in any form, but standard output is sufficient.
8. A robot that is not on the table can choose to ignore the `MOVE`, `LEFT`, `RIGHT` and `REPORT` commands.
9. Input can be from a file, or from standard input, as the developer chooses.
10. Provide test data to exercise the application.
11. It is not required to provide any graphical output showing the movement of the toy robot.
12. The application should handle error states appropriately and be robust to user input.

### Constraints
The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot. Any move that would cause the robot to fall must be ignored.

Example Input and Output:  
a)  
`PLACE 0,0,NORTH`  
`MOVE`  
`REPORT`  
Output: `0,1,NORTH`  

b)  
`PLACE 0,0,NORTH`  
`LEFT`  
`REPORT`  
Output: `0,0,WEST`  

c)  
`PLACE 1,2,EAST`  
`MOVE`  
`MOVE`  
`LEFT`  
`MOVE`  
`REPORT`  
Output: `3,3,NORTH`

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- ABOUT THE PROJECT -->
## About The Project

The application is a simulation of a toy robot moving on a square table top.
1. The application accepts a width, height and number of robots parameter
2. The user can then able to execute command namely `PLACE`, `MOVE`, `LEFT`, `RIGHT`, and `REPORT`
3. The application will then store the user input from the command line and update the state
of the robot
4. If the application detects that the robot will fall, it will reset from its previous state and continues to accept further commands

<p align="right">(<a href="#top">back to top</a>)</p>

### Built With

* [C++](https://isocpp.org/)

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

The application can be installed locally. Follow the simple steps below.

### Prerequisites

Install the following tools
* C++
  ```sh
  sudo apt update
  sudo apt install build-essential
  gcc --version
  g++ --version
  ```

### Installation

**Back-end Setup**
1. go to the root folder (cd toy_robot)
2. mkdir build && cd build
3. cmake ../source
2. run main program ./toy_robot

Note: Please use a minimum of C++14 compiler

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>

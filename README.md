# Rage-on-the-Road-An-OpenGL-Car-Racing-Game

---------------------
## Introduction to Project 



`Rage on the Road` is an OpenGL-based `2D car racing game` created using the `GLUT (OpenGL Utility Toolkit)` library in C++. It is a fun and challenging game where the player has to drive a car on a busy highway while avoiding collisions with other vehicles. The game features a top-down view of the road and the player's car, and the objective is to score as many points as possible by covering as much distance as possible without crashing into any other cars.


The game has various features such as `speed control`, `level-up mechanism`, and a `scorekeeping system`. The game has a simple user interface and can be controlled using the keyboard.The game features three lanes of traffic, with other cars moving in each of them at different speeds. The `player's car can move left and right to switch lanes`, and the `speed of the game can be adjusted using the arrow keys`. 


Rage on the Road is a perfect example of how computer graphics can be used to create engaging and interactive games. It is a great way to learn about the basics of game development and OpenGL programming while having fun at the same time.

----------------------

## Computer Graphics concepts used



| Sr. No | Computer Graphics Concept | Description | Usage |
| ------ | ------------------------ | ----------- | ----- |
| 1.     | Coordinate Systems        | A coordinate system is a reference system used to represent the positions of objects in a two-dimensional or three-dimensional space. | The `glOrtho` function is used to define the coordinate system in the main function of the code. |
| 2.     | Shapes and Primitives     | Basic geometric shapes such as points, lines, triangles, rectangles, and polygons. | Various functions such as `glBegin`, `glEnd`, and `glVertex` are used to draw shapes like rectangles, triangles, and lines in the code. |
| 3.     | Colors and Shading        | Colors can be applied to shapes to give them a more visually appealing look. Shading is used to provide depth and realism to the shapes. | Functions like `glColor3f` and `glShadeModel` are used in the code to set the color and shading of the shapes respectively. |
| 4.     | Transformations           | Transformations involve modifying the position, orientation, and size of objects in a scene. | Used to move the cars and road dividers across the screen. |
| 5.     | Timer                     | Technique used to control the frame rate of the animation | The given code uses the `glutTimerFunc` function to create the illusion of motion in the game. Used to set the frame rate and update the display at regular intervals |
| 6.     | User Interaction          | This involves allowing the user to interact with the scene by responding to user inputs such as mouse clicks, key presses, or touch events. | In the given code, user interaction is implemented using the `glutSpecialFunc` and `glutKeyboardFunc` functions to detect user key presses and act accordingly. |



--------------------


## User Defined Functions

User Defined Functions | Descriptions
----------------------|----------------------
startGame()           | This function is responsible for displaying the road, the cars, and the score. It uses the glBegin() and glEnd() functions to define the vertices of the different shapes, such as the road, the cars, and the score.
firstDesign()         | This function is responsible for displaying the game menu before the game starts. It uses the glBegin() and glEnd() functions to define the vertices of the different shapes, such as the menu background, the game title, and the instructions.
display()             | This function is used to display the game on the screen. It contains two main functions, startGame() and firstDesign(), which display the different components of the game. It also uses OpenGL functions like glClear(), glClearColor(), and glFlush() to clear the screen, set the background color, and flush the current rendering context to the screen.
spe_key()             | This function is used to handle special keyboard events like arrow keys. It updates the values of the FPS and lrIndex variables based on the arrow key pressed.
processKeys()         | This function is used to handle normal keyboard events like space and escape keys. It updates the values of the start variable and other game variables based on the key pressed.
timer()               | This function is used to handle the timing of the game. It uses the glutTimerFunc() function to set the frame rate of the game.
tree()                | This Function is used to draw a tree on the screen.
renderBitmapString()   | This Function is used to render text on the screen. It takes three arguments - the x and y coordinates of where the text should be rendered and the text to be rendered. It uses OpenGL's built-in function glRasterPos2f to set the position for rendering the text and then iterates over the characters in the input text and renders them using the built-in function glutBitmapCharacter.


-------------------








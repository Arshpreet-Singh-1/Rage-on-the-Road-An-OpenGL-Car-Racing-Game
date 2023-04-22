// Rage on the Road : An OpenGL Car Racing Game 


// Include necessary libraries
#include <windows.h>
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>


// Set the game speed to 50 frames per second (FPS)
int FPS = 50;


// Set initial values for game track, score, and level
int start = 0;
int gv = 0;
int level = 0;
int score = 0;


// Set initial values for track divisions and car positions
float roadDivTop = 0;
float roadDivMdl = 0;
float roadDivBtm = 0;
// For Card Left / RIGHT
int lrIndex = 0;
// Car Coming
int car1 = 0;
int lrIndex1 = 0;
int car2 = +35;
int lrIndex2 = 0;
int car3 = +70;
int lrIndex3 = 0;


// Set the fonts for displaying text
const int font1 = (int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2 = (int)GLUT_BITMAP_HELVETICA_18;
const int font3 = (int)GLUT_BITMAP_8_BY_13;


// Function for displaying text on screen
char s[30];
void renderBitmapString(float x, float y, void* font, const char* string)
{
    const char* c;
    glRasterPos2f(x, y);
    // Loop through the characters in the string and display them using the specified font
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}


// Function for drawing a tree at the given (x, y) coordinates
void tree(int x, int y)
{
    int newx = x;
    int newy = y;


    // Draw the bottom part of the tree
    glColor3f(0.871, 0.722, 0.529); // Set the color to a light brown
    glBegin(GL_TRIANGLES); // Begin drawing a triangle
    glVertex2f(newx + 11, newy + 55); // Specify the first vertex of the triangle
    glVertex2f(newx + 12, newy + 55 - 10); // Specify the second vertex of the triangle
    glVertex2f(newx + 10, newy + 55 - 10); // Specify the third vertex of the triangle
    glEnd(); // End drawing the triangle


    // Draw the top part of the tree
    glColor3f(0.133, 0.545, 0.133); // Set the color to a dark green
    glBegin(GL_TRIANGLES); // Begin drawing a triangle
    glVertex2f(newx + 11, newy + 55 + 3); // Specify the first vertex of the triangle
    glVertex2f(newx + 12 + 3, newy + 55 - 3); // Specify the second vertex of the triangle
    glVertex2f(newx + 10 - 3, newy + 55 - 3); // Specify the third vertex of the triangle
    glEnd(); // End drawing the triangle
}


void startGame()
{
    // Drawing the game track and moving the road divider lines.
    // The track consists of a gray rectangular road with white borders on the left and right sides
    // The track is divided into three parts: top, middle, and bottom.
    // The road divider lines are drawn in yellow color and move downwards.


    // Road
    glColor3f(0.412, 0.412, 0.412); // setting the color to gray
    glBegin(GL_POLYGON); // drawing the rectangular road using GL_POLYGON
    // coordinates of the vertices are hardcoded to create a simple rectangular shape
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();


    // left and right borders of the road are drawn using white color, and 
    // their coordinates are hardcoded as well


    // Road Left Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(23, 100);
    glVertex2f(23, 0);
    glEnd();


    // Road Right Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(77, 0);
    glVertex2f(77, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();


    // the road divider lines are drawn in yellow color
    // The top, middle, and bottom lines are drawn using GL_POLYGON, and their coordinates are also hardcoded
    // the road divider lines are moved downwards
    // This is done by decrementing the values of roadDivTop, roadDivMdl, and roadDivBtm, 
    // which control the y-coordinate of the road divider lines
    // If any of these values become less than a certain threshold 
    // (i.e., -100 for roadDivTop, -60 for roadDivMdl, and -20 for roadDivBtm), 
    // the respective road divider line is reset to its starting position, and the score is incremented by 1. 
    // The score is used to keep track of the player's progress in the game


    // TOP
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, roadDivTop + 80);
    glVertex2f(48, roadDivTop + 100);
    glVertex2f(52, roadDivTop + 100);
    glVertex2f(52, roadDivTop + 80);
    glEnd();
    roadDivTop = roadDivTop - 0.5;
    if (roadDivTop < -100)
    {
        roadDivTop = 20;
        score++;
    }
    // Middle
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, roadDivMdl + 40);
    glVertex2f(48, roadDivMdl + 60);
    glVertex2f(52, roadDivMdl + 60);
    glVertex2f(52, roadDivMdl + 40);
    glEnd();
    roadDivMdl = roadDivMdl - 0.5;
    if (roadDivMdl < -60)
    {
        roadDivMdl = 60;
        score++;
    }
    // Bottom
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, roadDivBtm + 0);
    glVertex2f(48, roadDivBtm + 20);
    glVertex2f(52, roadDivBtm + 20);
    glVertex2f(52, roadDivBtm + 0);
    glEnd();
    roadDivBtm = roadDivBtm - 0.5;
    if (roadDivBtm < -20)
    {
        roadDivBtm = 100;
        score++;
    }



    // The code increases the game's speed with the level by increasing the FPS (frames per second) value by 2 
    // when the score is a multiple of 5. 


    // Score Board
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(80, 97);
    glVertex2f(100, 97);
    glVertex2f(100, 98 - 8);
    glVertex2f(80, 98 - 8);
    glEnd();


    // Print Score
    char buffer[50];
    sprintf_s(buffer, "SCORE: %d", score);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5, 95, (void*)font3, buffer);
    // Speed Print
    char buffer1[50];
    sprintf_s(buffer1, "SPEED:%dKm/h", FPS);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5, 95 - 2, (void*)font3, buffer1);
    // level Print
    if (score % 5 == 0)
    {
        int last = score / 5;
        if (last != level)
        {
            level = score / 5;
            FPS = FPS + 2;
        }
    }
    char level_buffer[50];
    sprintf_s(level_buffer, "LEVEL: %d", level + 1);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5, 95 - 4, (void*)font3, level_buffer);


    // rendering the main car and an opposite cars on the screen, and checking if they collide with each other.
    // Each car is made up of three polygons: two rectangles for the wheels and one trapezoid for the body. 


    // renders the main car with a black front and back tire and a green car body using GL_POLYGON.
    // Main Car
    // Front Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26 - 2, 5);
    glVertex2f(lrIndex + 26 - 2, 7);
    glVertex2f(lrIndex + 30 + 2, 7);
    glVertex2f(lrIndex + 30 + 2, 5);
    glEnd();
    // Back Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26 - 2, 1);
    glVertex2f(lrIndex + 26 - 2, 3);
    glVertex2f(lrIndex + 30 + 2, 3);
    glVertex2f(lrIndex + 30 + 2, 1);
    glEnd();
    // Car Body
    glColor3f(0.678, 1.000, 0.184);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26, 1);
    glVertex2f(lrIndex + 26, 8);
    glColor3f(0.000, 0.545, 0.545);
    glVertex2f(lrIndex + 28, 10);
    glVertex2f(lrIndex + 30, 8);
    glVertex2f(lrIndex + 30, 1);
    glEnd();


    // renders the opposite car1 with black front and back tires and a red car body using GL_POLYGON
    // The position of this car is determined by the variables lrIndex1 and car1.
    // decrements the value of car1, moving the opposite car downwards on the screen.
    // If the car goes off the top of the screen (car1 < -100), it resets to its original position 
    // at the top of  the screen and moves to the same lane as the main car (lrIndex1 = lrIndex).
    // checks for a collision between the main car and the opposite car
    // If their x-coordinates (abs(lrIndex - lrIndex1)) are within 8 units of each other 
    // and the y-coordinate of the opposite car (car1 + 100) is less than 10 units 
    // (i.e., the cars overlap vertically), the game ends and the game over flag (gv) is set to 1.


    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1 + 26 - 2, car1 + 100 - 4);
    glVertex2f(lrIndex1 + 26 - 2, car1 + 100 - 6);
    glVertex2f(lrIndex1 + 30 + 2, car1 + 100 - 6);
    glVertex2f(lrIndex1 + 30 + 2, car1 + 100 - 4);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1 + 26 - 2, car1 + 100);
    glVertex2f(lrIndex1 + 26 - 2, car1 + 100 - 2);
    glVertex2f(lrIndex1 + 30 + 2, car1 + 100 - 2);
    glVertex2f(lrIndex1 + 30 + 2, car1 + 100);
    glEnd();
    glColor3f(1.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1 + 26, car1 + 100);
    glVertex2f(lrIndex1 + 26, car1 + 100 - 7);
    glVertex2f(lrIndex1 + 28, car1 + 100 - 9);
    glVertex2f(lrIndex1 + 30, car1 + 100 - 7);
    glVertex2f(lrIndex1 + 30, car1 + 100);
    glEnd();
    car1--;
    if (car1 < -100)
    {
        car1 = 0;
        lrIndex1 = lrIndex;
    }
    if ((abs(lrIndex - lrIndex1) < 8) && (car1 + 100 < 10))
    {
        start = 0;
        gv = 1;
    }



    // similarly for Opposite car 2
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2 + 26 - 2, car2 + 100 - 4);
    glVertex2f(lrIndex2 + 26 - 2, car2 + 100 - 6);
    glVertex2f(lrIndex2 + 30 + 2, car2 + 100 - 6);
    glVertex2f(lrIndex2 + 30 + 2, car2 + 100 - 4);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2 + 26 - 2, car2 + 100);
    glVertex2f(lrIndex2 + 26 - 2, car2 + 100 - 2);
    glVertex2f(lrIndex2 + 30 + 2, car2 + 100 - 2);
    glVertex2f(lrIndex2 + 30 + 2, car2 + 100);
    glEnd();
    glColor3f(0.300, 0.000, 0.500);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2 + 26, car2 + 100);
    glVertex2f(lrIndex2 + 26, car2 + 100 - 7);
    glVertex2f(lrIndex2 + 28, car2 + 100 - 9);
    glVertex2f(lrIndex2 + 30, car2 + 100 - 7);
    glVertex2f(lrIndex2 + 30, car2 + 100);
    glEnd();
    car2--;
    if (car2 < -100)
    {
        car2 = 0;
        lrIndex2 = lrIndex;
    }
    if ((abs(lrIndex - lrIndex2) < 8) && (car2 + 100 < 10))
    {
        start = 0;
        gv = 1;
    }


    // Similarly for opposite car 3
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3 + 26 - 2, car3 + 100 - 4);
    glVertex2f(lrIndex3 + 26 - 2, car3 + 100 - 6);
    glVertex2f(lrIndex3 + 30 + 2, car3 + 100 - 6);
    glVertex2f(lrIndex3 + 30 + 2, car3 + 100 - 4);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3 + 26 - 2, car3 + 100);
    glVertex2f(lrIndex3 + 26 - 2, car3 + 100 - 2);
    glVertex2f(lrIndex3 + 30 + 2, car3 + 100 - 2);
    glVertex2f(lrIndex3 + 30 + 2, car3 + 100);
    glEnd();
    glColor3f(1.000, 0.271, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3 + 26, car3 + 100);
    glVertex2f(lrIndex3 + 26, car3 + 100 - 7);
    glVertex2f(lrIndex3 + 28, car3 + 100 - 9);
    glVertex2f(lrIndex3 + 30, car3 + 100 - 7);
    glVertex2f(lrIndex3 + 30, car3 + 100);
    glEnd();
    car3--;
    if (car3 < -100)
    {
        car3 = 0;
        lrIndex3 = lrIndex;
    }
    if ((abs(lrIndex - lrIndex3) < 8) && (car3 + 100 < 10))
    {
        start = 0;
        gv = 1;
    }
}


void fristDesign()
{
    // The design consists of a road with a green background, hills in the background, blue sky,
    // trees, and a menu, and also displaying some text on the screen


    // Road BackGround
    glColor3f(0.000, 0.350, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(0, 55);
    glVertex2f(100, 55);
    glColor3f(0.6, 0.8, 0.3);
    glVertex2f(100, 50 - 50);
    glVertex2f(0, 50 - 50);
    glEnd();


    // Road Design In Front Page
    glColor3f(0, 0.3, 0.3);
    glBegin(GL_TRIANGLES);
    glVertex2f(32 - 2 + 21, 55);
    glVertex2f(32 + 58, 50 - 50);
    glVertex2f(32 - 22, 50 - 50);
    glEnd();
    // Road Middle
    glColor3f(0.8, 0.8, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(32 - 2 + 21, 55);
    glVertex2f(50 + 2, 50 - 50);
    glVertex2f(50 - 2, 50 - 50);
    glEnd();


    // Road Sky
    glColor3f(0.000, 0.60, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(100, 100);
    glVertex2f(0, 100);
    glColor3f(0.933, 0.933, 0.933);
    glVertex2f(0, 55);
    glVertex2f(100, 55);
    glEnd();


    // Hill 1
    glColor3f(0.235, 0.702, 0.443);
    glBegin(GL_TRIANGLES);
    glVertex2f(20, 55 + 10);
    glVertex2f(20 + 7, 55);
    glVertex2f(0, 55);
    glEnd();


    // Hill 2
    glColor3f(0.000, 0.400, 0.000);
    glBegin(GL_TRIANGLES);
    glVertex2f(20 + 15, 55 + 12);
    glVertex2f(20 + 20 + 10, 55);
    glVertex2f(0 + 10, 55);
    glEnd();


    // Hill 3
    glColor3f(0.235, 0.702, 0.443);
    glBegin(GL_TRIANGLES);
    glVertex2f(87, 55 + 10);
    glVertex2f(100, 55);
    glVertex2f(60, 55);
    glEnd();


    // Hill 4
    glColor3f(0.000, 0.400, 0.000);
    glBegin(GL_TRIANGLES);
    glVertex2f(70, 70);
    glVertex2f(90, 55);
    glVertex2f(50, 55);
    glEnd();


    // Trees on front page
    tree(5, -15);
    tree(0, 0);
    tree(9, 5);
    tree(80, 0);
    tree(75, -15);
    tree(72, 5);


    // Menu Place Holder
    glColor3f(0.098, 0.098, 0.439);
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 - 15 + 10);
    glVertex2f(32 - 4, 50 - 15 + 10);
    glEnd();


    glColor3f(00, 0, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 4 + 10);
    glVertex2f(32 - 4, 50 + 4 + 10);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(32 + 45, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 - 15 + 10);
    glVertex2f(32 + 45, 50 - 15 + 10);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 - 14 + 10);
    glVertex2f(32 + 46, 50 - 14 + 10);
    glVertex2f(32 + 46, 50 - 15 + 10);
    glVertex2f(32 - 4, 50 - 15 + 10);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 + 5 + 10);
    glVertex2f(32 - 5, 50 + 5 + 10);
    glVertex2f(32 - 5, 50 - 15 + 10);
    glVertex2f(32 - 4, 50 - 15 + 10);
    glEnd();


    //Text Information in First Page
    if (gv == 1)
    {
        glColor3f(1.000, 0.000, 0.000);
        renderBitmapString(35, 60 + 15, (void*)font1, "GAME OVER");
        glColor3f(1.000, 0.000, 0.000);
        char buffer2[50];
        sprintf_s(buffer2, "Your Score is : %d", score);
        renderBitmapString(33, 60 - 4 + 15, (void*)font1, buffer2);
    }


    glColor3f(0.000, 0.000, 0.000);
    renderBitmapString(20, 90, (void*)font2, "Computer Graphics (UCS505) Project");
    renderBitmapString(10, 90-5, (void*)font2, "Rage on the Road :\n An OpenGL Car Racing Game ");


    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(30, 50 + 10, (void*)font2, "Press SPACE to Start");
    renderBitmapString(30, 50 - 3 + 10, (void*)font2, "Press ESC      to Exit");


    glColor3f(1.000, 1.000, 1.000);
    renderBitmapString(30, 50 - 6 + 10, (void*)font3, "Press UP    to Increase Speed");
    renderBitmapString(30, 50 - 8 + 10, (void*)font3, "Press DWON  to Decrease Speed");
    renderBitmapString(30, 50 - 10 + 10, (void*)font3, "Press RIGHT to Turn Right");
    renderBitmapString(30, 50 - 12 + 10, (void*)font3, "Press LEFT  to Turn Left");


    glColor3f(0.000, 1.000, 1.000);
    renderBitmapString(30 - 8, 50 - 40, (void*)font3, "Arshpreet Singh          (102017045)");
    renderBitmapString(30 - 8, 50 - 43, (void*)font3, "Lagan Kapoor             (102197007)");
}


void display()
{
    // clears the color buffer using glClear(GL_COLOR_BUFFER_BIT) to set the background color to black.
    glClear(GL_COLOR_BUFFER_BIT);


    // If the variable start is equal to 1, it sets the clear color to dark green 
    // using glClearColor(0.000, 0.392, 0.000, 1) and calls the startGame() function, 
    // which presumably displays the actual game graphics.


    if (start == 1)
    {
        glClearColor(0.000, 0.392, 0.000, 1);
        startGame();
    }


    // If start is not equal to 1, it calls the fristDesign() function, 
    // which presumably displays the initial design of the game, such as the title screen or main menu.


    else
    {
        fristDesign();
    }


    // flushes any pending OpenGL commands using glFlush() and 
    // swaps the front and back buffers using glutSwapBuffers(). 
    // This is necessary because OpenGL uses double buffering to prevent flickering and tearing 
    // when drawing to the screen.


    glFlush();
    glutSwapBuffers();
}


// The function uses a switch statement to handle different keys. 
// If the down arrow key is pressed, the FPS (frames per second) variable is decreased by 2, 
// but not below a certain minimum value based on the level of the game. 
// If the up arrow key is pressed, the FPS variable is increased by 2. 
// If the left arrow key is pressed, the lrIndex variable is moved to the left by an amount based on the FPS, 
//but not below a certain minimum value of -1. 
// If the right arrow key is pressed, the lrIndex variable is moved to the right by an amount based on the FPS, 
// but not above a certain maximum value of 45.


void spe_key(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_DOWN:
        if (FPS > (50 + (level * 2)))
            FPS = FPS - 2;
        break;
    case GLUT_KEY_UP:
        FPS = FPS + 2;
        break;


    case GLUT_KEY_LEFT:
        if (lrIndex >= 0)
        {
            lrIndex = lrIndex - (FPS / 10);
            if (lrIndex < 0)
            {
                lrIndex = -1;
            }
        }
        break;


    case GLUT_KEY_RIGHT:
        if (lrIndex <= 44)
        {
            lrIndex = lrIndex + (FPS / 10);
            if (lrIndex > 44)
            {
                lrIndex = 45;
            }
        }
        break;


    default:
        break;
    }
}


// The function then checks the value of the character key against certain cases. 
// If the key pressed is the space bar (' '), it sets the game variables to their initial values, 
// indicating the start of the game. If the key pressed is the Escape key (27), the program exits.
// If none of the above conditions are met, the function simply returns without any further action.


void processKeys(unsigned char key, int x, int y)
{


    switch (key)
    {
    case ' ':
        if (start == 0)
        {
            start = 1;
            gv = 0;
            FPS = 50;
            roadDivTop = 0;
            roadDivMdl = 0;
            roadDivBtm = 0;
            lrIndex = 0;
            car1 = 0;
            lrIndex1 = 0;
            car2 = +35;
            lrIndex2 = 0;
            car3 = +70;
            lrIndex3 = 0;
            score = 0;
            level = 0;
        }
        break;


    case 27:
        exit(0);
        break;
    default:
        break;
    }
}


// This is a timer function that is used in the game loop to control the frame rate of the game. 
// It uses the glutTimerFunc() function from the GLUT library to call itself every 1000 / FPS milliseconds, 
// where FPS is the current frame rate of the game. This function then calls glutPostRedisplay() to redraw 
//the game screen, which triggers the display() function to be called again. 
// This creates a loop that continuously updates the game screen at a steady frame rate.



void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, timer, 0);
}


int main(int argc, char* argv[])
{
    // Initializes GLUT with the command line arguments provided.
    glutInit(&argc, argv);
    // Sets the display mode to RGB color and double buffering.
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    // Sets the initial window size and position, and creates a window with the specified title
    glutInitWindowSize(500, 650);
    glutInitWindowPosition(200, 20);
    glutCreateWindow("Rage on the Road : An OpenGL Car Racing Game");


    // Registers the display function, special key function, and keyboard function.
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys);


    // Sets up the 2D orthographic projection with the specified coordinates and clear color.
    glOrtho(0, 100, 0, 100, -1, 1);
    glClearColor(0.184, 0.310, 0.310, 1);


    // Sets up a timer function that calls the display function at a fixed interval based on the current frame rate.
    glutTimerFunc(1000, timer, 0);
    // Enters the GLUT event processing loop, which handles user input and updates the display as necessary.
    glutMainLoop();


}

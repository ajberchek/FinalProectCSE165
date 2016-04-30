Use the following keywords in the text file

Wall: for a wall object's animation
Player: for a player object's animation
Mole: for a mole object's animation
Door: for a door object's animation
Coin: for a coin object's animation

then it will need to be followed by a $ character to delimit it

then there will be a number (indexed from 0) that will correspond to the number of the animation in the vector of animations

then there will be a $ character to delimit it

then the path to image

ex:

Wall$0$Images/Wall/0.bmp

This is for just displaying the single image needed for a wall, it doesnt change state, it doesnt move, it is just there, wall is wall.

and

Mole$0$Images/Mole/moleHiding.bmp
Mole$1$Images/Mole/moleTransition.bmp
Mole$1$Images/Mole/moleReadyToAttack.bmp
Mole$2$Images/Mole/moleReadyToAttack.bmp
Mole$3$Images/Mole/moleAttacking.bmp
Mole$3$Images/Mole/moleReadyToAttack.bmp
Mole$4$Images/Mole/moleTransition.bmp
Mole$4$Images/Mole/moleHiding.bmp


For the mole cases:
0 represents the Animation for resting.
1 represents the Animation for rising up out of its hole.
2 represents the Animation for staying up out of its hole.
3 represents the animation for attacking.
4 represents the animation for going back down into its hole.

Animation class will always increment to the next image in a circular manner to draw after it draws the current image that way the next time draw gets called it will draw the next one in its sequence.

Because it is circular, if there is only one texture in that animation vector it will display that same texture next time because of the circular fashion.


Animation:

OpenGL allows for various texturing rendering options and allows the programmer to tell the computer how to handle the rendering. 
Below are some options for texture rendering. Note that these options affects the speed of rendering as well as how well it looks.

glShadeModel:
	GL_SMOOTH: Pixel Fragments get their own colors. The color is determined through interpolation.
		- Slower, but look smoother.
	GL_FLAT:   Pixel Fragments are all assigned to a single color base on their distance to a given vertex. 
		- Faster, but more rough and edgy.
glTexCoord2f:
Think of it as a rectangle of pixels. A square of area of 1 unit from [0,1] to [0,1] is perfectly map for each pixel 1 : 1 in a region of that square. Please don't change unless neccessary.

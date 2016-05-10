#include "Animation.h"
#include <iostream>

using namespace std;



Animation::Animation()
{
	imgPtr = new vector<GLuint *>();
	it = 0;
}

void Animation::windowToScene(float &x, float &y)
{
	x = (2.0f*(x/float(newW)) - 1.0f);
	y = 1.0f - (2.0f*(y/float(newH)));
}

int Animation::animate(float x, float y, float w, float h) 	 
{	

	it = ((it) % imgPtr->size());

	Animation::windowToScene(x,y);

	//cout << "NewW: " << newW << " NewH: " << newH << endl;

	w = 2.0f*((w/float(newW)));
	h = 2.0f*((h/float(newH)));

	

	//cout << "animate is called" << endl;
	//cout << "Drawing on coordinates (x,y,w,h): " << x << ", " << y << ", " << w << ", " << h << endl;

	// Binding Texture
	//glShadeModel(GL_SMOOTH);
	glBindTexture(GL_TEXTURE_2D, *(imgPtr->at((it))));


	glEnable(GL_TEXTURE_2D);

		
	// Drawing the Texture
	glBegin(GL_POLYGON);											// texCoord for tex, vertex for where to map
	glTexCoord2f(0.0f, 1.0f);	glVertex2d(x, y);
	glTexCoord2f(1.0f, 1.0f);	glVertex2d(x+w, y);
	glTexCoord2f(1.0f, 0.0f);	glVertex2d(x+w, y-h);
	glTexCoord2f(0.0f, 0.0f);	glVertex2d(x, y-h);
	glEnd();
	
	// Fixing this code so there's no possibility of overflow

	//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	
	glDisable(GL_TEXTURE_2D);
	
	
	// Current Isssue: Which element of the vector to render?
	// Technical Deliberation: Parameters such as lightning and background. 
	return it;
}

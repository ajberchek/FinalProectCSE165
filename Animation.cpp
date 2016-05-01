#include "Animation.h"
#include <iostream>

using namespace std;



Animation::Animation()
{
	imgPtr = new vector<GLuint *>();
	it = imgPtr->begin();
}

void Animation::animate(float &x, float &y, float &w, float &h) 	 // Why not take in a Collideable container instead
{	

	cout << "animate is called" << endl;

	// Binding Texture
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glBindTexture(GL_TEXTURE_2D, *(imgPtr->at((it-imgPtr->begin()))));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	
	// Drawing the Texture
	glBegin(GL_POLYGON);											// texCoord for tex, vertex for where to map
																	// texCoord is set to non-stretching, 1 to 1 mapping.
	glTexCoord2f(0.0f, 1.0f);	glVertex2d(x, y+h);
	glTexCoord2f(1.0f, 1.0f);	glVertex2d(x+w, y+h);
	glTexCoord2f(1.0f, 0.0f);	glVertex2d(x+w, y);
	glTexCoord2f(0.0f, 0.0f);	glVertex2d(x, y);
	glEnd();
	

	it = imgPtr->begin() + ((it-imgPtr->begin()+1) % imgPtr->size());


	glDisable(GL_TEXTURE_2D);
	
	
	// Current Isssue: Which element of the vector to render?
	// Technical Deliberation: Parameters such as lightning and background. 
}

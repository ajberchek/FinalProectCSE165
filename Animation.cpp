#include "Animation.h"

Animation::Animation()
{
	imgPtr = new vector<GLuint *>();
}

void Animation::animate(float x, float y, float w, float h)
{	
	// Binding Texture
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glBindTexture(GL_TEXTURE_2D, *(imgPtr->at(0)));
	
	// Drawing the Texture
	glBegin(GL_POLYGON);									//texCoord for tex, vertex for where to map
															//texCoord is set to non-stretching, 1 to 1 mapping.
	glTexCoord2f(0.0f, 1.0f);	glVertex2d(x, y+h);
	glTexCoord2f(1.0f, 1.0f);	glVertex2d(x+w, y+h);
	glTexCoord2f(1.0f, 0.0f);	glVertex2d(x+w, y);
	glTexCoord2f(0.0f, 0.0f);	glVertex2d(x, y);
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
	
	
	// Current Isssue: Which element of the vector to render?
	// Technical Deliberation: Parameters such as lightning and background. 
}

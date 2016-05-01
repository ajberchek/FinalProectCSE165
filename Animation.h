#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include <GL/gl.h>
using namespace std;
class Animation
{
	public:
		Animation();
		vector<GLuint *> * imgPtr;
		vector<GLuint *>::iterator it;
		void animate(float &x, float &y, float &w, float &h);
};
#endif 
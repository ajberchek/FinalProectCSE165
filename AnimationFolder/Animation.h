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
		void animate();
};
#endif 

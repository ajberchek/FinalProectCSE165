#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
using namespace std;
class Animation
{

	public:
		vector<GLuint *> * imgPtr;
		void animate();
};
#endif 

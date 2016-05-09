
# include <iostream>
# include "app_window.h"
# include <vector>
# include "GameLogic.h"
# include<string.h>
# include<sstream>
#include <chrono>
#include <thread>

float newH;
float newW;
bool resizeCalledAlready = false;


GameLogic * gLogic;

Animation *testAnim;

AppWindow::AppWindow ( const char* label, int x, int y, int w, int h )
          :GlutWindow ( label, x, y, w, h )
 {
   _markx = 0;
   _marky = 0;
   addMenuEntry ( "Option 0", evOption0 );
   addMenuEntry ( "Option 1", evOption1 );
   scor = 0;
   s = 0;
   time = "";
   score = "";
 }

// mouse events are in window coordinates, but your scene is in [0,1]x[0,1],
// so make here the conversion when needed
void AppWindow::windowToScene ( float& x, float &y )
 {
   x = (2.0f*(x/float(_w))) - 1.0f;
   y = 1.0f - (2.0f*(y/float(_h)));
 }

// Called every time there is a window event
void AppWindow::handle ( const Event& e )
 {
   bool rd=true;

   if ( e.type==Keyboard ) 
    switch ( e.key )
    { case ' ': // space bar
	   std::cout << "Space pressed.\n";
       _markx = 1.5;
       _marky = 1.5;
       redraw();
	   break;

	  case 27: // Esc was pressed
	   exit(1);
	}

   if ( e.type==MouseDown || e.type==Motion)
    { _markx=(float)e.mx;
      _marky=(float)e.my;
      windowToScene(_markx,_marky);
    }

   if ( e.type==Menu )
    { std::cout<<"Menu Event: "<<e.menuev<<std::endl;
      rd=false; // no need to redraw
    }

	// Considering checking if the user will move out of bound. Have a function to check and return true if not out of bound and false if out of bound?
	// Currently it is possible for user to move to the edge and move past where we can see the user. 
   if ( e.type==SpecialKey )
    switch ( e.key )
    { 
		case GLUT_KEY_LEFT:  
			break;
	     	case GLUT_KEY_RIGHT: 
			break;
	      	case GLUT_KEY_UP:    
			break;
	      	case GLUT_KEY_DOWN:  
			break;
	      default: rd=false; // no redraw
	}
	gLogic->eventQueue.push(e);

   if (rd) redraw(); // ask the window to be rendered when possible
}

void AppWindow::resize ( int w, int h )
 {
   // Define that OpenGL should use the whole window for rendering
   cout << "resize called: " << endl;
   cout << "Resize to this width: " << w << endl;
   cout << "Resize to this height: " << h << endl;
   glViewport( 0, 0, w, h );
   _w=w; _h=h;
   newW = w;
   newH = h;
   if(!resizeCalledAlready)
   {
	   gLogic = new GameLogic(); 
	   resizeCalledAlready = true;
   }
 }

// here we will redraw the scene according to the current state of the application.
void AppWindow::draw ()
 {
   // Clear the rendering window
   glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

   // Clear the trasnformation stack
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();

   
   /*
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
   */
   /*
   vector<GLuint *> * test = testAnim->imgPtr;
   test->push_back(&texture);
   float x = 0.0f;
   float y = 0.0f;
   float w = 1.0f;
   float h = 1.0f;
   testAnim->animate(x, y, w, h);
   */
   /* you may use GL_POLYGON for generic *convex* polygons, like this:
   glBegin( GL_POLYGON );
   glColor3f ( ... );
   glVertex2d ( ... );
   glVertex2d ( ... );
   glVertex2d ( ... );
   glVertex2d ( ... );
   glEnd();*/

   // Swap buffers
   //
   	stringstream ts, ss;
   	ts<<"Time : ";
	ts<<s;
	time = ts.str();
   	drawText(time.data(), time.size(),1,590);	//580
	s = gLogic->getTime();
	
	ss<<"Score : ";
	ss<<scor;
	score = ss.str();
	drawText(score.data(), score.size(),500,590);
	scor = gLogic->getScore();
	
	glBegin( GL_POLYGON );
	glColor3f (0,0,1);
	glVertex2f (-1,1);
	glVertex2f (1,1);
	glVertex2f (1,.95);
	glVertex2f (-1,.95);
	glEnd();
	glColor3f (1,1,1);
	/*if(s > 60)
   	{
   		m += 1;
   		s -= 60;
   	}
   	if(m > 0 && s <= 0)
   	{
   		m -=1;
   		s += 60;
   	}*/
   if(gLogic)
   {
	   gLogic->update();
   }
   
   glFlush();         // flush the pipeline (usually not necessary)
   glutSwapBuffers(); // we were drawing to the back buffer, now bring it to the front
}
void AppWindow::drawText(const char * text, int length, int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	double * matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0,800,0,600, -5,5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x,y);
	for(int i = 0; i < length; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

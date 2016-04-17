#include "../MazeAlgoFolder/MazeAlgorithmText.cpp"
#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
	#define separator "\\\\"
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
	#define separator "/"
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif

int main()
{
	char cCurrentPath[FILENAME_MAX];

	string testFileName = "mazeFile.txt";


	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		throw(0xBAD);
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	printf ("The current working directory is %s", cCurrentPath);

	string pathToMaze = cCurrentPath + (string)separator + testFileName;
	
	MazeAlgorithmText mt(pathToMaze);

	mt.genMaze(0);

}

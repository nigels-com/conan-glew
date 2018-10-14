#include <GL/glew.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	GLenum err;

#if defined(WIN32) || defined(__APPLE__)
    if (1)
#else
    /* Need X11 display to init GLUT */
    if (getenv("DISPLAY")!=NULL)
#endif
    {
        glutInit(&argc, argv);
        glutCreateWindow("GLUT Window");
        err = glewInit();
        if (GLEW_OK != err)
        {
            printf("Error: %s\n", glewGetErrorString(err));
            return EXIT_FAILURE;
        }
    }
    printf("Bincrafters GLEW %s\n", glewGetString(GLEW_VERSION));
    return EXIT_SUCCESS;
}

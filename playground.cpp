#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <glfw3.h>
GLFWwindow* window;

#include <glm/glm.hpp>
using namespace glm;


GLFWmonitor* monitor;
#include <glm/glm.hpp>
using namespace glm;


#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include FT_OUTLINE_H
#include FT_TRIGONOMETRY_H

#define WIDTH   640
#define HEIGHT  480

int window_width, window_height;
int window_x, window_y;
int screen_width, screen_height;

const GLFWvidmode *mode, *modes;


/* origin is the upper left corner */
unsigned char image[HEIGHT][WIDTH];

FT_Library  library;
FT_Face     face;      /* handle to face object */
// char* fontName = "tr.ttf";
// unsigned char Image[800][800];




// TODO
/*

	Right now, both GLFW 3.1 and 3.2 exist on your machine. 3.1 seems to be the 
	system default, residing in /usr/include and /usr/lib/x86_64-linux-gnu/libglfw.so.3

	3.2 resides in /usr/local/.

	You can either remove 3.1 from your system, and try to install 3.2 as the system-wide default,
	or leave it as it is, and just be sure to link to the 3.2 version in your program (probably safer and wiser).

	So, to do that, you will finally make a separate repo, and stop piggybacking off of the makefile from ogl-master.
	Should just be a matter of some simple linking really.


*/






void set_yellow(){
	glClearColor(0.8f,0.8f,0.0f,0.0f);	
}

void set_red(){
	glClearColor(0.8f,0.1f,0.1f,0.0f);
}

void init_ft()
{
  FT_Library    library;
  FT_Face       face;

  FT_GlyphSlot  slot;
  FT_Matrix     matrix;                 /* transformation matrix */
  FT_Vector     pen;                    /* untransformed origin  */
  FT_Error      error;

  const char*         filename;
  const char*         text;

  double        angle;
  int           target_height;
  int           n, num_chars;


  filename = "/usr/share/fonts/truetype/droid/DroidSansFallbackFull.ttf";
  text = "Look at dis";
  num_chars     = strlen( text );
  angle         = ( 25.0 / 360 ) * 3.14159 * 2;      /* use 25 degrees     */
  target_height = HEIGHT;

  error = FT_Init_FreeType( &library );              /* initialize library */
  /* error handling omitted */

  error = FT_New_Face( library, filename, 0, &face );/* create face object */

  if (error == FT_Err_Unknown_File_Format ){
	fprintf(stderr,"Unknown file format found.\n");
  	exit(1);
  }
}


void get_screen_resolution(GLFWmonitor *monitor) {
    const GLFWvidmode * mode = glfwGetVideoMode(monitor);

    screen_width = mode->width;
    screen_height = mode->height;
}

//not really needed if in fullscreen mode
void set_window_size_pos(){
	window_height = screen_height * 0.95;
	window_width = screen_width * 0.95;
	window_x = (screen_width - window_width) / 2;
	window_y = (screen_height - window_height) / 2;
}

int main( void )
{

	int status;

	const char* str = glfwGetVersionString();
	printf("%s\n",str);

	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}


	monitor = glfwGetPrimaryMonitor();
	get_screen_resolution(monitor);
	set_window_size_pos();
	mode = glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	glfwWindowHint(GLFW_VISIBLE,1);

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_DECORATED,0);

	
	// Open a window and create its OpenGL context
	window = glfwCreateWindow( window_width, window_height, 
		"INTRUDER", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an "
			"Intel GPU, they are not 3.3 compatible. Try the 2.1 version"
			" of the tutorials.\n" );
		getchar();
		glfwTerminate();
		return -1;
	}

	// glfwSetWindowMonitor(window,monitor,0,0,mode->width,mode->height,mode->refreshRate);

	glfwMakeContextCurrent(window);
	// glfwSetWindowPos(window, window_x, window_y);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		// getchar();
		glfwTerminate();
		return -1;
	}



	//init_ft();

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);



	// Dark blue background
	float r,g,b, inc;
	r = g = b = 0;

	inc = 0.01;
	bool red = true;
	float cur_seconds, prev_seconds;

	prev_seconds = glfwGetTime();

	set_red();

	do{
		glClear(GL_COLOR_BUFFER_BIT);

		

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

		cur_seconds = glfwGetTime();
		if (cur_seconds - prev_seconds >= 0.7){
			prev_seconds = cur_seconds;
			if (red){
				set_yellow();
				red = false;
			}
			else {
				set_red();
				red = true;
			}
		}

		if (glfwGetKey(window, GLFW_KEY_ESCAPE ) == GLFW_PRESS){
			break;
		}




	} // Check if the ESC key was pressed or the window was closed
	while(glfwWindowShouldClose(window) == 0 );

	mode = glfwGetVideoMode(monitor);
	printf("%d %d %d %d %d %d\n",mode->width,
		mode->height,mode->redBits, mode->greenBits, 
		mode->blueBits, mode->refreshRate);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	// status = system("./take_picture.sh");	
	return 0;
}


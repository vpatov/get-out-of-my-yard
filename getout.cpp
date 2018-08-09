
#include "getout.h"

using namespace std;

int window_width, window_height;
int window_x, window_y;
int screen_width, screen_height;


GLFWwindow* window;
GLFWmonitor* monitor;
const GLFWvidmode *mode, *modes;

bool key_press_started = false;
bool trigger_intruder = false;



// TODO
/*
	1) configure the freetype library to display some text
	2) Refactor, organize and make the code cleaner and more elegant
	3) Key combo to break program + mouse movement to trigger intruder.
	4) Talk to python code that will take picture. 
		a) Open up socket, bind it to ephemeral port on localhost
		b) Pass port number to python script.
		c) Python script waits for signal from C program to take picture.
		d) Python script sends signal to c program once script is done.

	5) Figure out good way to get home directory in project, to call python script and save image.
	6) Look into how GLFW threads and see if you can create two functions, flicker() and check_keys().
		This separation would be cleanest and would make most sense. You should be able to just use pthreads. 
				^^ lol not necessary compoopers are fast
*/


   

string default_key_combo = "LEFT CONTROL,LEFT SHIFT,A";
vector<int> combo_keycodes;

void set_yellow(){
	glClearColor(0.8f,0.8f,0.0f,0.0f);	
}

void set_red(){
	glClearColor(0.8f,0.1f,0.1f,0.0f);
}


void get_screen_resolution(GLFWmonitor *monitor) {
    const GLFWvidmode * mode = glfwGetVideoMode(monitor);

    screen_width = mode->width;
    screen_height = mode->height;
}

//not really needed if in fullscreen mode
void set_window_size_pos(){
	window_height = screen_height * 0.75;
	window_width = screen_width * 0.75;
	window_x = (screen_width - window_width) / 2;
	window_y = (screen_height - window_height) / 2;
}

void init_key_combo(){
	vector<string> keys;
	int keycode;

    keys = split(default_key_combo, ',');
    for (vector<string>::iterator it = keys.begin(); it != keys.end(); it++){
    	keycode = get_keycode(*it);
    	if (keycode >= 0)
    		combo_keycodes.push_back(keycode);

    	printf("%d\n", keycode);
    }
}



void init_user_preferences(){
	init_key_combo();
}



void intruder(){
	float cur_seconds, prev_seconds, flicker_rate;
	bool red = true;


	// system("python3 ../take_picture.py");

	flicker_rate = 0.4;
	glfwSetWindowMonitor(window,monitor,0,0,mode->width,mode->height,mode->refreshRate);
	set_red();
	prev_seconds = glfwGetTime();
	do{
		glClear(GL_COLOR_BUFFER_BIT);


		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

		cur_seconds = glfwGetTime();
		if (cur_seconds - prev_seconds >= flicker_rate){
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

		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS){
			printf("Escape sequence captured.\n");
			break;
		}

		if (glfwGetKey(window, GLFW_KEY_ESCAPE ) == GLFW_PRESS){
			printf("ESC key pressed.\n");
			break;
		}

	} // Check if the ESC key was pressed or the window was closed
	while(glfwWindowShouldClose(window) == 0 );

}



bool key_in_combo(int key, std::vector<int> &key_combo){
	for (std::vector<int>::iterator it = key_combo.begin(); it != key_combo.end(); it++){
		if (*it == key)
			return true;
	}
	return false;
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	printf("action: %d\n",action);

	if (!key_press_started){
		key_press_started = true;
	}
	else if (!key_in_combo(key,	combo_keycodes)){
		trigger_intruder = true;
	}

	// if pressing down
	if (action == 1){
		pressed_keys[key] = true;
	}

	// if releasing
	else if (action == 0){
		pressed_keys[key] = false;
	}

	printf("key: %d, scancode: %d, action: %d, mods: %d\n", key, scancode, action, mods);
}


//return true if user successfully unlocks with correct keypress, false otherwise
bool process_keys(){
	do{
		glfwWaitEvents();

		// for (vector<int>::iterator it = combo_keycodes.begin(); it != combo_keycodes.end(); it++){
		// 	printf("%d\n", *it);
		// }

		if (glfwGetKey(window, GLFW_KEY_ESCAPE ) == GLFW_PRESS){
			printf("ESC key pressed.\n");
			return true;
			break;
		}

	

		// if key_press_started && no keys are being pressed right now, trigger intruder	

		int count_pressed = 0;
		for (std::vector<int>::iterator it = combo_keycodes.begin(); it != combo_keycodes.end(); it++){
			if (glfwGetKey(window,*it) == GLFW_PRESS){
				count_pressed++;
			}
		}
		if (count_pressed == combo_keycodes.size())
			return true;

		else if (count_pressed == 0 && key_press_started)
			return false;	

		else if (trigger_intruder)
			return false;

		//if (key_press_started)
		//	return false;

	} // Check if the ESC key was pressed or the window was closed
	while(glfwWindowShouldClose(window) == 0 );

	return true;
}



int main( void )
{

	int status, success;

	const char* str = glfwGetVersionString();
	init_user_preferences();

	printf("%s\n",str);

	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}

	
	monitor = glfwGetPrimaryMonitor();
	mode = glfwGetVideoMode(monitor);

	get_screen_resolution(monitor);
	set_window_size_pos();

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
	glfwWindowHint(GLFW_DECORATED,GLFW_FALSE);
	// glfwWindowHint(GLFW_VISIBLE,GLFW_FALSE);

	
	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 1, 1, 
		"INTRUDER", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window.\n" );
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetWindowPos(window, 0, 0);
	glfwSetKeyCallback(window, key_callback);

	success = process_keys();

	if (success){
		glfwTerminate();
		printf("Successfully unlocked. Welcome.\n");
		return 0;
	}
	else {
		printf("I scream.. no sound. <I had already tried>.\n");
		intruder();
		

	}



	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	// status = system("./take_picture.sh");	
	return 0;
}




// void init_ft()
// {
//   FT_Library    library;
//   FT_Face       face;

//   FT_GlyphSlot  slot;
//   FT_Matrix     matrix;                 /* transformation matrix */
//   FT_Vector     pen;                    /* untransformed origin  */
//   FT_Error      error;

//   const char*         filename;
//   const char*         text;

//   double        angle;
//   int           target_height;
//   int           n, num_chars;


//   filename = "/usr/share/fonts/truetype/droid/DroidSansFallbackFull.ttf";
//   text = "Look at dis";
//   num_chars     = strlen( text );
//   angle         = ( 25.0 / 360 ) * 3.14159 * 2;      /* use 25 degrees     */
//   target_height = HEIGHT;

//   error = FT_Init_FreeType( &library );              /* initialize library */
//   /* error handling omitted */

//   error = FT_New_Face( library, filename, 0, &face );/* create face object */

//   if (error == FT_Err_Unknown_File_Format ){
// 	fprintf(stderr,"Unknown file format found.\n");
//   	exit(1);
//   }
// }

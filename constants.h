#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)

//-----------------------------------------------
//                  Constants
//-----------------------------------------------

// window
const char CLASS_NAME[] = "Cipher";
const char GAME_TITLE[] = "Cipher";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH =  1280;               // width of game in pixels
const UINT GAME_HEIGHT = 720;               // height of game in pixels

// game
const double PI = 3.14159265;
const float FRAME_RATE = 100.0f;                // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f/FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f/MIN_FRAME_RATE; // maximum time used in calculations
const float GRAVITY = 6.67428e-11f;             // gravitational constant

// graphic images
const char PLATFORM1_IMAGE[] = "pictures\\platform1.png";
const char PLATFORM1_IMAGE[] = "pictures\\Background\\platform1.png";
const char BACKGROUND1_IMAGE[] = "pictures\\Background\\background1.png";
const char MIDDLEGROUND1_IMAGE[] = "pictures\\Background\\middleground1.png";
const char FRONTGROUND1_IMAGE[] = "pictures\\Background\\frontground1.png";
const char CYRAXQ_IMAGE[] = "pictures\\Bullets\\CyraxQ.png";

const char KEN_IMAGE[] = "pictures\\playerTest.png";


// key mappings

// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY      = VK_ESCAPE;       // escape key
const UCHAR ALT_KEY      = VK_MENU;         // Alt key
const UCHAR ENTER_KEY    = VK_RETURN;       // Enter key


// Controls
//Player 1
const UCHAR P1RIGHT_KEY = 0x44;
const UCHAR P1LEFT_KEY = 0x41;
const UCHAR P1DROP_KEY = 0x53;
const UCHAR P1JUMP_KEY = 0x57;
const UCHAR P1SKILL1_KEY = 0x54;
const UCHAR P1SKILL2_KEY = 0x59;
const UCHAR P1SKILL3_KEY = 0x55;

//Player 2
const UCHAR P2RIGHT_KEY = VK_RIGHT;
const UCHAR P2LEFT_KEY = VK_LEFT;
const UCHAR P2DROP_KEY = VK_DOWN;
const UCHAR P2JUMP_KEY = VK_UP;
const UCHAR P2SKILL1_KEY = VK_OEM_COMMA;
const UCHAR P2SKILL2_KEY = VK_OEM_PERIOD;
const UCHAR P2SKILL3_KEY = VK_OEM_2;



// weapon types

#endif

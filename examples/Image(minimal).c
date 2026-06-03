//This is an early look at the programming language (subject of change)
//here it is an example of the image loading scheme
#include "bios.h"   // the api file istelf

void game_entry(const bios_api_t* api)
{
    int image = api->asset_load_self("test.eimg");  //assume the image is in the game's folder,

    api->gfx_clear(bios_rgb565(0, 0, 0));  //white backround to check if the parser mistakenly reads only zeros(blacks)
    api->gfx_draw_image(0, 0, image);   //draws the image starting from 0 0, basically as much in the top left corner as possible
    api->gfx_present(); //show our beauty on the screen

    api->sleep_ms(2000);    //after game_entry ends, the game also ends. this lets us see the image before the game closes
}
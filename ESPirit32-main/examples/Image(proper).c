//This is an early look at the programming language (subject of change)
//here it is an example of the image loading scheme
#include "bios.h"   // the api file istelf

void game_entry(const bios_api_t* api)  //where the bios jumps into(not the traditional .elf loading scheme)
{
    int w = 0, h = 0;  //display sizes, this is from the template file you will also get
    if (api->gfx_size(&w, &h) != 0 || w <= 0 || h <= 0) {
        api->print("gfx_size failed (display not ready?)");
        return;
    }

    api->print("game started"); //whatever

    int image = api->asset_load_self("test.eimg");  //assume the image is in the game's folder,
    if (image < 0) {
        api->print("Failed to load image"); //if something went wrong
        return;
    }

    api->gfx_clear(bios_rgb565(255, 255, 255));  //white backround to check if the parser mistakenly reads only zeros(blacks)
    api->gfx_draw_image(0, 0, image);   //draws the image starting from 0 0, basically as much in the top left corner as possible
    api->gfx_present(); //show our beauty on the screen
    api->print("image drawn");  //why i keep debug lines in the public repo


    api->sleep_ms(2000);
        

}

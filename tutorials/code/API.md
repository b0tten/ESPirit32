(also is present in a [smaller version](API%20(smaller%20version).txt))
* A complete guide on the BIOS's API



    * Logging / Timing:
        * print()
            * Accepts text in brackets("), that is later outputted as a new line in the output console, that can be viewed if you use "idf.py monitor" in ESP-IDF terminal.

        * print_int()
            * Same as previous, but only accepts and prints integer values.

        * sleep_ms()
            * Accepts integer values, waits / stops the current process for the specified time, measured in milliseconds.

        * ticks_ms()
            * Returns the amount of time passed since your program started, 
            * think of it as a stopwatch: once your program starts, you can check how much time passed since then.
            * Measured in milliseconds

    * Graphics:
        * bios_rgb565(r, g, b)
            * This command translates standard RGB values into the color pallete / scheme of the screen, think of it as a translator, but for the colors: Your program tells normal values, it translates it to a language the screen can understand.
            * Essential for all the graphics commands.
            * Example usage:
            ```
            gfx_pixel(0, 0, bios_rgb565(255,255,255))
            ```

        * gfx_present()
            * Your program draws an image in a buffer, this command submits it to the screen
            * Think of it as a canvas, you first draw, then show everyone.

        * gfx_size()
            * Returns the display size, first the width, then the height, measured in pixels.
            * BIOS has no way of asking the screen its size, it reads it from the config file.

        * gfx_clear(rgb565)
            * Fills the entire screen with a solid color.
            * Accepts only rgb565 values, use 'bios_rgb565(r, g, b)' to translate from normal RGB values.

        * gfx_fill_rect(x, y, w, h, rgb565)
            * Draws a rectangle on specified X and Y coordinates(top-left origin), with a specified width(W) and height(H)
            * Accepts only rgb565 values, use 'bios_rgb565(r, g, b)' to translate from normal RGB values.

        * gfx_pixel(x, y, rgb565)
            * Draws a singular pixel on specified X and Y coordinates.
            * Accepts only rgb565 values, use 'bios_rgb565(r, g, b)' to translate from normal RGB values.

        * gfx_backlight(int)
            * Sets the screens backlight / brightness to a spicified amount.
            * Only integer values are accepted, from 0 to 100.

        * gfx_draw_text(x, y, rgb565)
            * Draws text on the screen, starting from a scpecified X and Y coordinate(top-left origin), with a specified color,
            * Accepts only rgb565 values, use 'bios_rgb565(r, g, b)' to translate from normal RGB values.
            * Only accepts English, for current state of the project will make everything caps-locked.
            * Accepts a little of special symbols, if it can't draw something, will draw a question mark.

        * gfx_draw_text_scaled(x, y, rgb565, scale)
            * Same as previous, but this command can scale text up by a whole(integer) amount.
            * Accepts integer values in the 'scale' argument, from 1 to 5.
            * Text is scaled exactly by that 'scale' times, scale 2 is 2 times larger than scale 1.

        * gfx_text_width(text)
            * Returns the text width of the specified text, measured in pixels.
            * Accepts string values (you write that in brackets (") ),
            * Example: gfx_text_width("Hello world!") will return '60' as an integer value.

        * gfx_text_height(text)
            * Same as previous, but returns height of the text.
            * (Note: height always equals 7, because of each character being 5x7 pixels big)

        * gfx_draw_image(x, y, asset_id)
            * Draws an image from a specified X and Y coordinate(top-left origin),
            * from an asset id you got when loading that image.
            * You first need to GET THE ID, then draw it.
    
    * Game management:
        * select_game(name)
            * Starts a game from "`sd/GAMES/<this_app_name>/`" folder, you can pass `MYGAME` or `MYGAME.ELF` (case-insensitive).
            * If it succeds, your current program will be closed and the new one will be opened instead

        * Exiting
            * To exit from your current program/game back to menu, your program should use the "return" command.
            * This is not a part of the API, it's how the game loader works

    * Filesystem:
        * read_self(path, buffer, size)
            * Reads from "`sd/GAMES/<this_app_name>/...`".
            * Path is the relative path from that starting folder,
            * Buffer is the place to where the data will go,
            * Size is the size of that data container, if the element has more lines than the size argument, only the first lines until that size limit will be returned
            * The entire command returns 0 and the data that was read, if everything ok,
            * Or if not ok, returns an error code.
            * 
            * In that buffer, new lines of that file are appended at the end
            * Line 1 will be at position 0 in that array
            * line 2 will be at position 1, and so on.
            * 
            * Example:
        
           ```
           char tmp[64];
           tmp[0] = 0;
           int check = api->read_data(file.txt, tmp, sizeof(tmp));
           if (check == 0) api->print("ok");
           ```
        
        * read_data(path, buffer, size)
            * Same as previous, but reads from "`sd/ASSETS/<this_app_name>/...`"
            * That means:
            * The relative path's starting point changes to "`sd/ASSETS/<this_app_name>/...`".
        
        * list_self(dir, buffer, size)
            * Same as previous ones, but
            * Lists files from "`sd/GAMES/<this_app_name>/...`".
            * You should you this to list elements in a folder
            * Instead of lines of document in the array/buffer you want to store in, different files will be stored.
            * Eaxample of that:
            * 
            * In a folder containing "document1.txt" and "document2.txt", you  will get this is the array:
            * Pos 0: document1.txt
            * Pos 1: document1.txt
        
        * list_data(dir, buffer, size)
            * Same as previous one, but
            * Lists files from "`sd/ASSETS/<this_app_name>/...`".

    * Assets (images):

        * asset_load_self(path)
            * Loads an .eimg image from "`sd/GAMES/<this_app_name>/...`".
            * Path is a relative path starting from the game's directory (mentioned higher).
            * Returns an asset(image) id, that can be used to interact with that asset (display that image).
            * Example:

            ```
            int image = asset_load_self(image.eimg);
            gfx_draw_image(image);
            ```

        * asset_load_data(path)
            * Same as previous, but
            * The starting point for that relative path changes to "`sd/ASSETS/<this_app_name>/...`".
            * That means
            * Loads images from "`sd/ASSETS/<this_app_name>/...`".
        
        * asset_uload(assed_id)
            * Unloads a previously loaded asset from memory.
            * You only have 2MB of RAM for assets, they weigh there the same as on the SD card.
            * Unload assets to have memory for the new ones.

        * asset_defragment()
            * Rebuilds currently loaded assets, repacks the asset pool while keeping the same asset IDs
            * Defragments the asset pool.
            * Returns a negative integer if an error has occured
            * 
            * Should only be done when no assets are currently waiting to be drawn,
            * When not to call (when it will fail):
                * `gfx_draw_image()` done, before it was presented via `gfx_present()`

                ```
                gfx_draw_image();
                ```
            * When you can call:
                * After the image was presented

                ```
                gfx_draw_image();
                gfx_present();
                ```
                * Note: if it still fails, try clearing your canvas with `gfx_clear()`
    
    * Inputs (buttons):

        * button_pressed(name)
            * Returns true if the passed button is pressed(active)
            * Name is the name for the button, not the GPIO pin.
            * Names come from the `config.txt` file.
            * All device must have the default navigation buttons, being:
                * `btn_up`
                * `btn_down`
                * `btn_left`
                * `btn_right`
                * `btn_select`
                * `btn_back`

    * Other (Use at your own risk):

        * install_game(name)
            * Similar to `select_game()`, but
            * Installs the selected game to an internal OTA slot.
            * Only one game at atime can be loaded in that storage, previous one will be deleted
            * Installed game can not be launched with `select_game()` command.
            * Installed game does not need an SD card in order to load itself
            * Note: theese commands were not tested, so they might be broken.
        
        * start_installed_game()
            * Starts an installed game form an OTA storage slot, from the `install_game()` command
            * Note: theese commands were not tested, so they might be broken.

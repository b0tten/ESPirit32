/**
 * @file bios_api.h
 * @brief A complete guide on the BIOS's API.
 */

 #ifndef BIOS_API_H
 #define BIOS_API_H
 
 #include <stdint.h>
 
 /* =========================================================================
  * Logging / Timing
  * ========================================================================= */
 
 /**
  * @defgroup logging Logging / Timing
  * @{
  */
 
 /**
  * @brief Accepts text in brackets("), that is later outputted as a new line
  *        in the output console, that can be viewed if you use "idf.py monitor"
  *        in ESP-IDF terminal.
  *
  * @param text  The text to print.
  */
 void print(const char *text);
 
 /**
  * @brief Same as print(), but only accepts and prints integer values.
  *
  * @param value  The integer to print.
  */
 void print_int(int value);
 
 /**
  * @brief Accepts integer values, waits / stops the current process for the
  *        specified time, measured in milliseconds.
  *
  * @param ms  Time to wait in milliseconds.
  */
 void sleep_ms(int ms);
 
 /**
  * @brief Returns the amount of time passed since your program started.
  *
  * Think of it as a stopwatch: once your program starts, you can check how
  * much time passed since then. Measured in milliseconds.
  *
  * @return  Elapsed time in milliseconds.
  */
 int ticks_ms(void);
 
 /** @} */
 
 /* =========================================================================
  * Graphics
  * ========================================================================= */
 
 /**
  * @defgroup graphics Graphics
  * @{
  */
 
 /**
  * @brief Translates standard RGB values into the color palette / scheme of
  *        the screen.
  *
  * Think of it as a translator, but for the colors: your program tells normal
  * values, it translates it to a language the screen can understand.
  * Essential for all the graphics commands.
  *
  * @param r  Red value.
  * @param g  Green value.
  * @param b  Blue value.
  * @return   Color in RGB565 format.
  *
  * @code
  * gfx_pixel(0, 0, bios_rgb565(255, 255, 255));
  * @endcode
  */
 uint16_t bios_rgb565(int r, int g, int b);
 
 /**
  * @brief Your program draws an image in a buffer, this command submits it
  *        to the screen.
  *
  * Think of it as a canvas, you first draw, then show everyone.
  */
 void gfx_present(void);
 
 /**
  * @brief Returns the display size, first the width, then the height,
  *        measured in pixels.
  *
  * BIOS has no way of asking the screen its size, it reads it from the
  * config file.
  *
  * @param[out] width   Display width in pixels.
  * @param[out] height  Display height in pixels.
  */
 void gfx_size(int *width, int *height);
 
 /**
  * @brief Fills the entire screen with a solid color.
  *
  * Accepts only rgb565 values, use bios_rgb565(r, g, b) to translate from
  * normal RGB values.
  *
  * @param rgb565  Fill color in RGB565 format.
  */
 void gfx_clear(uint16_t rgb565);
 
 /**
  * @brief Draws a rectangle on specified X and Y coordinates (top-left origin),
  *        with a specified width (W) and height (H).
  *
  * Accepts only rgb565 values, use bios_rgb565(r, g, b) to translate from
  * normal RGB values.
  *
  * @param x       X coordinate (top-left origin).
  * @param y       Y coordinate (top-left origin).
  * @param w       Width in pixels.
  * @param h       Height in pixels.
  * @param rgb565  Fill color in RGB565 format.
  */
 void gfx_fill_rect(int x, int y, int w, int h, uint16_t rgb565);
 
 /**
  * @brief Draws a singular pixel on specified X and Y coordinates.
  *
  * Accepts only rgb565 values, use bios_rgb565(r, g, b) to translate from
  * normal RGB values.
  *
  * @param x       X coordinate.
  * @param y       Y coordinate.
  * @param rgb565  Pixel color in RGB565 format.
  */
 void gfx_pixel(int x, int y, uint16_t rgb565);
 
 /**
  * @brief Sets the screen's backlight / brightness to a specified amount.
  *
  * Only integer values are accepted, from 0 to 100.
  *
  * @param level  Brightness level (0–100).
  */
 void gfx_backlight(int level);
 
 /**
  * @brief Draws text on the screen, starting from a specified X and Y
  *        coordinate (top-left origin), with a specified color.
  *
  * Accepts only rgb565 values, use bios_rgb565(r, g, b) to translate from
  * normal RGB values. Only accepts English; for current state of the project
  * will make everything caps-locked. Accepts a little of special symbols;
  * if it can't draw something, will draw a question mark.
  *
  * @param x       X coordinate (top-left origin).
  * @param y       Y coordinate (top-left origin).
  * @param rgb565  Text color in RGB565 format.
  */
 void gfx_draw_text(int x, int y, uint16_t rgb565);
 
 /**
  * @brief Same as gfx_draw_text(), but this command can scale text up by a
  *        whole (integer) amount.
  *
  * Accepts integer values in the 'scale' argument, from 1 to 5.
  * Text is scaled exactly by that 'scale' times; scale 2 is 2 times larger
  * than scale 1.
  *
  * @param x       X coordinate (top-left origin).
  * @param y       Y coordinate (top-left origin).
  * @param rgb565  Text color in RGB565 format.
  * @param scale   Scale factor (1–5).
  */
 void gfx_draw_text_scaled(int x, int y, uint16_t rgb565, int scale);
 
 /**
  * @brief Returns the text width of the specified text, measured in pixels.
  *
  * Accepts string values (you write that in brackets (") ).
  *
  * @param text  The string to measure.
  * @return      Width in pixels.
  *
  * @code
  * gfx_text_width("Hello world!"); // returns 60
  * @endcode
  */
 int gfx_text_width(const char *text);
 
 /**
  * @brief Same as gfx_text_width(), but returns height of the text.
  *
  * @note Height always equals 7, because of each character being 5x7 pixels big.
  *
  * @param text  The string to measure.
  * @return      Height in pixels (always 7).
  */
 int gfx_text_height(const char *text);
 
 /**
  * @brief Draws an image from a specified X and Y coordinate (top-left origin),
  *        from an asset id you got when loading that image.
  *
  * You first need to GET THE ID, then draw it.
  *
  * @param x         X coordinate (top-left origin).
  * @param y         Y coordinate (top-left origin).
  * @param asset_id  Asset ID returned by asset_load_self() or asset_load_data().
  *
  * @code
  * int image = asset_load_self("image.eimg");
  * gfx_draw_image(0, 0, image);
  * @endcode
  */
 void gfx_draw_image(int x, int y, int asset_id);
 
 /** @} */
 
 /* =========================================================================
  * Game Management
  * ========================================================================= */
 
 /**
  * @defgroup game_management Game Management
  * @{
  */
 
 /**
  * @brief Starts a game from "sd/GAMES/<this_app_name>/" folder.
  *
  * You can pass MYGAME or MYGAME.ELF (case-insensitive).
  * If it succeeds, your current program will be closed and the new one
  * will be opened instead.
  *
  * @param name  Game name, e.g. "MYGAME" or "MYGAME.ELF".
  */
 void select_game(const char *name);
 
 /**
  * @defgroup exiting Exiting
  * @ingroup game_management
  *
  * To exit from your current program/game back to menu, your program's game
  * entry should end. Your game runs in a `void game_entry()` thing:
  *
  * @code
  * void game_entry(const bios_api_t *api) { <your code> }
  * @endcode
  *
  * Once it ends, the game will tell the bios that it is done, which means
  * the menu will be opened back again.
  */
 
 /** @} */
 
 /* =========================================================================
  * Filesystem
  * ========================================================================= */
 
 /**
  * @defgroup filesystem Filesystem
  * @{
  */
 
 /**
  * @brief Reads from "sd/GAMES/<this_app_name>/...".
  *
  * Path is the relative path from that starting folder.
  * Buffer is the place to where the data will go.
  * Size is the size of that data container; if the element has more lines
  * than the size argument, only the first lines until that size limit will
  * be returned. The entire command returns 0 and the data that was read if
  * everything is ok, or if not ok, returns an error code.
  *
  * In that buffer, new lines of that file are appended at the end:
  * line 1 will be at position 0 in that array, line 2 will be at position 1,
  * and so on.
  *
  * @param path    Relative path from the game's starting folder.
  * @param buffer  Buffer where the data will go.
  * @param size    Size of that data container.
  * @return        0 and the data read if ok, error code otherwise.
  *
  * @code
  * char tmp[64];
  * tmp[0] = 0;
  * int check = api->read_self("file.txt", tmp, sizeof(tmp));
  * if (check == 0) api->print("ok");
  * @endcode
  */
 int read_self(const char *path, char *buffer, int size);
 
 /**
  * @brief Same as read_self(), but reads from "sd/ASSETS/<this_app_name>/...".
  *
  * That means the relative path's starting point changes to
  * "sd/ASSETS/<this_app_name>/...".
  *
  * @param path    Relative path from the assets starting folder.
  * @param buffer  Buffer where the data will go.
  * @param size    Size of that data container.
  * @return        0 and the data read if ok, error code otherwise.
  */
 int read_data(const char *path, char *buffer, int size);
 
 /**
  * @brief Same as read_self() / read_data(), but lists files from
  *        "sd/GAMES/<this_app_name>/...".
  *
  * You should use this to list elements in a folder. Instead of lines of a
  * document in the array/buffer you want to store in, different files will
  * be stored.
  *
  * In a folder containing "document1.txt" and "document2.txt":
  * - Pos 0: document1.txt
  * - Pos 1: document2.txt
  *
  * @param dir     Relative directory path.
  * @param buffer  Buffer where filenames will go.
  * @param size    Size of that data container.
  * @return        0 on success, error code otherwise.
  */
 int list_self(const char *dir, char *buffer, int size);
 
 /**
  * @brief Same as list_self(), but lists files from
  *        "sd/ASSETS/<this_app_name>/...".
  *
  * @param dir     Relative directory path.
  * @param buffer  Buffer where filenames will go.
  * @param size    Size of that data container.
  * @return        0 on success, error code otherwise.
  */
 int list_data(const char *dir, char *buffer, int size);
 
 /** @} */
 
 /* =========================================================================
  * Assets (Images)
  * ========================================================================= */
 
 /**
  * @defgroup assets Assets (Images)
  * @{
  */
 
 /**
  * @brief Loads an .eimg image from "sd/GAMES/<this_app_name>/...".
  *
  * Path is a relative path starting from the game's directory.
  * Returns an asset (image) id that can be used to interact with that asset
  * (display that image).
  *
  * @param path  Relative path to the .eimg file.
  * @return      Asset ID, used to interact with / display that image.
  *
  * @code
  * int image = asset_load_self("image.eimg");
  * gfx_draw_image(0, 0, image);
  * @endcode
  */
 int asset_load_self(const char *path);
 
 /**
  * @brief Same as asset_load_self(), but the starting point for that relative
  *        path changes to "sd/ASSETS/<this_app_name>/...".
  *
  * That means it loads images from "sd/ASSETS/<this_app_name>/...".
  *
  * @param path  Relative path to the .eimg file.
  * @return      Asset ID, used to interact with / display that image.
  */
 int asset_load_data(const char *path);
 
 /**
  * @brief Unloads a previously loaded asset from memory.
  *
  * You only have 2MB of RAM for assets; they weigh there the same as on the
  * SD card. Unload assets to have memory for the new ones.
  *
  * @param asset_id  The asset ID returned by asset_load_self() or asset_load_data().
  */
 void asset_uload(int asset_id);
 
 /**
  * @brief Rebuilds currently loaded assets, repacks the asset pool while
  *        keeping the same asset IDs. Defragments the asset pool.
  *
  * Returns a negative integer if an error has occurred.
  *
  * Should only be done when no assets are currently waiting to be drawn.
  *
  * @warning When NOT to call (when it will fail): after gfx_draw_image() has
  *          been called, but before gfx_present() is called.
  * @code
  * gfx_draw_image(...); // draw done
  * // asset_defragment() here will FAIL
  * @endcode
  *
  * When you CAN call — after the image was presented:
  * @code
  * gfx_draw_image(...);
  * gfx_present();
  * // asset_defragment() is safe here
  * @endcode
  * @note If it still fails, try clearing your canvas with gfx_clear().
  *
  * @return  0 on success, negative integer on error.
  */
 int asset_defragment(void);
 
 /** @} */
 
 /* =========================================================================
  * Input (Buttons)
  * ========================================================================= */
 
 /**
  * @defgroup input Input (Buttons)
  * @{
  */
 
 /**
  * @brief Returns true if the passed button is pressed (active).
  *
  * Name is the name for the button, not the GPIO pin. Names come from the
  * config.txt file. All devices must have the default navigation buttons:
  * - btn_up
  * - btn_down
  * - btn_left
  * - btn_right
  * - btn_select
  * - btn_back
  *
  * @param name  Button name (e.g. "btn_up").
  * @return      true if the button is pressed, false otherwise.
  */
 int button_pressed(const char *name);
 
 /** @} */
 
 /* =========================================================================
  * Other (Use at your own risk)
  * ========================================================================= */
 
 /**
  * @defgroup experimental Other (Use at your own risk)
  * @{
  */
 
 /**
  * @brief Similar to select_game(), but installs the selected game to an
  *        internal OTA slot.
  *
  * Only one game at a time can be loaded in that storage; the previous one
  * will be deleted. Installed game cannot be launched with select_game().
  * Installed game does not need an SD card in order to load itself.
  *
  * @param name  Game name to install.
  *
  * @note These commands were not tested, so they might be broken.
  */
 void install_game(const char *name);
 
 /**
  * @brief Starts an installed game from an OTA storage slot, from the
  *        install_game() command.
  *
  * @note These commands were not tested, so they might be broken.
  */
 void start_installed_game(void);
 
 /** @} */
 
 #endif /* BIOS_API_H */
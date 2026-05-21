# **ESPirit32: Breathe life into your hardware.**

*Code less, create more.*

*Fast. Stable. **Yours**.*

## Overview
- **ESPirit32** is an Operating System that prioritises stability and predictability over extra speed, why have a 60hz screen if the app crashes constantly?

- Instead of writing complex system code, you just write your game. ESPirit32 handles the "scary stuff" - the SD card, the screen drivers, and the memory management, leaving you free to focus on the fun.

### **Why ESPirit32?**
- Designed for High Availability: Utilizing Dual cores, yor game gest the whole core, while the system transfers to the second one to make you get the most performance out of you chip.
- Massive Playground: 2MB of PSRAM to satisfy your assets, allowing you to load high-resolution images that other handhelds can't handle.
- Simple API: No more fighting with SPI registers. Load an asset, draw an image, check a button - all in a couple lines of code.

## Under the Hood
If you’re a developer who likes to know how the gears turn, here is why ESPirit32 is different from your average .ELF loader:
- Dual-Core Implementation: It uses second core to utlize inputs and crash satbility: Games run on core 0, while core 1 tracks inputs and recovers the system from most crashes.
- DMA-Backed Graphics: Graphics use dual buffer system, while your app draws in buffer one, second buffer already sent the image to the screen via DMA.
- Resource Handle Architecture: Games don't touch raw hardware, while it is a security feature, it also makes games transferrable between different configurations of devices.
- ELF Loader: Dynamically load compiled games directly from an SD card. No need to re-flash the chip to change the game.

## License
The BIOS is licensed under the GNU General Public License v3.0 (GPLv3).
See [LICENSE](LICENSE) for the full text.

### Special Exception
Applications and games using the BIOS through its public API
are not considered derivative works and may be licensed independently.


## Disclaimer
The authors provide this BIOS and examples "as-is".
We do not manufacture, endorse, or support any devices.
Any device or application built with this BIOS is the responsibility of its creator.



(Partially made with ai, see [AI excuse](AI%20excuse.md))

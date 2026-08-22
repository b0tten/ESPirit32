# **ESPirit32: It just works.**

* **Code less, create more.**
* **Fast. Stable. Predictable.**



## Overview
**ESPirit32** is a bare-metal operating system for ESP32 handhelds that prioritizes low-level stability, predictability, and developer quality of life.



## Why ESPirit32?
* **Real OS, Not a Menu:** Stop re-writing display drivers for every project. ESPirit32 handles hardware abstraction so you can focus entirely on game logic.
* **True Portability:** Apps are built for the platform, not the pinout. Write your code once, run it across supported configurations without modifying pin definitions.
* **Workflow > Overclock:** Designed to optimize developer time without sacrificing raw performance.
* **Sandboxed & Stable:** So-called hardware "limitation" was turned into a stability powerhouse.



## The Vision
* **Bridge the Gap:** Arduino is approachable but fragile; raw ESP-IDF is powerful but steep. ESPirit32 combines the simplicity of high-level sandboxing with raw embedded performance.
* **The "Dark Side" is Handled:** We deal with SPI DMA pipelines, display transaction batching, PSRAM memory defragmentation, and hardware RNG so you don't have to.
* **Build it. Run it. It just works.**



## Technical Highlights
* **High-Speed Display Engine:** Customized pipeline capable of sub-20ms frame flushes* over a shared SPI bus, saturating the display bus at maximum wire speed.
* **Console Focus:** Designed primarily for display-based applications and games. *(Support for general purpose GPIO hardware controls like external motors/LEDs will arrive in future updates).*



## Compatibility & Status
> **ALPHA NOTICE:** ESPirit32 aims to run the exact same binary across a broad range of hardware. Currently in **ALPHA**, supported board configurations are limited. 
> 
> Check out [tutorials/hardware](tutorials/hardware) for more information.



## License
The ESPirit32 BIOS is licensed under the **GNU General Public License v3.0 (GPLv3)**. See [LICENSE](LICENSE) for details.

### Special Exception
Applications, games, and libraries linking to the BIOS strictly via its public API (`bios_api_t`) are **not** considered derivative works and may be licensed independently under any license (open or proprietary).



## Disclaimers
*50 FPS (20ms frame flush) is fully possible and achievable, however it is not the default and is *not* the recommended display bus speed mode.

Provided "as-is" without warranty. The maintainers do not manufacture or officially endorse specific hardware devices.

*(Partially written with AI assistance - see [AI_excuse.md](AI%20excuse.md))*

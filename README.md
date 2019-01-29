# JABNES (Just Another Basic Nintendo Emulation Software)
Jabnes is written by BEN1JEN in C++ and is currently under active development (as of febuary 2019.) This markdown file hopefully contains all the information you'll need to do whatever you want to do with this project.

## Screendump info:
```
+------------------+ JABNES p0.0.2:
| J  A  B  N  E  S | - Creator: BEN1JEN
| u  n  a  i  m  o | - Licence: GPL 3.0
| s  o  s  n  u  f | - Ganra: Emulator
| t  t  i  t  l  t | - - System: NES
|    h  c  e  a  w | - - Supported ROMs: none
|    e     n  t  a | - - Emulated: CPU (no unofficial opcodes)
|    r     d  i  r | - Build Type: pre-alpha
|          o  o  e | - Platforms: Linux
|             n    | - Git Repo: https://gitlab.101100.ca/ben1jen/jabnes
+------------------+ - \/Info:\/
JABNES is an NES emulator for linux written in C++ with no set goals in mind.
It is unlikly to ever suppert any actual ROMs, but is in constant development.
NOTE: this project does not have base features (thus the p before the version.)
```

## links:
### My social stuff:
* [Me on gitlab](https://gitlab.101100.ca/ben1jen)
* [Me on github](https://github.com/ben1jen)
* [Me on twitter](https://twitter.com/BEN1JEN)
* [Repository main page](https://gitlab.101100.ca/ben1jen/jabnes)
### This markdown file
* [Screendump / Information](#screendump-info)
* [Details](#details)
* [Repository links](#github-and-gitlab)
* [Building](#building)
* * [On Linux](#linux)
* * [On Windows](#windows)
* * [On MacOS](#macos)
* [Running](#running)
* * [Changing the ROM](#loaded-rom)
* * [Changing the colour pallet](#colour-pallet)
### Footer
* [Licence (GPL3.0)](/blob/master/LICENCE.txt)
* [Disclaimer](#disclaimer)

## Details:
This is an NES emulator written by BEN1JEN with the help of 101100, strictly for the purpose of having the experience of writing one. As a result the project does not have any goal of doing something another emulator hasn't already done, but I do still want to make this somewhat usable. In the future I may add a goal, I'm currently considering adding a giant set of tools built in, making it ideal for homebrew development (which is why I'm using gtkmm/cairo.) However currently I still need to make it render anything useful at all.

If you do feel like making a pull request, I'll definitely look into it as soon as possible. But I might turn it down, or add it as a second mode if it adds a major feature to the emulator that I was wanting to build myself. Like I said before this project (for now) is still primarily for me to learn about the NES and C++.

Enjoy :)

## Github, Gitlab and bitbucket:
I'm planning on having a mirror of this on Github (and the same applies for Bitbucket), but origin/my primary server will still be on my Gitlab instance. hosted at [gitlab.101100.ca](https://gitlab.101100.ca/ben1jen).
If I do put a mirror up anywhere else it'll be here in this list:
* [Local Gitlab](https://gitlab.101100.ca/ben1jen/jabnes)

## Building:

Building is fairly simple and currently works on Linux.
### Instructons:
* [Linux](#linux)
* [Windows](#windows)
* [MacOS](#macos)

### Linux:
To build make sure you have Gtkmm, then just type make!

How to get Gtkmm on Linux with the following distros:
#### Ubuntu:

### Windows:
Coming soon...

### MacOS:
Coming soon...

## Running:
To run there are no command line args, and the program begins emulation of the ROM at startup. So to change any parameters you have to modify the source (instructions are below.)

### How to configure:
#### Loaded ROM:
 
1. Open loop.cpp
2. Look for the `JabnesCanvas::JabnesCanvas() {}` function at the top of the file
3. Go past the screendump
4. Look for this line: `current_state.load_rom("default_rom.nes");` where default_rom.nes is whatever I currently have it set to
5. Then Change default_rom.nes to your ROM file (NOTE: your ROM has to be in the same directory as the jabnes executible, or you have to use a relative path, but it does not need to be present at build time.)

The rom file is expected to be a [standard ines ROM file](https://wiki.nesdev.com/w/index.php/INES).
Currently no mappers (chips on the ROM board) are supported.

#### Colour pallet:
1. Open loop.cpp
2. Look for the `JabnesCanvas::JabnesCanvas() {}` function at the top of the file
3. Go past the screendump
4. Look for this line: `nes_ppu.load_pal(this->palette, "default_pallet.pal", false);` where default_pallet.pal is whatever I currently have it set to
5. Then Change default_pallet.pal to your pallet file (NOTE: your pallet has to be in the same directory as the jabnes executible, or you have to use a reletive path, but it does not need to be present at build time.)

The pallet has to be a [standard VGA pallet file](https://wiki.nesdev.com/w/index.php/.pal), with no header, and 64 three-byte colours.


# Disclaimer
This software is 100% free with no promises attached of any kind, and I reserve the write to delete this project, rename it, change the licence for future commits, or even halt development at any time with no warning. Even this disclaimer may change in a future commit. With that said the GPL3.0 licence still applies in every case, this disclaimer is not any sort of legal thingy, just a warning.
Currently I would not recommend actually using this software, unless you are trying to learn how to build your own NES emulator.

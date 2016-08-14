# wut
Let's try make a Wii U Toolchain / SDK for creating rpx/rpl.

Licensed under the terms of the GNU General Public License, version 2 or later (GPLv2+).

Doxygen output can be found at https://decaf-emu.github.io/wut

## Requirements
- devkitPRO + devkitPPC
- Tested on Linux, OS X and cygwin on Windows

## Usage
- git clone --recursive https://github.com/decaf-emu/wut.git
- cd wut
- export devkitPRO=...
- export devkitPPC=...
- export WUT_ROOT=$PWD
- make install
- cd samples/helloworld
- make

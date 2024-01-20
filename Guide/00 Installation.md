# Installation
### Dependencies
In order to use DogeLib, you must first install it's dependencies. The list of
dependencies is as follows -
* [SDL2](https://www.libsdl.org/)
* [SDL2_ttf](https://github.com/libsdl-org/SDL_ttf)
* [SDL2-image](https://github.com/libsdl-org/SDL_image)
* [SDL2-gfx](https://www.ferzkopp.net/wordpress/2016/01/02/sdl_gfx-sdl2_gfx/)
* [SDL2-net](https://github.com/libsdl-org/SDL_net)

To install these on Debian (and on most Debian based distros), paste:
```sh
sudo apt install libsdl2-2.0-0 libsdl2-dev libsdl2-gfx-1.0-0 libsdl2-gfx-dev libsdl2-ttf-2.0-0 libsdl2-dev libsdl2-image-2.0-0 libsdl2-image-dev libsdl2-net-2.0-0 libsdl2-net-dev
```
in your terminal.

If you are not on a Debian based distro, there should be installation
instructions for each dependency on their respective websites.

## Installing DogeLib
In your terminal, navigate to wherever you would like to download DogeLib:
```sh
cd Dev
```
Next we create an example project directory and navigate into it.
```sh
mkdir DogeLibExample
cd DogeLibExample
```
Next clone the repo (I use git in this example, however you can also download
DogeLib as a zip file from the github and extract it wherever you like):
```sh
git clone git@github.com:DogeSSBM/DogeLib.git .
```
The contents of the directory should be as follows:
```sh
ls

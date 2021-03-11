#pragma once

struct{
	u8 key[SDL_NUM_SCANCODES];
	u8 prev[SDL_NUM_SCANCODES];
}keys = {0};

bool keyState(const SDL_Scancode key)
{
	return keys.key[key];
}

bool keyPressed(const SDL_Scancode key)
{
	return keys.key[key] && !keys.prev[key];
}

bool keyHeld(const SDL_Scancode key)
{
	return keys.key[key] && keys.prev[key];
}

bool keyReleased(const SDL_Scancode key)
{
	return !keys.key[key] && keys.prev[key];
}

#define MOUSE_L		SDL_BUTTON_LEFT
#define MOUSE_M		SDL_BUTTON_MIDDLE
#define MOUSE_R		SDL_BUTTON_RIGHT
#define MOUSE_F		SDL_BUTTON_X1
#define MOUSE_B		SDL_BUTTON_X2

#define MW_U		1u
#define MW_R		(1u<<1)
#define MW_D		(1u<<2)
#define MW_L		(1u<<3)

struct{
	Offset vec;
	Coord pos;
	u32 state;
	u32 wheel;
	struct{
		Offset vec;
		Coord pos;
		u32 state;
		u32 wheel;
	}prev;
}mouse = {0};

bool mouseBtnPressed(const u32 mouseBtn)
{
	return mouse.state&mouseBtn && !(mouse.prev.state&mouseBtn);
}

bool mouseBtnState(const u32 mouseBtn)
{
	return mouse.state&mouseBtn;
}

bool mouseBtnHeld(const u32 mouseBtn)
{
	return mouse.state&mouseBtn && mouse.prev.state&mouseBtn;
}

bool mouseBtnReleased(const u32 mouseBtn)
{
	return !(mouse.state&mouseBtn) && mouse.prev.state&mouseBtn;
}

bool mouseScrolled(const u32 mouseWheel)
{
	return mouse.wheel & mouseWheel;
}

#pragma once

struct{
	Offset vec;
	Coord pos;
	u32 state;
	struct{
		Coord pos;
		u32 state;
	}prev;
}mouse = {0};

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

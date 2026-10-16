#ifndef DOGELIB_DECLS_H
#define DOGELIB_DECLS_H

// Panic.h --------------------------------------------------------------------
// helper function for panic macro
void panicHelper(const char *func, const char *file, const int line, const char * format, ...);
// helper function for notNull macro
void notNullHelper(const char *func, const char *file, const int line, void *ptr);
// helper function for assertExprHelper macro
void assertExprHelper(const char *func, const char *file, const int line, const bool val, const char *expr);
// helper function for assertLogExprHelper macro
void assertLogExprHelper(const char *func, const char *file, const int line, const bool val, const char *expr);
// helper function for logMsgHelper macro
void logMsgHelper(const char *func, const char *file, const int line, const char * format, const char *exprs,...);
// helper function for logExprHelper macro
void logExprHelper(const char * format, const char *exprs,...);
// helper function for assertExprMsgHelper macro
void assertExprMsgHelper(const char *func, const char *file, const int line, const bool val, const char *expr, const char *format, ...);
// helper function for assertLogExprMsgHelper macro
void assertLogExprMsgHelper(const char *func, const char *file, const int line, const bool val, const char *expr, const char *format, ...);

// Types.h --------------------------------------------------------------------
// returns a Coord with positions x and y
Coord iC(const int x, const int y);
// returns a Coord with x and y both equal to i
Coord iiC(const int i);
// returns a rect at position x, y and length xlen, ylen
Rect iR(const int x, const int y, const int xlen, const int ylen);
// returns the corner position of rect
Coord irC(const Rect rect);
// returns the length of rect
Length irL(const Rect rect);
// returns a rect at position pos and length len
Rect ccR(const Coord pos, const Length len);
// returns a rect at position pos and length xlen, ylen
Rect ciR(const Coord pos, const int xlen, const int ylen);
// returns a square rect at position pos and length len
Rect ciiS(const Coord pos, const int len);
// returns a square rect at position x, y and length len
Rect iiS(const int x, const int y, const int len);
// returns a float Coord with positions x and y
Coordf fC(const float x, const float y);
// returns a Coord with x and y both equal to i
Coordf ffC(const float i);
// returns the max of the ints
int imax(const int a, const int b);
// returns the min of the ints
int imin(const int a, const int b);
// returns the absolute value of i
int iabs(const int i);
// exponentiation function for integers
int ipow(int num, int pow);
// returns the max of the floats
float fmost(const float a, const float b);
// returns the min of the floats
float fleast(const float a, const float b);
// makes n positive
int posSign(const int n);
// makes n negative
int negSign(const int n);
// makes n positive
float posSignf(const float n);
// makes n negative
float negSignf(const float n);
// matches the sign of n to s
int matchSign(const int s, const int n);
// matches the sign of n to s
float matchSignf(const float s, const float n);
// returns true if s and n have the same sign
bool sameSign(const int s, const int n);
// matches the sign of n to the inverse sign of s
int invSign(const int s, const int n);
// matches the sign of n to the inverse sign of s
float invSignf(const float s, const float n);
// returns n with l being its lower bound
int lbound(const int n, const int l);
// returns n with l being its upper bound
int ubound(const int n, const int u);
// returns n with l being its lower bound
float lboundf(const float n, const float l);
// returns n with l being its upper bound
float uboundf(const float n, const float u);

// Coords.h -------------------------------------------------------------------
// rotates d 90deg right
Direction dirROR(const Direction d);
// rotates d 90deg left
Direction dirROL(const Direction d);
// inverts d (rotates 180deg);
Direction dirINV(const Direction d);
// true if d is left or right
Direction dirLR(const Direction d);
// true if d is up or down
Direction dirUD(const Direction d);
// returns true if a is aligned with the same axis as b
bool dirAXA(const Direction a, const Direction b);
// true if d is a positive direction (right or down);
Direction dirPOS(const Direction d);
// true if d is a negative direction (left or up);
Direction dirNEG(const Direction d);
// returns the minimum component of pos
int coordMin(const Coord pos);
// returns coord comprised of the lesser components of a and b
Coord coordLeast(const Coord a, const Coord b);
// returns the maximum component of pos
int coordMax(const Coord pos);
// returns coord comprised of the greater components of a and b
Coord coordMost(const Coord a, const Coord b);
// returns true if both components of a and b are equal
bool coordSame(const Coord a, const Coord b);
// returns coord with absolute value of both components of pos
Coord coordAbs(const Coord pos);
// clamps n to be within min (inclusive); to max (exclusive);
int clamp(const int n, const int min, const int max);
// true if n within min (inclusive); and max (exclusive);
bool inBound(const int n, const int min, const int max);
// similar to clamp, but wraps values
int wrap(const int n, const int min, const int max);
// Clamps both x and y component of coord to >= 0 and < their respective component in len
Coord coordClampLen(const Coord pos, const Length len);
// Returns true if the x and y component of coord are >= 0 and < their respective component in len
bool coordInLen(const Coord pos, const Length len);
// Returns true if each part of pos1 is less than their counterpart in pos2
bool coordMaxCoord(const Coord a, const Coord b);
// Returns true if each part of a is greater than or equal to their counterpart in b
bool coordMinCoord(const Coord a, const Coord b);
// takes 2 opposite corner coords and returns rect
Rect coordsToRect(const Coord a, const Coord b);
// resizes rect by len
Rect rectResize(const Rect rect, const int len);
// returns true if neither components of pos are 0
bool coordNz(const Coord pos);
// returns true if both components of pos are 0
bool coordEz(const Coord pos);
// multiplies both components of pos by num
Coord coordMuli(const Coord pos, const int num);
// multiplies each component of a and b
Coord CoordMul(const Coord a, const Coord b);
// inverts the sign of both components of pos
Coord coordInv(const Coord pos);
// adds num to both components of pos
Coord coordAddi(const Coord pos, const int num);
// subtracts each component of a from b
Coord coordSub(const Coord a, const Coord b);
// subtracts num from both components of pos
Coord coordSubi(const Coord pos, const int num);
// takes modulus of each component of a by b
Coord coordMod(const Coord a, const Coord b);
// takes modulus of each component of pos by num
Coord coordModi(const Coord pos, const int num);
// takes the midpoint of a and b
Coord coordMid(const Coord a, const Coord b);
// takes the distance squared between a and b
uint coordDistSq(const Coord a, const Coord b);
// divides each component of pos by num
// if num is 0, sets each component to 0
Coord coordDivi(const Coord pos, const int num);
// divides each component of a by b
// if a component of b is 0, sets that component to 0
Coord coordDiv(const Coord a, const Coord b);
// offsets a coord in a direction by a number of units
Coord coordShift(const Coord coord, const Direction dir, const int units);
// adds each component of a to b
Coord coordAdd(const Coord a, const Offset b);
// offsets the pos by 1/2 the length
Coord coordCenter(const Coord pos, const Length len);
// offsets the pos by -1/2 the length
Coord coordUncenter(const Coord pos, const Length len);
// scales and offsets pos
Coord coordOffScale(const Coord pos, const Offset off, const int scale);
// takes pos, gets its position in terms of percentage of oldLen side lengths
// returns a new position offset by the same percentage of newLen's sides
Coord resizeTransform(const Length oldLen, const Length newLen, const Coord pos);
// gets lower right corner of rect
Coord rectCorner(const Rect rect);
// returns rect at pos with length len
Rect rectify(const Coord pos, const Length len);
// offsets rect pos by 1/2 its length
Rect rectCenter(Rect r);
// returns midpoint of rect
Coord rectMid(const Rect r);
// returns rect pos offset by len of rect
Length unrectify(const Rect rect);
// returns true if pos is in rect
bool coordInRect(const Coord pos, const Rect rect);
// returns index of first rect that coord can be found in or -1 if in none
int coordInRectArr(const Coord coord, Rect *const rect, const int num);
// offsets rect by off
Rect rectOffset(const Rect rect, const Offset off);

// Vec.h ----------------------------------------------------------------------
// returns the angle of a vector centered at (0,0) pointing in the direction of coord
float cfToRad(const Coordf coord);
// converts radians to degrees
float radToDeg(const float rad);
// returns the angle of a vector centered at (0,0) pointing in the direction of coord
float cfToDeg(const Coordf coord);
// converts degrees to radians
float degToRad(const float deg);
// returns the other end position of a unit vector centered at (0, 0) with angle rad
Coordf radToCf(const float rad);
// returns the other end position of a unit vector centered at (0, 0) with angle deg
Coordf degToCf(const float deg);
// converts a Coord to a Coordf
Coordf CCf(const Coord coord);
// converts a Coordf to a Coord
Coord CfC(const Coordf coordf);
// returns a Coordf whose components are the are the max of the respective components of pos1 and pos2
Coordf cfMost(const Coordf pos1, const Coordf pos2);
// returns a Coordf whose components are the are the max of the respective components of pos1 and pos2
Coordf cfLeast(const Coordf pos1, const Coordf pos2);
// rounds the components of pos to be at least f
Coordf cfMaxf(const Coordf pos, const float f);
// rounds the components of pos to be at most f
Coordf cfMinf(const Coordf pos, const float f);
// clamps n so that it is at least min and at most max
float fclamp(const float n, const float min, const float max);
// returns true if n is greater than min (inclusive) and less than max (exclusive)
bool finBound(const float n, const float min, const float max);
// wraps the value of n between min and max
float fwrap(const float n, const float min, const float max);
// offsets coord by the components of off
Coordf cfAdd(const Coordf coord, const Offsetf off);
// multiplies the components of coord1 bt coord2
Coordf cfMul(const Coordf coord1, const Coordf coord2);
// multiplies both components of coord by num
Coordf cfMulf(const Coordf coord, const float num);
// divides both components of coord1 by coord2. sets component to 0 in case of division by 0
Coordf cfDiv(const Coordf coord1, const Coordf coord2);
// divides both components of coord by num. sets component to 0 in case of division by 0
Coordf cfDivf(const Coordf coord, const float num);
// returns the distance between the two coords
float cfDist(const Coordf coord1, const Coordf coord2);
// returns the length of a vector with one point o at (0,0) and the other at coord
float cfMag(const Coordf coord);
// creates a vector given angle in rads and a magnitude
Coordf radMagToCf(const float rad, const float mag);
// creates a vector given angle in rads and a magnitude
Coordf degMagToCf(const float deg, const float mag);
// normalized vector pointed at coord to a vector of unit length
Coordf cfNormalize(const Coordf coord);
// returns true if s and n have the same sign
bool sameSignf(const float s, const float n);
// inverts the sign of both components of pos
Coordf cfInv(const Coordf pos);
// returns coord with absolute value of both components of pos
Coordf cfAbs(const Coordf coord);
// returns the maximum component of pos
float cfMax(const Coordf pos);
// returns the minimum component of pos
float cfMin(const Coordf pos);
// returns true if both components of a and b are equal
bool cfSame(const Coordf a, const Coordf b);
// takes modulus of each component of pos by num
Coordf cfModf(const Coordf pos, const float num);
// takes modulus of each component of a by b
Coordf cfMod(const Coordf a, const Coordf b);
// subtracts each component of a from b
Coordf cfSub(const Coordf a, const Coordf b);
// adds num to both components of pos
Coordf cfAddf(const Coordf pos, const float num);
// rounds pos down to the nearest multiple of scale
Coordf cfSnap(const Coordf pos, const float scale);
// rounds pos to the nearest multiple of scale
Coordf cfSnapMid(const Coordf pos, const float scale);
// takes pos, gets its position in terms of percentage of oldLen
// returns a new position offset by the same percentage of newLen's sides
Coordf resizeTransformf(const Lengthf oldLen, const Lengthf newLen, const Coordf pos);
// returns angle of vector with orgin at pos1 and end at pos2
float cfCfToRad(const Coordf pos1, const Coordf pos2);
// returns angle of vector with orgin at pos1 and end at pos2
float cfCfToDeg(const Coordf pos1, const Coordf pos2);
// reduces the angle to +-180deg
float degReduce(float deg);
// reduces the angle to +-pi rad
float radReduce(float rad);
// inverts the angle
float degInv(const float deg);
// takes a vertex and returns the angle between the 2 other points (always <= pi rad)
float cf3Rad(const Coordf vtx, const Coordf pos1, const Coordf pos2);
// takes a vertex and returns the angle between the 2 other points (always <= 180deg)
float cf3Deg(const Coordf vtx, const Coordf pos1, const Coordf pos2);
// takes a vector and rotates it n rads
Coordf cfRotateRad(const Coordf vec, const float n);
// takes a vector and rotates it d deg
Coordf cfRotateDeg(const Coordf vec, const float d);
// returns true if line [p0, p1] intersects with line [p2, p3], sets intersection point to at if not NULL
bool lineIntersection(const Coordf p0, const Coordf p1, const Coordf p2, const Coordf p3, Coordf *at);

// Colors.h -------------------------------------------------------------------
// returns true if the colors are the same
bool colorSame(const Color, const Color );

// Timing.h -------------------------------------------------------------------
// returns the number of miliseconds that have elapsed since starting the program
uint getTicks(void);

// Graphics.h
// sets the drawing blend mode
void setBlend(const BlendMode mode);
// draws a pixel at (x, y)
void drawPixel(const int x, const int y);
// draws pixel at pos
void drawPixelCoord(const Coord pos);
// draws line from (x1, y1) to (x2, y2)
void drawLine(const int x1, const int y1, const int x2, const int y2);
// draws line from a to b
void drawLineCoords(const Coord a, const Coord b);
// draws a horizontal line at (x, y) of length len
void drawHLine(const int x, const int y, const int len);
// draws a vertical line at (x, y) of length len
void drawVLine(const int x, const int y, const int len);
// draws a rect at (x, y) of length (xlen, ylen)
void drawRect(const int x, const int y, const int xlen, const int ylen);
// draws a rect at with corners
void drawRectCoords(const Coord a, const Coord b);
// draws a rect with top left corner and bottom right corners
void drawRectCorners(const int x1, const int y1, const int x2, const int y2);
// draws a rect with its center at (x, y) of length (xlen, ylen)
void drawRectCentered(const int x, const int y, const int xlen, const int ylen);
// draws a rect centered at corners
void drawRectCenteredCorners(const int x1, const int y1, const int x2, const int y2);
// draws a rect centered at corners
void drawRectCenteredCoords(const Coord a, const Coord b);
// fills a rect at (x, y) with length (xlen, ylen)
void fillRect(const int x, const int y, const int xlen, const int ylen);
// fills a rect with top left corner and bottom right corners
void fillRectCorners(const int x1, const int y1, const int x2, const int y2);
// fills a rect with its center at (x, y) of length (xlen, ylen)
void fillRectCentered(const int x, const int y, const int xlen, const int ylen);
// fills a rect centered at corners
void fillRectCenteredCorners(const int x1, const int y1, const int x2, const int y2);
// fills a rect with corners
void fillRectCoords(const Coord a, const Coord b);
// fills a rect centered at corners
void fillRectCenteredCoords(const Coord a, const Coord b);
// draws a rect at pos with length len
void drawRectCoordLength(const Coord pos, const Length len);
// fills a rect with its center at pos of length len
void drawRectCenteredCoordLength(const Coord pos, const Length len);
// fills a rect at pos of length len
void fillRectCoordLength(const Coord pos, const Length len);
// fills a rect centered at pos of length len
void fillRectCenteredCoordLength(const Coord pos, const Length len);
// draws a rect
void drawRectRect(const Rect rect);
// draws a rect centered on its x and y components
void drawRectCenteredRect(const Rect rect);
// fills a rect
void fillRectRect(const Rect rect);
// fills a rect centered on its x and y components
void fillRectCenteredRect(const Rect rect);
// draws a square at (x, y) with length len
void drawSquare(const int x, const int y, const int len);
// draws a square at pos with length len
void drawSquareCoord(const Coord pos, const int len);
// draws a square centered on (x, y) with length len
void drawSquareCentered(const int x, const int y, const int len);
// draws a square centered at pos with length len
void drawSquareCenteredCoord(const Coord pos, const int len);
// fills a square at (x, y) with length len
void fillSquare(const int x, const int y, const int len);
// fills a square at pos with length len
void fillSquareCoord(const Coord pos, const int len);
// fills a square centered on (x, y) with length len
void fillSquareCentered(const int x, const int y, const int len);
// fills a square centered at pos with length len
void fillSquareCenteredCoord(const Coord pos, const int len);
// fills a square at x and y resized by resize
void fillSquareResize(const int x, const int y, const int len, const int resize);
// fills a square at pos resized by resize
void fillSquareCoordResize(const Coord pos, const int len, const int resize);
// fills a border at (x, y) with length (xlen, ylen) with thickness b
void fillBorder(const int x, const int y, const int xlen, const int ylen, const int b);
// fills a border at pos with length len with thickness b
void fillBorderCoord(const Coord pos, const Length len, const int b);
// fills a border around rect with thickness b
void fillBorderRect(const Rect rect, const int b);
// fills a border centered at (x, y) with length (xlen, ylen) with thickness b
void fillBorderCentered(const int x, const int y, const int xlen, const int ylen, const int b);
// fills a border centered at pos with length len with thickness b
void fillBorderCenteredCoord(const Coord pos, const Length len, const int b);
// fills a square border at pos with length len with thickness b
void fillBorderCoordSquare(const Coord pos, const int len, const int b);
// draws a circle centered at (x, y) with radius r
void drawCircle(const int x, const int y, const int r);
// fills a circle centered at (x, y) with radius r
void fillCircle(const int x, const int y, const int r);
// draws a circle centered at pos with radius r
void drawCircleCoord(const Coord pos, const int r);
// fills a circle centered at pos with radius r
void fillCircleCoord(const Coord pos, const int r);
// draws a thick line with rounded edges from (x1, y1) to (x2, y2) with radius r
void drawLineThick(const int x1, const int y1, const int x2, const int y2, const int r);
// draws a thick line with rounded edges from a to b with radius r
void drawLineThickCoords(const Coord a, const Coord b, const int r);
// gets current drawing color
Color getColor(void);
// sets drawing color
void setColor(const Color c);
// returns c as a u32
u32 colorToU32(const Color c);
// returns u as a Color
Color u32ToColor(const u32 u);
// draws a tri
void drawTri(const Coord pos1, const Coord pos2, const Coord pos3);
// fills a tri
void fillTri(const Coord pos1, const Coord pos2, const Coord pos3);
// draws a poly
void drawPoly(Coord *pos, const uint num);
// fills a poly
void fillPoly(Coord *pos, const uint num);
// draws a bezier curve
void bezier(const Coord *pos, const uint numc, const uint nums);
// sets red green and blue components of drawing color
void setRGB(const u8 r, const u8 g, const u8 b);
// sets red green blue and alpha components of drawing color
void setRGBA(const u8 r, const u8 g, const u8 b, const u8 a);
// fills screen with current drawing color
void fillScreen(void);
// fills screen with defaultColor
void clear(void);
// outlines the window
void outlineWindow(void);
// sets window title
void setWindowTitle(const char *title);
// gets window title
const char* getWindowTitle(void);
// renders everything to window
void draw(void);
// clears window and returns current time
uint frameStart(void);
// renders window and handles events and frame timing
void frameEnd(const uint t);
// cleans up gfx stuff
void gfx_quit(void);
// initializes gfx stuff
void gfx_init(void);

// Text.h ---------------------------------------------------------------------
// renders text to image
Img* textImg(const char *text);
// renders text to texture
Texture* textTexture(const char *text);
// draws text at x y position
Length drawText(const char *text, const int x, const int y);
// draws text at pos
Length drawTextCoord(const char *text, const Coord pos);
// draws text centered on pos x y
Length drawTextCentered(const char *text, const int x, const int y);
// draws text centered on pos
Length drawTextCenteredCoord(const char *text, const Coord pos);
// returns the length of text if it were to be rendered
Length textLength(const char *text);
// returns the top left coord of text given its center pos
Coord textCenteredCoord(const Coord center, const char *text);
// returns rect given pos and text
Rect textRect(const Coord pos, const char *text);
// returns rect with pos as top left coord of text given its center pos
Rect textCenteredRect(const Coord center, const char *text);
// returns the x component of the length of the text if it were to be rendered
int getTextXLen(const char *text);
// returns the y component of the length of the text if it were to be rendered
int getTextYLen(const char *text);
// spaces coords evenly between start and stop
Coord* spanListCoords(Coord *coords, const Coord start, const Coord stop, const uint num);
// spaces coords evenly centered between start and stop
Coord* spanListCoordsCentered(Coord *coords, const Coord start, const Coord stop, const uint num);
// gets rectangles of multiple texts spaced evenly between start and stop
Rect* getTextListRect(const char **textList, Rect *const rect, const Coord start, const Coord stop, const uint num);
// gets rectangles of multiple texts spaced evenly centered between start and stop
Rect* getTextListRectCentered(const char **textList, Rect *const rect, const Coord start, const Coord stop, const uint num);
// returns the index of the first rectangle that coord is in otherwise returns -1
int coordInRectList(const Coord coord, Rect *const rect, const int num);
// returns the index of the first text rectangle that coord is in otherwise returns -1
int coordInTextList(const Coord coord, const Coord start, const Coord stop, const uint num, const char **textList);
// draws a collection of strings spaced evenly between 2 points
void spanTextList(const char **textList, const Coord start, const Coord stop, const uint num);
// draws a collection of strings spaced evenly centered between 2 points
void spanTextListCentered(const char **textList, const Coord start, const Coord stop, const uint num);
// sets the size of text to be rendered
void setTextSize(const uint size);
// gets the current size of text to be rendered
int getTextSize(void);
// sets the color of text to be rendered
void setTextColor(const Color c);
// gets the current color of text to be rendered
Color getTextColor(void);
// cleans up text stuff
void text_quit(void);
// initializes text stuff
void text_init(void);

// Image.h --------------------------------------------------------------------
// cleans up img stuff
void img_quit(void);
// initializes img stuff
void img_init(void);
// frees a Img
void freeImg(Img *image);
// frees a Texture
Texture* textureFree(Texture *t);
// loads an Img from a file
Img* loadImg(const char *file);
// creates a Texture from an Img
Texture* imgTexture(Img *img);
// loads a Texture from a file
Texture* loadTexture(const char *file);
// draws an Img
void drawImg(Img *image);
// loads an Img from a file and draws it immidiately
void loadDrawImg(const char *file);
// gets the Length of Texture
Length textureLen(Texture *texture);
// returns a bounding Rect of the texture at pos
Rect textureRect(Texture *texture, const Coord pos);
// draws a texture at x y
Length drawTexture(Texture *texture, const int x, const int y);
// draws a texture at pos
Length drawTextureCoord(Texture *texture, const Coord pos);
// draws a texture centered at x y
Length drawTextureCentered(Texture *texture, const int x, const int y);
// draws a texture centered at pos
Length drawTextureCenteredCoord(Texture *texture, const Coord pos);
// resizes a texture to xlen ylen and draws it at x y
Length drawTextureResize(Texture *texture, const int x, const int y, const int xlen, const int ylen);
// resizes a texture to len and draws it at pos
Length drawTextureCoordResize(Texture *texture, const Coord pos, const Length len);
// resizes a texture to xlen ylen and draws it centered at x y
Length drawTextureCenteredResize(Texture *texture, const int x, const int y, const int xlen, const int ylen);
// resizes a texture to len and draws it centered at pos
Length drawTextureCenteredCoordResize(Texture *texture, const Coord pos, const Length len);

// Input.h --------------------------------------------------------------------
// returns true if currently inputting text
bool textInputState(void);
// returns true when text input ends
bool textInputEnded(void);
// stop inputting text
void textInputStop(void);
// a default function for when to stop text input
bool defaultTextInputDone(void);
// begin inputting text
void textInputStart(char *buf, const st bufsize, boolFunc textInputDone);
// returns the current press state of the key
bool keyState(const Scancode key);
// returns true if the key was just pressed
bool keyPressed(const Scancode key);
// returns true if the key was pressed last frame and is still pressed
bool keyHeld(const Scancode key);
// returns true if the key was pressed or released
bool keyChanged(const Scancode key);
// returns true if the key was released
bool keyReleased(const Scancode key);
// returns time at which the key was last pressed
uint keyPressTime(const Scancode key);
// returns time at which the key was last released
uint keyReleaseTime(const Scancode key);
// returns the amount of time the key has been held
uint keyHeldTime(const Scancode key);
// returns a pointer to the name for the scancode or an empty string
const char* keyName(const Scancode key);
// returns the current position of the mouse
Coord mousePos(void);
// returns true if mouseBtn was just pressed
bool mouseBtnPressed(const u32 mouseBtn);
// returns the current press state of mouseBtn
bool mouseBtnState(const u32 mouseBtn);
// returns true if mouseBtn was pressed last frame and is still pressed
bool mouseBtnHeld(const u32 mouseBtn);
// returns true if mouseBtn was just released
bool mouseBtnReleased(const u32 mouseBtn);
// returns true if the press state if mouseBtn changed
bool mouseBtnChanged(const u32 mouseBtn);
// returns the direction the mouse wheel was scrolled left or right
int mouseScrolledX(void);
// returns the direction the mouse wheel was scrolled up or down
int mouseScrolledY(void);
// returns true if mouse if currently moving
bool mouseMoving(void);
// returns true if mouse just began moving
bool mouseMoveStart(void);
// returns true if mouse just stopped moving
bool mouseMoveStop(void);
// returns the distance the mouse has moved since last frame
Offset mouseMovement(void);
// sets the relative mode of the mouse
void setRelativeMouse(const bool state);
// returns true if any of the Ctrl keys are pressed
bool keyCtrlState(void);
// returns true if any of the Shift keys are pressed
bool keyShiftState(void);
// returns true if both keys are pressed
bool keyComboState(const Scancode modkey, const Scancode key);
// returns true if modkey is pressed and key was just pressed
bool keyComboPressed(const Scancode modkey, const Scancode key);
// returns true if Ctrl is pressed and key was just pressed
bool checkCtrlKey(const Scancode key);
// inits input stuff
void input_init(void);
// returns an offset based on the state of the W A S and D keys
Offset wasdKeyStateOffset(void);
// returns an offset based on the state of the arrow keys
Offset arrowKeyStateOffset(void);
// returns an offset based on the state of the W A S and D keys or the arrow keys
Offset dirKeyStateOffset(void);
// returns an offset based on if W A S or D was just pressed
Offset wasdKeyPressedOffset(void);
// returns an offset based on if arrow keys were just pressed
Offset arrowKeyPressedOffset(void);
// returns an offset based on if W A S D or arrow keys were just pressed
Offset dirKeyPressedOffset(void);

// Events.h -------------------------------------------------------------------
// handles events
void events(const uint endOfFrame);

// File.h ---------------------------------------------------------------------
// returns the number of chars in file
size_t fileLen(const char *filePath);
// returns string containing contents of file
char* fileReadText(const char *filePath);

// DogeUtil.h
// clears the terminal
void clearTerminal(void);
// returns a random number between a and b
float randRange(float a, float b);
// reallocs and zeros data to new size
void* recalloc(void *data, const st newsize);
// inits everything
void init(void);

// Poly.h ---------------------------------------------------------------------
// creates a polygon
Poly polyCreate(const uint numVertex, ...);
// frees a poly
void polyFree(const Poly p);
// returns a bounding box rectangle around a poly
Rect polyBbRect(const Poly p);
// returns the corners of a bounding box rectangle around a poly
CoordPair polyBbMinMax(const Poly p);

// Display.h ------------------------------------------------------------------
// gets the index of the display the window is on
int getWinDisplayIndex(void);
// gets the display rectangle the window is on
Rect getWinDisplayRect(void);
// gets the display length the window is on
Length getWinDisplayLen(void);
// gets the length of the display at index i
Length getDisplayIndexLen(const uint i);
// gets the display rectange at index i
Rect getDisplayIndexRect(const uint i);
// gets the offset of the display the window is on
Coord getWinDisplayOffset(void);
// gets the offset of the display at index i
Coord getDisplayIndexOffset(const uint i);
// gets the number of displays
uint getDisplayNum(void);
// gets the length of all displays together
Length getDisplayTotalLen(void);

// Window.h -------------------------------------------------------------------
// sets window mode fullscreen / borderless / windowed
void setWindowMode(const WindowMode mode);
// sets if window is resizable
void setWindowResizable(const bool resizable);
// gets if window is resizable
bool getWindowResizable(void);
// sets length of window
void setWindowLen(const Length len);
// gets length of window on previous frame
Length getWindowPrvLen(void);
// gets length of window
Length getWindowLen(void);
// returns if window was resized
bool windowResized(void);
// gets midpoint of window
Coord getWindowMid(void);
// returns if a display coord is within window
bool coordInWindow(const Coord pos);
// maximizes window then returns its length
Length maximizeWindow(void);
// restored window to the size it was before maximizing
Length restoreWindow(void);
// moves window to x y display pos
void winSetPos(const int x, const int y);
// moves window to coord display pos
void winSetPosCoord(const Coord pos);
// returns if window is maximized
bool winIsMaximized(void);
// returns if window is minimized
bool winIsMinimized(void);
// confines mouse to window
void winSetGrab(const bool isGrabbed);
// returns if mouse is confined to window
bool winIsGrabbed(void);
// gets the window currently with focus
Window* winGetFocused(void);
// returns if window is focused
bool winIsFocused(void);
// gets opacity of window
float winGetOpacity(void);
// sets opacity of window
void winSetOpacity(const float value);

// Net.h
// cleans up net stuff
void net_quit(void);
// initializes net stuff
void net_init(void);

#endif /* end of include guard: DOGELIB_DECLS_H */

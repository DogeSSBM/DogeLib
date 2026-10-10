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
// returns the corner position of rect
Coord irC(const Rect rect);
// returns the length of rect
Length irL(const Rect rect);
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

// GetInt.h
int strToInt(const char*);
uint digits(int);
int shiftR(const int);
int getR(const int);
char intToChar(const int);
void intToStr(int, char*);
int getInt(void);

// Colors.h
bool colorSame(const Color, const Color );
u8* colorIndex(Color*, const int);

// Timing.h
static inline uint getTicks(void);

// Graphics.h
void setBlend(const BlendMode);
void drawPixel(const int, const int);
void drawPixelCoord(const Coord);
void drawLine(const int, const int, const int, const int);
void drawLineCoords(const Coord, const Coord);
void drawHLine(const int, const int, const int);
void drawVLine(const int, const int, const int);
void drawRect(const int, const int, const int, const int);
void drawRectCoords(const Coord, const Coord);
void drawRectCorners(const int, const int, const int, const int);
void drawRectCentered(const int, const int, const int, const int);
void drawRectCenteredCorners(const int, const int, const int, const int);
void drawRectCenteredCoords(const Coord, const Coord);
void fillRect(const int, const int, const int, const int);
void fillRectCorners(const int, const int, const int, const int);
void fillRectCentered(const int, const int, const int, const int);
void fillRectCenteredCorners(const int, const int, const int, const int);
void fillRectCoords(const Coord, const Coord);
void fillRectCenteredCoords(const Coord, const Coord);
void drawRectCoordLength(const Coord, const Length);
void drawRectCenteredCoordLength(const Coord, const Length);
void fillRectCoordLength(const Coord, const Length);
void fillRectCenteredCoordLength(const Coord , const Length);
void drawRectRect(const Rect);
void drawRectCenteredRect(const Rect);
void fillRectRect(const Rect);
void fillRectCenteredRect(const Rect);
void drawSquare(const int, const int, const int);
void drawSquareCoord(const Coord , const int);
void drawSquareCentered(const int, const int, const int);
void drawSquareCenteredCoord(const Coord, const int);
void fillSquare(const int, const int, const int);
void fillSquareCoord(const Coord, const int);
void fillSquareCentered(const int, const int y, const int);
void fillSquareCenteredCoord(const Coord, const int);
void fillSquareResize(const int, const int, const int, const int);
void fillSquareCoordResize(const Coord , const int, const int);
void fillBorder(const int, const int, const int, const int, const int);
void fillBorderCoord(const Coord, const Length, const int);
void fillBorderCoordSquare(const Coord, const int, const int);
void drawCircle(const int, const int, const int);
void fillCircle(const int, const int, const int);
void drawCircleCoord(const Coord, const int);
void fillCircleCoord(const Coord, const int);
void drawLineThick(const int, const int, const int, const int, const int);
void drawLineThickCoords(const Coord, const Coord, const int);
Color getColor(void);
void setColor(const Color);
u32 colorToU32(const Color);
Color u32ToColor(const u32);
void drawTri(const Coord, const Coord, const Coord);
void fillTri(const Coord, const Coord, const Coord);
void drawPoly(Coord *, const uint);
void fillPoly(Coord *, const uint);
void bezier(const Coord *, const uint, const uint);
void setRGB(const u8, const u8, const u8);
void setRGBA(const u8, const u8, const u8, const u8);
void fillScreen(void);
void clear(void);
void outlineWindow(void);
void draw(void);
uint frameStart(void);
void frameEnd(const uint);
void gfx_quit(void);
void gfx_init(void);

// Text.h
Img* textImg(const char*);
Texture* textTexture(const char*);
Length drawText(const char*, const int, const int);
Length drawTextCoord(const char*, const Coord);
Length drawTextCentered(const char*, const int, const int);
Length drawTextCenteredCoord(const char*, const Coord);
Length getTextLength(const char*);
int getTextXLen(const char*);
int getTextYLen(const char*);
Coord* spanTextListCoords(Coord*, const Coord, const Coord, const uint);
Coord* spanTextListCoordsCentered(Coord*, const Coord, const Coord, const uint);
Rect* getTextListRect(const char**, Rect* const, const Coord, const Coord, const uint);
Rect* getTextListRectCentered(const char**, Rect* const, const Coord, const Coord, const uint);
int coordInRectList(const Coord, Rect* const, const int);
int coordInTextList(const Coord, const Coord, const Coord, const uint, const char**);
void spanTextList(const char**, const Coord, const Coord, const uint);
void spanTextListCentered(const char**, const Coord, const Coord, const uint);
void setTextSize(const uint);
int getTextSize(void);
void setTextColor(const Color);
Color getTextColor(void);
void text_quit(void);
void text_init(void);

// Image.h
void img_quit(void);
void img_init(void);
void freeImg(Img*);
Texture* textureFree(Texture*);
Img* loadImg(const char*);
Texture* imgTexture(Img*);
Texture* loadTexture(const char*);
void drawImg(Img*);
void loadDrawImg(const char*);
Length textureLen(Texture*);
Rect textureRect(Texture*, const Coord);
Length drawTexture(Texture*, const int, const int);
Length drawTextureCoord(Texture*, const Coord);
Length drawTextureCentered(Texture*, const int, const int);
Length drawTextureCenteredCoord(Texture*, const Coord);
Length drawTextureResize(Texture*, const int, const int, const int, const int);
Length drawTextureCoordResize(Texture*, const Coord, const Length);
Length drawTextureCenteredResize(Texture*, const int, const int, const int, const int);
Length drawTextureCenteredCoordResize(Texture*, const Coord, const Length);

// Input.h
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

// Events.h
void events(const uint);

// File.h
size_t fileLen(const char*);
char* fileReadText(const char*);

// DogeUtil.h
void clearTerminal(void);
float randRange(float, float);
void* recalloc(void *, const st, const st);
void init(void);

// Poly.h
Poly polyCreate(const uint, ...);
void polyDestroy(const Poly);
Rect polyBbRect(const Poly);
CoordPair polyBbMinMax(const Poly);

// Display.h
int getWinDisplayIndex(void);
Rect getWinDisplayRect(void);
Length getWinDisplayLen(void);
Length getDisplayIndexLen(const uint);
Rect getDisplayIndexRect(const uint);
Coord getWinDisplayOffset(void);
Coord getDisplayIndexOffset(const uint);
uint getDisplayNum(void);
Length getDisplayTotalLen(void);

// Window.h
void setWindowMode(const WindowMode);
void setWindowResizable(const bool);
bool getWindowResizable(void);
void setWindowLen(const Length);
Length getWindowPrvLen(void);
Length getWindowLen(void);
bool windowResized(void);
Length getWindowMid(void);
bool coordInWindow(const Coord);
Length maximizeWindow(void);
Length restoreWindow(void);
void winSetPos(const int, const int);
void winSetPosCoord(const Coord);
bool winIsMaximized(void);
bool winIsMinimized(void);
void winSetGrab(const bool);
bool winIsGrabbed(void);
Window* winGetFocused(void);
bool winIsFocused(void);


// Net.h
void net_init(void);
void net_quit(void);

#endif /* end of include guard: DOGELIB_DECLS_H */

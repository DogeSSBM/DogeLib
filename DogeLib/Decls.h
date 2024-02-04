#ifndef DOGELIB_DECLS_H
#define DOGELIB_DECLS_H

// Coords.h
static inline Direction dirROR(const Direction);
static inline Direction dirROL(const Direction);
static inline Direction dirINV(const Direction);
static inline Direction dirLR(const Direction);
static inline Direction dirUD(const Direction);
static inline bool dirAXA(const Direction, const Direction);
static inline Direction dirPOS(const Direction);
static inline Direction dirNEG(const Direction);
static inline int coordMin(const Coord);
static inline Coord coordLeast(const Coord, const Coord);
static inline int coordMax(const Coord);
static inline Coord coordMost(const Coord, const Coord);
static inline bool coordSame(const Coord, const Coord);
static inline Coord coordAbs(const Coord);
static inline int clamp(const int, const int, const int);
static inline bool inBound(const int, const int, const int);
static inline int wrap(const int, const int, const int);
static inline bool coordInLen(const Coord, const Length);
static inline bool coordMaxCoord(const Coord, const Coord);
static inline bool coordMinCoord(const Coord, const Coord);
static inline Rect coordsToRect(const Coord, const Coord);
static inline bool coordNz(const Coord);
static inline Coord coordMuli(const Coord, const int);
static inline Coord CoordMul(const Coord, const Coord);
static inline Coord coordInv(const Coord);
static inline Coord coordAddi(const Coord, const int);
static inline Coord coordSub(const Coord, const Coord);
static inline Coord coordMod(const Coord, const Coord);
static inline Coord coordModi(const Coord, const int);
static inline Coord coordMid(const Coord, const Coord);
static inline uint coordDistSq(const Coord, const Coord);
static inline Coord coordDivi(const Coord, const int);
static inline Coord coordDiv(const Coord, const Coord);
static inline Coord coordShift(const Coord, const Direction, const int);
static inline Coord coordAdd(const Coord, const Offset);
static inline Coord coordCenter(const Coord, const Length);
static inline Coord coordUncenter(const Coord, const Length);
static inline Coord coordOffScale(const Coord, const Offset, const int);
static inline Coord resizeTransform(const Length, const Length, const Coord);
static inline Rect rectify(const Coord, const Length);
static inline Rect rectCenter(Rect);
static inline Length unrectify(const Rect);
static inline bool coordInRect(const Coord, const Rect);
static inline int coordInRectArr(const Coord, Rect *const, const int);
static inline Rect rectOffset(const Rect, const Offset);

// Vec.h
float cfToRad(const Coordf);
float radToDeg(const float);
float cfToDeg(const Coordf);
float degToRad(const float);
Coordf radToCf(const float);
Coordf degToCf(const float);
Coordf CCf(const Coord);
Coord CfC(const Coordf);
Coordf cfMost(const Coordf, const Coordf);
Coordf cfLeast(const Coordf, const Coordf);
float fclamp(const float, const float, const float);
bool finBound(const float, const float, const float);
float fwrap(const float, const float, const float);
Coordf cfAdd(const Coordf, const Offsetf);
Coordf cfMul(const Coordf, const Coordf);
Coordf cfMulf(const Coordf, const float);
Coordf cfDiv(const Coordf, const Coordf);
Coordf cfDivf(const Coordf, const float);
float cfDist(const Coordf, const Coordf);
float cfMag(const Coordf);
Coordf radMagToCf(const float, const float);
Coordf degMagToCf(const float, const float);
Coordf cfNormalize(const Coordf);
Coordf cfTranslate(const Coordf, const Vectorf);
bool fSameSign(const float, const float);
Coordf cfNeg(const Coordf);
Coordf cfAbs(const Coordf);
float cfMax(const Coordf);
float cfMin(const Coordf);
bool cfSame(const Coordf, const Coordf);
Coordf cfMod(const Coordf, const Coordf);
Coordf cfModf(const Coordf, const float);
Coordf cfSub(const Coordf, const Coordf);
Coordf cfAddf(const Coordf, const float);
Coordf cfSnap(const Coordf, const float);
Coordf cfSnapMid(const Coordf, const float);
Coordf resizeTransformf(const Lengthf, const Lengthf, const Coordf);
float cfCfToRad(const Coordf, const Coordf);
float cfCfToDeg(const Coordf, const Coordf);
float degReduce(const float);
float degInv(const float);
float cf3Rad(const Coordf, const Coordf, const Coordf);
float cf3Deg(const Coordf, const Coordf, const Coordf);
Coordf cfRotateRad(const Coordf, const float);
Coordf cfRotateDeg(const Coordf, const float);
bool lineIntersection(const Coordf, const Coordf, const Coordf, const Coordf, Coordf*);

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
bool inputTypeState(const InputType);
bool keyState(const Scancode);
bool keyPressed(const Scancode);
bool keyHeld(const Scancode);
bool keyChanged(const Scancode);
bool keyReleased(const Scancode);
InputType keyInputType(const Scancode);
bool mouseBtnPressed(const u32);
bool mouseBtnState(const u32);
bool mouseBtnHeld(const u32);
bool mouseBtnReleased(const u32);
bool mouseBtnChanged(const u32);
InputType mouseBtnInputType(const u32);
int mouseScrolledX(void);
int mouseScrolledY(void);
bool mouseMoving(void);
bool mouseMoveStart(void);
bool mouseMoveStop(void);
Length mouseMovement(void);
void setRelativeMouse(const bool);
bool keyCtrlState(void);
bool keyShiftState(void);
bool keyComboPressed(const Scancode, const Scancode);
bool checkCtrlKey(const Scancode);
void input_init(void);
Offset wasdKeyStateOffset(void);
Offset arrowKeyStateOffset(void);
Offset dirKeyStateOffset(void);
Offset wasdKeyPressedOffset(void);
Offset arrowKeyPressedOffset(void);
Offset dirKeyPressedOffset(void);

// Events.h
void events(const uint);

// File.h
uint fileLen(const char*);
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

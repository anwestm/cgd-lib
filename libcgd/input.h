//
// Created by ANDREAS WESTMAN
// on 2019-02-02.
//

#ifndef CGD_LIB_INPUT_H
#define CGD_LIB_INPUT_H

#include <SDL2/SDL.h>

typedef enum
{
    CGD_KEY_UNKNOWN = 0,

    CGD_KEY_A = 4,
    CGD_KEY_B = 5,
    CGD_KEY_C = 6,
    CGD_KEY_D = 7,
    CGD_KEY_E = 8,
    CGD_KEY_F = 9,
    CGD_KEY_G = 10,
    CGD_KEY_H = 11,
    CGD_KEY_I = 12,
    CGD_KEY_J = 13,
    CGD_KEY_K = 14,
    CGD_KEY_L = 15,
    CGD_KEY_M = 16,
    CGD_KEY_N = 17,
    CGD_KEY_O = 18,
    CGD_KEY_P = 19,
    CGD_KEY_Q = 20,
    CGD_KEY_R = 21,
    CGD_KEY_S = 22,
    CGD_KEY_T = 23,
    CGD_KEY_U = 24,
    CGD_KEY_V = 25,
    CGD_KEY_W = 26,
    CGD_KEY_X = 27,
    CGD_KEY_Y = 28,
    CGD_KEY_Z = 29,

    CGD_KEY_1 = 30,
    CGD_KEY_2 = 31,
    CGD_KEY_3 = 32,
    CGD_KEY_4 = 33,
    CGD_KEY_5 = 34,
    CGD_KEY_6 = 35,
    CGD_KEY_7 = 36,
    CGD_KEY_8 = 37,
    CGD_KEY_9 = 38,
    CGD_KEY_0 = 39,

    CGD_KEY_RETURN = 40,
    CGD_KEY_ESCAPE = 41,
    CGD_KEY_BACKSPACE = 42,
    CGD_KEY_TAB = 43,
    CGD_KEY_SPACE = 44,

    CGD_KEY_MINUS = 45,
    CGD_KEY_EQUALS = 46,
    CGD_KEY_LEFTBRACKET = 47,
    CGD_KEY_RIGHTBRACKET = 48,
    CGD_KEY_BACKSLASH = 49,
    CGD_KEY_NONUSHASH = 50,
    CGD_KEY_SEMICOLON = 51,
    CGD_KEY_APOSTROPHE = 52,
    CGD_KEY_GRAVE = 53,
    CGD_KEY_COMMA = 54,
    CGD_KEY_PERIOD = 55,
    CGD_KEY_SLASH = 56,

    CGD_KEY_CAPSLOCK = 57,

    CGD_KEY_F1 = 58,
    CGD_KEY_F2 = 59,
    CGD_KEY_F3 = 60,
    CGD_KEY_F4 = 61,
    CGD_KEY_F5 = 62,
    CGD_KEY_F6 = 63,
    CGD_KEY_F7 = 64,
    CGD_KEY_F8 = 65,
    CGD_KEY_F9 = 66,
    CGD_KEY_F10 = 67,
    CGD_KEY_F11 = 68,
    CGD_KEY_F12 = 69,

    CGD_KEY_PRINTSCREEN = 70,
    CGD_KEY_SCROLLLOCK = 71,
    CGD_KEY_PAUSE = 72,
    CGD_KEY_INSERT = 73,
    CGD_KEY_HOME = 74,
    CGD_KEY_PAGEUP = 75,
    CGD_KEY_DELETE = 76,
    CGD_KEY_END = 77,
    CGD_KEY_PAGEDOWN = 78,
    CGD_KEY_RIGHT = 79,
    CGD_KEY_LEFT = 80,
    CGD_KEY_DOWN = 81,
    CGD_KEY_UP = 82,

    CGD_KEY_NUMLOCKCLEAR = 83,
    CGD_KEY_KP_DIVIDE = 84,
    CGD_KEY_KP_MULTIPLY = 85,
    CGD_KEY_KP_MINUS = 86,
    CGD_KEY_KP_PLUS = 87,
    CGD_KEY_KP_ENTER = 88,
    CGD_KEY_KP_1 = 89,
    CGD_KEY_KP_2 = 90,
    CGD_KEY_KP_3 = 91,
    CGD_KEY_KP_4 = 92,
    CGD_KEY_KP_5 = 93,
    CGD_KEY_KP_6 = 94,
    CGD_KEY_KP_7 = 95,
    CGD_KEY_KP_8 = 96,
    CGD_KEY_KP_9 = 97,
    CGD_KEY_KP_0 = 98,
    CGD_KEY_KP_PERIOD = 99,

    CGD_KEY_NONUSBACKSLASH = 100,
    CGD_KEY_APPLICATION = 101,
    CGD_KEY_POWER = 102,
    CGD_KEY_KP_EQUALS = 103,
    CGD_KEY_F13 = 104,
    CGD_KEY_F14 = 105,
    CGD_KEY_F15 = 106,
    CGD_KEY_F16 = 107,
    CGD_KEY_F17 = 108,
    CGD_KEY_F18 = 109,
    CGD_KEY_F19 = 110,
    CGD_KEY_F20 = 111,
    CGD_KEY_F21 = 112,
    CGD_KEY_F22 = 113,
    CGD_KEY_F23 = 114,
    CGD_KEY_F24 = 115,
    CGD_KEY_EXECUTE = 116,
    CGD_KEY_HELP = 117,
    CGD_KEY_MENU = 118,
    CGD_KEY_SELECT = 119,
    CGD_KEY_STOP = 120,
    CGD_KEY_AGAIN = 121,
    CGD_KEY_UNDO = 122,
    CGD_KEY_CUT = 123,
    CGD_KEY_COPY = 124,
    CGD_KEY_PASTE = 125,
    CGD_KEY_FIND = 126,
    CGD_KEY_MUTE = 127,
    CGD_KEY_VOLUMEUP = 128,
    CGD_KEY_VOLUMEDOWN = 129,

    CGD_KEY_KP_COMMA = 133,
    CGD_KEY_KP_EQUALSAS400 = 134,

    CGD_KEY_INTERNATIONAL1 = 135,
    CGD_KEY_INTERNATIONAL2 = 136,
    CGD_KEY_INTERNATIONAL3 = 137,
    CGD_KEY_INTERNATIONAL4 = 138,
    CGD_KEY_INTERNATIONAL5 = 139,
    CGD_KEY_INTERNATIONAL6 = 140,
    CGD_KEY_INTERNATIONAL7 = 141,
    CGD_KEY_INTERNATIONAL8 = 142,
    CGD_KEY_INTERNATIONAL9 = 143,
    CGD_KEY_LANG1 = 144, /**< Hangul/English toggle */
    CGD_KEY_LANG2 = 145, /**< Hanja conversion */
    CGD_KEY_LANG3 = 146, /**< Katakana */
    CGD_KEY_LANG4 = 147, /**< Hiragana */
    CGD_KEY_LANG5 = 148, /**< Zenkaku/Hankaku */
    CGD_KEY_LANG6 = 149, /**< reserved */
    CGD_KEY_LANG7 = 150, /**< reserved */
    CGD_KEY_LANG8 = 151, /**< reserved */
    CGD_KEY_LANG9 = 152, /**< reserved */

    CGD_KEY_ALTERASE = 153, /**< Erase-Eaze */
    CGD_KEY_SYSREQ = 154,
    CGD_KEY_CANCEL = 155,
    CGD_KEY_CLEAR = 156,
    CGD_KEY_PRIOR = 157,
    CGD_KEY_RETURN2 = 158,
    CGD_KEY_SEPARATOR = 159,
    CGD_KEY_OUT = 160,
    CGD_KEY_OPER = 161,
    CGD_KEY_CLEARAGAIN = 162,
    CGD_KEY_CRSEL = 163,
    CGD_KEY_EXSEL = 164,

    CGD_KEY_KP_00 = 176,
    CGD_KEY_KP_000 = 177,
    CGD_KEY_THOUSANDSSEPARATOR = 178,
    CGD_KEY_DECIMALSEPARATOR = 179,
    CGD_KEY_CURRENCYUNIT = 180,
    CGD_KEY_CURRENCYSUBUNIT = 181,
    CGD_KEY_KP_LEFTPAREN = 182,
    CGD_KEY_KP_RIGHTPAREN = 183,
    CGD_KEY_KP_LEFTBRACE = 184,
    CGD_KEY_KP_RIGHTBRACE = 185,
    CGD_KEY_KP_TAB = 186,
    CGD_KEY_KP_BACKSPACE = 187,
    CGD_KEY_KP_A = 188,
    CGD_KEY_KP_B = 189,
    CGD_KEY_KP_C = 190,
    CGD_KEY_KP_D = 191,
    CGD_KEY_KP_E = 192,
    CGD_KEY_KP_F = 193,
    CGD_KEY_KP_XOR = 194,
    CGD_KEY_KP_POWER = 195,
    CGD_KEY_KP_PERCENT = 196,
    CGD_KEY_KP_LESS = 197,
    CGD_KEY_KP_GREATER = 198,
    CGD_KEY_KP_AMPERSAND = 199,
    CGD_KEY_KP_DBLAMPERSAND = 200,
    CGD_KEY_KP_VERTICALBAR = 201,
    CGD_KEY_KP_DBLVERTICALBAR = 202,
    CGD_KEY_KP_COLON = 203,
    CGD_KEY_KP_HASH = 204,
    CGD_KEY_KP_SPACE = 205,
    CGD_KEY_KP_AT = 206,
    CGD_KEY_KP_EXCLAM = 207,
    CGD_KEY_KP_MEMSTORE = 208,
    CGD_KEY_KP_MEMRECALL = 209,
    CGD_KEY_KP_MEMCLEAR = 210,
    CGD_KEY_KP_MEMADD = 211,
    CGD_KEY_KP_MEMSUBTRACT = 212,
    CGD_KEY_KP_MEMMULTIPLY = 213,
    CGD_KEY_KP_MEMDIVIDE = 214,
    CGD_KEY_KP_PLUSMINUS = 215,
    CGD_KEY_KP_CLEAR = 216,
    CGD_KEY_KP_CLEARENTRY = 217,
    CGD_KEY_KP_BINARY = 218,
    CGD_KEY_KP_OCTAL = 219,
    CGD_KEY_KP_DECIMAL = 220,
    CGD_KEY_KP_HEXADECIMAL = 221,

    CGD_KEY_LCTRL = 224,
    CGD_KEY_LSHIFT = 225,
    CGD_KEY_LALT = 226, /**< alt, option */
    CGD_KEY_LGUI = 227, /**< windows, command (apple), meta */
    CGD_KEY_RCTRL = 228,
    CGD_KEY_RSHIFT = 229,
    CGD_KEY_RALT = 230, /**< alt gr, option */
    CGD_KEY_RGUI = 231, /**< windows, command (apple), meta */

    CGD_KEY_MODE = 257,
    CGD_KEY_AUDIONEXT = 258,
    CGD_KEY_AUDIOPREV = 259,
    CGD_KEY_AUDIOSTOP = 260,
    CGD_KEY_AUDIOPLAY = 261,
    CGD_KEY_AUDIOMUTE = 262,
    CGD_KEY_MEDIASELECT = 263,
    CGD_KEY_WWW = 264,
    CGD_KEY_MAIL = 265,
    CGD_KEY_CALCULATOR = 266,
    CGD_KEY_COMPUTER = 267,
    CGD_KEY_AC_SEARCH = 268,
    CGD_KEY_AC_HOME = 269,
    CGD_KEY_AC_BACK = 270,
    CGD_KEY_AC_FORWARD = 271,
    CGD_KEY_AC_STOP = 272,
    CGD_KEY_AC_REFRESH = 273,
    CGD_KEY_AC_BOOKMARKS = 274,

    CGD_KEY_BRIGHTNESSDOWN = 275,
    CGD_KEY_BRIGHTNESSUP = 276,
    CGD_KEY_DISPLAYSWITCH = 277, /**< display mirroring/dual display
                                           switch, video mode switch */
    CGD_KEY_KBDILLUMTOGGLE = 278,
    CGD_KEY_KBDILLUMDOWN = 279,
    CGD_KEY_KBDILLUMUP = 280,
    CGD_KEY_EJECT = 281,
    CGD_KEY_SLEEP = 282,

    CGD_KEY_APP1 = 283,
    CGD_KEY_APP2 = 284,

    CGD_KEY_AUDIOREWIND = 285,
    CGD_KEY_AUDIOFASTFORWARD = 286,

    CGD_NUM_KEYS = 512 /**< not a key, just marks the number of KEYs
                                 for array bounds */
} cgd_keycode;

void cgd_input_handle_event(SDL_Event event);
char cgd_input_key_down(cgd_keycode code);
char cgd_input_key_pressed(cgd_keycode code);

#endif //CGD_LIB_INPUT_H

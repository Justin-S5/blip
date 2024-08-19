#ifndef RAYLIB5_H
#define RAYLIB5_H

// LINUX
#if defined(unix) || defined(__unix__) || defined(__unix)

#endif

// MAC OS
#if defined (__APPLE__) || defined (__MACH__)
#include "raylib5/macos/include/raylib.h"
#endif

// WINDOWS
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

#endif

#endif // RAYLIB5_H
#ifndef PCH_H
#define PCH_H

#include <stdint.h>
#include <cstdio>
#include <iostream>
#include <fstream>

#include "Cipher.h"
#include "MathCore.h"
#include "Utills.h"

#if defined(__linux) || defined(__linux__) || defined(linux)
# define LINUX

#elif defined(__APPLE__)
# define MACOS

#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64)
# define WINDOWS

#endif

#endif //PCH_H

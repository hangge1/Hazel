#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory>
#include <algorithm>
#include <utility>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Hazel/Core/Log.h"

#include "Hazel/Debug/Instrumentor.h"

#ifdef HZ_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
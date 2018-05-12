#pragma once

#include <iostream>

// Display a log with log format
#define LOG std::clog << "[LOG]:[" << __func__ << "@" << __LINE__ << "]: "

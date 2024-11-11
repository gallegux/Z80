#pragma once

#include <iostream>
#include <iomanip>


#define debug //printf
#define debug_z80 //printf
#define debug_mem //printf


#define FLUSH std::cout << std::flush;


#define LOG_TO(stream,level,message) stream << (level) << " " << __FILE__ << ":" << __LINE__ << " - " << message << std::endl; // NOLINT(misc-macro-parentheses): Not having parentheses around message is a feature, it allows using streams in LOG macros

#define LOG_ERROR(message)   LOG_TO(std::cerr, "ERROR  ", message)
#define LOG_WARNING(message) LOG_TO(std::cerr, "WARNING", message)
#define LOG_INFO(message)    LOG_TO(std::cerr, "INFO   ", message)
#define LOG_DEBUG(message)   LOG_TO(std::cout, "DEBUG  ", message)


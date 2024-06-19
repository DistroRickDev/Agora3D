

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

#include <fmt/format.h>

auto raw_time{std::time(nullptr)};

#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)    // only show filename and not it's path (less clutter)
#define LOG_PREFIX std::put_time(std::localtime(&raw_time), "%c ") << __FILENAME__ << "(" << __FUNCTION__ << ":" << __LINE__ << ") "

#if defined(LOG_TO_PERSITANCY)
    auto constexpr logger_path("/tmp/game_engine.log"); 
    static auto logger_file {std::ofstream(logger_path, std::ios::trunc)};

#if !defined(NDEBUG)
#define LOG_DEBUG(args...) \
    logger_file << LOG_PREFIX << "[DEBUG]: " << fmt::format(args) << std::endl;

#else
#define LOG_DEBUG(args...)
#endif  // NDEBUG

#define LOG_ERROR(args...) \
    logger_file << LOG_PREFIX << "[ERROR]: " << fmt::format(args) << std::endl;

#define LOG_INFO(args...) \
    logger_file << LOG_PREFIX << "[INFO]: " << fmt::format(args) << std::endl;

#define LOG_WARN(args...) \
    logger_file << LOG_PREFIX << "[WARN]: " << fmt::format(args) << std::endl;

#else

#if !defined(NDEBUG)
#define LOG_DEBUG(args...) \
    std::cout << LOG_PREFIX << "[DEBUG]: " << fmt::format(args) << std::endl;

#else
#define LOG_DEBUG(args...)
#endif  // NDEBUG

#define LOG_ERROR(args...) \
    std::cout << LOG_PREFIX << "[ERROR]: " << fmt::format(args) << std::endl;

#define LOG_INFO(args...) \
    std::cout << LOG_PREFIX << "[INFO]: " << fmt::format(args) << std::endl;

#define LOG_WARN(args...) \
    std::cout << LOG_PREFIX << "[WARN]: " << fmt::format(args) << std::endl;
#endif

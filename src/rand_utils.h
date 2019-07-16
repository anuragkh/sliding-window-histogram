#ifndef SLIDING_WINDOW_HISTOGRAM_RAND_UTILS_H
#define SLIDING_WINDOW_HISTOGRAM_RAND_UTILS_H

#include <cstdint>
#include <random>
#include <chrono>

class RandUtils {
 public:
  static double rand_double(const double &max);

  static double rand_double(const double &min, const double &max);

  static int64_t rand_int64(const int64_t &max);

  static int64_t rand_int64(const int64_t &min, const int64_t &max);

  static uint64_t rand_uint64(const uint64_t &max);

  static uint64_t rand_uint64(const uint64_t &min, const uint64_t &max);

  static int32_t rand_int32(const int32_t &max);

  static int32_t rand_int32(const int32_t &min, const int32_t &max);

  static uint32_t rand_uint32(const uint32_t &max);

  static uint32_t rand_uint32(const uint32_t &min, const uint32_t &max);
};

#endif //SLIDING_WINDOW_HISTOGRAM_RAND_UTILS_H

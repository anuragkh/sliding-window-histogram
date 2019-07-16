#include "rand_utils.h"

double RandUtils::rand_double(const double &max) {
  return rand_double(0, max);
}

double RandUtils::rand_double(const double &min, const double &max) {
  static thread_local std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_real_distribution<double> distribution(min, max);
  return distribution(generator);
}

int64_t RandUtils::rand_int64(const int64_t &max) {
  return rand_int64(0, max);
}

int64_t RandUtils::rand_int64(const int64_t &min, const int64_t &max) {
  static thread_local std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int64_t> distribution(min, max);
  return distribution(generator);
}

uint64_t RandUtils::rand_uint64(const uint64_t &max) {
  return rand_uint64(0, max);
}

uint64_t RandUtils::rand_uint64(const uint64_t &min, const uint64_t &max) {
  static thread_local std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<uint64_t> distribution(min, max);
  return distribution(generator);
}

int32_t RandUtils::rand_int32(const int32_t &max) {
  return rand_int32(0, max);
}

int32_t RandUtils::rand_int32(const int32_t &min, const int32_t &max) {
  static thread_local std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int32_t> distribution(min, max);
  return distribution(generator);
}

uint32_t RandUtils::rand_uint32(const uint32_t &max) {
  return rand_uint32(0, max);
}

uint32_t RandUtils::rand_uint32(const uint32_t &min, const uint32_t &max) {
  static thread_local std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<uint32_t> distribution(min, max);
  return distribution(generator);
}

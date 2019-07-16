#include <iostream>
#include "benchmark.h"

int main(int argc, char** argv) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " [window-size] [skew] [shift]" << std::endl;
    return 0;
  }
  size_t window_factor = std::stoull(argv[1]);
  double skew = std::stod(argv[2]);
  size_t k = std::stoull(argv[3]);
  size_t num_ops = Benchmark::shift_by_k(window_factor, skew, k);
  std::cout << window_factor << "\t" << skew << "\t" << k << "\t" << num_ops << "\n";
  return 0;
}
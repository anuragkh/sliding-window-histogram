#include <iostream>
#include "benchmark.h"

int main(int argc, char** argv) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " [window-size] [initial-skew] [final-skew]" << std::endl;
    return 0;
  }
  size_t window_factor = std::stoull(argv[1]);
  double init_skew = std::stod(argv[2]);
  double final_skew = std::stod(argv[3]);
  size_t num_ops = Benchmark::zipf_parameter(window_factor, init_skew, final_skew);
  std::cout << window_factor << "\t" << init_skew << "\t" << final_skew << "\t" << num_ops << "\n";
  return 0;
}
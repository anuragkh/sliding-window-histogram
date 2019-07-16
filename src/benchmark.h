#ifndef SLIDING_WINDOW_HISTOGRAM_BENCHMARK_H
#define SLIDING_WINDOW_HISTOGRAM_BENCHMARK_H

#include <cstddef>
#include <vector>
#include "zipf_generator.h"
#include "histogram_distribution.h"
#include "sliding_window_distribution.h"
#include "statistical_test.h"

class DefaultMapper {
 public:
  size_t operator()(size_t i) const {
    return i;
  }
};

class ShiftByKMapper {
 public:
  ShiftByKMapper(size_t shift, size_t n) : shift_(shift), n_(n) {}

  size_t operator()(size_t i) const {
    return (i + shift_) % n_;
  }

 private:
  size_t shift_;
  size_t n_;
};

class Benchmark {
 public:
  static const size_t DEFAULT_DOMAIN_SIZE = 1000000;

  template<typename KeyMapper = DefaultMapper>
  static size_t run(size_t domain_size,
                    size_t window_size,
                    double init_zipf_theta,
                    double final_zipf_theta,
                    const KeyMapper &mapper = KeyMapper()) {
    std::cerr << "Initializing initial zipf generator..." << std::endl;
    ZipfGenerator init_access_pattern_generator(init_zipf_theta, domain_size);

    std::cerr << "Initializing final zipf generator..." << std::endl;
    ZipfGenerator final_access_pattern_generator(final_zipf_theta, domain_size);

    std::cerr << "Creating running distribution..." << std::endl;
    auto running = new SlidingWindowDistribution(window_size, domain_size, init_access_pattern_generator);

    std::cerr << "Creating reference distribution..." << std::endl;
    auto ref = running->snapshot();

    std::cerr << "Running benchmark..." << std::endl;
    size_t num_ops = 0;
    double sup = 0.0, delta = 1.0 / (double) window_size, threshold = StatisticalTest::threshold(window_size);
    auto *running_cum = new double[domain_size];
    std::memcpy(running_cum, ref->cum(), domain_size * sizeof(double));
    do {
      auto added = mapper(final_access_pattern_generator.next()), removed = running->slide_one(added);
      auto beg = std::min(removed, added), end = std::max(removed, added);
      auto update = added > removed ? -delta : delta;
      for (size_t i = beg; i < end; ++i) {
        running_cum[i] += update;
        sup = std::max(sup, std::abs(running_cum[i] - ref->cum(i)));
      }
      ++num_ops;
    } while (sup < threshold);
    std::cerr << "Benchmark finished in num_ops=" << num_ops << std::endl;
    return num_ops;
  }

  static size_t zipf_parameter(size_t window_factor, double init_zipf_theta, double final_zipf_theta) {
    return run(DEFAULT_DOMAIN_SIZE, window_factor * DEFAULT_DOMAIN_SIZE, init_zipf_theta, final_zipf_theta);
  }

  static size_t shift_by_k(size_t window_factor, double zipf_theta, size_t k) {
    return run(DEFAULT_DOMAIN_SIZE,
               window_factor * DEFAULT_DOMAIN_SIZE,
               zipf_theta,
               zipf_theta,
               ShiftByKMapper(k, DEFAULT_DOMAIN_SIZE));
  }
};

#endif //SLIDING_WINDOW_HISTOGRAM_BENCHMARK_H

#ifndef SLIDING_WINDOW_HISTOGRAM_SLIDING_WINDOW_DISTRIBUTION_H
#define SLIDING_WINDOW_HISTOGRAM_SLIDING_WINDOW_DISTRIBUTION_H

#include <cstddef>
#include <list>
#include <vector>
#include "histogram_distribution_with_items.h"
#include "static_histogram_distribution.h"

class SlidingWindowDistribution : public HistogramDistributionWithItems {
 public:

  template <typename Generator>
  SlidingWindowDistribution(size_t window_size, size_t domain_size,
                            const Generator &init_access_pattern)
      : HistogramDistributionWithItems(domain_size), window_size_(window_size) {
    for (size_t i = 0; i < window_size; ++i) {
      add_item(init_access_pattern.next());
    }
  }

  size_t slide_one(size_t item);

  size_t window_size() const;

  StaticHistogramDistribution *snapshot() const;

 protected:
  size_t window_size_{};
};

#endif //SLIDING_WINDOW_HISTOGRAM_SLIDING_WINDOW_DISTRIBUTION_H

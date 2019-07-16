#include "sliding_window_distribution.h"

size_t SlidingWindowDistribution::slide_one(size_t item) {
  add_item(item);
  return remove_item();
}

StaticHistogramDistribution* SlidingWindowDistribution::snapshot() const {
  return new StaticHistogramDistribution(domain_size_, histogram_, num_items_);
}

size_t SlidingWindowDistribution::window_size() const {
  return window_size_;
}

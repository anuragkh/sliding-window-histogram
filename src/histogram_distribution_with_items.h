#ifndef SLIDING_WINDOW_HISTOGRAM_HISTOGRAM_DISTRIBUTION_WITH_ITEMS_H
#define SLIDING_WINDOW_HISTOGRAM_HISTOGRAM_DISTRIBUTION_WITH_ITEMS_H

#include <queue>
#include "histogram_distribution.h"

class HistogramDistributionWithItems : public HistogramDistribution {
 public:
  explicit HistogramDistributionWithItems(size_t domain_size);

  void add_item(size_t item);

  size_t remove_item();
 protected:
  std::queue<size_t> items_;
};

#endif //SLIDING_WINDOW_HISTOGRAM_HISTOGRAM_DISTRIBUTION_WITH_ITEMS_H

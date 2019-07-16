#include "histogram_distribution_with_items.h"

HistogramDistributionWithItems::HistogramDistributionWithItems(size_t domain_size)
    : HistogramDistribution(domain_size) {
}

void HistogramDistributionWithItems::add_item(size_t item) {
  ++histogram_[item];
  items_.push(item);
  num_items_++;
}

size_t HistogramDistributionWithItems::remove_item() {
  auto item = items_.front();
  --histogram_[item];
  items_.pop();
  --num_items_;
  return item;
}

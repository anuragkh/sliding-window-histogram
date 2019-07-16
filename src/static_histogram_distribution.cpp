#include "static_histogram_distribution.h"
#include "rand_utils.h"

StaticHistogramDistribution::StaticHistogramDistribution(size_t domain_size, const size_t *histogram, size_t num_items)
    : HistogramDistribution(domain_size), cum_(new double[domain_size]) {
  for (size_t i = 0; i < domain_size; ++i) {
    histogram_[i] = histogram[i];
    num_items_ += histogram_[i];
    cum_[i] = (double) num_items_ / (double) num_items;
  }
}

double StaticHistogramDistribution::cum(size_t item) {
  return cum_[item];
}

double *StaticHistogramDistribution::cum() const {
  return cum_;
}

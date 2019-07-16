#ifndef SLIDING_WINDOW_HISTOGRAM_STATIC_HISTOGRAM_DISTRIBUTION_H
#define SLIDING_WINDOW_HISTOGRAM_STATIC_HISTOGRAM_DISTRIBUTION_H

#include "histogram_distribution.h"

class StaticHistogramDistribution : public HistogramDistribution {
 public:
  StaticHistogramDistribution(size_t domain_size, const size_t *histogram, size_t num_items);

  double cum(size_t item);

  double* cum() const;
 private:
  double *cum_;
};

#endif //SLIDING_WINDOW_HISTOGRAM_STATIC_HISTOGRAM_DISTRIBUTION_H

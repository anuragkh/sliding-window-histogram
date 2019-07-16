#ifndef SLIDING_WINDOW_HISTOGRAM_HISTOGRAM_DISTRIBUTION_H
#define SLIDING_WINDOW_HISTOGRAM_HISTOGRAM_DISTRIBUTION_H

#include <vector>
#include <list>

class HistogramDistribution {
 public:
  explicit HistogramDistribution(size_t domain_size);
  HistogramDistribution(size_t domain_size, const size_t *histogram);

  ~HistogramDistribution();

  double prob(size_t item) const;

  void reset(size_t domain_size, const size_t *histogram);

  size_t num_items() const;
  size_t domain_size() const;
 protected:

  size_t domain_size_;
  size_t *histogram_;
  size_t num_items_;
};

#endif //SLIDING_WINDOW_HISTOGRAM_HISTOGRAM_DISTRIBUTION_H

#include "histogram_distribution.h"

HistogramDistribution::HistogramDistribution(size_t domain_size)
    : domain_size_(domain_size), histogram_(new size_t[domain_size]), num_items_(0) {
}

HistogramDistribution::HistogramDistribution(size_t domain_size, const size_t *histogram)
    : HistogramDistribution(domain_size) {
  for (size_t i = 0; i < domain_size; ++i) {
    histogram_[i] = histogram[i];
    num_items_ += histogram_[i];
  }
}

HistogramDistribution::~HistogramDistribution() {
  delete[] histogram_;
}

double HistogramDistribution::prob(size_t item) const {
  return (double) histogram_[item] / (double) num_items_;
}

void HistogramDistribution::reset(size_t domain_size, const size_t *histogram) {
  if (domain_size_ != domain_size) {
    domain_size_ = domain_size;
    delete[] histogram_;
    histogram_ = new size_t[domain_size];
  }
  for (size_t i = 0; i < domain_size; ++i) {
    histogram_[i] = histogram[i];
    num_items_ += histogram_[i];
  }
}

size_t HistogramDistribution::domain_size() const {
  return domain_size_;
}

size_t HistogramDistribution::num_items() const {
  return num_items_;
}


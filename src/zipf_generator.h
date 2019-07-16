#ifndef SLIDING_WINDOW_HISTOGRAM_ZIPF_GENERATOR_H
#define SLIDING_WINDOW_HISTOGRAM_ZIPF_GENERATOR_H

#include <cassert>
#include <cstdio>
#include <cmath>
#include <ctime>

class ZipfGenerator {
 public:
  // Constructor for zipf distribution
  ZipfGenerator(double theta, size_t n);

  ~ZipfGenerator();

  // Returns the next zipf value
  size_t next() const;

 private:
  // Generates the zipf probability distribution
  void generate_zipf();

  double theta_;       // The skew parameter (0=pure zipf, 1=pure uniform)
  size_t n_;         // The number of objects
  double *zdist_;

};

#endif //SLIDING_WINDOW_HISTOGRAM_ZIPF_GENERATOR_H

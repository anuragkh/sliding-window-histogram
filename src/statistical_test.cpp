#include "statistical_test.h"

#include <cmath>
#include <iostream>

double StatisticalTest::difference(StaticHistogramDistribution *ref, HistogramDistribution *running) {
  // KS-Statistic
  double sup = 0;
  double Y_cum = 0;
  for (size_t i = 0; i < ref->domain_size(); ++i) {
    Y_cum += running->prob(i);
    sup = std::max(sup, std::abs(Y_cum - ref->cum(i)));
  }
  return sup;
}

double StatisticalTest::threshold(size_t N, double alpha) {
  static CTable C_TABLE;
  return C_TABLE[alpha] * std::sqrt(2.0 / (double) N);
}

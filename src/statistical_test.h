#ifndef SLIDING_WINDOW_HISTOGRAM_STATISTICAL_TEST_H
#define SLIDING_WINDOW_HISTOGRAM_STATISTICAL_TEST_H

#include <unordered_map>
#include "sliding_window_distribution.h"
#include "static_histogram_distribution.h"

class StatisticalTest {
 public:
  struct CTable {
   public:
    CTable() {
      c_table_[0.1] = 1.22;
      c_table_[0.05] = 1.36;
      c_table_[0.025] = 1.48;
      c_table_[0.01] = 1.63;
      c_table_[0.005] = 1.73;
      c_table_[0.001] = 1.95;
    }

    double operator[](double alpha) {
      return c_table_[alpha];
    }

   private:
    std::unordered_map<double, double> c_table_;
  };

  static double difference(StaticHistogramDistribution* ref, HistogramDistribution* running);

  static double threshold(size_t N, double alpha = 0.05);
};

#endif //SLIDING_WINDOW_HISTOGRAM_STATISTICAL_TEST_H

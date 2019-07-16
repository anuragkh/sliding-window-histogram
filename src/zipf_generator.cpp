#include "zipf_generator.h"
#include "rand_utils.h"

ZipfGenerator::ZipfGenerator(double theta, size_t n) {
  // Ensure parameters are sane
  assert(n > 0);
  assert(theta >= 0.0);
  assert(theta <= 1.0);

  // srand (time(NULL));

  this->theta_ = theta;
  this->n_ = n;
  this->zdist_ = new double[n];
  this->generate_zipf();
}

ZipfGenerator::~ZipfGenerator() {
  delete[] zdist_;
}

size_t ZipfGenerator::next() const {
  double r = RandUtils::rand_double(1.0);
  int64_t lo = 0;
  int64_t hi = n_;
  while (lo != hi) {
    int64_t mid = (lo + hi) / 2;
    if (zdist_[mid] <= r) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }

  return lo;
}

void ZipfGenerator::generate_zipf() {
  double sum = 0.0;
  double c;
  double expo = 1.0 - theta_;
  double sumc = 0.0;
  uint64_t i;

  /*
   * zipfian - p(i) = c / i ^^ (1 - theta)
   * At theta = 1, uniform
   * At theta = 0, pure zipfian
   */

  for (i = 1; i <= n_; i++) {
    sum += 1.0 / pow((double) i, (double) (expo));

  }
  c = 1.0 / sum;

  for (i = 0; i < n_; i++) {
    sumc += c / pow((double) (i + 1), (double) (expo));
    zdist_[i] = sumc;
  }
}

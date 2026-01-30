#include <chrono>
#include <iostream>
#include <random>

using namespace std;
using namespace std::chrono;

int main() {
  //  See:  https://cplusplus.com/reference/random/

  cout << "--- Mersenne Twister 19937 generator (64 bit) -------" << endl;

  // "True" random number generator (class)
  random_device rd;
  // Mersenne Twister 19937 generator (64 bit) with rd setting the seed.
  mt19937_64 gen(rd());
  // Distribution, uniform on doubles.
  uniform_real_distribution<double> rng(-1.0, 1.0);

  // Get random value.  Generator sent into a distribution.
  double x = rng(gen);
  cout << x << endl;

  uniform_real_distribution<double> rng2(-5.0, 5.0);
  // Get random value.  Same generator different distribution.
  cout << rng2(gen) << endl;

  uniform_int_distribution<> rngint(1, 20);

  // Get random values.  Same generator different distribution.
  for (int i = 0; i < 10; i++)
    cout << rngint(gen) << " ";
  cout << endl;

  cout << "--- Linear congruential generator m, a, mod -------" << endl;

  // Linear congruential generator.
  linear_congruential_engine<uint_fast32_t, 48271, 12345, 2147483647> gen2(
      rd());

  uniform_int_distribution<> rngint2(1, 20);
  for (int i = 0; i < 10; i++)
    cout << rngint2(gen2) << " ";
  cout << endl;

  cout << "--- Setting the seed -------" << endl;

  // Set your own seed, same sequence on every run.
  gen2.seed(12345);
  for (int i = 0; i < 10; i++)
    cout << rngint2(gen2) << " ";
  cout << endl;

  // Set the seed by the clock.
  typedef std::chrono::high_resolution_clock myclock;
  myclock::time_point beginning;
  auto elapsed = duration_cast<microseconds>(myclock::now() - beginning);
  unsigned seed2 = elapsed.count();

  gen2.seed(seed2);
  for (int i = 0; i < 10; i++)
    cout << rngint2(gen2) << " ";
  cout << endl;

  for (int i = 0; i < 10; i++)
    cout << rngint2(gen) << " ";
  cout << endl;

  cout << "--- Default generator m, a, mod -------" << endl;

  default_random_engine dgen(rd());
  uniform_int_distribution<int> die(1, 6);

  for (int i = 0; i < 10; i++)
    cout << die(dgen) << " ";
  cout << endl;

  uniform_int_distribution<int> udist(0, 9);
  vector<int> counts(10);
  for (int i = 0; i < 1000000; i++)
    counts[udist(dgen)]++;

  for (int i = 0; i < 10; i++)
    cout << counts[i] << endl;
  cout << endl;

  for (int i = 0; i < 10; i++)
    counts[i] = 0;

  cout << "--- Other distributions -------" << endl;

  normal_distribution<double> ndist(5, 2);
  for (int i = 0; i < 1000000; i++) {
    double num = floor(ndist(dgen));
    if (num <= 9 && num >= 0)
      counts[num]++;
  }

  for (int i = 0; i < 10; i++)
    cout << counts[i] << endl;
  cout << endl;

  return 0;
}

#include <primesieve.hpp>
#include <iostream>
#include <vector>

int main()
{
  // store primes between 1000 and 2000
  std::vector<int> primes;
  primesieve::generate_primes(1000, 2000, &primes);

  for (auto i: primes) {
  	std::cout << i << std::endl;
  }

  return 0;
}
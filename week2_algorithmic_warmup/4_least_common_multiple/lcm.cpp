#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcb_euclid_internal(long long a, long long b) 
{
  long long remainder = a % b;

  if (remainder == 0)
    return b;

  a = b;
  b = remainder;

  //std::cout << a << " " << b << std::endl;

  return gcb_euclid_internal(a, b);
}

long long gcd_euclid(long long a, long long b)
{
  if (a < 1 || b < 1)
    return -1;

  long long temp_a = a > b ? a : b;
  long long temp_b = a > b ? b : a;

  return gcb_euclid_internal(temp_a, temp_b);
}

long long lcm_fast(long long a, long long b) {
  long long greatestCommonDivisor = gcd_euclid(a, b);

  if (greatestCommonDivisor <= 0)
    return 0;

  return (a * b) / greatestCommonDivisor;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}

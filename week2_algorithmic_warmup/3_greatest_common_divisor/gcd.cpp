#include <iostream>

int gcd_naive(int a, int b)
{
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++)
    {
      if (a % d == 0 && b % d == 0)
      {
        if (d > current_gcd)
        {
          current_gcd = d;
        }
      }
    }
    return current_gcd;
}

int gcb_euclid_internal(int a, int b) 
{
    int remainder = a % b;

    if (remainder == 0)
      return b;

    a = b;
    b = remainder;

    //std::cout << a << " " << b << std::endl;

    return gcb_euclid_internal(a, b);
}

int gcd_euclid(int a, int b)
{
    if (a < 1 || b < 1)
      return -1;

    int temp = a > b ? a : b;
    a = temp;
    b = b < a ? b : a;

    return gcb_euclid_internal(a, b);
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd_euclid(a, b) << std::endl;
    return 0;
}

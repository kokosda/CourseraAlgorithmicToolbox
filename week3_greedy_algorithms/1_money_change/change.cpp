#include <iostream>

/*
Task. The goal in this problem is to find the minimum number of coins needed to change the input value
(an integer) into coins with denominations 1, 5, and 10.
Input Format. The input consists of a single integer 𝑚.
Constraints. 1 ≤ 𝑚 ≤ 10^3.
Output Format. Output the minimum number of coins with denominations 1, 5, 10 that changes 𝑚.
*/

int get_change(int m) {
  //write your code here
  int n = m / 10;
  int remainder = m % 10;

  if (remainder >= 5) {
    remainder -= 5;
    n += 1;
  }

  n += remainder;

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

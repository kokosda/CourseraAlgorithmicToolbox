#include <iostream>
#include <vector>

using std::vector;

int get_change(int money) {
  const vector<int> COINS { 1, 3, 4 };
  const int END = 1000000; 
  vector<int> min_num_coins(money);
  min_num_coins[0] = 0;
  int num_coins = 0;
  size_t coins_size = COINS.size();

  for (int m = 1; m < money; m++) {
    min_num_coins[m] = END;

    for (int i = 0; i < coins_size; i++) {
      if (m >= COINS[i]) {
        num_coins = min_num_coins[m - COINS[i]] + 1;

        if (num_coins < min_num_coins[m]) {
          min_num_coins[m] = num_coins;
        }
      }
    }
  }

  int result = min_num_coins[money - 1];
  return result;
}

int main() {
  int m;
  std::cin >> m;
  // m = 34;
  std::cout << get_change(m) << '\n';
  system("pause");
  return 0;
}

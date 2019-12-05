#include <iostream>
#include <vector>

using std::vector;

const static vector<int> COINS { 1, 3, 4 };
const static int END = 1000000;

int get_change(int money) {
  vector<int> min_num_coins(money);
  // min_num_coins.push_back(0);
  int num_coins = 0;
  size_t coins_size = COINS.size();

  for (int m = 1; m <= money; m++) {
    // min_num_coins.push_back(END);
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
  return min_num_coins[money];
}

int main() {
  int m;
  // std::cin >> m;
  m = 34;
  std::cout << get_change(m) << '\n';
  system("pause");
  return 0;
}

#include <iostream>
#include <vector>

using std::vector;

const int ROW_MAX = 1000 + 1;
const int COL_MAX = 300 + 1;

int optimal_weight(int W, const vector<int> &w) {
  int value[ROW_MAX][COL_MAX];
  size_t n = w.size();

  for (size_t j = 0; j <= n; j++) {
    value[0][j] = 0;
  }

  for (int w = 0; w <= W; w++) {
    value[w][0] = 0;
  }

  int val, wi, vi;

  for (size_t i = 1; i <= n; i++) {
    for (int w = 1; w <= W; i++) {
      value[w][i] = wi = value[w][i - 1];

      if (wi <= w) {
        val = value[w - wi][i - 1];
      }
    }
  }

  int result = 0;
  return result;
}

void insert_data(int &W, vector<int> &w) {
  W = 10;
  w = { 1, 4, 8 };
}

int main() {
  int n, W;
  // std::cin >> W >> n;
  vector<int> w(n);
  // for (int i = 0; i < n; i++) {
  //   std::cin >> w[i];
  // }
  insert_data(W, w);
  std::cout << optimal_weight(W, w) << '\n';
  system("pause");
  return 0;
}

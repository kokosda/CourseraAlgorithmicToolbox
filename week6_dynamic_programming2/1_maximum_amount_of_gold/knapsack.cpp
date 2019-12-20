#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

const int WEIGHT_MAX = 1000 + 1;
const int ITEMS_COUNT_MAX = 300 + 1;

void show_results(int distance[][WEIGHT_MAX], int n, int m) {
  bool enabled = true;

  if (!enabled) {
    return;
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      std::cout << distance[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int optimal_weight(int W, const vector<int> &w) {
  int weights[ITEMS_COUNT_MAX][WEIGHT_MAX];
  const int w_size = w.size();

  for (int i = 0; i <= w_size; i++) {
    weights[i][0] = 0;
  }

  for (int i = 0; i <= W; i++) {
    weights[0][i] = 0;
  }

  int prev, cur;

  for (int i = 1; i <= w_size; i++) {
    for (int j = 1; j <= W; j++) {
      if (j >= w[i]) {
        weights[i][j] = w[i] + weights[i - 1][j - w[i]];
        show_results(weights, w_size, W);
      }
      else {
        weights[i][j] = weights[i - 1][j];
        show_results(weights, w_size, W);
      }
    }
  }

  int result = weights[w_size][W];
  return result;
}

int optimal_weight_2(int W, const vector<int> &w) {
  int weights[ITEMS_COUNT_MAX][WEIGHT_MAX];
  const int w_size = w.size();

  for (int i = 0; i <= w_size; i++) {
    weights[i][0] = 0;
  }

  for (int i = 0; i <= W; i++) {
    weights[0][i] = 0;
  }

  int value, val;

  for (int i = 1; i <= w_size; i++) {
    for (int j = 1; j <= W; j++) {
      value = weights[i - 1][j];

      if (w[i] <= j) {
        val = (weights[i - 1][j - w[i]]) + w[i];

        if (value < val) {
          value = val;
        }

        weights[i][j] = value;
      }

      show_results(weights, w_size, W);
    }
  }

  int result = weights[w_size][W];
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
  std::cout << optimal_weight_2(W, w) << '\n';
  system("pause");
  return 0;
}

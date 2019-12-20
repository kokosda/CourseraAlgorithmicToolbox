#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

const int WEIGHT_MAX = 1000 + 1;
const int ITEMS_COUNT_MAX = 300 + 1;

void show_weights(int weights[][WEIGHT_MAX], int n, int m) {
  bool enabled = false;

  if (!enabled) {
    return;
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      std::cout << weights[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int optimal_weight_3(int W, const vector<int> &w) {
  int weights[ITEMS_COUNT_MAX][WEIGHT_MAX];
  const int w_size = w.size();

  for (int i = 1; i <= w_size; i++) {
    for (int j = 1; j <= W; j++) {      
        if (i==0 || j==0) 
          weights[i][j] = 0;
        else if (w[i - 1] <= j) 
          weights[i][j] = std::max(w[i - 1] + weights[i - 1][j - w[i - 1]],  weights[i - 1][j]);
        else
          weights[i][j] = weights[i - 1][j];

      show_weights(weights, w_size, W);
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
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  // insert_data(W, w);
  std::cout << optimal_weight_3(W, w) << '\n';
  system("pause");
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using std::vector;

const int WEIGHT_MAX = 10000 + 1;
const int ITEMS_COUNT_MAX = 300 + 1;

void show_vector(const vector<int> &a, std::string name) {
  bool enabled = false;

  if (!enabled)
    return;

  std::cout << name << " size " << a.size() << ": ";
  for (int i = 0; i < a.size(); i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

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

int optimal_weight(int W, const vector<int> &w) {
  int weights[ITEMS_COUNT_MAX][WEIGHT_MAX];
  const int w_size = w.size();

  for (int i = 0; i <= w_size; i++) {
    for (int j = 0; j <= W; j++) {      
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

int optimal_weight_2(int W, const vector<int> &w) {
  int weights[ITEMS_COUNT_MAX][WEIGHT_MAX];
  const int w_size = w.size();

  for (int i = 0; i <= w_size; i++) {
    weights[i][0] = 0;
  }

  for (int i = 0; i <= W; i++) {
    weights[0][i] = 0;
  }

  for (int i = 1; i <= w_size; i++) {
    for (int j = 1; j <= W; j++) {              
        weights[i][j] = weights[i - 1][j];

        if (weights[i][j] <= j)
          weights[i][j] = std::max(weights[i][j], weights[j - weights[i][j]][i - 1]);

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

void insert_data_2(int &W, vector<int> &w) {
  W = 24;
  w = { 122, 183, 195 };
}

void insert_data_random(int &W, vector<int> &w) {
  srand(time(NULL));
  W = rand() % 780 - 1 + 100;
  int w_size = rand() % 9 + 1;
  int weight = rand() % 83 + 100;
  w.push_back(weight);

  while(w.size() < w_size) {
    bool isPresented = true;

    while(isPresented) {
      weight = rand() % 83;
      int i = 0;

      while(i < w.size()) {
        if (w[i] == weight) {
          isPresented = true;
          break;
        }
        else {
          isPresented = false;
        }

        ++i;
      }
    }

    w.push_back(weight);
  }

  std::sort(w.begin(), w.end());
}

int main() {
  int n = 0, W;
  std::cin >> W >> n;
  vector<int> w(n);
  // for (int i = 0; i < n; i++) {
  //   std::cin >> w[i];
  // }
  // insert_data(W, w);
  // std::cout << "W=" << W << std::endl;
  // show_vector(w, "w");
  std::cout << optimal_weight(W, w) << '\n';
  // system("pause");
  return 0;
}

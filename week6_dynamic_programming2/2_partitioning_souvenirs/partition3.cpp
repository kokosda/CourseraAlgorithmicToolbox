#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

const int VALUE_MAX = 300 + 1;
const int ITEMS_COUNT_MAX = 200 + 1;

void show_vector(const vector<int> &a, std::string name) {
  bool enabled = true;

  if (!enabled)
    return;

  std::cout << name << " size " << a.size() << ": ";
  for (int i = 0; i < a.size(); i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

void show_2d_array(int weights[][VALUE_MAX], int n, int m) {
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

vector<int> get_optimal_weight(int W, const vector<int> &w, int &optimal_weight) {
  int weights[ITEMS_COUNT_MAX][VALUE_MAX];
  const int w_size = w.size();

  for (int i = 0; i <= w_size; i++) {
    for (int j = 0; j <= W; j++) {
        if (i==0 || j==0)
          weights[i][j] = 0;
        else if (w[i - 1] <= j)
          weights[i][j] = std::max(w[i - 1] + weights[i - 1][j - w[i - 1]],  weights[i - 1][j]);
        else
          weights[i][j] = weights[i - 1][j];
    }
  }

  optimal_weight = weights[w_size][W];
  int temp_optimal_weight = optimal_weight;
  int temp_w = W;
  vector<int> result;

  for (int i = w_size; i > 0 && temp_optimal_weight > 0; i--) {
    if (temp_optimal_weight == weights[i - 1][temp_w]) {
      continue;
    }
    else {
        result.push_back(w[i - 1]);
        temp_optimal_weight = temp_optimal_weight - w[i - 1]; 
        temp_w = temp_w - w[i - 1]; 
    }
  }

  show_vector(result, "backtrace");

  return result;
}

int partition3(vector<int> &A) {
  int total = 0;
  int A_size = A.size();

  for (int i = 0; i < A_size; i++) {
    total += A[i];
  }

  if (total % 3) {
    return 0;
  }

  int W = total / 3;
  int i = 3;
  vector<int> copy_A(A);

  show_vector(copy_A, "copy_A");

  for (int i = 3; i > 0; i--) {
    int optimal_weight = 0;
    vector<int> backtrace = get_optimal_weight(W, copy_A, optimal_weight);

    if (optimal_weight != W) {
      return 0;
    }

    for (int i = 0; i < backtrace.size(); i++) {
      std::vector<int>::iterator position = std::find(copy_A.begin(), copy_A.end(), backtrace[i]);
      if (position != copy_A.end()) {
          copy_A.erase(position);
      }
    }
    show_vector(copy_A, "copy_A");
  }

  return 1;
}

void insert_data(vector<int> &A) {
  A = { 17, 59, 34, 57, 17, 23, 67, 1, 18, 2, 59 };
  // 34 + 67 + 17 = 23 + 59 + 1 + 17 + 18 = 59 + 2 + 57.
}

int main() {
  int n = 0;
  // std::cin >> n;
  vector<int> A(n);
  insert_data(A);
  // for (size_t i = 0; i < A.size(); ++i) {
  //   std::cin >> A[i];
  // }
  std::cout << partition3(A) << '\n';
  system("pause");
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

const int VALUE_MAX = 30 + 1;
const int ITEMS_COUNT_MAX = 20 + 1;

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

void show_1d_array(bool* array, int n, std::string name) {
  bool enabled = false;

  if (!enabled) {
    return;
  }
  
  std::cout << name << " size " << n << ": ";
  for (int i = 0; i < n; i++) {
      std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void show_1d_array(int* array, int n, std::string name) {
  bool enabled = false;

  if (!enabled) {
    return;
  }
  
  std::cout << name << " size " << n << ": ";
  for (int i = 0; i < n; i++) {
      std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void show_2d_array(int array[][VALUE_MAX], int n, int m) {
  bool enabled = false;

  if (!enabled) {
    return;
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      std::cout << array[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void show_2d_array(bool** array, int n, int m) {
  bool enabled = true;

  if (!enabled) {
    return;
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      std::cout << array[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool partition3 (vector<int> &A) {
  const int k = 3;
  int N = A.size();

  std::sort(A.begin(), A.end());

  int sum = 0;

  for (int i = 0; i < N; i++) {
    sum += A[i];
  }

  int target = sum / k;

  if (sum % k > 0 || A[N - 1] > target)
    return false;

  int size = 1 << N;
  bool* dp = new bool[size];
  dp[0] = true;

  for (int i = 1; i < size; i++) {
    dp[i] = false;
  }

  int* total = new int[size];

  for (int i = 0; i < size; i++) {
    total[i] = 0;
  }

  for (int state = 0; state < size; state++) {
      if (!dp[state]) {
        continue;
      }
        
      for (int i = 0; i < N; i++) {
          int future = state | (1 << i);

          if (state != future && !dp[future]) {
              if (A[i] <= target - (total[state] % target)) {
                  dp[future] = true;
                  total[future] = total[state] + A[i];
                  show_1d_array(dp, size, "dp");
                  show_1d_array(total, size, "tl");
              } else {
                  break;
              }
          }
      }
  }
  
  bool result = dp[size - 1];
  delete[] dp, total;
  return result;
}

void insert_data(vector<int> &A) {
  // A = { 17, 59, 34, 57, 17, 23, 67, 1, 18, 2, 59 };
  A = { 3, 3, 3 };
  // 34 + 67 + 17 = 23 + 59 + 1 + 17 + 18 = 59 + 2 + 57.
  // A = { 23, 23, 23, 11, 11, 11, 4, 4, 4, 7, 7, 7, 17, 17, 17 };
  // A = { 23, 23, 11, 11, 4, 4, 7, 7, 17, 17 };
}

int main() {
  int n = 0;
  std::cin >> n;
  vector<int> A(n);
  // insert_data(A);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
  system("pause");
  return 0;
}

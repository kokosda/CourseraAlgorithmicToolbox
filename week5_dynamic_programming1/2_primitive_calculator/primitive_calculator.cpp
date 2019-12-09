#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } 
    else if (n > 3 && ((n - 1) % 3 == 0)) {
      n = n - 1;
    }
    else if (n % 2 == 0) {
      n /= 2;
    }
    else if (n > 2 && ((n - 1) % 2 == 0)) {
      n = n - 1;
    }
    else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

const vector<int> OPERATIONS = { 1, 2, 3};

int get_operation_result(int m, int operation_index) {
  if (operation_index == 0)
    return m + OPERATIONS[operation_index];
  else
    return m * OPERATIONS[operation_index];
}

vector<int> optimal_sequence_dynamic(int n) {
  const int END = -1; 
  vector<int> sequence(n + 1);
  vector<int> result_sequence;
  sequence[0] = 1;
  int num_operations = 0;
  size_t operations_size = OPERATIONS.size();

  for (int m = 1; m <= n; m++) {
    sequence[m] = END;

    for (int i = 0; i < operations_size; i++) {
      int operation_result = get_operation_result(m, i);

      if (operation_result)
      sequence[m] = std::max(sequence[m], operation_result);
    }
  }

  return result_sequence;
}

// 1 3 9 11

int main() {
  int n;
  // std::cin >> n;
  n = 10;
  vector<int> sequence = optimal_sequence_dynamic(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  std::cout << std::endl;
  system("pause");
}

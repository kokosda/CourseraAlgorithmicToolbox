#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

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

vector<int> optimal_sequence_dynamic(int n) {
    vector<int> arr(n + 1);
    arr[0] = 0;
    size_t arr_size = arr.size();
    vector<int> sequence;

    for (int i = 1; i < arr_size; i++) {
        arr[i] = arr[i - 1] + 1;

        if (i % 2 == 0) {
          arr[i] = std::min(arr[i / 2] + 1, arr[i]);
        }

        if (i % 3 == 0) {
          arr[i] = std::min(arr[i / 3] + 1, arr[i]); 
        }
    }

    // show_vector(arr, "arr");

    int i = n;
    while (i > 1) {
        sequence.push_back(i);

        if (arr[i - 1] == arr[i] - 1) {
            i = i - 1;
        }
        else if (i % 2 == 0 && (arr[i / 2] == arr[i] - 1)) {
            i = i / 2; 
        }
        else if (i % 3 == 0 && (arr[i / 3] == arr[i] - 1)) {
            i = i / 3;
        }
    }

    sequence.push_back(1);
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

// 1 3 9 11

int main() {
  int n;
  std::cin >> n;
  // n = 96234;
  vector<int> sequence = optimal_sequence_dynamic(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  // std::cout << std::endl;
  // system("pause");
}

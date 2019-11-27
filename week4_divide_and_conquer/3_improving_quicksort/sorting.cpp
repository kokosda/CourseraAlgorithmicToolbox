#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

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

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
      show_vector(a, "swap2");
    }
  }
  swap(a[l], a[j]);
  show_vector(a, "swap3");
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  show_vector(a, "swap1");
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

void insert_data_set_1(vector<int>& a) {
  a = vector<int> { 2, 3, 9, 2, 2 };
}

int main() {
  int n;
  // std::cin >> n;
  vector<int> a;
  insert_data_set_1(a);
  // for (size_t i = 0; i < a.size(); ++i) {
  //   std::cin >> a[i];
  // }
  show_vector(a, "origin");
  srand(NULL);
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
  system("pause");
  return 0;
}

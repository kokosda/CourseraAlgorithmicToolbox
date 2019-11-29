#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

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
  const int x = a[l];
  int j = l;

  std::cout << "l=" << l << " r=" << r << " x=" << x << " j=" << j << std::endl;

  for (int i = l + 1; i <= r; i++) {
    std::cout << "a[i=" << i << "]=" << a[i] << " ";
    if (a[i] <= a[l]) {
      j++;
      std::cout << "\na[j=" << j << "]=" << a[j] << std::endl;
      show_vector(a, "swap2 - before");
      swap(a[i], a[j]);
      show_vector(a, "swap2 - after");
    }
  }
  show_vector(a, "swap3 - before");
  swap(a[l], a[j]);
  show_vector(a, "swap3 - after");
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    std::cout << "l >= r" << " (" << l << ", " << r << ")" << std::endl;
    return;
  }

  int k = l + rand() % (r - l + 1);
  std::cout << "k=" << k << std::endl;
  swap(a[l], a[k]);
  show_vector(a, "swap1");
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

std::pair<int, int> partition3(vector<int> &a, int left, int middle, int right) {
  std::cout << "left=" << left << " right=" << right << " a[" << left << "]=" << a[left] << " a[" << right << "]" << std::endl;

  int j = left;

  for (int i = left + 1; i <= right; i++) {
    if (a[i] < a[left]) {
      j++;
      std::cout << "\na[j=" << j << "]=" << a[j] << std::endl;
      show_vector(a, "swap j - before");
      swap(a[i], a[j]);
      show_vector(a, "swap j - before");
    }
  }

  int p = middle;

  for (int i = left + 1; i <= right; i++) {
    if (a[i] == a[middle]) {
      p++;
      std::cout << "\na[p=" << p << "]=" << a[p] << std::endl;
      show_vector(a, "swap p - before");
      swap(a[i], a[p]);
      show_vector(a, "swap p - after");
    }
  }

  swap(a[left], a[j]);
  swap(a[middle], a[p]);
  return std::pair<int, int>(j, p);
}

void randomized_quick_sort_3(vector<int> &a, int left, int middle, int right) {
  if (left >= middle) {
    std::cout << "left >= right" << " (" << left << ", " << right << ")" << std::endl;
    return;
  }

  if (middle >= right) {
    std::cout << "middle >= right" << " (" << middle << ", " << right << ")" << std::endl;
    return;
  }

  int k = left + rand() % (right - left + 1);
  std::cout << "k1=" << k << std::endl;
  swap(a[left], a[k]);
  show_vector(a, "swap k1");
  k = left + rand() % (right - left + 1);
  std::cout << "k2=" << k << std::endl;
  swap(a[middle], a[k]);
  show_vector(a, "swap k2");
  std::pair<int, int> pair = partition3(a, left, middle, right);
  int m1 = pair.first;
  int m2 = pair.second;

  randomized_quick_sort_3(a, left, m2, m1 - 1);
  randomized_quick_sort_3(a, m1 + 1, m2, right);
}

void insert_data_set_1(vector<int>& a) {
  a = vector<int> { 1, 3, 9, 2, 2 };
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
  srand(time(NULL));

  randomized_quick_sort_3(a, 0, a.size() / 2, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
  system("pause");
  return 0;
}

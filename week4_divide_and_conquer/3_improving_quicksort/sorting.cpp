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

std::pair<int, int> partition3(vector<int> &a, int l, int r) {
  int lt = l;
  int i = l;
  int gt = r;
  int pivot = a[l];

  while (i <= gt) {
    if (a[i] < pivot) {
      swap(a[lt], a[i]);
      lt++;
      i++;
    }
    else if (a[i] > pivot) {
      swap(a[i], a[gt]);
      gt--;
    }
    else
    {
      i++;
    }    
  }

  return std::pair<int, int>(lt, gt);
}

void randomized_quick_sort_3(vector<int> &a, int l, int r) {
  if (l >= r) {
    // std::cout << "l >= r" << " (" << l << ", " << r << ")" << std::endl;
    return;
  }

  int k = l + rand() % (r - l + 1);
  // std::cout << "k=" << k << std::endl;
  swap(a[l], a[k]);
  // show_vector(a, "swap1");
  std::pair<int, int> m = partition3(a, l, r);
  int lt = m.first;
  int gt = m.second;

  randomized_quick_sort_3(a, l, lt - 1);
  randomized_quick_sort_3(a, gt + 1, r);
}

void insert_data_set_1(vector<int>& a) {
  a = vector<int> {1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4};
}

void insert_data_set_2(vector<int>& a) {
  srand(time(NULL));
  a = vector<int>(rand() % 2 + 100000);
  size_t size = a.size();

  for(size_t i = 0; i < size; i++) {
    a[i] = rand() % 60000;
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  // insert_data_set_2(a);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  // show_vector(a, "origin");
  srand(time(NULL));

  randomized_quick_sort_3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
  // system("pause");
  return 0;
}

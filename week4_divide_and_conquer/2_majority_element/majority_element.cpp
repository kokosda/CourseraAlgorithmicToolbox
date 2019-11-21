#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

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

int merge(vector<int> &b1, vector<int> &c1, int b, int c, const int &m) {
  if (b == c)
    return b;

  vector<int> v;
  int value = -2;
  int oppositeValue = -2;
  
  if (b == -1) {
    v = b1;
    value = c;
  }
  else if (c == -1) {
    v = c1;
    value = b;
  }

  int vSize = v.size();
  int index = 0;
  int approveCount = (b1.size() == c1.size() || b1.size() == 2 || c1.size() == 2) ? 1 : 2;

  while (index < vSize) {
    if (v[index] == value) {
        approveCount--;
        if (approveCount == 0) {
          return value;
        }
    }
    index++;
  }

  return -1;
}

int get_majority_element(vector<int> &a) {
  if (a.size() == 1)
    return a[0];
  if (a.size() == 2)
    return a[0] == a[1] ? a[0] : -1;

  const int aSize = a.size();
  const size_t m = (aSize % 2) == 0 ? aSize / 2 : (aSize / 2) + 1;

  vector<int> b1 (a.begin(), a.begin() + m);
  show_vector(b1, "b1");
  vector<int> c1 (a.begin() + m, a.end());
  show_vector(c1, "c1");

  int b = get_majority_element(b1);
  int c = get_majority_element(c1);

  int result = merge(b1, c1, b, c, m);
  std::cout << "result=" << result << " [b=" << b << ", c=" << c << "]" << std::endl;
  return result;
}

void insert_data_set_1(vector<int>& a) {
  // a = vector<int> { 8, 3, 8, 36, 8, 24, 1, 8, 5, 8, 8, 8, 1, 8, 8, 8, 8 };
  // a = vector<int> { 1, 2, 3, 4 };
  // a = vector<int> { 4, 4, 1, 1, 1, 4 };
  // a = vector<int> { 1, 1, 2, 4, 1, 4, 1 };
  a = vector<int> { 1, 1, 4, 2, 1 };
  // a = vector<int> { 3, 3, 4, 4, 4, 3, 3 };
  // a = vector<int> { 2, 1, 2, 0, 0, 1, 2, 2, 1, 0, 2 };
}

void insert_data_set_2(vector<int>& a) {
  srand(time(NULL));
  a = vector<int>(rand() % 2 + 10);
  size_t size = a.size();

  for(size_t i = 0; i < size; i++) {
    a[i] = rand() % 3;
  }
}

int main() {
  int n;
  // std::cin >> n;
  vector<int> a;
  insert_data_set_1(a);
  // a = vector<int>(n);
  show_vector(a, "initial");
  // for (size_t i = 0; i < a.size(); ++i) {
  //   std::cin >> a[i];
  // }
  std::cout << (get_majority_element(a) != -1) << '\n';
  system("pause");
  return 0;
}

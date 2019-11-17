#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  //write your code here
  return 0;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) 
      return i;
  }
  return -1;
}

void insert_capacities_data_set_1(int &n, int &m) {
  n = 5;
  m = 5;
}

void insert_data_set_1(vector<int> &a, vector<int> &b) {
  a[0] = 1;
  a[1] = 5;
  a[2] = 8;
  a[3] = 12;
  a[4] = 13;

  b[0] = 8;
  b[1] = 1;
  b[2] = 23;
  b[3] = 1;
  b[4] = 11;
}

int main() {
  int n;
  int m;
  insert_capacities_data_set_1(n, m);
  // std::cin >> n;
  vector<int> a(n);
  // for (size_t i = 0; i < a.size(); i++) {
  //   std::cin >> a[i];
  // }
  // std::cin >> m;
  vector<int> b(m);
  // for (int i = 0; i < m; ++i) {
  //   std::cin >> b[i];
  // }
  insert_data_set_1(a, b);
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << linear_search(a, b[i]) << ' ';
  }
  std::cout << std::endl;
  system("pause");
  return 0;
}

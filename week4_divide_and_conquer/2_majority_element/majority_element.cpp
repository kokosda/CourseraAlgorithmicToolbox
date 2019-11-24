#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using std::vector;

const int NO_MAJORITY = -1;

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

int merge(vector<int> &a, int b, int c, int leftB, int rightB, int leftC, int rightC) {
  if (b == c)
    return b;

  if (c == NO_MAJORITY) {
    int sizeB = rightB - leftB + 1;
    int sizeC = rightC - leftC + 1;

    if (sizeB > sizeC)
      return b;
  }

  int v = 0, w = NO_MAJORITY;

  if (b == NO_MAJORITY) {
    v = c;
  }
  else if (c == NO_MAJORITY) {
    v = b;
  }
  else {
    v = b;
    w = c;
  }
  
  int countV = 0, countW = 0, index = 0;
  int size = a.size();
  int innerM = size / 2;

  while (index < size) {
      if (a[index] == v) {
        countV++;
        if (countV > innerM)
          return v;
      }
      else if (w != NO_MAJORITY && a[index] == w) {
        countW++;
        if (countW > innerM)
          return w;
      }

    index++;
  }

  return NO_MAJORITY;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right)
    return a[left];
  if ((left + 1) == right)
    return a[left] == a[right] ? a[left] : NO_MAJORITY;

  const int size = right - left + 1;
  const size_t m = ((size % 2) == 0 ? size / 2 : (size / 2) + 1) + (left == 0 ? 0 : (left - 1));

  // std::cout << "size " << size << " left " << left << " right " << right << " m " << m << std::endl;

  int b = get_majority_element(a, left, m - 1);
  int c = get_majority_element(a, m, right);
  int leftB = left;
  int rightB = m - 1;
  int leftC = m;
  int rightC = right;

  int result = merge(a, b, c, leftB, rightB, leftC, rightC);
  // std::cout << "result=" << result << " l=" << left << " r=" << right << " [b=" << b << ", c=" << c << "]" << std::endl;
  return result;
}

int merge_2(vector<int> &a, int v, size_t lo, size_t hi) {
  int count = 0;
  for (int i = lo; i <= hi; i++) {
    if (a[i] == v) {
      count++;
    }
  }
  return count;
}

int get_majority_element_2(vector<int> &a, size_t lo, size_t hi) {
  if (lo == hi) {
    return a[lo];
  }

  int m = (hi - lo) / 2 + lo;
  int left = get_majority_element_2(a, lo, m);
  int right = get_majority_element(a, m + 1, hi);

  std::cout << "lo " << lo << " hi " << hi << " left " << left << " right " << right << " m " << m << std::endl;

  if (left == right) {
    return left;
  }

  int leftCount = merge_2(a, left, lo, m);
  int rightCount = merge_2(a, right, m + 1, hi);

  if (leftCount == rightCount) {
    return NO_MAJORITY;
  }

  int result = leftCount > rightCount ? left : right;

  std::cout << "lo " << lo << " hi " << hi << " left " << left << " right " << right << " m " << m << " leftCount " << leftCount << " rightCount " << rightCount << std::endl;

  return result;
}

void insert_data_set_1(vector<int>& a) {
  // a = vector<int> { 8, 3, 8, 36, 8, 24, 1, 8, 5, 8, 8, 8, 1, 8, 8, 8, 8 };
  // a = vector<int> { 1, 2, 3, 4 };
  // a = vector<int> { 4, 4, 1, 1, 1, 4 };
  // a = vector<int> { 1, 1, 2, 4, 1, 4, 1 };
  // a = vector<int> { 1, 1, 4, 2, 1 };
  a = vector<int> { 3, 3, 4, 4, 4, 3 };
  // a = vector<int> { 2, 1, 2, 0, 0, 1, 2, 2, 1, 0, 2 };
  // a = vector<int> { 2, 1, 2 };
}

void insert_data_set_2(vector<int>& a) {
  srand(time(NULL));
  a = vector<int>(rand() % 2 + 100000);
  size_t size = a.size();

  for(size_t i = 0; i < size; i++) {
    a[i] = rand() % 2;
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
  std::cout << (get_majority_element_2(a, 0, a.size() - 1)) << '\n';
  system("pause");
  return 0;
}

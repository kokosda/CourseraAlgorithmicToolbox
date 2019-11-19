#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using std::vector;

void show_vector(const vector<int> &a, std::string name) {
  std::cout << name << " size " << a.size() << ": ";
  for (int i = 0; i < a.size(); i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

const vector<int> merge(vector<int>& a, vector<int>& b) {
  vector<int> result(a.size() + b.size());
  size_t currentResultEndIndex = 0;
  size_t aSize = a.size();
  size_t bSize = b.size();

  while (aSize > 0 && bSize > 0) {
    int a1 = aSize > 0 ? a[0] : -1;
    int b1 = bSize > 0 ? b[0] : -1;

    if (a1 <= b1) {
      result[currentResultEndIndex] = a1;
      a.erase(a.begin());
      aSize--;
    }
    else {
      result[currentResultEndIndex] = b1;
      b.erase(b.begin());
      bSize--;
    }

    currentResultEndIndex++;
  }

  size_t size = aSize > 0 ? aSize : bSize;
  vector<int>& v = aSize > 0 ? a : b;

  if (size > 0) {
    size_t index = 0;
    while(index < size)
    {
        result[currentResultEndIndex] = v[index];
        currentResultEndIndex++;
        index++;
    }
  }

  // show_vector(result, "r");
  return result;
}

const vector<int> merge_sort(const vector<int>& a) {
  if (a.size() == 1) {
    return a;
  }

  size_t m = (a.size() % 2) == 0 ? a.size() / 2 : (a.size() / 2) + 1;
  // std::cout << "a.size=" << a.size() << "\n";

  vector<int> b;
  vector<int> c;
  vector<int>::const_iterator first;
  vector<int>::const_iterator last;
  
  if (m > 1) {
    first = a.begin();
    last = a.begin() + m;
    b = vector<int>(first, last);
  }
  else {
    b = vector<int> { a[0] };
  }

  // std::cout << "b.size=" << b.size() << " b[0]=" << b[0] << " b[last]=" << b[b.size() - 1] << "\n";

  if (m > 1) {
    first = last;
    last = a.end();
    c = vector<int>(first, last);
  }
  else {
    c = vector<int> { a[1] };
  }

  // std::cout << "c.size=" << c.size() << " c[0]=" << c[0] << " c[last]=" << c[c.size() - 1] << "\n";

  b = merge_sort(b);
  c = merge_sort(c);

  const vector<int> result = merge(b, c);
  return result;
}

void insert_data_set_1(vector<int>& a) {
  a = vector<int> { 8, 3, 8, 36, 8, 24, 1, 8, 5, 8, 8, 8, 1, 8, 8, 8, 8 };
}

void insert_data_set_2(vector<int>& a) {
  srand(time(NULL));
  a = vector<int>(rand() % 10 + 100);
  size_t size = a.size();

  for(size_t i = 0; i < size; i++) {
    a[i] = rand();
  }
}

int main() {
  int n;
  //std::cin >> n;
  vector<int> a;
  insert_data_set_2(a);
  show_vector(a, "initial");
  // for (size_t i = 0; i < a.size(); ++i) {
  //   std::cin >> a[i];
  // }
  vector<int> sorted = merge_sort(a);
  // for (int i = 0; i < sorted.size(); i++) {
  //   std::cout << sorted.at(i) << " ";
  // }
  show_vector(sorted, "sorted");
  std::cout << std::endl;
  system("pause");
  return 0;
}

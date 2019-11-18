#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right)
    return -1;
  if (left + 1 == right)
    return a[left];
  
  return -1;
}

const vector<int> merge(vector<int>& a, vector<int>& b) {
  vector<int> result(a.size() + b.size());
  size_t currentResultEndIndex = result.size() - 1;
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

    currentResultEndIndex--;
  }

  size_t indexA = 0;
  size_t indexB = 0;

  while (indexA < aSize || indexB < bSize)
  {
    if (aSize > 0) {
      result[currentResultEndIndex] = a[indexA];
      currentResultEndIndex--;
      indexA++;
      continue;
    }

    if (bSize > 0) {
      result[currentResultEndIndex] = b[indexB];
      currentResultEndIndex--;
      indexB++;
      continue;
    }
  }

  std::cout << "r.size=" << result.size() << " r[0]=" << result[0] << " r[last]=" << result[result.size() - 1] << "\n";
  return result;
}

const vector<int> merge_sort(const vector<int>& a) {
  if (a.size() == 1) {
    return a;
  }

  size_t m = (a.size() % 2) == 0 ? a.size() / 2 : (a.size() / 2) + 1;
  std::cout << "a.size=" << a.size() << "\n";

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

  std::cout << "b.size=" << b.size() << " b[0]=" << b[0] << " b[last]=" << b[b.size() - 1] << "\n";

  if (m > 1) {
    first = last;
    last = a.end();
    c = vector<int>(first, last);
  }
  else {
    c = vector<int> { a[1] };
  }

  std::cout << "c.size=" << c.size() << " c[0]=" << c[0] << " c[last]=" << c[c.size() - 1] << "\n";

  b = merge_sort(b);
  c = merge_sort(c);

  const vector<int> result = merge(b, c);
  return result;
}

void insert_data_set_1(vector<int> &a) {
  a.push_back(2);
  a.push_back(3);
  a.push_back(9);
  a.push_back(2);
  a.push_back(2);
}

int main() {
  int n;
  //std::cin >> n;
  vector<int> a;
  insert_data_set_1(a);
  // for (size_t i = 0; i < a.size(); ++i) {
  //   std::cin >> a[i];
  // }
  // std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  vector<int> sorted = merge_sort(a);
  for (int i = 0; i < sorted.size(); i++) {
    std::cout << sorted.at(i) << " ";
  }
  std::cout << std::endl;
  system("pause");
  return 0;
}

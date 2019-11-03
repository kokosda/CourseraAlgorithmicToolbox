#include <iostream>
#include <vector>

/*
Task. The goal of this code problem is to implement an algorithm for the fractional knapsack problem.
Input Format. The first line of the input contains the number 𝑛 of items and the capacity 𝑊 of a knapsack.
The next 𝑛 lines define the values and weights of the items. The 𝑖-th line contains integers 𝑣𝑖 and 𝑤𝑖—the
value and the weight of 𝑖-th item, respectively.
Constraints. 1 ≤ 𝑛 ≤ 10^3, 0 ≤ 𝑊 ≤ 2 · 10^6; 0 ≤ 𝑣𝑖 ≤ 2 · 10^6, 0 < 𝑤𝑖 ≤ 2 · 10^6 for all 1 ≤ 𝑖 ≤ 𝑛. All the
numbers are integers.
Output Format. Output the maximal value of fractions of items that fit into the knapsack. The absolute
value of the difference between the answer of your program and the optimal value should be at most
10^−3. To ensure this, output your answer with at least four digits after the decimal point (otherwise
your answer, while being computed correctly, can turn out to be wrong because of rounding issues).
*/

using std::vector;

int get_next_best_index(vector<int>& weights, vector<int>& values) {
  int n = weights.size();
  double best_ratio = 0.0;
  double temp_ratio = 0.0;
  int index = 0;

  for (int i = 0; i < n; i++) {
    int v = values[i];
    int w = weights[i];

    if (w <= 0)
      continue;

    temp_ratio = (double)v / w;

    if (temp_ratio > best_ratio) {
      best_ratio = temp_ratio;
      index = i;
    }
  }

  return index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  int counter = 0;
  vector<int> a(capacity);

  while(counter <= n) {
    if (capacity == 0) {
      return value;
    }

    int index = get_next_best_index(weights, values);

    int v = values[index];
    int w = weights[index];
    values[index] = 0;
    weights[index] = 0;

    double ratio = (double)v / w;
    int weight_to_take = capacity - w >= 0 ? w : capacity;

    value += weight_to_take * ratio;
    capacity -= weight_to_take;
    counter++;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

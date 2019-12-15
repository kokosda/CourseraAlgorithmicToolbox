#include <iostream>
#include <string>
#include <algorithm>

using std::string;

const int DIMENSION_X = 100;
const int DIMENSION_Y = 100;

void show_distance(int distance[][DIMENSION_Y], int n, int m) {
  bool enabled = false;

  if (!enabled) {
    return;
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      std::cout << distance[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int edit_distance(const string &str1, const string &str2) {
  const size_t n = str1.length();
  const size_t m = str2.length();
  int distance [DIMENSION_X][DIMENSION_Y];

  for (int i = 0; i < DIMENSION_X; i++) {
    distance[i][0] = i;
  }

  for (int j = 0; j < DIMENSION_Y; j++) {
    distance[0][j] = j;
  }

  int insertion, deletion, match, mismatch, cost;

  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      insertion = distance[i][j-1] + 1;
      deletion = distance[i-1][j] + 1;
      cost = std::min(insertion, deletion);

      if (str1[i - 1] == str2[j - 1]) {
        match = distance[i-1][j-1];
        distance[i][j] = std::min(cost, match);
      }
      else {
        mismatch = distance[i-1][j-1] + 1;
        distance[i][j] = std::min(cost, mismatch);
      }

      show_distance(distance, n, m);
      // std::cout << std::endl;
    }
  }

  show_distance(distance, n, m);
  
  int result = distance[n][m];
  return result;
}

int main() {
  string str1; //= "short";
  string str2; //= "ports";
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  system("pause");
  return 0;
}

/*
EditDistance(A[1 . . . n], B[1 . . .m])
D(i , 0) ← i and D(0, j) ← j for all i , j
  for j from 1 to m:
    for i from 1 to n:
      insertion ← D(i , j − 1) + 1
      deletion ← D(i − 1, j) + 1
      match ← D(i − 1, j − 1)
      mismatch ← D(i − 1, j − 1) + 1
      if A[i] = B[j]:
        D(i , j) ← min(insertion, deletion, match)
      else:
        D(i , j) ← min(insertion, deletion, mismatch)
return D(n,m)
*/
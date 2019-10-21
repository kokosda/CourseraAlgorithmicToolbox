#include <iostream>
#include <vector>
#include <algorithm>


long long MaxPairwiseProductFast(const std::vector<long long>& numbers) {
    int n = numbers.size();

    if (n == 1)
        return numbers[0];

    long long first_max = 0;
    int index_of_first_max = 0;

    for (int i = 0; i < n; ++i) {
        if (first_max >= numbers[i])
            continue;
        first_max = numbers[i];
        index_of_first_max = i;
    }

    long long second_max = 0;
    int index_of_second_max = 0;

    for (int i = 0; i < n; ++i) {
        if (i == index_of_first_max)
            continue;
        if (second_max >= numbers[i])
            continue;
        second_max = numbers[i];
        index_of_second_max = i;
    }

    long long max_product = first_max * second_max;
    // std::cout << "Indexes [1st, 2nd] max:" << index_of_first_max << " " << index_of_second_max << "\n";
    return max_product;
}

int MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

std::vector<long long> GetStressTestNumbers() {
    int n = rand() % 10 + 2;
    std::vector<long long> numbers(n);
    int number = 0;

    for (int i = 0; i < n; i++) {
        number = rand() % 10000;
        numbers.push_back(number);
    }
    return numbers;
}

int main() {
    // std::vector<long long> numbers;
    // while (true) {
    //     numbers = GetStressTestNumbers();
    //     int naiveMaxProduct = MaxPairwiseProduct(numbers);
    //     int fastMaxProduct = MaxPairwiseProductFast(numbers);
    //     std::cout << MaxPairwiseProduct(numbers) << " " << MaxPairwiseProductFast(numbers);
    //     if (naiveMaxProduct != fastMaxProduct) {
    //         std::cout << "STOPPED";
    //         break;
    //     }
    // }
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers);
    return 0;
}

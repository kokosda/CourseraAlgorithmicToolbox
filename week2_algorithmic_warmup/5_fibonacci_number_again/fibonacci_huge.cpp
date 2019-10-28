#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

std::string calculate_period(long long n, long long m) {
    if (n <= 1)
        return "1";

    long long previous = 0;
    long long current  = 1;
    long long remainder;
    const std::string periodIndicator = "01";
    int periodLength = periodIndicator.length();
    std::string remainderStr;
    std::string tail = periodIndicator;
    std::string result(periodIndicator);
    long long length;

    for (long long i = 2; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        remainder = current % m;

        remainderStr = std::to_string(remainder);

        std::cout << "tail before: " << tail << std::endl;

        tail = tail.substr(1) + remainderStr;

        std::cout << "tail after: " << tail << std::endl;

        if (tail.compare(tail.length() - periodLength, periodLength, periodIndicator) != 0) {
            result += remainderStr;
            std::cout << "result0: " << result << " tail0: " << tail << std::endl;
            continue;
        }

        length = i - 1;
        std::cout << "length: " << length << std::endl;
        break;
    }

    result = result.substr(0, length);
    std::cout << "result: " << result << std::endl;

    return result;
}

int get_fibonacci_number(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    long long fibonnaci_number;

    if (n <= 10) {
        fibonnaci_number = get_fibonacci_number(n);
    }
    else {
        std::string period = calculate_period(n, m);
        long long remainder = n % period.length();
        fibonnaci_number = get_fibonacci_number(remainder);
    }
    
    long long result = fibonnaci_number % m;
    return result;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    return 0;
}

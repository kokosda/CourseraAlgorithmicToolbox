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

long long calculate_period(long long n, long long m) {
    long long previous = 0;
    long long current  = 1;
    long long length;

    for (long long i = 0; i < m * m; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
        
        if (previous == 0 && current == 1) {
            length = i + 1;
            break;
        }
    }

    return length;
}

int get_fibonacci_number(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }

    return current;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    long long period = calculate_period(n, m);
    long long remainder = n % period;
    int fibonnaci_number = get_fibonacci_number(remainder, m);
    
    long long result = fibonnaci_number % m;
    return result;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    return 0;
}

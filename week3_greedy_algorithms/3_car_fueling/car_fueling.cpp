#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    stops[stops.size() - 1] = dist;

    int num_refills = 0;
    int current_refill = 0;
    const int stops_count = stops.size();
    const int IMPOSSIBLE = -1;

    // cout << "BEFORE: stops count " << stops_count << std::endl;

    while ((current_refill + 1) < stops_count) {
        int last_refill = current_refill;
        // cout << "CYCLE START: current refill " << current_refill << " stop " << stops[current_refill] << " last refil " << last_refill << std::endl;

        while (((current_refill + 1) < stops_count) && ((stops[current_refill + 1] - stops[last_refill]) <= tank)) {
            ++current_refill;
            // cout << "INNER CYCLE: current refill " << current_refill << " stop " << stops[current_refill] << " last refil " << last_refill << std::endl;
        }

        if (current_refill == last_refill) {
            // cout << "IMPOSSIBLE: current refill " << current_refill << " stop " << stops[current_refill] << " last refil " << last_refill << std::endl;
            return IMPOSSIBLE;
        }
        if ((current_refill + 1) < stops_count) {
            ++num_refills;
            // cout << "NUM REFILLS: current refill " << current_refill << " stop " << stops[current_refill] << " last refil " << last_refill << " num refills " << num_refills << std::endl;
        }
    }
    return num_refills;
}

void insert_data_1(int & d, int & m, int & n, vector<int> & stops) {
    d = 950;
    m = 400;
    n = 4;
    stops[1] = 200;
    stops[2] = 375;
    stops[3] = 550;
    stops[4] = 750;
}

void insert_data_2(int & d, int & m, int & n, vector<int> & stops) {
    d = 10;
    m = 3;
    n = 4;
    stops[1] = 1;
    stops[2] = 2;
    stops[3] = 5;
    stops[4] = 9;
}

void insert_data_3(int & d, int & m, int & n, vector<int> & stops) {
    d = 200;
    m = 250;
    n = 2;
    stops[1] = 100;
    stops[2] = 150;
}

void insert_data_4(int & d, int & m, int & n, vector<int> & stops) {
    d = 500;
    m = 200;
    n = 4;
    stops[1] = 100;
    stops[2] = 200;
    stops[3] = 300;
    stops[4] = 400;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    // n = 4;
    vector<int> stops(n + 2);
    stops[0] = 0;
    // insert_data_3(d, m, n, stops);
    for (size_t i = 1; i <= n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";
    // system("pause");
    return 0;
}

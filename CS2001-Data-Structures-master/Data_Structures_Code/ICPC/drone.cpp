#include <iostream>
#include <queue>

int find_last_seat(int n) {
    std::queue<int> seats;
    for (int i = 1; i <= n; ++i) {
        seats.push(i);
    }

    int skip = 0;
    while (seats.size() > 1) {
        for (int i = 0; i < skip; ++i) {
            seats.push(seats.front());
            seats.pop();
        }
        seats.pop();
        ++skip;
    }

    return seats.front();
}

int main() {

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << find_last_seat(n) << std::endl;
    }

    return 0;
}

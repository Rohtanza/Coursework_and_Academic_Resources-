#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

int main() {
    // freopen("input.txt", "r", stdin);
    int N, D;
    std::cin >> N >> D;
    int A, B;
    std::cin >> A >> B;
    std::vector<std::tuple<int, int, int>> customers;
    for (int i = 0; i < N; i++) {
        int packages_of_A, packages_of_B;
        std::cin >> packages_of_A >> packages_of_B;
        customers.push_back(std::make_tuple(i + 1, A * packages_of_A + B * packages_of_B, i + 1));
    }
    std::sort(customers.begin(), customers.end(),
              [&](const std::tuple<int, int, int> &a, const std::tuple<int, int, int> &b) {
                  return std::get<1>(a) < std::get<1>(b);
              });
    std::vector<int> served_customers;
    int packages_A = D;
    int packages_B = D;
    for (const auto &customer: customers) {
        int index, demand, customer_index;
        std::tie(index, demand, customer_index) = customer;
        if (packages_A >= demand) {
            packages_A -= demand;
            served_customers.push_back(customer_index);
        }
    }
    std::cout << served_customers.size() << std::endl;
    for (const auto &customer: served_customers) {
        std::cout << customer << " ";
    }
    std::cout << std::endl;
    return 0;
}

#include <unordered_set>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

auto lambda = [](std::vector<int> v){
    std::unique_ptr<std::vector<int>> result = std::make_unique<std::vector<int>>();
    if(v.empty())
        return result;
    std::unordered_set uno(v.begin(),v.end());
    for (auto &digit : uno){
            const int num_items = std::count(v.cbegin(), v.cend(), digit);
            std::cout << "number: " << digit << ", count: " << num_items << '\n';
        result->push_back(digit);
    }
    return result;
};

int main() {
    std::vector<int> v1 = {11, 2, 5, 4, 7, 8, 6, 3, 5, 5, 5, 4, 8, 23, 21, 4, 4, 5, 4, 12, 2};
    auto result = lambda(v1);
    for (auto &digit: *result){
        std::cout << digit << " ";
    }
    return 0;
}
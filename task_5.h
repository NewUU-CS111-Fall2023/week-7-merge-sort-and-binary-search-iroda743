#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> frequencyMap;
    for (int num : nums) {
        frequencyMap[num]++;
    }

    auto compare = [&](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> maxHeap(compare);

    for (const auto& entry : frequencyMap) {
        maxHeap.push(entry);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    std::vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().first);
        maxHeap.pop();
    }

    std::reverse(result.begin(), result.end());

    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int k;
    std::cin >> k;

    std::vector<int> result = topKFrequent(nums, k);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

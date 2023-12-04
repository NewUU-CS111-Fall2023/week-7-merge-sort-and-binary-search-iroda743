#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits> 

int findMedian(std::vector<int>& arr, int start, int end) {
    std::vector<int> subarray(arr.begin() + start, arr.begin() + end + 1);
    std::sort(subarray.begin(), subarray.end());
    int medianIndex = subarray.size() / 2;
    return subarray[medianIndex];
}

int minMedianOperation(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 2; ++i) {
        int minMedian = std::numeric_limits<int>::max();
        for (int j = 0; j < n - i; j += 2) {
            int median = findMedian(arr, i, i + j);
            minMedian = std::min(minMedian, median);
        }

        auto it = std::find(arr.begin(), arr.end(), minMedian);
        if (it != arr.end()) {
            arr.erase(it);
        }
    }

    return std::accumulate(arr.begin(), arr.end(), 0);
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;

        std::vector<int> arr(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> arr[j];
        }

        int result = minMedianOperation(arr);
        std::cout << result << std::endl;
    }

    return 0;
}

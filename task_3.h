#include <iostream>
#include <vector>
#include <algorithm>

void mergeArrays(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::vector<int> result;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] >= arr2[j]) {
            result.push_back(arr1[i]);
            ++i;
        } else {
            result.push_back(arr2[j]);
            ++j;
        }
    }

    while (i < arr1.size()) {
        result.push_back(arr1[i]);
        ++i;
    }

    while (j < arr2.size()) {
        result.push_back(arr2[j]);
        ++j;
    }

    for (int k = 0; k < result.size(); ++k) {
        std::cout << result[k] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> arr1(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> arr1[j];
        }

        std::vector<int> arr2(m);
        for (int j = 0; j < m; ++j) {
            std::cin >> arr2[j];
        }

        mergeArrays(arr1, arr2);
    }

    return 0;
}

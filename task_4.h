#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

int kthSmallest(std::vector<std::vector<int>>& matrix, int n, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int i = 0; i < n; ++i) {
        minHeap.push(matrix[i][0]);
    }

    for (int i = 0; i < k - 1; ++i) {
        int minElement = minHeap.top();
        minHeap.pop();

        int rowIndex = i;
        auto it = std::upper_bound(matrix[rowIndex].begin(), matrix[rowIndex].end(), minElement);
        int colIndex = std::distance(matrix[rowIndex].begin(), it);
        if (colIndex < n) {
            minHeap.push(matrix[rowIndex][colIndex]);
        }
    }

    return minHeap.top();
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int result = kthSmallest(matrix, n, k);
    std::cout << result << std::endl;

    return 0;
}

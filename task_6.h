#include <iostream>
#include <vector>

std::pair<int, int> searchInsertPosition(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            index = mid;
            return {1, index};
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            index = mid;
            right = mid - 1;
        }
    }

    return {-1, index + 1};
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int target;
    std::cin >> target;

    std::pair<int, int> result = searchInsertPosition(nums, target);
    std::cout << result.first << " " << result.second << std::endl;

    return 0;
}

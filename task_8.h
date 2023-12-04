#include <iostream>
#include <vector>

int findMissingNumber(std::vector<int>& nums, int n) {
    int expectedSum = (n * (n + 1)) / 2; 
    int actualSum = 0;

    for (int num : nums) {
        actualSum += num;
    }

    return expectedSum - actualSum;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> nums[i];
    }

    int missingNumber = findMissingNumber(nums, n);
    std::cout << "0 " << missingNumber << std::endl;

    return 0;
}

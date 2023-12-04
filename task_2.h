#include <iostream>
#include <vector>
#include <algorithm>

int maxBeautifulness(std::vector<int>& permutation) {
    int n = permutation.size();
    

    int initialBeautifulness = 0;
    for (int i = 0; i < n; ++i) {
        initialBeautifulness += std::abs(permutation[i] - (i + 1));
    }

    int maxImprovement = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(permutation[i], permutation[j]);

            int currentBeautifulness = 0;
            for (int k = 0; k < n; ++k) {
                currentBeautifulness += std::abs(permutation[k] - (k + 1));
            }

            maxImprovement = std::max(maxImprovement, initialBeautifulness - currentBeautifulness);

            std::swap(permutation[i], permutation[j]);
        }
    }

    return initialBeautifulness - maxImprovement;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> permutation[i];
    }

    int result = maxBeautifulness(permutation);
    std::cout << result << std::endl;

    return 0;
}

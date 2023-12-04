#include <iostream>

int recursivePow(int x, int n) {
    if (n == 0) {
        return 1;
    }

    return x * recursivePow(x, n - 1);
}

int main() {
    int x, n;
    std::cin >> x >> n;

    //  result
    int result = recursivePow(x, n);
    std::cout << result << std::endl;

    return 0;
}

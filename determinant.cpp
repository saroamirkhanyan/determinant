#include <iostream>
#include <vector>
#include "array2d.hpp"

static int __determinant(array2d<int>& matrix, int i, std::vector<bool> visited) {
        if(i == matrix.n) return 1;
        int sum = 0, sign = 1;
        for(int j = 0; j < matrix.n; j++) {
                if(visited[j]) continue;
                std::vector<bool> visited_minor;
                copy(visited.begin(), visited.end(), back_inserter(visited_minor));
                visited_minor[j] = true;
                int minor = __determinant(matrix, i + 1, visited_minor);
                sum += sign * matrix.at(i, j) * minor;
                sign *= -1;
        }
        return sum;
}

int determinant(array2d<int>& matrix) {
        std::vector<bool> visited(matrix.n, false);
        return __determinant(matrix, 0, visited);
}

int main() {
        int n;
        std::cin >> n;
        array2d<int> matrix(n, n);
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                        std::cin >> matrix.index(i, j);
                }
        }
        array2d_utils::print(matrix);
        std::cout << determinant(matrix) << std::endl;
        return 0;
}


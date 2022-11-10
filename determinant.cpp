#include <iostream>
#include <vector>
#include <cassert>
#include <future>
#include <numeric>
#include "array2d.hpp"
#include "bitmask.hpp"

template<typename A, typename B>
static A __determinant(array2d<A>& matrix, size_t i, const B& visited) {
        if(i == matrix.n) return 1;
        short sign = 1;
        std::vector<std::future<A>> additives;
        A sum = 0;
        for(size_t j = 0; j < matrix.n; j++) {
                if(bitmask::has<B>(visited, j)) continue;
                auto __calc_additive = [&matrix, visited, i, j](short sign) {
                        A visited_minor = bitmask::set(visited, j);
                        A minor = __determinant(matrix, i + 1, visited_minor);
                        return sign * matrix.at(i, j) * minor;
                };
                if(matrix.n < 9 || i > 1) {
                        sum += __calc_additive(sign);
                } else {
                        additives.push_back(std::async(std::launch::async, 
                                                __calc_additive, sign));
                }
                sign *= - 1;
        }
        return sum + std::accumulate(
                        begin(additives), 
                        end(additives), 
                        0, 
                        [&](int accumulator, std::future<A>& additive) {
                                return accumulator + additive.get();
                        });
}

template<typename A>
A determinant(array2d<A>& matrix) {
        assert(matrix.n < 64);
        return __determinant<A, unsigned int>(matrix, 0, 0);
}

int main() {
        int n;
        std::cin >> n;
        std::cout << n << std::endl;
        array2d<int> matrix(n, n);
        for(size_t i = 0; i < n; i++) {
                for(size_t j = 0; j < n; j++) {
                        std::cin >> matrix.index(i, j);
                }
        }
        array2d_utils::print(matrix);
        std::cout << determinant<int>(matrix) << std::endl;
        return 0;
}


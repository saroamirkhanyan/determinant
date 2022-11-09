#ifndef __ARRAY2D_HPP__
#define __ARRAY2D_HPP__
#include <iostream>

template <typename A>
class array2d_index;

template<typename A>
class array2d {
        A* array;
        public:
        size_t n, m;
        array2d(const size_t& n, const size_t& m) {
                this->n = n;
                this->m = m;
                array = new int[n * m];
        }
        private:
        inline size_t inline_index(const size_t& i, const size_t& j) {
                return i * n + j;
        }
        public:
        void set(const size_t& i, const size_t& j, const A& value) {
                this->array[inline_index(i, j)] = value;
        }
        const array2d_index<A> index(const size_t& i, const size_t& j) {
                return array2d_index<A>(this, i, j);
        }
        A at(const size_t& i, const size_t& j) {
                return array[inline_index(i, j)];
        }
        ~array2d() {
                delete [] array;
        }
};

template <typename A>
class array2d_index {
        size_t i, j;
        array2d<A>* array;
        public:
        array2d_index(array2d<A>* array, const size_t& i, const size_t& j) {
                assert(array != NULL);
                this->i = i;
                this->j = j; 
                this->array = array;
        }
        friend std::istream & operator >> (std::istream& in, array2d_index<A> index) {
                A value;
                in >> value;
                index.array->set(index.i, index.j, value);
                return in;
        }
};

namespace array2d_utils {
        template<typename A>
        void print(array2d<A>& array) {
                for(int i = 0; i < array.n; i++) {
                        for(int j = 0; j < array.m; j++) {
                                if(j != 0) std::cout << " ";
                                std::cout << array.at(i, j);
                        }
                        std::cout << std::endl;
                }
        }
}

#endif // __ARRAY2D_HPP__

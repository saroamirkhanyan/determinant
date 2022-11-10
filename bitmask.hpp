#ifndef __BITMASK_HPP__
#define __BITMASK_HPP__

namespace bitmask {
        template<typename A>
        inline A set(const A& a, int i) {
                return a | 1 << (i - 1);
        }
        template<typename A>
        inline A unset(const A& a, int i) {
                return a ^ 1 << (i - 1);
        }
        template<typename A>
        inline bool has(const A& a, int i) {
                return (a & 1 << (i - 1)) != 0;
        }
}

#endif // __BITMASK_HPP__

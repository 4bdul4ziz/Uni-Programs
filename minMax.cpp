auto it = max_element(std::begin(cloud), std::end(cloud)); // c++11

template <typename T, size_t N>
const T *mybegin(const T (&a)[N]) { return a; }
template <typename T, size_t N>
const T *myend(const T (&a)[N]) { return a + N; }

#include <iostream>
#include <algorithm>

template <typename T, size_t N>
const T *mybegin(const T (&a)[N])
{
    return a;
}
template <typename T, size_t N>
const T *myend(const T (&a)[N]) { return a + N; }

int main()
{
    const int cloud[] = {1, 2, 3, 4, -7, 999, 5, 6};

    std::cout << *std::max_element(mybegin(cloud), myend(cloud)) << '\n';
    std::cout << *std::min_element(mybegin(cloud), myend(cloud)) << '\n';
}
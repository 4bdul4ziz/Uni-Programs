#include <iostream>
#include <cmath>

int karatsuba(int x, int y);
int getSize(int num);

int main(int argc, const char *argv[])
{
    int x = 1234;
    int y = 9876;

    std::cout << "Started Karatsuba Multiplication with x=" << x << " y=" << y << std::endl;

    int product = karatsuba(x, y);

    std::cout << "Result: " << product << std::endl;
    return 0;
}

int karatsuba(int x, int y)
{
    // Determine the size of each number
    int n = fmax(getSize(x), getSize(y));

    // Base case - Both numbers have 1 digit
    if (n == 1)
    {
        return x * y;
    }

    // Calculate a, b, c and d | ex.1234 / 100 = 12.34 -> integer division = 12 -> modulo division = 34
    int p = pow(10, n / 2);
    int a = x / p;
    int b = x % p;
    int c = y / p;
    int d = y % p;

    // Calculate ac, bd and k recursively
    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int k = karatsuba(a + b, c + d) - ac - bd;

    // return the result
    return ac * pow(10, 2 * (n / 2)) + (k * p) + bd;
}

int getSize(int num)
{
    return num > 0 ? (int)log10((double)num) + 1 : 1;
}
#include <stdio.h>

int main()
{
    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    int a = x2 - x1;
    int b = y2 - y1;
    int c = x3 - x1;
    int d = y3 - y1;
    int e = x3 - x2;
    int f = y3 - y2;
    int g = a * a + b * b;
    int h = c * c + d * d;
    int i = e * e + f * f;
    if (g == h && g == i)
        printf("YES");
    else
        printf("NO");
    return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int num1;
    long num2;
    long long num3;
    char ch;
    float num4;
    double num5;
    ch = 'a';
    scanf("%d %ld %lld %c %f %lf", &num1, &num2, &num3, &ch, &num4, &num5);
    printf("%d\n%ld\n%lld\n%c\n%.2f\n%.5lf", num1, num2, num3, ch, num4, num5);
    return 0;
}

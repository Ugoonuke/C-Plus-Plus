#include <stdio.h>

void update(int *a,int *b, int c) {
   c = *a + *b;
   *b = *a - *b;
    if(*b < 0){
        *b = -*b;
    }
    *a = c;
}

int main() {
    int a, b, c;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb, c);
    printf("%d\n%d", a, b);

    return 0;
}

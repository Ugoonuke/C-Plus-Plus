#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void array(int);

int main(){
    int n, k, q, b, c;
    scanf("%d%d", &n, &q);
    vector <vector<int> >a(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        a[i].resize(k);
        for(int j = 0; j < k; j++){
            scanf("%d", &a[i][j]);
        }
        if(i == n-1){
            for(int p = 0; p < q; p++){
                scanf("%d%d", &b, &c);
                printf("%d\n", a[b][c]);
            }
        }
    }
	return 0;
}

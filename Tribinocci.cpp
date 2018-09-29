#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

long long trib(int,int,long long[]);

using namespace std;
int main() {
    int n, pos = 3;
    cin>>n;
    if(n < 2) {
        cout<<0;
        return 0;
    }
    else if(n == 3) {
        cout<<1;
        return 0;
    }
    long long fib[n];
    fib[0] = 0LL;
    fib[1] = 0LL;
    fib[2] = 1LL;
    cout<<trib(n+1, pos, fib);
    return 0;
}

long long trib(int n, int pos, long long fib[]) {
    if(pos < n) {
        fib[pos] = fib[pos-3]+fib[pos-2]+fib[pos-1];
        return (trib(n,pos+1,fib));
    }
    return fib[pos-1];
}

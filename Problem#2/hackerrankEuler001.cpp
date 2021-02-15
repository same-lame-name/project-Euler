#include <bits/stdc++.h>

using namespace std;

void solveByGeneratingOddFibonacci(long long N){
    long long sumOfEvenFibonacci = 0;

    for(long long last = 1, util, secondLast = 1; ; ){
        if(last + secondLast > N) break;

        sumOfEvenFibonacci += (last + secondLast);

        util = secondLast;
        secondLast = secondLast + 2 * last;
        last = 2 * util + 3 * last;

        assert(last & 1);
        assert(secondLast & 1);
    }
    
    cout << sumOfEvenFibonacci << '\n';
    return;
}

int main(){
    int testcases;
    long long N;
    cin >> testcases;
    
    while(testcases--){
        cin >> N;
        solveByGeneratingOddFibonacci(N);
    }
    return 0;
}
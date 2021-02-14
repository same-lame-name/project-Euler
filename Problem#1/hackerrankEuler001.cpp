#include "bits/stdc++.h"
using namespace std;

void solveByBruteFore(int N){
    long long sumOfMultiplesOf3Or5 = 0;
    for(int number = 1; number < 1000; ++number){
        if(number % 3 == 0 || number % 5 == 0) sumOfMultiplesOf3Or5 += number;
    }

    cout << sumOfMultiplesOf3Or5 << '\n';
    return;
}

long long sumOfMultiplesOf(int N, int number){
    int m = (N - 1) / number;
    assert((m * (m + 1) & 1) == 0);
    long long sumOfMultiplesOfN = (long long)number * m * (m + 1) / 2;
    return sumOfMultiplesOfN;
}

int LCMof(int N, int M){
    return N * M / (__gcd(N, M));
}

void solveByInclusionExclusion(int N){
    long long sumOfMultiplesOf3Or5 = 0;

    sumOfMultiplesOf3Or5 = sumOfMultiplesOf(N, 3) + sumOfMultiplesOf(N, 5) - sumOfMultiplesOf(N, LCMof(3, 5));
    cout << sumOfMultiplesOf3Or5 << '\n';
    return;
}

int main(){
    int testcases, N;
    cin >> testcases;
    while(testcases--){
        cin >> N;
        solveByInclusionExclusion(N);
    }
    return 0;
}

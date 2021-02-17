#include <bits/stdc++.h>

using namespace std;

void solve(long long N){
    long long number = N; 
    long long largestPrimeFactor = 1;
    for(long long primeFactor = 2; primeFactor * primeFactor <= number; ++primeFactor){
        if(number % primeFactor) continue;
        largestPrimeFactor = primeFactor;
        while(number % primeFactor == 0) number /= primeFactor;
    }

    largestPrimeFactor = max(number, largestPrimeFactor);
    cout << largestPrimeFactor << '\n';

    return;
}

int main(){
    int testcases;
    long long N;

    cin >> testcases;
    while(testcases--){
        cin >> N;
        solve(N); 
    }
    return 0;
}
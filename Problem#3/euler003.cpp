#include <bits/stdc++.h>

using namespace std;

int main(){
    long long number = 600851475143;
    long long largestPrimeFactor = 1;
    for(long long primeFactor = 2; primeFactor * primeFactor <= number; ++primeFactor){
        if(number % primeFactor) continue;
        largestPrimeFactor = primeFactor;
        while(number % primeFactor == 0) number /= primeFactor;
    }

    largestPrimeFactor = max(number, largestPrimeFactor);
    cout << largestPrimeFactor << '\n';

    return 0;
}
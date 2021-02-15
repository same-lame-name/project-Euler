#include <bits/stdc++.h>

using namespace std;

void solveByBruteForce(){
    const int maxLimit = (int)4e6;
    long long sumOfEvenFibonacci = 0;
    for(int current, secondLast = 0, last = 1; ; ){
        current = secondLast + last;
        if(current > maxLimit) break;

        if((current & 1) == 0){
            sumOfEvenFibonacci += current;
        } 

        secondLast = last;
        last = current;
    }

    cout << sumOfEvenFibonacci << '\n';
    return;
}

void solveByGeneratingOddFibonacciTerms(){
    const int maxLimit = (int)4e6;
    int sumOfEvenFibonacci = 0;
    for(int last = 1, secondLast = 1, util; ; ){
        if(last + secondLast > maxLimit) break;
        else sumOfEvenFibonacci += (last + secondLast); 

        util = last;
        last = 2 * secondLast + 3 * last;
        secondLast = secondLast + 2 * util;

        assert(last & 1);
        assert(secondLast & 1);
    }

    cout << sumOfEvenFibonacci << '\n';
}

int main(){
    #ifdef FIRST
        solveByBruteForce();
    #else 
        solveByGeneratingOddFibonacciTerms();
    #endif
    return 0;
}
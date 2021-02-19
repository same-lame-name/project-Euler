#include <bits/stdc++.h>

using namespace std;

map<int, int> getPrimeFactorization(int number){
    map<int, int> factorization;
    for(int prime = 2, exp; prime * prime <= number; ++prime){
        exp = 0;
        while(number % prime == 0){
            exp++;
            number /= prime;
        }

        if(exp) factorization[prime] = exp;
    }

    if(number > 1) factorization[number] = 1;
    return factorization;
}

void solveByPrimeFactorization(){
    map<int, int> commonPrimeFactorization;
    for(int number = 1; number <= 20; ++number){
        map<int, int> factorization = getPrimeFactorization(number);
        for(auto &ele : factorization){
            int prime = ele.first, exponent = ele.second;
            commonPrimeFactorization[prime] = max(commonPrimeFactorization[prime], exponent);
        }
    }

    int lowestCommonMultiple = 1;
    for(auto &ele : commonPrimeFactorization){
        for(int rep = 0; rep < ele.second; ++rep){
            lowestCommonMultiple *= ele.first;
        }
    }

    cout << lowestCommonMultiple << '\n';
    return;
}

int getLCM(int x, int y){
    return x * (y / (__gcd(x, y)));
}

void solveByRepeatedLCM(){
    int currentLCM = 1;
    for(int number = 1; number <= 20; ++number){
        currentLCM = getLCM(currentLCM, number);
    }

    cout << currentLCM << '\n';
    return;
}

int main(){
    #ifdef FIRST
        solveByPrimeFactorization();
    #else
        solveByRepeatedLCM();
    #endif
}
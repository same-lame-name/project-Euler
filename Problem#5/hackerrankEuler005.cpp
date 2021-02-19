#include <bits/stdc++.h>

using namespace std;

map<long long, long long> getPrimeFactorization(long long number){
    map<long long, long long> factorization;
    for(long long prime = 2, exp; prime * prime <= number; ++prime){
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

void solveByPrimeFactorization(long long limit){
    map<long long, long long> commonPrimeFactorization;
    for(long long number = 1; number <= limit; ++number){
        map<long long, long long> factorization = getPrimeFactorization(number);
        for(auto &ele : factorization){
            long long prime = ele.first, exponent = ele.second;
            commonPrimeFactorization[prime] = max(commonPrimeFactorization[prime], exponent);
        }
    }

    long long lowestCommonMultiple = 1;
    for(auto &ele : commonPrimeFactorization){
        for(long long rep = 0; rep < ele.second; ++rep){
            lowestCommonMultiple *= ele.first;
        }
    }

    cout << lowestCommonMultiple << '\n';
    return;
}

long long getLCM(long long x, long long y){
    return x * (y / (__gcd(x, y)));
}

void solveByRepeatedLCM(long long limit){
    long long currentLCM = 1;
    for(long long number = 1; number <= limit; ++number){
        currentLCM = getLCM(currentLCM, number);
    }

    cout << currentLCM << '\n';
    return;
}

int main(){
    int testcases, N;
    cin >> testcases;
    while(testcases--){
        cin >> N;
        solveByPrimeFactorization(N);
    }
    return 0;
}
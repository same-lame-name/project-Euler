#include "bits/stdc++.h"
using namespace std;

void solveByBruteFore(){
	//Since the problem contraints are small, we could just go over each number from [1..1000)
	//And add it to our running sum if it is divisible by 3 or by 5.
	int sumOfMultiplesOf3Or5 = 0;
	for(int number = 1; number < 1000; ++number){
		if(number % 3 == 0 || number % 5 == 0) sumOfMultiplesOf3Or5 += number;
	}

	//Another way to implement the above routine without expensive % operator.
	// for(int number = 1, mod3 = 0, mod5 = 0; number < 1000; ++number){
	// 	mod3++, mod5++;
	// 	if(mod3 == 3 || mod5 == 5) sumOfMultiplesOf3Or5 += number;
	// 	if(mod3 == 3) mod3 = 0;
	// 	if(mod5 == 5) mod5 = 0;
	// }

	cout << sumOfMultiplesOf3Or5 << '\n';
	return;
}

int sumOfMultiplesOf(int N){
	//Sum of series S = 1*N + 2*N + 3*N + .. m*N
	//We need numbers less than 1000, so m*N < 1000. So we need to find such 'm'
	//It is equal to the number of multiples of N less than 1000 i.e. 1000/N
	//Now S = N * (1 + 2 + 3 + .. + m) = N * m * (m + 1) / 2. Here the sum from 1 -> m is just the mth triangular number.
	int m = 999 / N;

	//We assert that m * (m + 1) is always even
	assert((m * (m + 1) & 1) == 0);
	int sumOfMultiplesOfN = N * m * (m + 1) / 2;
	return sumOfMultiplesOfN;
}

int LCMof(int N, int M){
	//We recall that LCM(a, b) * gcd(a, b) = a * b
	//There is a inbuilt function to calculate gcd(a, b), so we use that to calculate LCM(a, b)
	return N * M / (__gcd(N, M));
}

void solveByInclusionExclusion(){
	//Here we use the principal of inclusion-exclusion to count.
	//First we take all the numbers that are multiple of 3, then we take all the multiples of 5.
	//However we realize that some numbers which are multiples of both 3&5 are included in both list.
	//We have included them twice, but need them only once. So we remove all those numbers which are multiples of 3&5.
	//To find the multiples of m&n is easier than to find multiples of m||n. 
	//We realize that mulitples of m&n are multiples of LCM(m, n).
	//Since no multiple of m&n can be less than their LCM and every multiple of m&n is multiple of their LCM. 

	int sumOfMultiplesOf3Or5 = 0;

	//multiples of 3 + multiples of 5 - multiples of 3&5.
	sumOfMultiplesOf3Or5 = sumOfMultiplesOf(3) + sumOfMultiplesOf(5) - sumOfMultiplesOf(LCMof(3, 5));
	cout << sumOfMultiplesOf3Or5 << '\n';
	return;
}

int main(){

	#ifdef FIRST 
		solveByBruteFore();
	#else 
		solveByInclusionExclusion();
	#endif
	return 0;
}

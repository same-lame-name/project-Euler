#include <bits/stdc++.h>

using namespace std;

bool isPalindromicNumber(int N){
    string stringRepresentation = to_string(N);
    int left = 0, right = stringRepresentation.size() - 1;
    while(left < right){
        if(stringRepresentation[left] != stringRepresentation[right]) return false;
        left++;
        right--;
    }

    return true;
}

void methodOfBruteForce(int N){
    int largestPalindromicNumber = 1;
    for(int first = 100, product; first < 1000; ++first){
        for(int second = first; second < 1000; ++second){
            product = first * second;
            if(isPalindromicNumber(product) && product < N){
                largestPalindromicNumber = max(largestPalindromicNumber, product);
            }
        }
    }

    cout << largestPalindromicNumber << '\n';
    return;
}

void methodOfGeneratingPalindromicNumbers(int N){
   //11 * (9091 * a + 910 * b + 100 * c) is palindromic number formed by two three-digit numbers
   //11 * (9091a + 910b + 100c) = m * n
   //So without loss of generality m has to be three-digit multiple of 11 i.e m = 11x
   //which means (9091a + 910b + 100c) = xn

   int largestPalindromicNumber = 1;
   for(int a = 9, number; a > 0; --a){
       for(int b = 9; b >= 0; --b){
           for(int c = 9; c >=0; --c){
               number = 9091 * a + 910 * b + 100 * c;
               if(number * 11 >= N) continue;
               for(int x = 90, n; x >= 10; --x){
                   if(number % x) continue;
                   if((number / x) > 999) continue;
                   largestPalindromicNumber = number * 11;
                   goto publishResult;
               }
           }
       }
   }

   publishResult:;
   cout << largestPalindromicNumber << '\n';
   return;
}

int main(){
    int testcases, N;
    cin >> testcases;
    while(testcases--){
        cin >> N;
        methodOfGeneratingPalindromicNumbers(N);
    }
}
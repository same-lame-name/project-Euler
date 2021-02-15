fibonacci :: [Int]
fibonacci = 1 : 2 : (zipWith (+) fibonacci (tail fibonacci))

fibonacciWithinLimit :: [Int]
fibonacciWithinLimit = takeWhile (<= limit) fibonacci
    where limit = 4000000

evenFibonacciWithinLimit :: [Int]
evenFibonacciWithinLimit = filter even fibonacciWithinLimit

sumOfList :: [Int] -> Int
sumOfList [] = 0;
sumOfList (x : xs) = x + sumOfList xs

sumOfEvenFibonacci :: Int
sumOfEvenFibonacci = sumOfList evenFibonacciWithinLimit
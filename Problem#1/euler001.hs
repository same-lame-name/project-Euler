--main function to interact with outside world
main :: IO()
main = print solve

solve :: String
solve = show (sumOfList setOfMultiplesOf3Or5)

--list of numbers which are multiple of 3 or 5 and are less than 1000
setOfMultiplesOf3Or5 = [x | x <- [1..999], x `mod` 3 == 0 || x `mod` 5 == 0]

--function to calculate the sum of the list
sumOfList :: [Integer] -> Integer
sumOfList [] = 0
sumOfList (x : xs) = x + sumOfList(xs)

--other implementation to calculate the sum of the list
sumOfListWithAccumulators :: [Integer] -> Integer
sumOfListWithAccumulators = sumOfListUtil 0
sumOfListUtil a [] = a
sumOfListUtil a (x : xs) = sumOfListUtil (a + x) xs

{-
    Calling sumOfListWithAccumulators with List as parameter will give the sum of List
    i.e. 
    sumOfListWithAccumulators setOfMultiplesOf3Or5 = sumOfList setOfMultiplesOf3Or5
-}
 
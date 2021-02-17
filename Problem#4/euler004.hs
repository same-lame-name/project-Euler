palindromeNumbers :: [Integer]
palindromeNumbers = [x * y | x <- [100..999], y <- [100..999], isPalindrome (x * y)]

isPalindrome :: Integer -> Bool
isPalindrome x = (show x) == reverse (show x)

largestInTheList :: [Integer] -> Integer
largestInTheList l = currentLargest 0 l
    where currentLargest local [] = local
          currentLargest local (x : xs) 
            | local < x = currentLargest x xs
            | otherwise = currentLargest local xs

largestPalindromeNumber :: Integer
largestPalindromeNumber = largestInTheList palindromeNumbers
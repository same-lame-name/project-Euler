main :: IO()
main = interact $ process

process :: String -> String
process = unlines . map show . map largestInTheListLessThan . map (read :: String -> Integer) . tail . lines

palindromeNumbers :: [Integer]
palindromeNumbers = [x * y | x <- [110, 121..990], y <- [100..999], isPalindrome (x * y)]

isPalindrome :: Integer -> Bool
isPalindrome x = (show x) == reverse (show x)

largestInTheListLessThan :: Integer -> Integer
largestInTheListLessThan within = currentLargest 0 within palindromeNumbers
    where currentLargest local within [] = local
          currentLargest local within (x : xs)
            | local < x && x < within = currentLargest x within xs
            | otherwise               = currentLargest local within xs 

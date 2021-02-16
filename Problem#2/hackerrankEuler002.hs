main :: IO()
main = interact $ process

process :: String -> String
process = unlines . map show . map sumOfList . map evenFibonacciWithinLimit . map (read :: String -> Integer) . tail . lines

fibonacciSequence :: [Integer]
fibonacciSequence = 1 : 2 : (zipWith (+) fibonacciSequence (tail fibonacciSequence))

evenFibonacciWithinLimit :: Integer -> [Integer]
evenFibonacciWithinLimit limit = filter even $ takeWhile (<= limit) fibonacciSequence

sumOfList :: [Integer] -> Integer
sumOfList [] = 0
sumOfList (x : xs) = x + sumOfList xs

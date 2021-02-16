main :: IO()
main = interact $ process

process :: String -> String
process = unlines . map show . map largestPrimeFactor . map (read :: String -> Integer) . tail . lines

largestPrimeFactor :: Integer -> Integer
largestPrimeFactor number = factorize number [2..] 
    where factorize x (p : xs)
            | p * p > x      = x
            | remainder == 0 = factorize quotient (p : xs)
            | otherwise      = factorize x xs
                where (quotient, remainder) = quotRem x p

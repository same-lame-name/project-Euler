--main function to interact with outside world
main :: IO()
main = interact $ process

process :: String -> String
process = unlines . map show . map sumOfMultiplesOf3Or5 . map (\x -> x - 1) . map (read :: String -> Integer) . tail . lines

-- We will get TLE with this solution. I'm learning haskell, so I will include this anyway.
-- sumOfMultiplesOf3Or5 :: Integer -> Integer
-- sumOfMultiplesOf3Or5 x
--     | x < 3                              = 0
--     | (x `mod` 3 == 0 || x `mod` 5 == 0) = x + sumOfMultiplesOf3Or5 (x - 1)
--     | otherwise                          = sumOfMultiplesOf3Or5 (x - 1)

-- sumOfMultiplesOf3Or5 :: Integer -> Integer
-- sumOfMultiplesOf3Or5 = sumWithAccumulator 0
-- sumWithAccumulator a x
--     | x < 3                              = a
--     | (x `mod` 3 == 0 || x `mod` 5 == 0) = sumWithAccumulator (a + x) (x - 1)
--     | otherwise                          = sumWithAccumulator a (x - 1)

sumOfMultiplesOf3Or5 :: Integer -> Integer
sumOfMultiplesOf3Or5 x = 3 * triangular (x `div` 3) + 5 * triangular (x `div` 5) - 15 * triangular (x `div` 15)
    where triangular y = (y * (y + 1)) `div` 2
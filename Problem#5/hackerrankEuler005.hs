main :: IO()
main = interact $ process

process :: String -> String
process = unlines . map show . map commonMultipleTill . map (read :: String -> Integer) . tail . lines

commonMultipleTill :: Integer -> Integer
commonMultipleTill 1 = 1
commonMultipleTill number = head $ filter (\x -> x `mod` number == 0) [step, 2 * step..]
    where step = commonMultipleTill (number - 1)

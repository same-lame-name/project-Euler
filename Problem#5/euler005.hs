commonMultipleTill :: Integer -> Integer
commonMultipleTill 1 = 1
commonMultipleTill number = head $ filter (\x -> x `mod` number == 0) [step, 2 * step..]
    where step = commonMultipleTill (number - 1)

lowestCommonMultipleTill20 :: Integer
lowestCommonMultipleTill20 = commonMultipleTill 20
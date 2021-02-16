sieve :: [Integer] -> [Integer]
sieve [] = []
sieve (p : xs) = p : sieve [x | x <- xs, x `mod` p > 0]

primes :: [Integer];
primes = sieve [2..]

-- I added sieve code for no particular reason. I am beginner in haskell so anything that
-- amuses me stays in the code. I suspect this inclusion slows down the code even.
-- my suspicion was correct. It is better we pass [2..] instead of sieve [2..] to largestPrimeFactor function.

largestPrimeFactor :: Integer -> Integer
largestPrimeFactor number = factorize number primes
    where factorize x (p : xs)
            | p * p > x     = x
            | remainder == 0 = factorize quotient (p : xs)
            | otherwise      = factorize x xs
                where (quotient, remainder) = quotRem x p

largestPrimeFactorOfRequiredValue :: Integer
largestPrimeFactorOfRequiredValue = largestPrimeFactor 600851475143
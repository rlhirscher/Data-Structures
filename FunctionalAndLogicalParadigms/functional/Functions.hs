{-

Ryan Hirscher
CSC4510 Programming Language Design
10/17/2023
Haskel Functions

This program is written in Haskell. It was designed to get familiar with the language's syntax and semantics. It also demonstrates several merits of the functional paradigm as it uses pure functions and returns immutable data.

Compile:
ghc Functions.hs

Execute:
./Functions

-}

-- Function to calculate the factorial of a number
factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n * factorial (n - 1)

-- Function to calculate the sum of integers from 1 to n
sumOfIntegers :: Integer -> Integer
sumOfIntegers 0 = 0
sumOfIntegers n = n + sumOfIntegers (n - 1)

-- Function to check if a number is even or odd
isEven :: Integer -> Bool
isEven n = n `mod` 2 == 0

-- Function to calculate the sum of elements in a list
sumList :: [Integer] -> Integer
sumList [] = 0
sumList (x:xs) = x + sumList xs

main :: IO ()
main = do
    putStrLn "Enter a number to calculate its factorial:"
    input <- getLine
    let n = read input :: Integer
    putStrLn ("Factorial of " ++ show n ++ " is " ++ show (factorial n))
    
    putStrLn "Enter a number to calculate the sum of integers from 1 to it:"
    input2 <- getLine
    let m = read input2 :: Integer
    putStrLn ("Sum of integers from 1 to " ++ show m ++ " is " ++ show (sumOfIntegers m))

    putStrLn "Enter a number to check if it's even or odd:"
    input3 <- getLine
    let x = read input3 :: Integer
    if isEven x
        then putStrLn (show x ++ " is even.")
        else putStrLn (show x ++ " is odd.")

    putStrLn "Enter a list of numbers separated by spaces to calculate their sum:"
    input4 <- getLine
    let numbers = map read (words input4) :: [Integer]
    putStrLn ("Sum of the numbers in the list is " ++ show (sumList numbers))


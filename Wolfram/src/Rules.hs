module Rules
    (toBin,
    rule30,
    rule90,
    rule110,
    isRule) where

isRule :: Int -> Bool
isRule 30 = True
isRule 90 = True
isRule 110 = True
isRule rule = False


toBin :: Int -> [Int]
toBin 0 = [0]
toBin n | n `mod` 2 == 1 = toBin (n `div` 2) ++ [1]
        | n `mod` 2 == 0 = toBin (n `div` 2) ++ [0]

rule30 :: Char -> Char -> Char -> Char
rule30 '*' '*' '*' = ' '
rule30 '*' '*' ' ' = ' '
rule30 '*' ' ' '*' = ' '
rule30 '*' ' ' ' ' = '*'
rule30 ' ' '*' '*' = '*'
rule30 ' ' '*' ' ' = '*'
rule30 ' ' ' ' '*' = '*'
rule30 ' ' ' ' ' ' = ' '

rule90 :: Char -> Char -> Char -> Char
rule90 '*' '*' '*' = ' '
rule90 '*' '*' ' ' = '*'
rule90 '*' ' ' '*' = ' '
rule90 '*' ' ' ' ' = '*'
rule90 ' ' '*' '*' = '*'
rule90 ' ' '*' ' ' = ' '
rule90 ' ' ' ' '*' = '*'
rule90 ' ' ' ' ' ' = ' '

rule110 :: Char -> Char -> Char -> Char
rule110 '*' '*' '*' = ' '
rule110 '*' '*' ' ' = '*'
rule110 '*' ' ' '*' = '*'
rule110 '*' ' ' ' ' = ' '
rule110 ' ' '*' '*' = '*'
rule110 ' ' '*' ' ' = '*'
rule110 ' ' ' ' '*' = '*'
rule110 ' ' ' ' ' ' = ' '
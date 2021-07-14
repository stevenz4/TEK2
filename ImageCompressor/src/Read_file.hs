module Read_file
    (readContent, contentToArray, replaceChar) where

import Lib

contentToArray :: String -> [String]
contentToArray = words

replaceChar :: Char -> Char
replaceChar '(' = ' '
replaceChar ')' = ' '
replaceChar ',' = ' '
replaceChar a = a

readContent :: [Char] -> IO String
readContent = readFile
module Parse
    (Rgb(..), getRgbArr, getX, getY, getR, getG, getB, printRGB, printRGBTab, printRGBTab2, printCluster, printPixel) where

import Lib
import Read_file

data Rgb = Rgb Int Int Int Int Int

getX :: Maybe Rgb -> Int
getX (Just (Rgb x y r g b)) = x
getX Nothing = -1

getY :: Maybe Rgb -> Int
getY (Just (Rgb x y r g b)) = y
getY Nothing = -1

getR :: Maybe Rgb -> Int
getR (Just (Rgb x y r g b)) = r
getR Nothing = -1

getG :: Maybe Rgb -> Int
getG (Just (Rgb x y r g b)) = g
getG Nothing = -1

getB :: Maybe Rgb -> Int
getB (Just (Rgb x y r g b)) = b
getB Nothing = -1

getRgbArr :: [String] -> [Maybe Rgb]
getRgbArr (a:b:c:d:e:f) = Just (Rgb (read a :: Int) (read b :: Int) (read c :: Int) (read d :: Int) (read e :: Int)):getRgbArr f
getRgbArr arr = [Nothing]

-- Return ReadMaybe quand c'est bon

printRGB :: Maybe Rgb -> IO()
printRGB Nothing = putStr ""
printRGB a = putStr ("[" ++ show (getX a) ++ ",") >>
                putStr (show (getY a) ++ "] ") >>
                putStr ("(" ++ show (getR a) ++ ",") >>
                putStr (show (getG a) ++ ",") >>
                putStr (show (getB a) ++ ") ")
                -- putStr "\n"

printRGBTab :: [Maybe Rgb] -> IO()
printRGBTab [] = putStr ""
printRGBTab [Nothing] = putStr ""
printRGBTab (x:xs) = printRGB x >>
                    printRGBTab xs

printRGBTab2 :: [[Maybe Rgb]] -> IO()
printRGBTab2 [] = putStr ""
printRGBTab2 [[Nothing]] = putStr ""
printRGBTab2 (x:xs) = putStr "[" >>
                    printRGBTab x >>
                    putStr "]\n" >>
                    printRGBTab2 xs

printCluster :: Maybe Rgb -> IO()
printCluster a = putStr ("(" ++ show (getR a) ++ ",") >>
                putStr (show (getG a) ++ ",") >>
                putStr (show (getB a) ++ ")")

printPixel :: Maybe Rgb -> IO()
printPixel a = putStr ("(" ++ show (getX a) ++ ",") >>
                putStr (show (getY a) ++ ")")
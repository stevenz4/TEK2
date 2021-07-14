module Cluster
    (calcDistance, initRandCLuster, calcShorterClust, getClustK, fillTab, addLastToList, 
fillTab, createTab, clusterisation, clusterisation2, clusterisationPrint, clusterisationLoop,  cleanTab, cleanTab2, averageClusterR, averageClusterG, averageClusterB, averageCluster, printPixelRgb, compareClust) where

import System.Random
import Parse

calcDistance :: Maybe Rgb -> Maybe Rgb -> Float --Calcule la distance entre 2 points
calcDistance (Just (Rgb _ _ a b c)) (Just (Rgb _ _ d e f)) = sqrt $ fromIntegral ((d - a)^2 + (e - b)^2 + (f - c)^2)

initRandCLuster :: Int -> StdGen -> StdGen -> StdGen -> [Maybe Rgb]
initRandCLuster nb s1 s2 s3
                | nb > 0 = Just (Rgb (-1) (-1) r g b):initRandCLuster (nb -1) s1' s2' s3'
                | otherwise = [Nothing]
                where   (r, s1') = randomR (0, 255) s1
                        (g, s2') = randomR (0, 255) s2
                        (b, s3') = randomR (0, 255) s3

createTab :: Int -> [[Maybe Rgb]] -> [[Maybe Rgb]]
createTab 0 tab = tab
createTab k tab = createTab (k-1) (tab ++ [[Just (Rgb (-1) (-1) (-1) (-1) (-1))]])

cleanTab2 :: [Maybe Rgb] -> [Maybe Rgb]
cleanTab2 [Nothing] = [Nothing]
cleanTab2 (x:xs) = xs

cleanTab :: [[Maybe Rgb]] -> [[Maybe Rgb]]
cleanTab (x:xs) = cleanTab2 x: cleanTab xs
cleanTab a = a

addLastToList :: [Maybe Rgb] -> Maybe Rgb -> [Maybe Rgb]
addLastToList colors color = colors ++ [color]

calcShorterClust :: [Maybe Rgb] -> Maybe Rgb -> Maybe Rgb -> Float -> Maybe Rgb --Trouve le K le plus proche de la couleur => Return K
calcShorterClust [Nothing] shorter _ _  = shorter
calcShorterClust (x:xs) shorter color dist = if (calcDistance x color) < dist
                                                    then calcShorterClust xs x color (calcDistance x color)
                                                    else calcShorterClust xs shorter color dist

getClustK :: [Maybe Rgb] -> Maybe Rgb -> Int -> Int --Return l'index d'un K
getClustK ((Just (Rgb x1 y1 a b c)):xs) (Just (Rgb x2 y2 d e f)) k = if (a == d && b == e && c == f)
                                                        then k
                                                        else getClustK xs (Just (Rgb x2 y2 d e f)) (k + 1)

fillTab :: Int -> Maybe Rgb -> [[Maybe Rgb]] -> [[Maybe Rgb]] --Prend K et une couleur => ajoute à la liste K
fillTab k color (x:xs) = if (k == 0)
                        then (addLastToList x color):xs
                        else x:(fillTab (k -1) color xs)

clusterisation :: [[Maybe Rgb]] -> [Maybe Rgb] -> [Maybe Rgb] -> [[Maybe Rgb]]          -- Creer la liste entiere des couleurs en fonction de K
clusterisation tab clusters [Nothing] = tab
clusterisation tab clusters (c:cs) = clusterisation (fillTab k_index c tab) clusters cs
                                    where   shorter = calcShorterClust clusters (Just (Rgb 1 1 1 1 1)) c 99999
                                            k_index = getClustK clusters shorter 0

clusterisation2 :: [[Maybe Rgb]] -> [Maybe Rgb]                        -- Return la liste des nouveaux K
clusterisation2 (x:xs) = averageCluster x:clusterisation2 xs
clusterisation2 a = [Nothing]

clusterisationLoop :: Int -> Float -> [Maybe Rgb] -> [Maybe Rgb] ->  [[Maybe Rgb]]
clusterisationLoop k ln clusters colors = if (check == True && k > 1)
                                then clusterisationLoop k ln newclusters colors
                                else tab2
                                where   blanktab = createTab (k -1) [[Just (Rgb (-1) (-1) (-1) (-1) (-1))]]
                                        tab2 = cleanTab (clusterisation blanktab clusters colors)
                                        newclusters = clusterisation2 tab2
                                        check = compareClust clusters ln newclusters

compareClust :: [Maybe Rgb] -> Float -> [Maybe Rgb] -> Bool
compareClust [Nothing] _ [Nothing] = False
compareClust [Nothing] _ _ = False
compareClust _ _ [Nothing] = False
compareClust (x:xs) ln (y:ys) = if ((r1 >= (r2 -ln) && r1 <= (r2 + ln))
                        || (g1 >= (g2 -ln) && g1 <= (g2 + ln))
                        || (b1 >= (b2 -ln) && b1 <= (b2 + ln)))
                        then True
                        else compareClust xs ln ys
                        where   r1 = fromIntegral (getR x) :: Float
                                r2 = fromIntegral (getR y) :: Float
                                g1 = fromIntegral (getG x) :: Float
                                g2 = fromIntegral (getG y) :: Float
                                b1 = fromIntegral (getB x) :: Float
                                b2 = fromIntegral (getB y) :: Float

averageClusterR :: [Maybe Rgb] -> Int -> Int -> Int
averageClusterR [] 0 0 = 0
averageClusterR (x:xs) nb r = averageClusterR xs (nb + 1) (r + (getR x))
averageClusterR colors nb r = r `div` nb

averageClusterG :: [Maybe Rgb] -> Int -> Int -> Int
averageClusterG [] 0 0 = 0
averageClusterG (x:xs) nb g = averageClusterG xs (nb + 1) (g + (getG x))
averageClusterG colors nb g = g `div` nb

averageClusterB :: [Maybe Rgb] -> Int -> Int -> Int
averageClusterB [] 0 0 = 0
averageClusterB (x:xs) nb b = averageClusterB xs (nb + 1) (b + (getB x))
averageClusterB colors nb b = b `div` nb

averageCluster :: [Maybe Rgb] -> Maybe Rgb
averageCluster colors = Just (Rgb (-1) (-1) r g b)
                        where   r = averageClusterR colors 0 0
                                g = averageClusterG colors 0 0
                                b = averageClusterB colors 0 0

printPixelRgb :: [Maybe Rgb] -> IO()
printPixelRgb [] = putStr ""
printPixelRgb [Nothing] = putStr ""
printPixelRgb (x:xs) = printPixel x >>
                        putStr " " >>
                        printCluster x >>
                        putStr "\n" >>
                        printPixelRgb xs

clusterisationPrint :: [Maybe Rgb] -> [[Maybe Rgb]] -> IO()
clusterisationPrint [Nothing] _ = putStr ""
clusterisationPrint _ [[Nothing]] = putStr ""
clusterisationPrint [Nothing] [[Nothing]] = putStr ""
clusterisationPrint (c:cs) (co:cos) = putStr "--\n" >>
                                        printCluster c >>
                                        putStr "\n-\n" >>
                                        printPixelRgb co >>
                                        clusterisationPrint cs cos
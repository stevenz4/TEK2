module Main where

import Lib
import Read_file
import Parse
import Cluster

import System.Environment
import System.Exit
import System.Random
import Data.Maybe
import Data.List

main :: IO()
main = do 
    args_tmp <- getArgs
    let options = getOpts defaultArgs args_tmp
    content <- (readContent (getPath options))
    let contentArr = contentToArray (map replaceChar content)
    let colors = getRgbArr contentArr
    s1 <- newStdGen
    s2 <- newStdGen
    s3 <- newStdGen
    let randClust = initRandCLuster (getNb options) s1 s2 s2
    let blanktab = createTab (getNb options -1) [[Just (Rgb (-1) (-1) (-1) (-1) (-1))]]
    let tab2 = cleanTab (clusterisation blanktab randClust colors)
    let clusters = clusterisation2 tab2
    let realtab = clusterisationLoop (getNb options) (getL options) clusters colors
    let realclusters = clusterisation2 realtab
    clusterisationPrint realclusters realtab
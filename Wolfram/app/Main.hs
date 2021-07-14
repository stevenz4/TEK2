module Main where

import Lib
import Print
import Rules

import System.Environment
import System.Exit
import Data.Maybe

main :: IO()
main = do
    args_tmp <- getArgs
    let options = getOpts defaultConf args_tmp
    if args_tmp == [] || isNothing(options) == True || (getRule options) == (-1) || isRule (getRule options) == False
        then exitWith(ExitFailure 84)
        else do
            let win_bis = divWin options
            printSpace (win_bis + (getMove options))
            putStr "*"
            printSpaceEnd (win_bis - 1)
            displaySteps "  *  " "" ((getLines options) - 1) ((win_bis - 1) + (getMove options)) (getMove options) (getRule options) (getWin options)


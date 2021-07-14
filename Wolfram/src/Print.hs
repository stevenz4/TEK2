module Print
    (printSpace,
    printSpaceEnd,
    createStep,
    displaySteps) where

import Lib
import Rules

printSpace :: Int ->  IO()
printSpace 0 = return ()
printSpace win = putStr " " >>
                printSpace (win - 1)

printSpaceEnd :: Int ->  IO()
printSpaceEnd 0 = putStr "\n"
printSpaceEnd win = if (win > 0) then putStr " " >>
                printSpaceEnd (win - 1)
                else putStr "\n" >>
                    return ()

createStep :: [Char] -> [Char] -> Int -> [Char]
createStep (a:b:c:d) step 30 = createStep (b:c:d) (step ++ [rule30 a b c]) 30
createStep (a:b:c:d) step 90 = createStep (b:c:d) (step ++ [rule90 a b c]) 90
createStep (a:b:c:d) step 110 = createStep (b:c:d) (step ++ [rule110 a b c]) 110
createStep [] step _ = step
createStep (a:c) step _ = step

printTest :: Int -> IO()
printTest a = print a

ifCut :: [Char] -> Int -> Int -> [Char]
ifCut step 0 win = do
                let cutsize = ((length step) - win) `div` 2
                cutStep step cutsize win
ifCut step actual_win win = step

cutStep :: [Char] -> Int -> Int -> [Char]
cutStep step size win = take win (drop size step)

displaySteps :: [Char] -> [Char] -> Int -> Int -> Int -> Int -> Int -> IO()
displaySteps step array (-1) win move rule w = printSpace win >>
                                putStr (ifCut (createStep step array rule) win w) >>
                                printSpaceEnd ((win - 1) - move) >>
                                displaySteps ("  " ++ (createStep step array rule) ++ "  ") array (-1) (minus win 1) move rule w
displaySteps step array lines win move rule w = if (lines > 1) then printSpace win >>
                                putStr (ifCut (createStep step array rule) win w) >>
                                printSpaceEnd ((win - 1) - move) >>
                                displaySteps ("  " ++ createStep step array rule ++ "  ") array (lines - 1) (minus win 1) move rule w
                                else  printSpace win >>
                                    putStr (ifCut (createStep step array rule) win w) >>
                                    printSpaceEnd ((win - 1) - move)
import System.Environment
import System.Exit
import Data.List

convertInt :: [String] -> [Int]
convertInt a = map (read :: String -> Int) a

main :: IO()
main = do
    args_tmp <- getArgs
    input <- getLine
    let args = convertInt args_tmp
    let sorted_args = doOp (args, []) (words input)
    if sorted_args == ([], [])
        then exitWith(ExitFailure 84)
        else if check sorted_args
            then putStrLn "OK"
            else putStr "KO: " >> print sorted_args

doOp :: ([Int], [Int]) -> [String] -> ([Int], [Int])
doOp args [] = args
doOp args (hd:tl)
    | hd == "sa"    = doOp (sa args) tl
    | hd == "sb"    = doOp (sb args) tl
    | hd == "sc"    = doOp (sc args) tl
    | hd == "pa"    = doOp (pa args) tl
    | hd == "pb"    = doOp (pb args) tl
    | otherwise     = doOp2 args (hd : tl)

doOp2 :: ([Int], [Int]) -> [String] -> ([Int], [Int])
doOp2 args (hd:tl)
    | hd == "ra"    = doOp (ra args) tl
    | hd == "rb"    = doOp (rb args) tl
    | hd == "rr"    = doOp (rr args) tl
    | hd == "rra"   = doOp (rra args) tl
    | hd == "rrb"   = doOp (rrb args) tl
    | hd == "rrr"   = doOp (rrr args) tl
    | otherwise     = ([], [])

check :: ([Int], [Int]) -> Bool
check ((hd:tl), b)
    | b /= []       = False
    | tl == []      = True
    | hd < head tl  = check (tl, []) 
    | otherwise     = False

sa :: ([a], [a]) -> ([a], [a])
sa ([], b) = ([], b)
sa ((hd : []), b) = ([hd], b)  
sa ((hd : (thd : tl)), b) = (thd : [hd] ++ tl, b)

sb :: ([a], [a]) -> ([a], [a])
sb (a, []) = (a, [])
sb (a, (hd : [])) = (a, [hd]) 
sb (a, (hd : (thd : tl))) = (a, thd : [hd] ++ tl)

sc :: ([a], [a]) -> ([a], [a])
sc a = sa (sb a)

pa :: ([a], [a]) -> ([a], [a])
pa (a, []) = (a, [])
pa (a, (hd:tl)) = (hd : a, tl)

pb :: ([a], [a]) -> ([a], [a])
pb ([], b) = ([], b)
pb ((hd:tl), b) = (tl, hd : b)

ra :: ([a], [a]) -> ([a], [a])
ra ((hd:tl), b) = (tl ++ [hd], b)

rb :: ([a], [a]) -> ([a], [a])
rb (a, (hd:tl)) = (a, tl ++ [hd])

rr :: ([a], [a]) -> ([a], [a])
rr a = ra (rb a)

rra :: ([a], [a])-> ([a], [a])
rra (a, b) = (last a : init a, b)

rrb :: ([a], [a])-> ([a], [a])
rrb (a, b) = (a, last b : init b)

rrr :: ([a], [a]) -> ([a], [a])
rrr a = rra (rrb a)

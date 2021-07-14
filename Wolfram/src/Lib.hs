module Lib
    (getOpts, defaultConf, Conf(..), getRule, getStart, getLines, getWin, getMove, divWin, minus) where

data Conf = Args Int Int Int Int Int

defaultConf :: Conf
defaultConf = Args (-1) 0 0 80 0

getOpts :: Conf -> [String] -> Maybe Conf
getOpts arg [] = Just arg
getOpts (Args rule start lines win move) ("--rule":b:c) = getOpts (Args (read b :: Int) start lines win move) c
getOpts (Args rule start lines win move) ("--start":b:c) = getOpts (Args rule (read b :: Int) lines win move) c
getOpts (Args rule start lines win move) ("--lines":b:c) = getOpts (Args rule start (read b :: Int) win move) c
getOpts (Args rule start lines win move) ("--window":b:c) = getOpts (Args rule start lines (read b :: Int) move) c
getOpts (Args rule start lines win move) ("--move":b:c) = getOpts (Args rule start lines win (read b :: Int)) c
getOpts arg a = Nothing

divWin :: Maybe Conf -> Int
divWin (Just (Args rule start lines win move)) =  win `div` 2

getRule :: Maybe Conf -> Int
getRule (Just (Args rule start lines win move)) = rule

getStart :: Maybe Conf -> Int
getStart (Just (Args rule start lines win move)) = start

getLines :: Maybe Conf -> Int
getLines (Just (Args rule start lines win move)) = lines

getWin :: Maybe Conf -> Int
getWin (Just (Args rule start lines win move)) = win

getMove :: Maybe Conf -> Int
getMove (Just (Args rule start lines win move)) = move

minus :: Int -> Int -> Int
minus a b = if (a <= b)
                then 0
                else (a - b)
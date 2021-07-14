module Lib
    (getOpts, defaultArgs, Args(..), getNb, getL, getPath) where

data Args = Args Int Float [Char]

defaultArgs :: Args
defaultArgs = Args 0 0 "null"

getOpts :: Args -> [String] -> Maybe Args
getOpts arg [] = Just arg
getOpts (Args nb l path) ("-n":b:c) = getOpts (Args (read b :: Int) l path) c
getOpts (Args nb l path) ("-l":b:c) = getOpts (Args nb (read b :: Float) path) c
getOpts (Args nb l path) ("-f":b:c) = getOpts (Args nb l b) c
getOpts arg a = Nothing

getNb :: Maybe Args -> Int
getNb (Just (Args nb a b)) = nb

getL :: Maybe Args -> Float
getL (Just (Args a l b)) = l

getPath :: Maybe Args -> [Char]
getPath (Just (Args a b path)) = path
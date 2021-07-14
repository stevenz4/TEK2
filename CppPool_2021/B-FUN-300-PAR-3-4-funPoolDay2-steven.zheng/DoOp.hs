myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem a (hd:tl) =  if a == hd
                then True
                else myElem a tl

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0  = Nothing
safeDiv a b = Just (div a b)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (hd:tl) index = if index < 0 || index > length (hd:tl)
                        then Nothing
                        else Just ((hd:tl) !! index)

safeSucc :: Maybe Int -> Maybe Int
safeSucc a = fmap (+ 1) a

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup a [] = Nothing
myLookup a (hd:tl) = if a == myFst hd
                    then Just (mySnd hd)
                    else myLookup a tl

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b - > Maybe c


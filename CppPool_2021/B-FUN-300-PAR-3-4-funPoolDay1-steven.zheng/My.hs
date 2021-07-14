mySucc :: Int -> Int
mySucc a  = a + 1

myIsNeg :: Int -> Bool
myIsNeg b = if b < 0 
            then True 
            else False

myAbs :: Int -> Int
myAbs c = if c >= 0
            then c
            else (-c)

myMin :: Int -> Int -> Int
myMin a b  = if (a > b)
            then b
            else a

myMax :: Int -> Int -> Int
myMax a b = if (a > b)
            then a
            else b

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "empty list"
myHead (hd : _) = hd

myTail :: [a] -> [a]
myTail [] = error "empty list"
myTail (_ : tl) = tl

myLength :: [a] -> Int
myLength [] = 0
myLength (_:tl) = 1 + myLength tl

myNth :: [a] -> Int -> a
myNth [] index = if index < 0 
                then error "index negative" 
                else error "out of bound"
myNth (hd:tl) i = if i == 0 
                then hd 
                else myNth tl (i - 1)

myTake :: Int -> [a] -> [a]
myTake i (hd:tl) = if i > myLength (hd:tl)
                    then (hd:tl)
                    else if i == 0
                    then []
                    else hd: (myTake(i - 1) tl)

myDrop :: Int -> [a] -> [a]
myDrop i (hd:tl) = if i >= (myLength (hd:tl) - 1)
                    then []
                    else if i == (0)
                    then (hd:tl)
                    else myDrop(i - 1) tl

myAppend :: [a] -> [a] -> [a]
myAppend [] x = x
myAppend (a:b) (c:d) = a : myAppend b (c:d)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:b) = myAppend(myReverse b) [a]

myInit :: [a] -> [a]
myInit [] = error "empty array"
myInit (a:b) = if (myLength (a:b)) == 1
                then []
                else myTake (myLength (a:b) - 1) (a:b)

myLast :: [a] -> a
myLast [] = error "empty array"
myLast (a:b) = myNth (a:b) (myLength (a:b) - 1)

myZip :: [a] -> [b] -> [(a, b)]
myZip _ [] = []
myZip [] _ = []
myZip (a:b) (c:d) = myTuple a c : myZip b d

-- myUnzip :: [(a, b)] -> ([a], [b])
-- myUnzip  (a:b) = myTuple list_one list_two
--                 where
--                     list_one = myFst a : myUnzip (myTuple (a:b))
--                     list_two = mySnd a : myUnzip (myTuple (a:b))
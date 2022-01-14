a b c  i o u f
0 1 2 3 4 5 6
n = size of the given string
​
here how we are getting the substrings on right and left in one attempt ?
ANs :
suppose you are at 3rd index, i= 3.
number of substrings in its right including s[3] = n - i = 7 - 3 = 4
=> i, io, iou, iouf
number of substring in its left excluding s[3] = i = 3
=> a, ab, abc
now you need to find the substrings where 0th index is the starting index and index 3 is also incuded in the number of substrings.. for this we will multiply i * (n-i)
​
watch this video for your reference https://youtu.be/0YvIfrX6kNs
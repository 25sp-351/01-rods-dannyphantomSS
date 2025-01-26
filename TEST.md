# Test Cases for assignment-1 

## Test Case 1: Valid Input
Input (Command Line): 
./rod_cutting 25
Input (Pieces): 
25, 100
Output: 
1 @ 25 = 100
Remainder: 0
Value: 100

## Test Case 2: No Argument for Command Line 
Input (Command Line): 
./rod_cutting -1
Output: 
Error: Rod length must be between 1 and 10,000.

## Test Case 3: Valid Input
Input (Command Line): 
./rod_cutting 60
3, 5 
6, 12 
10, 20 
20, 50 
30, 75
Output: 
2 @ 30 = 150 
1 @ 20 = 50 
Remainder: 10 
Value: 200

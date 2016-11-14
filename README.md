# Scales

Time Limit: 5000MS  
Memory Limit: 65536K

## Description

You are given scales for weighing loads. On the left side lies a single stone of known weight W<2<sup>N</sup>. You own a set of N different weights, weighing 1, 2, 4 ... 2<sup>(N-1)</sup> units of mass respectively. Determine how many possible ways there are of placing some weights on the sides of the scales; so as to balance them (put them in a state of equilibrium). Output this value modulo a small integer D.

## Input

The input begins with an integer t, the number of test cases. Then t test cases follow. For each test case, the first line contains three integers: N L D, where N denotes the number of weights at your disposal, L is the length of the binary representation of number W, and D is the modulus (1<=L<=N<=1000000, 2<=D<=100). The second line contains the value of W, encoded in the binary system as a sequence of exactly L characters 0 or 1 without separating spaces.

## Output

For each test case, output a single line containing one integer - the calculated number of possible weight placements, modulo D.

## Sample Input

2  
6 4 6  
1000  
6 6 100  
100110  

## Sample Output

3  
5  

## Source

Seventh ACM Egyptian National Programming Contest

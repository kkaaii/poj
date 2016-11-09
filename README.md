# Gangsters
Time Limit: 1,000 ms  
Memory Limit: 10,000 KB  

## Description

N gangsters are going to a restaurant. The i-th gangster comes at the time Ti and has the prosperity Pi.
The door of the restaurant has K+1 states of openness expressed by the integers in the range [0, K]. The state of openness can
change by one in one unit of time; i.e. it either opens by one, closes by one or remains the same. At the initial moment of
time the door is closed (state 0). The i-th gangster enters the restaurant only if the door is opened specially for him, i.e.
when the state of openness coincides with his stoutness Si. If at the moment of time when the gangster comes to the
restaurant the state of openness is not equal to his stoutness, then the gangster goes away and never returns. 

The restaurant works in the interval of time [0, T].

The goal is to gather the gangsters with the maximal total prosperity in the restaurant by opening and closing the door appropriately.

## Input

* The first line of the input file contains the values N, K, and T, separated by spaces. (1 <= N <= 100, 1 <= K <= 100, 0 <= T <= 30000)
* The second line of the input file contains the moments of time when gangsters come to the restaurant T1, T2, ..., TN, separated by spaces. (0 <= Ti <= T for i = 1, 2, ..., N)
* The third line of the input file contains the values of the prosperity of gangsters P1, P2, ..., PN, separated by spaces. (0 <= Pi <= 300 for i = 1, 2, ..., N)
* The forth line of the input file contains the values of the stoutness of gangsters S1, S2, ..., SN, separated by spaces. (1 <= Si <= K for i = 1, 2, ..., N)

All values in the input file are integers. 

## Output

Print to the output file the single integer - the maximal sum of prosperity of gangsters in the restaurant. In case when no gangster can enter the restaurant the output should be 0.

## Sample Input

4 10 20  
10 16 8 16  
10 11 15 1  
10 7 1 8  

## Sample Output

26

## Source

Northeastern Europe 1998

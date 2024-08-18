# Learning C - via Dr Chuck

## Text Book Code

### Chapter 2 
#### Problem 1 Rework For Loop - new_for_loop.c
Rewrite the below for loop to remove the && characters from the for loop logic
'''
for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
     s[i] = c;
'''
##### Approach
utilise an if state to `break` the for loop: 
`if (c = getchar() != '\n' && c != EOF)`

#### Problem 2 - htoi_learning.c
Write htoi function: converts a string of hexadecimal digits into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.

###### Approach
loop through each character(c) within the character array. See if the numerical representation lies between the integer values in ascii;
`'1'-'9' == 48-57`
`'a'-'f' == 65-70`
`'A'-'F' == 97-102`
then minus the equivalent(x) to get the correct integer and multiply by 16 ** of the index and accumulate: `acc + (c - x) * myPow(16, i)`

### Problem 2 Rework
## Lecture Code



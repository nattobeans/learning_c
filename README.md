# Learning C - via Dr Chuck

## Text Book Code
### Chapter 2 
#### Problem 1 Rework For Loop - new_for_loop.c
Rewrite the below for loop to remove the && characters from the for loop logic
```
for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
     s[i] = c;
```
##### Approach
utilise an if statement to `break` the for loop: 
`if (c = getchar() != '\n' && c != EOF) { break; }`

#### Problem 2 - htoi_learning.c
Write htoi function: converts a string of hexadecimal digits into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.

##### Approach
loop through each character(c) within the character array. See if the numerical representation lies between the integer values in ascii;
```
'1'-'9' == 48-57
'a'-'f' == 65-70
'A'-'F' == 97-102
```
then minus the equivalent(x) to get the correct integer and multiply by 16 ** of the index and accumulate: `acc + (c - x) * myPow(16, i)`

#### Problem 3 - string_squeeze.c
Write an alternate version of squeeze(s1, s2) which deletes each character in s1 which matches any character in the string s2.

##### Approach
loop thru s1 with a for loop. Then within said for loop loop through s2 and check if any characters are equal. If so set int check, if character doesnt match to 0. Below inner for loop set character: [position previously not in s2 + 1] to current character.

#### Problem 4 - any.c
Write the function any(s1, s2) which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.

##### Approach
loop thru s1 with a for loop. Then within said for loop loop through s2 and check if any characters are equal. If so set int check, if character doesnt match to 0. Below inner for loop set character: [position previously not in s2 + 1] to current character.

## Lecture Code



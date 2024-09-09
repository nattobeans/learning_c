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

##### Approach:
loop thru s1 with a for loop. Then within said for loop loop through s2 and check if any characters are equal. If so set int check, if character doesnt match to 0. Below inner for loop set character: [position previously not in s2 + 1] to current character.

#### Problem 5 - bits_learning.c
Get bits from position p to a lenght of n from the left.

##### Approach: 
Shift bits to the left by p+1-n to have first bit in window in left most position `x << (p+1-n)`. Then create a mask where n bits from the left are all one `z = 0U => ~(~z >> n)`. z needs to be an unsigned integer so the right shift populates with 0's instead of 1's. Then & the mask with the shift x to get all signifcant bits from the specified window.

#### Problem 6 - bits_learning.c
Calculate word length (amount of bits used to represent an integer) of the machine its ran on. Platform agnostic.

##### Approach
Define an integer 1 and shift the bit to the left contiously until the integer registers as 0. increase a counter each iteration.

#### Problem 7 - bits_learning.c

Rotate integer to the right by n amount. 

##### Approach
Create a y equivalent to x. Shift y (16 - n) amount to the left `y << (16 - n)`. (y & x are 16/short integers). and shift x n amount too the right `x >> n`. Then |/OR them to combine thier significant bits

#### Problem 8 - bits_learning.c
Invert (i.e., changes 1 into 0 and vice versa) the n bits of x that begin at position p, leaving the others unchanged.

##### Approach
Create a mask in the window of p and n `~(~0 << n))`. Then ^/XOR with the original int.


#### Problem 9 - bits_learning.c
In a 2's complement number system, x & ( x-1 ) deletes the rightmost 1-bit in x. (Why?) Use this observation to write a faster version of bitcount.

##### Approach
This works because minusing one flips the right most bit to 0 and all following bits to 1. Thus when anded it removes the right most bit as the new numbers bit in position c is 0 and the current digit it is 1. And all following bits are also opposite. Thus a simple `while (n != 0)` block with the code;
```
n &= n-1;
cnt++;
```
solves this problem.

#### Problem 10 - logic_ops.c
Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.

##### Approach
Rewrite statement with ternary operator `64 < c && c < 71 ? c + 32: c`


### Chapter 3
#### Problem 1 - show_special_char.c
Write a function expand(s, t) which converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string s to t. Use a switch.

##### Approach
Use swtich to catch both `\n` and `\t` charcter and instead of setting position `j` to the special character setting index j to `\\` and j+1 to `t or n`



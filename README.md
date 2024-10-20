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
Use swtich to catch both `\n` and `\t` charcter and instead of setting position `j` to the special character setting index j to `\\` and j+1 to `t or n`.

#### Problem 2 - expand_dash_notation.c
Write a function expand(s1 , s2) which expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.

##### Approach
use a while loop to span the whole string. utilise an inner for loop to locate the first `-`. check whether the dash is surrounded by a valid span then expand using a for loop starting from the first char of the span and ending with the last.

#### Problem 3 - convert_num_to_str.c
In a 2's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine it runs on.
```
itoa(n, s)    /* convert n to characters in s */
char s[];
int n;
{
    int i, sign;

    if ((sign = n) < 0)    /* record sign */
        n = -n;              /* make n positive */
    i = 0;
    do {    /* generate digits in reverse order */
        s[i++] = n % 10 + '0';     /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
```

##### Approach
in  two's complement system all bits must be flipped then add one to convert to a positive integer. Which will mean the highest possible negative integer will experience integer overflow error i.e: `1000 0000 XOR = 0111 1111 = + one = 1000 0000` thus it equals itself again.

The solution is to move the conversion

#### Problem 4 - integer_to.c
Write the analogous function itob(n, s) which converts the unsigned integer n into a binary character representation in s. Write itoh, which converts an integer to hexadecimal representation.

##### Approach
I have alread written a 16 bit printer btu I'll rewrite for 32 as thats the one on my pc. append int as char.

#### Problem 5 - itoa_padding.c
Write a version of itoa which accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.

##### Approach
Take the previously made function. decrement padding each iteration of the dowhile loop. if padding is above 0 after the end of the loop iterate till padding is 0 whilst adding '0' to for loop.


### Chapter 4
#### Problem 1 - rindex.c
Write the function rindex(s, t), which returns the position of the rightmost occurrence of t in s, or -1 if there is none.

##### Approach
no need to explain simple rindex function

#### Problem 2 - atof.c
Extend atof so it handles scientific notation of the form 123.45e-6 where a floating point number may be followed by e or E and an optionally signed exponent.

##### Approach
extend the current function by checking for an e/E character. If present


#### Problem 3 - no
##### Approach
Skipped as I didn't want to do it.


#### Problem 4 - read_buffer.c
Write a routine ungets(s) which will push back an entire string onto the input. Should ungets know about buf and bufp, or should it just use ungetch?

##### Approach
Just used bufp and buf as ungetch doesn't return a signal to catch and handle (classic c). loop over string and add to stack. did it in order wasnt sure if it should be reversed and also dont care.

#### Problem 5 - char_read_buffer.c
Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly.

##### Approach
remove buffer have single char instead. read char in getch and reassign to -1. check if c above -1 anin ungetch. if so donot reassign and print message.

#### Problem 6 - read_buffer.c
Our getch and ungetch do not handle a pushed-back EOF in a portable way. Decide what their properties ought to be if an EOF is pushed back, then implement your design.

##### Approach
check for EOF in getch and ungetch. If so clean buffer.`


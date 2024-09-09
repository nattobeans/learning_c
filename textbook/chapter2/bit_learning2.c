#include <stdio.h>

void print_bits16(unsigned short int num) {
    for(int i = 15; i >=0; i--) {
        unsigned short mask = 1 << i;
        unsigned short bit = (mask & num) ? 1 : 0;
        printf("%u", bit);
    }
    printf("\n");
}

unsigned short int slow_bitcount(unsigned short int n) /* count 1 bits in n */
{
    int b;

    for (b = 0; n != 0; n >>= 1)
        if (n & 01)
            b++;
    return(b);
}


unsigned short int fast_bitcount(short int n) {
    unsigned short int cnt = 0;
    // printf("-----START----------------------------------\n");
    while(n != 0) {
        // print_bits16(n);
        // print_bits16(n-1);
        n &= (n-1);
        // print_bits16(n);
        // printf("-----STEP----------------------------------\n");
        cnt++;
    }
    return cnt;
}


int main() {
    printf("----------------------------------------------\n");
    printf("Count significant bits\n");
    short int to_count = 0b101010011100010; 
    print_bits16(to_count);
    unsigned short int count_slow = slow_bitcount(to_count);
    unsigned short int count_fast = fast_bitcount(to_count);
    printf("Amount of bits in %d is %d\n", to_count, count_slow);
    printf("Amount of P in %d is %d\n", to_count, count_fast);
    printf("----------------------------------------------\n");
    return 1;
}
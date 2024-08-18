#include <stdio.h> 


void print_bits16(unsigned short int num) {
    printf("%d bit format: ", num);
    for (int i = 15; i >= 0; i--) {
        unsigned short mask = 1 << i;
        unsigned short bit = (num & mask) ? 1 : 0;
        printf("%u", bit);
    }
    printf("\n");
}

unsigned int get_bits_right(int x, int p, int n) /* get n bits from position p */
{
    print_bits16(~0 << n);
    print_bits16((1U << (16-n)) - 1);
    return((x >> (p+1-n)) &  ~(~0 << n));
}

unsigned int get_bits_left(int x, int p, int n)
{
    return ((x << (p+1-n)));
}


int main() {

    unsigned short int x = 65535; 
    // print_bits16(x);
    int y = get_bits_right(x, 5, 4);
    int z = get_bits_left(x, 3, 8);
    // print_bits16(y);

    unsigned int b = 0b1111111;
    // print_bits16(b);
    b = b >> 5;
    // print_bits16(b);

    return 1;
}
#include <stdio.h> 


// unsigned int number_length_calculator(int x) {
//     unsigned int cnt = 0;
//     while(x += 0) {
//         x <<= 1;
//         cnt++;
//     }
//     return cnt;
// }


// void print_bits(int num) {
//     printf("%d bit format: ", num);
    
//     for (int i = number_length_calculator(num); i >= 0; i--) {
//         unsigned short mask = 1 << i;
//         unsigned short bit = (num & mask) ? 1 : 0;
//         printf("%u", bit);
//     }
//     printf("\n");
// }


void print_bits16(unsigned short int num) {
    printf("%d bit format: ", num);
    
    for (int i = 15; i >= 0; i--) {
        unsigned short mask = 1 << i;
        unsigned short bit = (num & mask) ? 1 : 0;
        printf("%u", bit);
    }
    printf("\n");
}

unsigned short int get_bits_right(int x, int p, int n) /* get n bits from position p */
{
    return((x >> (p+1-n)) & ~(~0 << n));
}

unsigned short int get_bits_left(int x, int p, int n)
{
    unsigned short int zero_complement = ~0;
    return ((x << (p+1-n)) & ~(zero_complement >> n));
}

unsigned int word_length_calculator() {
    unsigned int x = 1;
    unsigned int cnt = 0;
    while(x += 0) {
        x <<= 1;
        cnt++;
    }
    return cnt;
}


unsigned short int rotate_right(unsigned short int x, int b) {
    unsigned int y = x << (16 - b);
    return (x >> b) | y;
}


unsigned short int invert(unsigned short int x, int p, int n) {
    return (~(~0 << n)) << (p + 1 - n) ^ x;
}


int main() {
    printf("----------------------------------------------\n");

    printf("Modified get_bits to move from left to right\n");
    unsigned short int x = 0b101010011100010; 
    print_bits16(x);
    unsigned short int y = get_bits_right(x, 5, 4);
    unsigned short int z = get_bits_left(x, 5, 4);
    print_bits16(y);
    print_bits16(z);
    printf("----------------------------------------------\n");

    printf("Discover Default Int length on Machine\n");
    unsigned int word_length = word_length_calculator();
    printf("WordLength of machine is: %d\n", word_length);
    printf("----------------------------------------------\n");

    printf("Rotate integer right\n");
    unsigned short int right = 0b101010101010101;
    print_bits16(right);
    right = rotate_right(right,  3);
    print_bits16(right);
    unsigned short int right2 = 0b00000001010101;
    print_bits16(right2);
    right2 = rotate_right(right2,  4);
    print_bits16(right2);
    printf("----------------------------------------------\n");

    printf("Invert bits from position p to n\n");
    unsigned short int inverted = ~0;
    print_bits16(inverted);
    inverted = invert(inverted, 7, 5);
    print_bits16(inverted);
    unsigned short int inverted2 = 0b101010101010101;;
    print_bits16(inverted2);
    inverted2 = invert(inverted2, 7, 5);
    print_bits16(inverted2);
    printf("----------------------------------------------\n");
    return 1;
}
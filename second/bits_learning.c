#include <stdio.h> 

void print_bits16(unsigned short int x) {
    print("%d bit format: ", x);
    for (int i = 15; i >= 0; i--) {
        unsigned short mask = 1 << i;
        unsigned short bit = (num & mask) ? 1 : 0;
        printf("%u", bit);
    }
    printf("\n");
}


unsigned int get_bits(int x, int p, int n) {
    return (( x << (p+1-n)) );
}


int main() {

    unsigned short int x = 100; 
    printf("%u\n", x);

    return 1;
}
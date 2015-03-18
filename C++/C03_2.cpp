#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

int dekad(unsigned short int bin[16]) {
    int pom[16];
    int i;
    int dekad;

    pom[0] = 1;
    for (i = 1; i < 16; i++) {
        pom[i] = pom[i - 1]*2;
    }

    dekad = 0;
    for (i = 0; i < 16; i++) {
        dekad = dekad + (pom[15 - i] * bin[i]);
    }

    return dekad;
}

int print_bin(unsigned short int bin[16]) {
    int i;

    for (i = 0; i < 16; i++) {
        printf("%i ", bin[i]);
    }

    return 1;
}

int main(void) {
    unsigned short int a_bin[16], b_bin[16], c_bin[16]; // binary numbers
    unsigned short int a_dec = 0, b_dec = 0, c_dec, d_dec; // decimal numbers
    int w, bshift; // weight for bin to dec conversion, number of bits for rshift
    int n; // index for loops
    char c; // char variable for pressed key

    printf("Two binary inputs and their decimal values :\n\n");


    // zaèátek
    srand(time(NULL));

    /* generování náhodných bitù (odkomentovat)
        for (n = 0; n < 16; n++) {
        a_bin[n] = rand() % 2;
        b_bin[n] = rand() % 2;
    }
    */

    /* hodnoty podle vzoru (pouze ke kontrole => smazat)*/
    a_bin[0] = 0; b_bin[0] = 1;
    a_bin[1] = 0; b_bin[1] = 1;
    a_bin[2] = 1; b_bin[2] = 1;
    a_bin[3] = 0; b_bin[3] = 1;
    a_bin[4] = 0; b_bin[4] = 1;
    a_bin[5] = 0; b_bin[5] = 0;
    a_bin[6] = 0; b_bin[6] = 1;
    a_bin[7] = 0; b_bin[7] = 1;
    a_bin[8] = 0; b_bin[8] = 1;
    a_bin[9] = 0; b_bin[9] = 0;
    a_bin[10] = 1; b_bin[10] = 0;
    a_bin[11] = 0; b_bin[11] = 0;
    a_bin[12] = 0; b_bin[12] = 1;
    a_bin[13] = 0; b_bin[13] = 0;
    a_bin[14] = 1; b_bin[14] = 1;
    a_bin[15] = 1; b_bin[15] = 1;

    
    a_dec = dekad(a_bin);
    b_dec = dekad(b_bin);

    printf("a_bin:   ");
    print_bin(a_bin);
    printf("     a_dec: %5i", a_dec);

    printf("\nb_bin:   ");
    print_bin(b_bin);
    printf("     b_dec: %5i", b_dec);

    /* Bit-wise conjuction */
    for(n=0; n<16; n++){
        if((a_bin[n]==1) && (a_bin[n]==b_bin[n])) c_bin[n]=1;
        else c_bin[n]=0;
    }
    c_dec = dekad(c_bin);
    d_dec = a_dec & b_dec;

    printf("\n\nBit-wise conjuction");
    printf("\n\nc_bin:   ");
    print_bin(c_bin);
    printf("     c_dec: %5i", c_dec);
    printf("     d_dec: %5i", d_dec);

    /* Bit-wise disjuction */
    for(n=0; n<16; n++){
        if((a_bin[n]==1) || (b_bin[n]==1)) c_bin[n]=1;
        else c_bin[n]=0;
    }
    c_dec = dekad(c_bin);
    d_dec = a_dec | b_dec;

    printf("\n\nBit-wise disjuction");
    printf("\n\nc_bin:   ");
    print_bin(c_bin);
    printf("     c_dec: %5i", c_dec);
    printf("     d_dec: %5i", d_dec);

    /* Bit-wise inequality */
    for(n=0; n<16; n++){
        if(a_bin[n]!= b_bin[n]) c_bin[n]=1;
        else c_bin[n]=0;
    }
    c_dec = dekad(c_bin);
    d_dec = a_dec ^ b_dec;

    printf("\n\nBit-wise inequality");
    printf("\n\nc_bin:   ");
    print_bin(c_bin);
    printf("     c_dec: %5i", c_dec);
    printf("     d_dec: %5i", d_dec);

    /* Bit shift to right: 4 bits of a_bin/a_dec */
    for(n=0; n<16; n++){
        if(n-4<0) c_bin[n] = 0;
        else c_bin[n]=a_bin[n-4];
    }
    c_dec = dekad(c_bin);
    d_dec = a_dec >> 4;

    printf("\n\nBit shift to right: 4 bits of a_bin/a_dec");
    printf("\n\nc_bin:   ");
    print_bin(c_bin);
    printf("     c_dec: %5i", c_dec);
    printf("     d_dec: %5i", d_dec);

    /* Bit-wise complement to a_bin/a_dec */
    for(n=0; n<16; n++){
        if(a_bin[n]==0) c_bin[n]=1;
        else c_bin[n]=0;
    }
    c_dec = dekad(c_bin);
    d_dec = ~a_dec;

    printf("\n\nBit-wise complement to a_bin/a_dec");
    printf("\n\nc_bin:   ");
    print_bin(c_bin);
    printf("     c_dec: %5i", c_dec);
    printf("     d_dec: %5i", d_dec);

    // konec

    scanf("%c", &c); // waiting for pressing key
    return 0; // program returns 0
}
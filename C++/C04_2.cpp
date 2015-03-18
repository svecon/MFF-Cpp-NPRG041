#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int main(void) {
    char stext1[] = "XIABDAWWFDUMZBEFDJQILCREBUIFBF"; // the first part of encrypted message
    char stext2[] = "OULCREBUFYUBHFUTBGVMMBQAJOUTC"; // the second part of encrypted message
    char rtext[150]; // destination string
    char * pointer;
    ;
    int n;
    int diff;

    printf("a) Concatenation:");
    strcpy(rtext, stext1);
    strcat(rtext, stext2);
    printf("\n\n%s", rtext);

    printf("\n\nb) Replacement A=>P and W=>S:");
    n = 0;
    while (rtext[n] != 0) {
        if (rtext[n] == 'A') rtext[n] = 'P';
        if (rtext[n] == 'W') rtext[n] = 'S';
        n++;
    }
    printf("\n\n%s", rtext);

    printf("\n\nc) Replacement LCR=>FSF");
    n = 0;
    /*
    while (rtext[n] != 0) {
        if (
                rtext[n] == 'L'
                and rtext[n + 1] == 'C'
                and rtext[n + 2] == 'R'
                ) {
            rtext[n] = 'F';
            rtext[n + 1] = 'S';
            rtext[n + 2] = 'F';
        }
        n++;
    }
     */
    /*
     *  tady to chce cyklus, ale nevím, jakou podmínku
     */
    //do {
    pointer = strstr(rtext, "LCR");
    strncpy(pointer, "FSF", 3);
    pointer = strstr(rtext, "LCR");
    strncpy(pointer, "FSF", 3);

    //} while (pointer != NULL);

    printf("\n\n%s", rtext);

    printf("\n\nd) Shift down in ASCII table:");
    n = 0;
    while (rtext[n] != 0) {
        rtext[n] = rtext[n] - 1;
        n++;
    }
    printf("\n\n%s", rtext);

    printf("\n\ne) Replacement capital=>small:");
    diff = 'A' - 'a';
    n = 0;
    while (rtext[n] != 0) {
        if (n > 0)
            rtext[n] = rtext[n] - diff;
        n++;
    }
    printf("\n\n%s", rtext);

    printf("\n\nf) Replacement a=><space> and b=>. :");
    n = 0;
    while (rtext[n] != 0) {
        if (rtext[n] == 'a') rtext[n] = ' ';
        if (rtext[n] == 'b') rtext[n] = '.';
        n++;
    }
    printf("\n\n%s", rtext);


    printf("\n\n");


    //scanf("%c", &c);										// waiting for pressing key
    return 0; // program returns 0
}



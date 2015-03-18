#include "stdio.h"

int main(void) {
    char text[] = "cat dog hen duck goat pig horse sheep cow lion tiger wolf fox elephant hippo owl eagle sparrow swallow"; // animal words separated by spaces
    int words = 1; // total number of words
    int nchar[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // array for counting of word with given number of characters
    int m = 0; // counter for number of characters in word
    int n = 0;
    int i;
    char c;


    printf("List of words in string: \n\n");

    while (text[n] != 0) {
        m++;
        printf("%c", text[n]);
        if (text[n] == ' ' || text[n] == 0) {
            m--;
            printf("\n");
            nchar[m]++;
            m = 0;
            words++;
        }
        n++;
    }
    nchar[m]++;

    printf("\n\nThe total number of words is: %i\n\n", words);

    for (i=0; i<10; i++){
        if(nchar[i]>0)
            printf("\nThe number of words with %i characters is %i", i, nchar[i]);
    }

    printf("\n\n");

    scanf("%c", &c);							// waiting for pressing key
    return 0; // program returns 0
}


#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "string.h"

typedef double t_temp[16][12];

void prn_mons(int tabs, int spaces) {
    int k = 0;
    int i = 0;
    char mon[] = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    for (i = 0; i < tabs; i++) {
        printf("    ");
    }
    while ((k < (strlen(mon)))) {
        if (mon[k] == ',') {
            for (i = 0; i < spaces; i++) {
                printf(" ");
            }
        } else printf("%c", mon[k]);
        k++;
    }

    printf("\n");

}

void prn_mon(int monord) {
    int k = 0;
    char mon[] = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    for (k = (monord - 1)*4; k < (monord - 1)*4 + 3; k++) {
        printf("%c", mon[k]);
    }
}

double mean_row(t_temp temp_tab, int year, int month_start, int month_end) { // prùmìr v jednom roku za více mìsícù
    int i;
    double avg = 0;

    for (i = month_start; i <= month_end; i++) {
        avg += temp_tab[year][i - 1];
    }
    avg /= (month_end - month_start + 1);

    return avg;
}

double mean_col(t_temp temp_tab, int month, int year_start, int year_end) { // prùmìr jednoho mìsíce za více rokù
    int i;
    double avg = 0;

    for (i = year_start; i <= year_end; i++) {
        avg += temp_tab[i][month];
    }
    avg /= (year_end - year_start + 1);

    return avg;
}

void temp_deviations(t_temp temp_tab, t_temp temp_dev) {
    int i, k;

    for (i = 0; i < 16; i++) {
        for (k = 0; k < 12; k++) {
            temp_dev[i][k] = temp_tab[i][k] - mean_col(temp_tab, k, 0, 15);
        }
    }
}

void sort_col(t_temp temp_tab, int month, int year_start, char opt) {
    int years[16];
    double temps[16];
    double tempf;
    int i, k;

    for (i = 0; i < 16; i++) {
        years[i] = year_start + i;
        temps[i] = temp_tab[i][month - 1];
    }

    for (i = 0; i < 16 - 1; i++) {
        for (k = 0; k < 16 - 1; k++) {
            if ((opt == 'u' && temps[k] > temps[k + 1]) || (opt == 'd' && temps[k] < temps[k + 1])) {
                tempf = temps[k + 1];
                temps[k + 1] = temps[k];
                temps[k] = tempf;

                tempf = years[k + 1];
                years[k + 1] = years[k];
                years[k] = tempf;
            }
        }
    }

    printf("\nSorted temperatures and relevant years for ");
    prn_mon(month);
    printf(":");
    for (i = 0; i < 16; i++) {
        printf("\n%i:  %.1f", years[i], temps[i]);
    }
    printf("\n");


}

int main(void) {
    t_temp temp = {-1.1, -0.3, 7.6, 12.7, 19.2, 27.6, 29.3, 29.1, 22.4, 14.2, 8.1, 0.5,
        -2.1, -1.1, 5.4, 11.0, 18.4, 23.9, 32.5, 26.0, 19.4, 11.8, 6.2, -0.5,
        -0.3, -1.3, 9.9, 13.7, 20.3, 22.0, 28.4, 28.1, 20.2, 14.6, 7.3, 0.4,
        1.1, -0.7, 10.6, 14.0, 17.5, 25.0, 27.3, 30.2, 23.2, 10.9, 5.2, 0.0,
        -8.6, -2.5, 5.1, 12.2, 15.2, 25.0, 25.3, 28.3, 24.9, 9.2, 1.5, 0.2,
        -3.1, -0.3, 4.6, 12.3, 14.0, 28.6, 29.0, 32.5, 22.0, 12.3, 9.1, 4.3,
        -2.5, 0.8, 7.7, 11.4, 17.2, 21.9, 29.0, 26.9, 17.1, 13.3, 3.1, 0.6,
        -1.0, -1.1, 7.3, 16.6, 18.0, 22.9, 27.1, 28.5, 19.4, 14.3, 8.0, 0.9,
        0.0, 2.6, 7.8, 10.9, 19.1, 28.8, 28.1, 28.1, 18.5, 13.8, 6.0, 1.5,
        0.2, 1.4, 8.6, 10.0, 18.1, 25.5, 32.5, 27.0, 20.4, 12.0, 2.0, 2.5,
        -0.7, -0.1, 6.1, 13.0, 18.4, 24.1, 31.9, 29.0, 21.6, 11.0, 5.3, 3.0,
        -5.4, 3.3, 11.6, 12.8, 16.9, 23.8, 28.7, 29.0, 23.4, 13.7, 3.8, 4.1,
        -3.8, 0.8, 13.1, 12.6, 13.7, 23.7, 26.3, 25.8, 20.8, 14.9, 6.7, 1.3,
        -1.2, 0.0, 8.6, 15.9, 15.6, 26.6, 29.2, 26.6, 20.8, 15.1, 4.1, -7.4,
        -2.5, 2.5, 8.8, 11.7, 19.8, 27.3, 33.3, 25.4, 22.9, 14.1, 4.1, 2.9,
        -6.4, -6.3, 2.5, 13.8, 19.1, 27.6, 28.1, 23.2, 20.1, 12.0, 5.1, 0.8}; // temp. table				// temp. table

    t_temp temp_dev;
    int styear = 1995; // starting year
    int enyear = 2010; //ending year
    char c; // char variable for pressed key
    int k, i;

    /* printing "Temperature table:" */
    printf("Temperature table:\n\n");
    prn_mons(3, 3); // printing months
    k = 0;
    do {
        printf("%d:    ", styear + k);
        for (i = 0; i < 12; i++) {
            printf("%6.1f", temp[k][i]);
        }
        printf("\n");
        k++;
    } while (k < 16);


    /* Prùmìrná teplota v mìsíci za 5 rokù ("pìtiletky") */
    printf("\n");
    printf("Average temperature of a month for a given years:\n\n");
    prn_mons(3, 3);
    for (k = 0; k < 3; k++) {
        printf("%i-%i", styear + (k * 5) + 1, styear + (k * 5) + 1 + 4);
        for (i = 0; i < 12; i++) {
            printf("%6.1f", mean_col(temp, i, (k * 5) + 1, (k * 5) + 1 + 4));
        }
        printf("\n");
    }


    /* Prùmìrná teplota za 4 mìsíce ("kvartály") */
    printf("\n");
    printf("Average temperature in quarters:\n\n");
    printf("       ");
    for (i = 0; i < 4; i++) {
        printf("   ");
        prn_mon((i * 3) + 1);
        printf("-");
        prn_mon((i * 3) + 1 + 2);
    }
    printf("\n");
    for (k = styear; k <= enyear; k++) {
        printf("%i:", k);
        for (i = 0; i < 4; i++) {
            printf("%10.1f", mean_row(temp, (k - styear), (i * 3) + 1, (i * 3) + 1 + 2));
        }
        printf("\n");
    }


    /* Tabulka odchylek */
    temp_deviations(temp, temp_dev);

    printf("\nTemperature deviation table: \n\n");
    prn_mons(3, 3); // printing months
    for (k = 0; k < 16; k++) {
        printf("%d:    ", styear + k);
        for (i = 0; i < 12; i++) {
            printf("%6.1f", temp_dev[k][i]);
        }
        printf("\n");
    }


    /* Seøazování */
    printf("\nIn main: sort_col(temp, 7, styear, 'u')\n");
    sort_col(temp, 7, styear, 'u');

    printf("\nIn main: sort_col(temp, 7, styear, 'd')\n");
    sort_col(temp, 7, styear, 'd');

    scanf("%c", &c); // waiting for pressing key
    return 0; // program returns 0
}


#include "stdafx.h"
#include "stdio.h"
#include "math.h"

int main(void) {
    float temp[16][12] = {-1.1, -0.3, 7.6, 12.7, 19.2, 27.6, 29.3, 29.1, 22.4, 14.2, 8.1, 0.5,
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
        -6.4, -6.3, 2.5, 13.8, 19.1, 27.6, 28.1, 23.2, 20.1, 12.0, 5.1, 0.8};


    //    char mon[] = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC"; // abbreaviations of months
    char mon[] = "JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC"; // abbreaviations of months
    int styear = 1995; // starting year
    int i, j, k, l, m, n, mc, yc;
    float min[20];
    float hel[20];
    float avg[3][12];
    float diff;

    printf("Temperature table:");
    printf("\n\n");

    printf("     ");
    for (i = 0; i < 12; i++) printf("%4c%c%c", mon[i * 3], mon[(i * 3) + 1], mon[(i * 3) + 2]);
    for (i = 0; i <= (2010 - styear); i++) {
        printf("\n%i:", (styear + i));
        for (j = 0; j < 12; j++) {
            printf("%6.1f", temp[i][j]);
        }
    }

    printf("\n\n\nAverage temperature in month (in period 1996-2000, 2001-2005, 2006-2010):");
    printf("\n            ");
    for (i = 0; i < 12; i++) printf("%4c%c%c", mon[i * 3], mon[(i * 3) + 1], mon[(i * 3) + 2]);
    for (i = 0; i<12; i++){
        for(j=1; j<=(2010-styear); j++){
            if(j<6) m=0;
            else if(j<11) m=1;
            else m = 2;
            avg[m][i]+=temp[j][i];
            printf("%6.1f\n", avg[m][i]);
            //printf("%6.1f", temp[j][i]);
        }
        printf("\n\n");
    }
    printf("\n1996-2000:");
    for (i=0; i<12; i++) printf("%6.1f", avg[0][i]/5);
    printf("\n2001-2005:");
    for (i=0; i<12; i++) printf("%6.1f", avg[1][i]/5);
    printf("\n2006-2010:");
    for (i=0; i<12; i++) printf("%6.1f", avg[2][i]/5);
    


    printf("\n\n\nThe coldest month (in period 1996-2010):");
    printf("\n            ");
    for (i = 0; i < 12; i++) printf("%4c%c%c", mon[i * 3], mon[(i * 3) + 1], mon[(i * 3) + 2]);
    printf("\nTemperature:");
    for (i = 0; i < 12; i++) {
        for (j = 1; j < (2010 - styear); j++) {
            if ((j == 1) || (min[i] > temp[j][i])) min[i] = temp[j][i];
        }
        printf("%6.1f", min[i]);
    }
    printf("\nYear       :");
    for (i = 0; i < 12; i++) {
        for (j = 0; j < (2010 - styear); j++) {
            if (min[i] == temp[j][i]) min[i] = styear + j;
        }
        printf("%6.0f", min[i]);
    }

    printf("\n\n\nThe hottest month (in period 1996-2010):");
    printf("\n            ");
    for (i = 0; i < 12; i++) printf("%4c%c%c", mon[i * 3], mon[(i * 3) + 1], mon[(i * 3) + 2]);
    printf("\nTemperature:");
    for (i = 0; i < 12; i++) {
        for (j = 1; j < (2010 - styear); j++) {
            if ((j == 1) || (min[i] < temp[j][i])) min[i] = temp[j][i];
        }
        printf("%6.1f", min[i]);
    }
    printf("\nYear       :");
    for (i = 0; i < 12; i++) {
        for (j = 0; j < (2010 - styear); j++) {
            if (min[i] == temp[j][i]) min[i] = styear + j;
        }
        printf("%6.0f", min[i]);
    }

    printf("\n\n\nMean and standart deviation of temperature in month:");
    printf("\n                   ");
    for (i = 0; i < 12; i++) printf("%4c%c%c", mon[i * 3], mon[(i * 3) + 1], mon[(i * 3) + 2]);
    printf("\nMean val. [deg. C]:");
    for (i = 0; i < 12; i++) {
        min[i] = 0;
        hel[i] = 0;
        for (j = 0; j <= (2010 - styear); j++) {
            min[i] += temp[j][i];
            hel[i] += (temp[j][i] * temp[j][i]);
        }
        printf("%6.1f", (min[i] / (2010 - styear + 1)));
    }
    printf("\nSt. dev. [deg. C] :");
    for (i = 0; i < 12; i++) {
        printf("%6.2f", sqrt((hel[i] / 16)-(min[i] * min[i] / 256)));
    }


    diff = 0;
    for (i = 0; i < (12 * (2010 - styear)); i++) {
        k = (int) i / 12;
        l = i % 12;
        m = (int) (i + 1) / 12;
        n = (i + 1) % 12;
        if (fabs(diff) < fabs(temp[k][l] - temp[m][n])) {
            diff = temp[m][n]-temp[k][l];
            mc = l + 1;
            yc = k + styear;
        }
    }
    k = (mc+1)%12;
    if (mc+1==k) l = yc;
    else l=yc+1;

    printf("\n\nThe maximum change of temperature happened between %i/%i and %i/%i", mc, yc, k, l);
    printf("\nThe difference of temperature was %.1f deg. C.", diff);

    printf("\n\n\nSorted temperatures and relevant years for July:");
    for(i=0; i<=(2010-styear); i++){
        hel[i] = temp[i][6];
    }
    l = 0;
    for(i=0; i<(2010-styear); i++){
        for(j=0; j<(2010-styear); j++){
            l++;
            if(hel[j]>hel[j+1]){
                diff = hel[j];
                hel[j]=hel[j+1];
                hel[j+1]=diff;
            }
        }
    }
    for(i=0; i<=(2010-styear); i++){
        printf("\n%.1f", hel[i]);
    }

    printf("\n\n%i steps performed during sorting.", l);

    printf("\n\n");
    return 0; // program returns 0
}
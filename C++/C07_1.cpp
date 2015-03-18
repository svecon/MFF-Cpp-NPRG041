#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef union t_quantity // union of quantity
{
    double mass; // mass in kilograms
    int number; // number in pieces
};

typedef struct t_frtvgtbl // structure of record for goods (fruit and vegetable) in store
{
    char sort[20]; // sort of goods - max. 19 characters
    char country[4]; // shipping country - max. 3 characters
    double price; // price in kc per kilogram or per piece
    char qtype; // quantity type: 'm' means mass, 'p' means pieces
    t_quantity quantity; // quantity in kilograms or pieces - union

};

typedef struct t_bill // structure of record for shopping
{
    int code; // code of goods
    double quant; // quantity of goods (in kg or pcs)
};

typedef struct t_record // structure of record for pointer and status of record for goods in store
{
    t_frtvgtbl *recptr; // pointer to record for goods in store
    char status; // status of record for goods in store 'o' means occupied, 'f'means free
};

t_record rec[30]; // array of records for pointers and statutes of records for goods in store
t_bill bill[30]; // array of records for bought goods
int nbill = 0; // number of filled records for bought goods

void init_recs(void) // function for store initialization by chosen goods
{
    t_frtvgtbl *my_rec;

    my_rec = (t_frtvgtbl*) malloc(sizeof (t_frtvgtbl));
    strcpy(my_rec->sort, "Pomeranc");
    strcpy(my_rec->country, "ESP");
    my_rec->price = 29.90;
    my_rec->qtype = 'm';
    my_rec->quantity.mass = 150.02;
    rec[0].status = 'o';
    rec[0].recptr = my_rec;
    my_rec = (t_frtvgtbl*) malloc(sizeof (t_frtvgtbl));
    strcpy(my_rec->sort, "Mandarinka");
    strcpy(my_rec->country, "MAR");
    my_rec->price = 33.90;
    my_rec->qtype = 'm';
    my_rec->quantity.mass = 85.55;
    rec[1].status = 'o';
    rec[1].recptr = my_rec;
    my_rec = (t_frtvgtbl*) malloc(sizeof (t_frtvgtbl));
    strcpy(my_rec->sort, "Grep cerv.");
    strcpy(my_rec->country, "CUB");
    my_rec->price = 34.90;
    my_rec->qtype = 'm';
    my_rec->quantity.mass = 45.85;
    rec[2].status = 'o';
    rec[2].recptr = my_rec;
    my_rec = (t_frtvgtbl*) malloc(sizeof (t_frtvgtbl));
    strcpy(my_rec->sort, "Grep bily");
    strcpy(my_rec->country, "ESP");
    my_rec->price = 31.90;
    my_rec->qtype = 'm';
    my_rec->quantity.mass = 65.08;
    rec[4].status = 'o';
    rec[4].recptr = my_rec;
    my_rec = (t_frtvgtbl*) malloc(sizeof (t_frtvgtbl));
    strcpy(my_rec->sort, "Pomelo   ");
    strcpy(my_rec->country, "CHN");
    my_rec->price = 36.00;
    my_rec->qtype = 'p';
    my_rec->quantity.number = 42;
    rec[5].status = 'o';
    rec[5].recptr = my_rec;
    my_rec = (t_frtvgtbl*) malloc(sizeof (t_frtvgtbl));
    strcpy(my_rec->sort, "Kivi     ");
    strcpy(my_rec->country, "ITA");
    my_rec->price = 4.00;
    my_rec->qtype = 'p';
    my_rec->quantity.number = 956;
    rec[7].status = 'o';
    rec[7].recptr = my_rec;
    my_rec = (t_frtvgtbl*) malloc(sizeof (t_frtvgtbl));
    strcpy(my_rec->sort, "Jahody   ");
    strcpy(my_rec->country, "FRA");
    my_rec->price = 68.90;
    my_rec->qtype = 'm';
    my_rec->quantity.mass = 45.23;
    rec[9].status = 'o';
    rec[9].recptr = my_rec;
    my_rec = (t_frtvgtbl*) malloc(sizeof (t_frtvgtbl));
    strcpy(my_rec->sort, "Svestky  ");
    strcpy(my_rec->country, "CZE");
    my_rec->price = 46.90;
    my_rec->qtype = 'm';
    my_rec->quantity.mass = 17.53;
    rec[10].status = 'o';
    rec[10].recptr = my_rec;
    my_rec = (t_frtvgtbl*) malloc(sizeof (t_frtvgtbl));
    strcpy(my_rec->sort, "Hrusky   ");
    strcpy(my_rec->country, "CZE");
    my_rec->price = 39.90;
    my_rec->qtype = 'm';
    my_rec->quantity.mass = 121.82;
    rec[11].status = 'o';
    rec[11].recptr = my_rec;
    my_rec = (t_frtvgtbl*) malloc(sizeof (t_frtvgtbl));
}

void print_store(void) // function for printing of store sum
{
    int n;

    printf("\nStore list:\n\n");
    for (n = 0; n < 30; n++)
        if (rec[n].status == 'o') // occupated records are printed only
        {
            if (rec[n].recptr->qtype == 'p')
                printf("%s (%s) \ncode: %d \tquantity: %6d pcs \tprice: %5.2f Kc/pc\n\n", rec[n].recptr->sort, rec[n].recptr->country, n + 1, rec[n].recptr->quantity.number, rec[n].recptr->price);
            else if (rec[n].recptr->qtype == 'm')
                printf("%s (%s) \ncode: %d \tquantity: %6.2f kg \tprice: %5.2f Kc/kg\n\n", rec[n].recptr->sort, rec[n].recptr->country, n + 1, rec[n].recptr->quantity.mass, rec[n].recptr->price);

        }
}

int print_freeitems(void) // function for printing of free records (codes) for goods in store
{
    int n;
    int free[30];
    int count_free = 0;

    /* determinating */

    for (n = 0; n < 30; n++) {
        if (rec[n].status != 'o') {
            free[count_free] = n + 1;
            count_free += 1;
        }
    }

    /* printing */

    printf("\nFree codes: ");
    for (n = 0; n < count_free; n++) {
        if (n > 0) printf(", ");
        printf("%i", free[n]);
    }
    printf("\n");
}

int add_newitem(void) // function for new sort of goods adding
{
    t_frtvgtbl *new_good;
    int new_code;

    print_freeitems();
    new_good = (t_frtvgtbl*) malloc(sizeof (t_frtvgtbl));

    printf("\nCode: ");
    scanf("%d", &new_code);
    new_code -= 1;

    printf("\nSort: ");
    scanf("%s", &new_good->sort);

    printf("\nCountry: ");
    scanf("%s", &new_good->country);

    fflush(stdin);
    printf("\nQuantity type (m/p): ");
    scanf("%c", &new_good->qtype);

    printf("\nQuantity in ");
    if (new_good->qtype == 'm') printf("kg");
    else printf("pc");
    printf(": ");
    if (new_good->qtype == 'm') scanf("%lf", &new_good->quantity.mass);
    else scanf("%d", &new_good->quantity.number);

    printf("\nPrice (");
    if (new_good->qtype == 'm') printf("kg");
    else printf("pc");
    printf("/Kc): ");
    scanf("%lf", &new_good->price);

    fflush(stdin);

    rec[new_code].status = 'o';
    rec[new_code].recptr = new_good;
}

void add_item(void) // function for increase of quantity of know goods in store
{
    int code_selected;
    t_quantity additional;
    bool in_kgs = true;

    printf("\nInsert code: ");
    scanf("%d", &code_selected);
    fflush(stdin);

    code_selected -= 1;

    if (rec[code_selected].recptr->qtype == 'p') in_kgs = false;

    printf("\n\nCurrent quantity of %s is: ", rec[code_selected].recptr->sort);
    if (in_kgs) printf("%.2f kg", rec[code_selected].recptr->quantity.mass);
    else printf("%i pcs", rec[code_selected].recptr->quantity.number);

    printf("\nInsert additional quantity in ");
    if (in_kgs) printf("kg");
    else printf("pcs");
    printf(": ");

    if (in_kgs) {
        scanf("%lf", &additional.mass);
        rec[code_selected].recptr->quantity.mass += additional.mass;
    } else {
        scanf("%d", &additional.number);
        rec[code_selected].recptr->quantity.number += additional.number;
    }
    fflush(stdin);

    printf("\nNew quantity of %s is: ", rec[code_selected].recptr->sort);
    if (in_kgs) printf("%.2f kg", rec[code_selected].recptr->quantity);
    else printf("%i pcs", rec[code_selected].recptr->quantity);

}

void sell_item(void) // function for sale of goods (one item) - added sequentialy to array bill[], order of current free element is stored in global variable nbill
{
    double ammount;
    int code_sel;
    bool in_kgs = true;

    printf("\nInsert code: ");
    scanf("%d", &code_sel);
    fflush(stdin);

    code_sel -= 1;

    if (rec[code_sel].recptr->qtype == 'p') in_kgs = false;

    printf("%s: insert quantity in ", rec[code_sel].recptr->sort);
    if (in_kgs) printf("kg");
    else printf("pcs");
    printf(": ");

    scanf("%lf", &ammount);
    fflush(stdin);

    bill[nbill].code = code_sel + 1;
    bill[nbill].quant = ammount;
    nbill += 1;

    printf("%s: ", rec[code_sel].recptr->sort);
    if (in_kgs)
        printf("%.2f kg  a %.2f Kc/kg", ammount, rec[code_sel].recptr->price);
    else
        printf("%.2f pcs a %.2f Kc/pcs", ammount, rec[code_sel].recptr->price);
    printf(", suma: %.2f Kc", ammount * rec[code_sel].recptr->price);


}

void bill_sum(void) // function for final bill completation
{
    int n = 0; // order of element in bill[] array
    double sumprice = 0; // total price of shopping
    double itemprice; // price for one item

    printf("\nBill assembling:\n");
    printf("--------------------------------------------------------------------------------------");
    while (bill[n].code != 0) // sequentially adds items from array bill[]
    {
        itemprice = bill[n].quant * rec[bill[n].code - 1].recptr->price; // overall price of given item computation
        printf("\n%d. \t%s:\t %6.2f\t a %6.2f Kc/u\t sum:    %7.2f Kc", n + 1, rec[bill[n].code - 1].recptr->sort, bill[n].quant, rec[bill[n].code - 1].recptr->price, itemprice);
        sumprice += itemprice; // adding price for given item to total price
        bill[n].code = 0; // clearing of items of array bill[], which are already counted to totla price
        bill[n].quant = 0;
        n++; // next element of bill[] array
    }// printing of final price
    printf("\n--------------------------------------------------------------------------------------");
    printf("\nSUM incl. VAT (10 proc.) \t\t\t\t %7.2f Kc", sumprice);
    printf("\nVAT (10 proc.)           \t\t\t\t %7.2f Kc", sumprice * 0.10);
    printf("\nSUM excl. VAT            \t\t\t\t %7.2f Kc", sumprice * 0.90);
    printf("\n--------------------------------------------------------------------------------------\n");
    nbill = 0; // array bill[] is now free, order of elements is set to start
}

int main(void) {
    char cmd; // command character
    int n; // index for loops

    for (n = 0; n < 30; n++) // records initialization - all are free
    {
        rec[n].status = 'f';
        bill[n].code = 0;
        bill[n].quant = 0;
    }
    init_recs(); // initial filling of store
    print_store(); // printing of store content

    printf("\nInsert command: 'q' = quit, 'p' = printing store, 'a' = adding goods, 'n' = new item, 's' = sell goods ");
    scanf("%c", &cmd);
    fflush(stdin);
    while (cmd != 'q') // if not quit
    {
        switch (cmd) {
            case 'p': print_store();
                break;
            case 'a': add_item();
                break;
            case 'n': add_newitem();
                break;
            case 's':
            {
                cmd = 'n';
                while (cmd == 'n') {
                    sell_item();
                    printf(" ('n' = next item, other = bill)");
                    scanf("%c", &cmd);
                    fflush(stdin);
                }
                bill_sum();
            }
        }
        printf("\nInsert command: 'q' = quit, 'p' = printing store, 'a' = adding goods, 'n' = new item, 's' = sell goods ");
        scanf("%c", &cmd);
        fflush(stdin);
    }
}

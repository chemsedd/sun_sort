        //--------------- Le programme de tri-à-bulles -----------------
//---Les bibiliotheques necéssaires !

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//---Reglage de fgets()

void string_fix ( char string [] )
{
    char *f = NULL;

    if ( f = strchr ( string , '\n' ) )
        *f = '\0';
}

//---Verification des entiers

bool check ( char number [] )
{
    bool test = true;
    int i;
    int cont = 0;

    string_fix ( number ); //--Regler fgets() avant la verification

    for (i = 0 ; i < strlen( number ) ; i ++)
    {
        if ( isdigit ( number [i] ) )
            cont++;
        else
        {
            printf("\n\t\t\tError ## please ENTER A VALIDE NUMBER : ");
            return !test;
        }

    }
    if ( cont > 4 )
    {
        printf("\n\t\t\tError ## The number must contain 4 digits at MAX ! Try again : ");
        return !test;
    }
    return test;
}

//---Fonction de lecture des entiers

int get_int ()
{
    char number[10];
    bool test;

    typing : fgets( number , sizeof ( number ) , stdin );
    fflush(stdin);

    if ( !check( number ) )
        goto typing;

    return atoi(number);
}

//---Lecture du tableau ( remplissage du tableau)

void read_table ( int *table , int table_size )
{
    int i;
    int number;

    printf("\n\n\t\tFill in the table : ");
    for ( i = 0 ; i < table_size ; i++ )
    {
        printf("\n\n\t\t\t>---> Type a number [ %d ] : ",i+1);
        table [i] = get_int();
    }
}

//---Affichage du tableau

void show_table ( int *table , int table_size )
{
    int i,j=7;

    printf("\n\n\n\n\n");

    for ( i = 0 ; i <
    j * table_size ; i++ )
        if ( i == 0 )
            printf("\t\t\t\t+");
        else
            if ( i % j == 0 )
                printf("+");
            else
                printf("-");

    printf("+\n");

    for ( i = 0 ; i < table_size ; i++ )
    {
        if ( i == 0 )
            printf("\t\t\t\t|");
        printf(" %4d |" , table [i] );
    }

    printf("\n");

    for ( i = 0 ; i < j * table_size ; i++ )
        if ( i == 0 )
            printf("\t\t\t\t+");
        else
            if ( i % j == 0 )
                printf("+");
            else
                printf("-");

    printf("+\n\n\n\n\n");
}

//---Permutation ( x prends la valeur de y et Vice-Versa )

void swap ( int *a , int *b )
{
    int x;

     x = *a;
    *a = *b;
    *b =  x;
}

//---L'algorithme de Tri-à-Bulles

void bubble_sort ( int *table , int table_size )
{
    int i;
    int j;
    int size;
    int c = 0;
    bool changed;
    bool sorted = true;

    size = table_size;

    do {
        changed = false;
        for ( i = 0 ; i < size - 1 ; i++ )
        {
            j = i + 1;
            if ( table [i] > table [j] )
            {
                sorted = false;
                c++;
                printf("\n\t\t\t\t#--#   Changed in iteration n : %d #--#",c);
                swap ( &table [i] , &table [j] );
                changed = true;
                Sleep ( 4500 );
                show_table ( table , table_size );
            }
        }
        size--;
    } while ( changed );
    if ( sorted )
        printf("\n\t\t\t\tTable is already sorted.\n\n");
    else
        printf("\n\t\t\t\t Sort finished ! \n\n");
}

//---Affichage du titre

void Show_title()
{
    printf("\n\n\t\t\t+----------------------------------------+"
           "\n\t\t\t|                                        |"
           "\n\t\t\t|        BUBBLE-SORT ALGORITHM           |"
           "\n\t\t\t|                                        |"
           "\n\t\t\t+----------------------------------------+");
}

//---Programme principale (main)

int main()
{
    int *table;
    int i;
    int j;
    int table_size;
    int choice;

    system("Color 81");

    Show_title();

    start : printf("\n\n\n\t\t#-----# Set the size of your table : ");
    table_size = get_int();

    table = ( int* ) malloc ( table_size * sizeof ( int ) );

    read_table ( table , table_size );

    printf("\n\t\t//-------- Table before bubble sort --------\\\ \n");
    show_table ( table , table_size );

    printf("\n\t\t//----------      Sorting table   ----------\\\ \n");
    bubble_sort ( table , table_size );

    printf("\n\t\tExit/Again ( 0 / 1 ) ? ");
    ask : choice = get_int();

    if ( choice == 1 )
        goto start;
    else if ( choice == 0 )
        exit(0);
        else
        {
            printf("\n\t\t\tWrong Choice please try again !!! : ");
            goto ask;
        }
}

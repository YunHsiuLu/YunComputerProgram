#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t card_number = 0;
    int32_t suit = 0;

    printf( "Please enter a card number (1-54):\n" );
    scanf( "%d", &card_number );

    if( card_number < 1 || card_number > 54 )
    {
        printf( "Wrong Input!\n" );
        return 0;
    }

    suit = ( card_number - 1 ) / 13;

    switch( suit )
    {
        case 0:
            printf( "Spade %d\n", card_number % 13 );
            break;
        case 1:
            printf( "Heart %d\n", card_number % 13 );
            break;
        case 2:
            printf( "Diamond %d\n", card_number % 13 );
            break;
        case 3:
            printf( "Club %d\n", card_number % 13 );
            break;
        case 4:
            printf( "Joker\n" );
            break;
        default:
            printf( "Unknown\n" );
            break;
    }

    return 0;
}

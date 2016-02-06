#include <stdio.h>
void main(void)
{
double price ;
int discount = 25 ;

printf ("Please enter the price before discount: ") ;
scanf ("%lf", &price) ;

price = price - price * discount / 100 ;

printf ("Please pay: $%.2lf\n", price );
}


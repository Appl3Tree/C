#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int input = 0;
	int scanfResult = 0;
	do
	{
		printf("%s", "Enter a number between 1 and 10 here: ");
		scanfResult = scanf("%d", &input);
		if ( scanfResult != 1 )
		{
			printf( "Error! The input was not between 1 and 10 and closed the scanf function.\n" );
			exit( 1 );
		}
	}
	while ( ( input < 1 || input > 10 ) );
	printf("You entered %d.\n", input);
}

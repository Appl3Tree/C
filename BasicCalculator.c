/*
	Programmer: Forrest Connelly
	Program: Basic Calculator
	Goal: Testing out storing a character into an array for determining the math calculation.
*/
#include <stdio.h>

int main( void )
{
	//	Declare variable(s).
	char action[1];
	float num1;
	float num2;

	//	Initialize variable(s).
	action[0] = 0;
	num1 = 0;
	num2 = 0;

	do
	{
		//	Display a blank line for readability.
		puts( "" );
	
		//	Display what to do and an example then scan in variable
		//	values.
		puts( "Do math stuffs." );
		puts( "Example: 1 + 2" );
		scanf( "%f%1s%f", &num1, action, &num2 );
	
		//	Depending on the value of action, use a switch statement
		//	to perform arithmetic.
		switch( action[0] )
		{
			case '+':
				printf( "%f + %f = %f\n", num1, num2, num1 + num2 );
				break;
	
			case '-':
				printf( "%f - %f = %f\n", num1, num2, num1 - num2 );
				break;
	
			case '*':
				printf( "%f * %f = %f\n", num1, num2, num1 * num2 );
				break;
	
			case '/':
				printf( "%f / %f = %f\n", num1, num2, num1 / num2 );
				break;
		} 
	} while ( (num1 = getchar()) != EOF );

	//	Display a blank line for readability.
	puts( "" );
}

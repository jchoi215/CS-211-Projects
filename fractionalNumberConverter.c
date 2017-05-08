#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


// 
// Name: Jae Rim Choi
//



int convertBinary(char* argument)
{
	int result = 0;
	int length = strlen(argument);
	int exp = 0;
	int i;

	for(i = length-1; i >= 0; i--)
	{
		if(argument[i] == '1') result += pow(2, exp);
		exp += 1;
	}

	return result;
}



void part2()
{
	printf("\n** ERROR: PART 2 HAS NOT BEEN BUILT YET **\n\n");

// BASIS FOR THIS EQUATION:
//
// ** UNKNOWN ** 
//
//




// 	char expBits [10];
// 	char mantissa[20];

// 	int numExpBits;
// 	int fractiBits;
// 	int expoBias;



// 	printf("\n\n======= [ CREATING BASIS ] =======\n");	
// 	printf("please input [Given Exponent bias]: "); scanf("%d",&expoBias);   getchar();
// 	printf("please input [ # of exponent bits]: "); scanf("%d",&numExpBits); getchar();
// 	printf("please input [ # of fraction bits]: "); scanf("%d",&fractiBits); getchar();
// 	printf("==================================\n\n");
	

// 	void convertToBinary(int value)
// 	{
// 		int length =15;
// 		char binary[length];
// 		int i;
		
// 		int creatingValue = 0;
// 		for(i = length-1; i <= 0; i--)
// 		{
			


// 		}



// 	} 

// 	printf("ERROR: system only running whole numbers...\n");
// 	printf("please input [value]: "); scanf("%d",&sign); getchar();

// 	while(1)
// 	{
// 		int sign;
// 		if(value < 0)
// 		{
// 			sign   = -1;
// 			value *= -1;
// 		}

// 		convertToBinary(value);

// 		// char * convert = (rein)
	
// 		printf("==================================\n\n");
// 		printf("please input [value]: "); scanf("%d",&sign); getchar();
// 	}

}








void part1()
{
	char expBits [10];
	char mantissa[20];

	int numExpBits;
	int fractiBits;
	int expoBias;



	printf("\n======= [ CREATING BASIS ] =======\n");	
	printf("please input [Given Exponent bias]: "); scanf("%d",&expoBias);   getchar();
	printf("please input [ # of exponent bits]: "); scanf("%d",&numExpBits); getchar();
	printf("please input [ # of fraction bits]: "); scanf("%d",&fractiBits); getchar();
	printf("==================================\n\n");
	
	int  sign = 0;
	printf("please input [sign]: "); scanf("%d",&sign); getchar();

	while(sign != -1)
	{

		while(1)
		{
			printf("please input Exponent Bits [length of %d]: ", numExpBits ); gets(expBits);
			expBits[strcspn(expBits, "\n\r")] = '\0';
			if(strlen(expBits) == numExpBits) break;
			else printf("ERROR: Exponent bit must be of [%d] length. \n", numExpBits );		
		}

		int expoResult = convertBinary(expBits);
		printf("result: %d\n", expoResult);


		while(1)
		{
			printf("please input mantissa Bits [length of %d]: ", fractiBits); gets(mantissa);
			mantissa[strcspn(mantissa, "\n\r")] = '\0';
			if(strlen(mantissa) == fractiBits) break;
			else printf("ERROR: mantissa bit must be of [%d] length. \n", fractiBits );		
		}
		
		int fracResult = convertBinary(mantissa);
		printf("result: %d\n", fracResult);


		int signCalc = pow(-1, sign);
		int denum    = pow(2, fractiBits);
		int offset   = expoResult - expoBias;
		int multi    = pow(2, offset);

		printf("Equation:\n  %d * ( (%d / %d)  + 1) * 2^%d \n", signCalc, fracResult, denum, offset );
		
		if(offset >= 0)
		{
			int calOffSet = pow(2, offset) * signCalc;
			int numA = calOffSet * fracResult;
			printf("Simplified more:\n  (%d / %d) + %d\n", numA, denum, calOffSet);
		}
		else
		{
			int calOffSet = pow(2, offset*-1);     
			int numA = (signCalc * fracResult);
			int denA = (calOffSet* denum);
			printf("Simplified more:\n  (%d / %d) - (2^%d) \n", numA, denA, offset);
		}
		printf("==================================\n\n");



		printf("please input [sign]: "); scanf("%d",&sign); getchar();
	}

}




int main()
{	
	while(1)
	{
		printf("================================== \n");
		printf("*  [ FLOATING POINT CONVERTER ]  * \n");
		printf("================================== \n\n");
		
		char q;
		while(1)
		{
			printf("[A] PART 1\n[B] PART 2\n[C] EXIT\nINSTRUCTION: ");
			scanf("%c", &q); getchar();
			if( q == 'a' || q == 'A' || q == 'b' || q == 'B'|| q == 'c' || q == 'C' ) break;
			printf("\n** ERROR: invalid input **\n\n");
		}

		switch(q)
		{
			case 'a':
			case 'A': part1(); break;
			case 'b':
			case 'B': part2(); break;
			case 'c': 
			case 'C': 
				printf("\n** CLOSING SYSTEM **\n\n"); exit(0);
				break;
		}		
	}
	
	return 0;
}
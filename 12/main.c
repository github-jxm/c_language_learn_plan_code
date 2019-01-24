#include <stdio.h>

#define P(A)      printf("%s:%d\n",#A,A);
#define SQUARE(x) printf("The square of "#x" is %d.\n", ((x)*(x)));

#define XNAME(n) x##n

int  main() 
{ 
	int a = 1, b = 2;
	int y =4;

	P(a);
	P(b);
	P(a+b);

	// #x被替换成字符串"y" 　　 
	SQUARE(y); // printf("square of " "y" " is %d.\n",(y)*(y))
	// #x被替换成字符串"6-3" 
	SQUARE(6-3); // printf("square of " "6-3" " is %d.\n",(6-3)*(6-3))
	// #x被替换成字符串"y+3" 
        SQUARE(y+3); // printf("square of " "y+3" " is %d.\n",(y+3)*(y+3)) 

	printf("\n");
	int XNAME(_1)  = 4 ;
        SQUARE(x_1); // printf("square of " "x_4" " is %d.\n",(x_4)*(x_4)) 
        SQUARE(XNAME(_1)); // printf("square of " "x_4" " is %d.\n",(x_4)*(x_4)) 

}



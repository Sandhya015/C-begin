#include <stdio.h>   

int main()
{
    int int1, int2;   

    printf("Input the values for Number1 and Number2 : ");   
    scanf("%d %d", &int1, &int2);   
    if (int1 == int2)  
        printf("Number1 and Number2 are equal\n");  
    else
        printf("Number1 and Number2 are not equal\n");   
}

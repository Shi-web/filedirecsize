/******************************************************************************

Name: Khushi Gauli
Student ID: 1002051688

*******************************************************************************/
#include <stdio.h>
#define BITS 8

void ConvertDecimalToBinary(int num, char cnum[]);
int main()
{
    int num1;
    int num2;
    int result;
    char Operator[3];
    char Cnum1[BITS+1] = {};
    char Cnum2[BITS+1] = {};
    char Cresult[BITS+1] = {};
    printf("Bitwise Calculator\n\n");
    printf("Enter two base 10 values with a bitwise operator to see the decimal result \nand the binary result. The format is\n\n");
    printf("FirstNumber BitwiseOperator SecondNumber \n\nFor example, enter the expression \n\n2 & 3\n\n");
    printf("This calculator can used with &, |, ^, << and >>\n\n");
    printf("Please note that the spaces between numbers and operator is essential \nand the two entered values must be between 0 and 255\n\n");
    
    printf("Enter expression  ");
    scanf("%d %s %d",&num1, Operator, &num2);
    
    
    while ( ( (num1<0)||(num1>255) ) || ( (num2<0)||(num2>255) ) )
    {
        printf("\nThe entered expression contains out of range values.\n");
        printf("Please reenter the expression using values between 0 and 255.\n");
        scanf("%d %s %d",&num1, Operator, &num2);
    }
   
    ConvertDecimalToBinary(num1,Cnum1);
    ConvertDecimalToBinary(num2,Cnum2);
    
    if (Operator[0] == '&')
    {
        result = num1&num2;
        ConvertDecimalToBinary(result,Cresult);
        printf("\nIn base 10...\n\n");
        printf("%d %s %d = %d",num1,Operator,num2,result);
        printf("\n\nIn %d-Bits base 2...\n\n",BITS);
        printf("   %s\n%s \n   %s",Cnum1,Operator,Cnum2);
        printf("\n===================\n");
        printf("   %s",Cresult);
        
    }
    
    else if (Operator[0] == '|')
    {
         result = num1|num2;
         ConvertDecimalToBinary(result,Cresult);
         printf("\nIn base 10...\n\n");
         printf("%d %s %d = %d",num1,Operator,num2,result);
         printf("\n\nIn %d-Bits base 2...\n\n",BITS);
         printf("   %s\n%s \n   %s",Cnum1,Operator,Cnum2);
         printf("\n===================\n");
         printf("   %s",Cresult);
        
    }
    
    else if (Operator[0] == '^') 
    {
         result = num1^num2;
         ConvertDecimalToBinary(result,Cresult);
         printf("\nIn base 10...\n\n");
         printf("%d %s %d = %d",num1,Operator,num2,result);
         printf("\n\nIn %d-Bits base 2...\n\n",BITS);
         printf("   %s\n%s \n   %s",Cnum1,Operator,Cnum2);
         printf("\n===================\n");
         printf("   %s",Cresult);
        
    }
    
    else if (Operator[0] == '<') 
    {
         result = num1<<num2;
         ConvertDecimalToBinary(result,Cresult);
         printf("\nIn base 10...\n\n");
         printf("%d %s %d = %d",num1,Operator,num2,result);
         printf("\n\nIn %d-Bits base 2...\n\n",BITS);
         printf("%s %s %d",Cnum1,Operator,num2);
         printf("\n%s",Cresult);
        
    }
    
    else if (Operator[0] == '>') 
    {
         result = num1>>num2;
         ConvertDecimalToBinary(result,Cresult);
         printf("\nIn base 10...\n\n");
         printf("%d %s %d = %d",num1,Operator,num2,result);
         printf("\n\nIn %d-Bits base 2...\n\n",BITS);
         printf("%s %s %d",Cnum1,Operator,num2);
         printf("\n%s",Cresult);
    }
    
    else
    {
        printf("Operator %s is not supported by this calculator", Operator);
    }
    
 
    return 0;
}

void ConvertDecimalToBinary(int num, char cnum[])
{
    int temp[BITS] = {};
    temp[0] = num;
    int val = BITS-1;
    int i;
    
    for(i = 0; i<=(BITS-1); i++)
    {
        temp[i+1] = temp[i]>>1;
        
    }
    
    for( i = 0; i<=(BITS-1); i++)
    {
        temp[i]=temp[i]&1;
        
    }
    
    for(i = 0; i<=(BITS-1); i++)
    {
        cnum[val] = temp[i]+'0';
        val--;
    }
    
}


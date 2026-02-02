/*Q1) Write a program to check a number is a prime or not.*/
#include <stdio.h>
int main(){
    int n,i,c = 1;
    printf("Enter a number:");
    scanf("%d",&n);

    if (n <= 1) {
        c = 0;
    } 
    else {
        for (i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                c = 0;
            }
        }
    }
    if (c == 1)
        printf("%d is a Prime number", n);
    else
        printf("%d is not a Prime number", n);
    return 0;
}



/*Q2) Write a program to reverse a 3-digit number.*/
#include <stdio.h>
int main(){
    int n,rev = 0, dig;
    printf("Enter a 3-digit number:");
    scanf("%d", &n);

    for (int i = 1; i <= 3; i++) {
        dig = n % 10;          
        rev = rev * 10 + dig;   
        n = n / 10;           
    }
    printf("Reversed number is: %d", rev);

    return 0;
}



/*Q3) Write a program to find the factorial of a number (use both iterative and recursion method)*/

//using iterative method.
#include <stdio.h>
int main(){
    int n,fact = 1;
    printf("Enter a number:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    printf("Factorial of %d is %lld", n, fact);

    return 0;
}

//Using recursion.
#include <stdio.h>
int fact(int n){
    if (n == 0) {
        return 1; 
    } else {
        return n * fact(n -1);
    }
}

int main(){
    int n, result;
    printf("Enter a number:");
    scanf("%d", &n);

    result = fact(n);
    printf("Factorial of %d is %d", n, result);

    return 0;
}



/*Q4) Write a program using temp variable to swap two numbers.*/
#include <stdio.h>
int main(){
    int a, b, temp;
    printf("Enter value of a:");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);

    temp = a;
    a = b;
    b = temp;

    printf("After swapping:\n");
    printf("a = %d\nb = %d", a, b);
    return 0;
}


/*Q5) Write a program to print the fibonacci series up to to n terms.*/
#include <stdio.h>
void fibonacci(int num)
{
    int a = 0, b = 1, c, i;

    if (num <= 0)
    {
        printf("Please enter a positive number");
    }
    else if (num == 1)
    {
        printf("%d", a);
    }
    else
    {
        printf("Fibonacci series:\n");
        printf("%d %d ", a, b);
        for (i = 2; i < num; i++)
        {
            c = a + b;
            printf("%d ", c);
            a = b;
            b = c;
        }
    }
}
int main(){
    int num;
    printf("Enter number of terms: ");
    scanf("%d", &num);

    fibonacci(num);
    return 0;
}
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
  
double my_sqrt(double, double, double);  
  
int main(int argc, char **argv)  
{  
   double x, e;  
   scanf("%lf,%lf", &x, &e);  
   printf("%.8lf\n", my_sqrt(x, x/2, e));  
   return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  


// Return sqrt of n
double my_sqrt(double n, double guess, double error)
{
    // If guess is good enough
    if (fabs((guess * guess) - n) < error)
    {
        return guess;
    }

    else 
    {
        return my_sqrt(n, 0.5 * (guess + (n / guess)), error);
    }
}


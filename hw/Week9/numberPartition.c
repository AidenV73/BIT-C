/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  

int count( int n, int m );

int main()   
{  
   int n, count( );  
   scanf("%d", &n);  
   printf("%d\n", count (n, n-1));    
   return 0;  
}  
  
int count( int n, int m )   
{   
    if (m == 0)
    {
        return 0;
    }

    else if (n == 0)
    {
        return 1;
    }

    else if (n < 0)
    {
        return 0;
    }

    else
    {
        return count(n - m, m) + count(n, m - 1);
    }
}    
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  



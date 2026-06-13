/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
  
typedef struct buy  
{  char  gname;  
   int   sname;  
   int   gprice;  
} BUY;  
int main( )  
{  int i, j, n;  
   int min, price[10][3];  
   int findm( int n, int price[][3], BUY scheme[] );  
  
   static BUY scheme[3]={ {'A', 0, 0}, {'B', 0, 0}, {'C', 0, 0} };  
  
   scanf( "%d", &n );  
   for( i = 0; i < n; i++ )  
    for( j = 0; j < 3; j++ )  
       scanf( "%d", &price[i][j] );  
  
   min = findm( n, price, scheme );  
  
   printf("Total Money are : %d\nGoods-Name  Shop-Name  Goods-Price\n", min );  
   for ( i=0; i < 3; i++ )  
       printf("         %c:%10d%13d\n", scheme[i].gname, scheme[i].sname, scheme[i].gprice );  
   return 0;  
}  
/* int findm( int n, int price[][3], BUY scheme[] ) */  
/* {                                                 */  
/* {                                                 */  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  

int findm( int n, int price[][3], BUY scheme[] ) 
{
    int min = 9999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }

            for (int k = 0; k < n; k++)
            {
                if (i == k || j == k)
                {
                    continue;
                }

                int current = price[i][0] + price[j][1] + price[k][2];
                
                if (current < min)
                {
                    min = current;
                    scheme[0].sname = i + 1;
                    scheme[0].gprice = price[i][0];

                    scheme[1].sname = j + 1;
                    scheme[1].gprice = price[j][1];

                    scheme[2].sname = k + 1;
                    scheme[2].gprice = price[k][2];
                }
            }
        }
    }
    return min;
}
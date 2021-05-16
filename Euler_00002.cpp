// ////////////////////////////////////////////////////////
// # Title
// Even Fibonacci numbers
//
// # URL
// https://projecteuler.net/problem=2
// https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem
//
// # Problem
// Each new term in the Fibonacci sequence is generated by adding the previous two terms.
// By starting with 1 and 2, the first 10 terms will be:
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
// By considering the terms in the Fibonacci sequence whose values do not exceed N,
// find the sum of the even-valued terms.
//
// # Solved by
// Jatin R Puthran
// May 2021
//
// # Algorithm
// As explained in the problem statement, you can compute all Fibonacci numbers in an iterative way:
// `F_i=F_{i-2}+F_{i-1}`
//
// My variables ''a'' and ''b'' stand for `F_{i-2}` and `F_{i-1}` whereas ''next'' is `F_i`
// After each iteration, ''next=a+b'' and then ''a'' becomes ''b'' and ''b'' becomes ''next''.
//
// A number is even if there is no remainder when divided by 2.
// In most programming languages it's written as ''variable % 2 == 0''
//
// Internally, your compiler might translate this to the more efficient ''(variable & 1) == 0''
//
// # IMPORTANT NOTE: 
// ''unsigned long long'' is required to pass all Hackerrank tests.




/*--------------------------------------------           C++ CODE :             --------------------------------------------------------------------------------------*/


#include <iostream>

int main()
{
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned long long last;
    std::cin >> last;

    unsigned long long sum = 0;
    // first Fibonacci numbers
    unsigned long long a = 1;
    unsigned long long b = 2;

    // until we reach the limit
    while (b <= last)
    {
      // even ?
      if (b % 2 == 0)
        sum += b;

      // next Fibonacci number
      auto next = a + b;
      a = b;
      b = next;
    }

    std::cout << sum << std::endl;
  }
  return 0;
}




/*----------------------------------------------------          C language CODE     -----------------------------------------------------------------------------------------*/
/*


#include <math.h>
#include <stdio.h>
int funrec(long int n)
{
  int a=1,b=2,d=0,sum=2;  
  while(d<n)
  {
      if(d%2==0)                                           //even or odd check
      {
          sum=sum+d;
      }
      d=a+b;
      a=b;
      b=d;
  }  
return sum;    
}


int main(){
    long int t,nt;
    scanf("%ld",&t); 
    while(t>0)
    {
        scanf("%ld",&nt);
        printf("%d\n",funrec(nt));
        --t;  
    }
    return 0;
}





*/


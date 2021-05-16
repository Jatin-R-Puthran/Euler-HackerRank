// # Title
// MULTIPLES OF 3 AND 5.
// # URL
//
// https://projecteuler.net/problem=1
// https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem
//
// PROBLEM :
// If we list all the natural numbers below 10 that are multiples of 3 or 5,
// we get 3, 5, 6 and 9. The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below N
//
// # Solved by
// Jatin R Puthran
// May 2021
//
// # Algorithm 
// We are supposed to find of all multiples of 3 or 5 below the input number,
// therefore we decrement it by one initially.
//
// In general, we know the sum of all numbers between 1 and `x` is `sum_{1..x} =x * (x+1)/2`
// (see https://en.wikipedia.org/wiki/Triangular_number )
//
// There are `floor{x/3}` numbers between 1 and x which are divisible by 3 (assuming `floor{x/3}` is an integer division).
// e.g. the range `1..10` contains `floor{10/3}=3` such numbers (it's 3, 6 and 9). Their sum is `3+6+9=18`.
// This can be written as `3/3 * (3+6+9)` which is the same as `3 * (3/3+6/3+9/3)=3 * (1+2+3)`.
// Those brackets represent ` sum_{1..3}i = sum_{1..10/3}i` (or short: ` sum{10/3}`)
// and thus our overall formula for the sum of all multiples of 3 becomes `3 * sum{x/3}`.
//
// The same formula can be used for 5:
// The sum of all numbers divisible by 5 is `5 * sum{x/5}`
//
// So simply by using these formulas we will get the numbers divisible by 3,5.
// However, there are numbers divisible by 3 __and__ 5, which means they are part of __both__ sums.
// We must not count them twice, that's why we (in addition to the aforementioned sums)
// compute the sum of all numbers divisible by 3*5=15 to correct for this error.
//
// In the end we print ''sumThree + sumFive - sumFifteen''
//
//Or we could have used some logical operator and solved this issue.
//
// # Alternative
// Looping through all numbers from 1 and N and checking each of those numbers
// whether they are divisible by 3 or 5 (using logical operator) easily solves the problem, too, and produces the result pretty much instantly.
// Even more, the code will be probably a bit shorter.
//
// However, Hackerrank's input numbers are too large for that simple approach (up to `10^9` with `10^5` test cases)
// and will lead to timeouts as in case of my C language code.

/*--------------------------------------------           C++ CODE :             --------------------------------------------------------------------------------------*/

#include <iostream>

// triangular number: `sum{x}=1+2+..+x = x*(x+1)/2`
unsigned long long sum(unsigned long long x)
{
  return x * (x + 1) / 2;
}

int main()
{
  unsigned int t;                                                         // t= no. of test cases. 
  std::cin >> t;
  while (t--)
  {
    unsigned long long n;                                                 // n=last number input by user
    std::cin >> n;

    n--; // not including the last number

    // find sum of all numbers divisible by 3 or 5
    auto sumThree   =  3 * sum(n/3);
    auto sumFive    =  5 * sum(n/5);

    // however, those numbers divisible by 3 AND 5 will be counted twice
    auto sumFifteen = 15 * sum(n/15);

    std::cout << (sumThree + sumFive - sumFifteen) << std::endl;
  }

  return 0;
}



/*----------------------------------------------------          C language CODE     -----------------------------------------------------------------------------------------*/
/*


#include<stdio.h>
int fun1(int m)
{
    int sum = 0;
    m= m-1;                                                          // not including the last number.
    while(m>2)
    {
     if(m%3==0 || m%5==0)                                            //The use of LOGICAL OPERATOR to avoid counting twice those numbers divisible by 3 AND 5.
           sum  = sum + m;    
           
      --m;
    }
    return sum;
}

int main()
{
  int t,m,sum;                                                      // t= no. of test cases.       m=last number input by user
  scanf("%d",&t);
  while(t>0)
  {
  scanf("%d",&m);
  printf("%d \n",fun1(m));
   --t;
  }
  return 0;
}



*/


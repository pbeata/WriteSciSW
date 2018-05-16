#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void prob2();
void prob3();
void prob4();


double compute_radius(double x, double y);
double get_rand();
void print_quadratic_roots(double a, double b, double c);


int main()
{

  /*
  // investigating overflow
  int e;
  int my_exp[5] = {10, 100, 1000, 1020, 1023};
  double x, de, base;

  base = 2.0;
  for (int i = 0; i < 5; i++)
  {
    e = my_exp[i];
    x = pow(base, e);
    printf("%.6e\n", x);
  }

  // more examples reaching the limit for overflow...
  de = 1023.9;
  printf("%.6e\n", pow(base, de));
  de = 1023.9999;
  printf("%.6e\n", pow(base, de));
  e = 1024;
  printf("%.6e\n", pow(base, e));
  */

  // prob3();

  prob4();

  return 0;
}


void prob2()
{
  int k, n;
  double x, y, roe, limit;
  limit = 0.5;
  n = 17;
  for (k = 0; k < n; k++)
  {
    x = pow(10.0, -k);
    y = (1.0 - cos(x)) / (x * x);
    roe = limit - y;
    printf("%d \t %.18f \t %.18f \t %.18f \n", k, cos(x), y, roe);
  }  
}


void prob3()
{
  double x, y;

  x = 10.0;
  y = 10.0;
  printf("%e\n", compute_radius(x, y));

  // x = 1.0 * pow(10.0, 6);
  // y = 1.0 * pow(10.0, 6);
  // printf("%e\n", compute_radius(x, y));  

  // x = 1.0 * pow(10.0, 8);
  // y = 2.0 * pow(10.0, 8);
  // printf("%e\n", compute_radius(x, y));  


  // x = 1.0 * pow(10.0, 11); 
  // y = 1.0 * pow(10.0, 10);
  // printf("%e\n", compute_radius(x, y));  

  // x = 1.0 * pow(10.0, 200); 
  // y = 1.0 * pow(10.0, 198);
  // printf("%e\n", compute_radius(x, y));  

}


/*
This type of problem for computing the root of a quadratic
equation is discussed in Goldberg's 1991 paper on floating-
point arithmetic. See equations (4-5) in that document to 
learn how this problem is handled more completely. 

How can we test this problem to make sure it is computing
the proper roots? 
*/
void prob4()
{
  srand(42);

  double a = get_rand();
  double b = get_rand();
  double c = get_rand();
  int n = 30;

  for (int i = 0; i < n; i++)
  {
    print_quadratic_roots(a, b, c);
    b = b * get_rand();
  }
}


double compute_radius(double x, double y)
{
  double r, c;
  if (x > y)
  {
    c = y / x;
    r = abs(x) * sqrt( 1.0 + (c * c) );
  }
  else
  {
    c = x / y;
    r = abs(y) * sqrt( 1.0 + (c * c) );
  }
  return r;
}


double get_rand()
{
  int a = 1;
  int b = 100;
  return ( (double)rand() / RAND_MAX ) * (b - a) + a;
}


void print_quadratic_roots(double a, double b, double c)
{
  double x_neg, x_pos;
  double ratio, check;
  double tol = pow(10.0, -8);

  check = b * b - 4.0 * a * c;
  if (abs(a) > tol && check >= 0.0)
  {
    ratio = c / a;
    x_neg = (-b - sqrt(check)) / (2.0 * a);
    x_pos = ratio * (1.0 / x_neg);
    printf("Roots of the quadratic: (%.6e, %.6e) \n", x_neg, x_pos);
  }
  else
  {
    printf("\n*error: nearing divide by zero, check input 'a'\n");
    printf("OR argument inside sqrt is < zero \n\n");
  }
}
#include <iostream>
#include <time.h>
#include <math.h>
//ANDREJ STOMNAROSKI INKI938
int frequency_of_primes (int n) {
  int i,j;
  int freq=n-1;
  for (i=2; i<=n; ++i) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
  return freq;
}


//So povikuvanje na funkcijata clock_t od biblioteakta time.h se pokazuva kolku vreme
//potrosil procesorot za izvrsuvanje na programata.
int main ()
{
  clock_t t;
  int f;
  t = clock();
  printf ("Calculating...\n");
  f = frequency_of_primes (99999);
  printf ("The number of primes lower than 100,000 is: %d\n",f);
  t = clock() - t;
  printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
  return 0;
}

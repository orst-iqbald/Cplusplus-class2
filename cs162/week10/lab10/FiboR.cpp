/*Name: Danish Iqbal
 * Program: Lab10 - Recursive
 * Date: 12/10/14
 * Description: Recursive Fibonacci w/ times
 * Source - http://www.tenouk.com/cpluscodesnippet/cplusfibonaccirecursive.html
 * *** I got this code from the above website
 */


#include <time.h>
#include <iostream>
using namespace std;
 
// function prototype, required by standard
long fibonacci(long);
 
int main(void)
{
int p;
clock_t start;
long double duration;
 
cout<<"A simple fibonacci using recursive function"<<endl;
cout<<"-----------------------------------------\n"<<endl;
 
// looping for 20 numbers. If you increase the iteration number, you may see the
// 'burden' that your computer faces to compute numbers
for(p = 0; p<40; p=p+2){
	start = clock();
	cout<<"Fibonacci("<<p<<") = "<<fibonacci(p)<<"\n";
	duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
	cout << "it took " << duration << " second\n";
 	}
return 0;
}
 
// recursive fibonacci function definition
long fibonacci(long number)
{
// for starting number 0, 1, fibonacci = number
if(number == 0 || number == 1)
return number;
// other number
else
// return and call itself
return (fibonacci(number-1) + fibonacci(number-2));
}

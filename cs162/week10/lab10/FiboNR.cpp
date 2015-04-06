/*
++ Program to Find Fibonacci Numbers using Iteration
 */
#include <time.h>
#include <cstring>
#include <iostream>
#include <cstdlib>
#define ll long long
using namespace std;
 
/* 
 *  * Iterative function to find Fibonacci Numbers 
 *   */
ll fibo_iter(int n)
{
    int previous = 1;
    int current = 1;
    int next = 1;
    for (int i = 3; i <= n; ++i) 
    {
        next = current + previous;
        previous = current;
        current = next;
    }
    return next;
}
/* 
 *  * Main
 *   */
int main()
{
clock_t start;
long double duration;

    int n;
    while (1)
    {
        cout<<"Enter the integer n to find nth fibonnaci no.(0 to exit): ";
        cin>>n;
        if (n == 0)
            break;
start = clock();
        cout<<fibo_iter(n)<<endl;
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "it took " << duration << " second\n";

    }
    return 0;
}

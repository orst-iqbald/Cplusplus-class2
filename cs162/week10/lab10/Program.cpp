  /*
  2   * Program.cpp
  3   * 
  4   *  OS: Fedora 13
  5   *  Language: Native C++
  6   *  Compiler: GNU g++
  7   *  Created on: Sep 11, 2010
  8   *      Author: julian
  9   */
#include <time.h>   
#include <cstdlib>   
#include <iostream>
   #include <stdlib.h>
   #include "FibonacciR.h"
   #include "FibonacciNR.h"
   using namespace std;
   void Usage(){
   	cout<<"Correct Usage:"<<endl;
   	cout<<"./Fibonacci [n]"<<endl;
   }
   int main(int argc, char** args) {
   	try{
  		const char* input; //Note: char by default initializes to '\0'
  		if(args[1]!=0)
   		{	
   			cout<<"1st passed arguement: '"<<args[1]<<"'"<<endl;
   			input= args[1]; 
   		}
    		int n= atoi(input);
   		cout<<"Finding '"<<n<<"'th "<<"fibonacci number...."<<endl;
  
clock_t start;
long double duration;
		start = clock();
 		cout<<"Calling Recursive Fibonacci implementation"<<endl;
  		FibonacciR fr(n);
   		fr.PrintFibonacci();
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "it took " << duration << " second\n";

clock_t start;
long double duration;
                start = clock();
   		cout<<"Calling Non-Recursive Fibonacci implementation"<<endl;
   		FibonacciNR fnr(n);
   		fnr.PrintFibonacci();
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "it took " << duration << " second\n";

   		cout << "Done!!!!" << endl; 
  		return 0;
   	}
   	catch(...)
   	{
   		cout<<"Oops an error occured! Please check usage"<<endl;
   		Usage();
   		return 1;
   	}
   }

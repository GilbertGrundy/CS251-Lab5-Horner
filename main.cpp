/*
Name: Gilbert Grundy
Assignment: Lab #5
*/

#include <iostream>
#include <stdlib.h>
#include <chrono>

const int MAX = 21; //n

using namespace std;

void coefficient_gen(int * nums);
float x_gen();
void display_poly(int degree, int * coefficients, float x);
double horner_alg(int degree, int * coefficients, float x);
double straight_alg(int degree, int * coefficients, float x);

int main()
{
	int coefficients[MAX]; //int to hold coefficient values from x^0 - x^n
	int degree = 1; //current degree of polynomial
	double result; //result of p(x)
	float x; //value of x
	int total_time; //time for algorithm to run

	cout << "Gilbert Grundy CS251 Lab #5.\n\n";

	srand(time(0)); //seed random generator

	coefficient_gen(coefficients); //get random coefficients between 0-99
	x = x_gen(); //generate random number between -20.00 - 20.00

	//loop until every polynomial between degree 1 - n is computed
	while(degree < MAX)
	{	// display polynomial and value of x	
		display_poly(degree, coefficients, x);	
		
		//use horner algorithm to get value, and print time taken
		result = horner_alg(degree, coefficients, x); 
		
		//use a straight evaluation to get the value of p(x) and print time taken
		straight_alg(degree, coefficients, x);

		//print out value for p(x)
		cout << "P(x) = " << result << "\n";
		cout << "\n";
		degree++; //increment the degree
	}
	
	return 0;
}


//function to create an array of random coefficients
void coefficient_gen(int * nums)
{
	for(int i = 0; i < MAX; i++)
	{
		nums[i] = (rand() % 99);
	}

	return;
}


//function to generate a random x
float x_gen()
{	
	float x;
	x = (float)rand() / RAND_MAX; //gets a value between 0-1
	x = x*20; //multiply by 20 so value is between 0-20
	if(rand()%2) x = -x; //randomly assign negative/positive

	return x;
}

//display function for the polynomial and x value
void display_poly(int degree, int * coefficients, float x)
{
	cout << "Degree " << degree << endl;

	for(int i = degree; i >= 0; i--)
	{
		cout << coefficients[i] << "x^" << i;
		if(i) cout << " + ";
	}
	
	cout << "\nx = " << x << "\n";

	return;
}

//function to run Horner's algorithm
double horner_alg(int degree, int * coefficients, float x)
{
	using namespace std::chrono;	
 	steady_clock::time_point start = steady_clock::now(); //start time

	double result = coefficients[degree]; //get the initial coefficient of n

	for(int i = (degree - 1); i >= 0; i--)
	{
		result = result*x; //multiply by x
		result += coefficients[i]; // add the next coefficient
	}

  	steady_clock::time_point finish = steady_clock::now(); //finish time

	//calculate total time
  	duration<double> time_span = duration_cast<duration<double>>(finish - start);

	//print time taken
  	std::cout << "Horner " << time_span.count() << " seconds.\n";

	//return the result
	return result;
}

//funtion to run a straight algorithm
double straight_alg(int degree, int * coefficients, float x)
{
	using namespace std::chrono;	
 	steady_clock::time_point start = steady_clock::now(); //start time

	double result = 0;
	double value = x;

	for(int i = degree; i >= 1; --i)
	{
		for(int j = 1; j < i; j++)
		{
			value = value*x; //multiply the x by itself to raise its power
		}

		result += (value*coefficients[i]); //multiply by coefficient and add it
		value = x; //value to x
	}

	result += (coefficients[0]*1);

  	steady_clock::time_point finish = steady_clock::now(); //finish time

	//total time
  	duration<double> time_span = duration_cast<duration<double>>(finish - start);

	//print totla time
  	std::cout << "Not Horner " << time_span.count() << " seconds.\n";

	//return the result
	return result;
}

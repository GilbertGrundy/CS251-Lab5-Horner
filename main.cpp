/*
Name: Gilbert Grundy
Assignment: Lab #5
*/

#include <iostream>
#include <stdlib.h>
#include <chrono>

const int MAX = 21;

using namespace std;

void coefficient_gen(int * nums);
float x_gen();
void display_poly(int degree, int * coefficients, float x);
double horner_alg(int degree, int * coefficients, float x);
double straight_alg(int degree, int * coefficients, float x);


int main()
{
	int coefficients[MAX];
	int degree = 1;
	double result;
	float x;
	int total_time;

	cout << "Gilbert Grundy CS251 Lab #5.\n\n";

	srand(time(0));

	coefficient_gen(coefficients);
	x = x_gen();

	while(degree < MAX)
	{
		display_poly(degree, coefficients, x);		
		
		result = horner_alg(degree, coefficients, x);
		
		straight_alg(degree, coefficients, x);

		cout << "P(x) = " << result << "\n";
		cout << "\n";
		degree++;
	}
	

	return 0;
}


void coefficient_gen(int * nums)
{
	for(int i = 0; i < MAX; i++)
	{
		nums[i] = (rand() % 99);
	}

	return;
}


float x_gen()
{	
	float x;
	x = (float)rand() / RAND_MAX;
	x = x*20;
	if(rand()%2) x = -x;

	return x;
}

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

double horner_alg(int degree, int * coefficients, float x)
{
	using namespace std::chrono;	
 	steady_clock::time_point start = steady_clock::now();

	double result = coefficients[degree];

	for(int i = (degree - 1); i >= 0; i--)
	{
		result = result*x;
		result += coefficients[i];
	}

  	steady_clock::time_point finish = steady_clock::now();
  	duration<double> time_span = duration_cast<duration<double>>(finish - start);

  	std::cout << "Horner " << time_span.count() << " seconds.\n";

	return result;
}


double straight_alg(int degree, int * coefficients, float x)
{
	using namespace std::chrono;	
 	steady_clock::time_point start = steady_clock::now();

	double result = 0;
	double value = x;

	for(int i = degree; i >= 1; --i)
	{
		for(int j = 1; j < i; j++)
		{
			value = value*x;
		}

		result += (value*coefficients[i]);
		value = x;
	}

	result += (coefficients[0]*1);

  	steady_clock::time_point finish = steady_clock::now();
  	duration<double> time_span = duration_cast<duration<double>>(finish - start);

  	std::cout << "Not Horner " << time_span.count() << " seconds.\n";

	return result;
}

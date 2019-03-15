/*
Name: Gilbert Grundy
Assignment: Lab #5
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>
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
	float total_time;
	struct timeval start; //start time of algorithm
    	struct timeval finish; //finish time of algorithm

	cout << "Gilbert Grundy CS251 Lab #5.\n\n";

	srand(time(0));

	coefficient_gen(coefficients);
	x = x_gen();

	while(degree < MAX)
	{
		display_poly(degree, coefficients, x);
		
		//get start time
        	gettimeofday(&start, NULL)
		
		result = horner_alg(degree, coefficients, x);
		
		//record finish time
            	gettimeofday(&finish, NULL);
		
		 //compute time
            	total_time += (finish.tv_sec - start.tv_sec);
            	total_time += (finish.tv_usec - start.tv_usec)/1000;
		
		cout << "Horner: " << total_time << "seconds\n";
		result = straight_alg(degree, coefficients, x);
		cout << "Non-Horner Result: " << result << "\n";
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
	double result = coefficients[degree];

	for(int i = (degree - 1); i >= 0; i--)
	{
		result = result*x;
		result += coefficients[i];
	}

	return result;
}


double straight_alg(int degree, int * coefficients, float x)
{
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
	return result;
}

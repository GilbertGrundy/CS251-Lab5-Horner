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

const int MAX = 20;

using namespace std;

void coefficient_gen(int * nums);
float x_gen();

int main()
{
	int coefficients[MAX];
	float x;

	cout << "Gilbert Grundy CS251 Lab #5.\n";

	srand(time(0));

	coefficient_gen(coefficients);
	x = x_gen();

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

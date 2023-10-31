﻿#include <iostream>
#include <cmath>
using namespace std;
double S0(const int N)
{
	double s = 0;
	for (int k = N; k <= 19; k++) {
		s += (sqrt(pow(sin(k), 2)) + pow(cos(N / k), 2));
	}
	
	return s;
}
double S1(const int N, int k)
{
	if (k > 19)
		return 0;
	else
		return (sqrt(pow(sin(k), 2)) + pow(cos(N / k), 2)) + S1(N, k + 1);
}
double S2(const int N, int k)
{
	if (N == k + 1)
		return 0;
	else
		return (sqrt(pow(sin(k), 2)) + pow(cos(N / k), 2)) + S2(N, k - 1);
}
double S3(const int N, const int k, double t)
{
	t = t + (sqrt(pow(sin(k), 2)) + pow(cos(N / k), 2));
	if (k >= 19)
		return t;
	else
		return S3(N, k + 1, t);
}
double S4(const int N, const int k, double t)
{
	t = t + (sqrt(pow(sin(k), 2)) + pow(cos(N / k), 2));
	if (N == k)
		return t;
	else
		return S4(N, k - 1, t);
}
int main()
{
	double N;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(N) << endl; 
	cout << "(rec up ++) S1 = " << S1(N, N) << endl;
	cout << "(rec up --) S2 = " << S2(N, 19) << endl;
	cout << "(rec down ++) S3 = " << S3(N, N, 0) << endl;
	cout << "(rec down --) S4 = " << S4(N, 19, 0) << endl;
	return 0;
}
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

long long int MOD = 1000000007;

// Function to find a^b efficiently
long long int power(long long int a,
					long long int b)
{

	// Base Case
	if (b == 0)
		return 1;

	// To store the value of a^b
	long long int temp = power(a, b / 2);

	temp = (temp * temp) % MOD;

	// Multiply temp by a until b is not 0
	if (b % 2 != 0) {
		temp = (temp * a) % MOD;
	}

	// Return the final ans a^b
	return temp;
}

// Function to find sum of all N-digit
// palindromic number divisible by 9
void palindromicSum(int N)
{

	long long int sum = 0, res, ways;

	// Base Case
	if (N == 1) {
		cout << "9" << endl;
		return;
	}

	if (N == 2) {
		cout << "99" << endl;
		return;
	}

	ways = N / 2;

	// If N is even, decrease ways by 1
	if (N % 2 == 0)
		ways--;

	// Find the total number of ways

	res = power(9, ways - 1);

	// Iterate over [1, N] and find the
	// sum at each index
	for (int i = 0; i < N; i++) {
		sum = sum * 10 + 45 * res;
		sum %= MOD;
	}

	// Print the final Sum
	cout << sum << endl;
}

// Driver Code
int main()
{
	int N = 3;
	palindromicSum(N);
	return 0;
}

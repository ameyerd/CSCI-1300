#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// global variable to count up the number of function calls
int n_eval = 0;

// returns the n-th fibonacci number, using a recursive approach
int fib_r(int n) {
	n_eval += 1;
	if (n==0) {
		return 0;
	} else if (n==1) {
		return 1;
	} else {
		return fib_r(n-1) + fib_r(n-2);
	}
}

// returns the n-th fibonacci number, using iterative approach
int fib_i(int n) {
	if (n==0) {
		return 0;
	} else if (n==1) {
		return 1;
	} else {
		int f[n+1];
		f[0] = 0;
		f[1] = 1;
		for (int i=2; i<=n; i++) {
			f[i] = f[i-1] + f[i-2];
		}
		return f[n];
	}
}


int main() {

    int n;  // NOTE: numbers larger than about 46 will take a while to do...
    cout << "Which Fibonacci number do you want? f_n, n = ";
    cin >> n;

    int t0 = time(0);  // current time since Jan 1 1970 in seconds...
	cout << "Recursive solution: " << fib_r(n) << endl;
	int t1 = time(0);
    cout << "Iterative solution: " << fib_i(n) << endl;
    int t2 = time(0);

    cout << "Recursive solution took " << t1-t0 << endl;
    cout << "Iterative solution took " << t2-t1 << endl;

    cout << "Recursion required " << n_eval << " function evaluations" << endl;

	cout << sizeof(n_eval) << endl;

    return 0;
}
#include <omp.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char * argv[]) {
	int n = atoi(argv[1]);
	int threads = atoi(argv[2]);

	n = 10000;
	threads = 1;

	long b[n];
	bool done[n];
	long sumB;
	int a[n][3];

	b[0] = 0;

	srand(123);
	a[0][0] = a[0][1] = a[0][2] = 0;
	for(int i = 1; i < n; ++i) {
		a[i][0] = rand() % i;
		a[i][1] = (rand() % 19) - 9;
		a[i][2] = (rand() % 3) + 1;
	}

	double start;
	for(int i = 1; i < n; ++i) {
		int help = b[a[i][0]];
		start = omp_get_wtime();
		while(omp_get_wtime() - start < a[i][2]/10) {}
		b[i] = help + a[i][1];
		sumB += b[i];
		cout << "b[" << i << "] = " << b[i]<< "\n";
	}
	cout << "sum = " << sumB;
	return 0;
}
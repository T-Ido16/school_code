#include <stdio.h>
#include <math.h>
double f(double x) {
	return (sqrt(-(4*x*x)/25 + 4));/*積分関数*/
}

double g(double x) {
	return (-sqrt(-(4*x*x)/25 + 4));/*積分関数*/
}

int main(void) {
	int n, m, N, N2 = 1000000;/*分割数*/
	double a = -5.0, b = 5.0;/*積分範囲は-5から5*/
	double h, i, io = 0.0, ie = 0.0, k, ko = 0.0, ke = 0.0;
	double sum, cd, object = 3.141592653;
	h = (b - a) / N2;
	N = N2 / 2;
	for (n = 1; n <= N; n++) io += f(a + (2*n-1) * h);
	for (n = 1; n <= N-1; n++) ie += f(a + 2 * n * h);
	i = h / 3.0 * (f(a) + 4.0 * io + 2.0 * ie + f(b));
	printf("2N = %d, I = %.8f\n", N2, i);

	for (m = 1; m <= N; m++) ko += g(a + (2*m-1) * h);
	for (m = 1; m <= N-1; m++) ke += g(a + 2 * m * h);
	k = h / 3.0 * (g(a) + 4.0 * ko + 2.0 * ke + g(b));
	printf("2N = %d, K = %.8f\n", N2, k);

	sum = i - k;
	object *= 10;/*理論値*/
	cd = sum-object;/*誤差の計算*/
	if(cd < 0)cd *= (-1);/*絶対値*/
	printf("面積%.8f,比較%.8f,差%.8f,\n",sum,object,cd);
	/*シンプソンの公式の方が誤差が小さい*/

	return 0;
}
#include <stdio.h>
#include <math.h>
double f(double x) {
	return (sqrt(-(4*x*x)/25 + 4));/*積分関数*/
}

double g(double x) {
	return (-sqrt(-(4*x*x)/25 + 4));/*積分関数*/
}

int main(void) {
	int n, m, N = 1000000;/*分割数*/
	double a = -5.0, b = 5.0;/*積分範囲は-5から5*/
	double h, i, k, s = 0.0, t = 0.0;
	double sum, difference, object = 3.141592653;
	h = (b - a) / N;
	for (n = 1; n <= N-1; n++) s += f(a + n * h);
	i = h / 2.0 *(f(a) + 2.0 * s + f(b));
	printf("分割数N = %d, f(x) = %.8f\n", N, i);

	h = (b - a) / N;
	for (m = 1; m <= N-1; m++) t += g(a + m * h);
	k = h / 2.0 *(g(a) + 2.0 * t + g(b));
	printf("分割数N = %d, g(x) = %.8f\n", N, k);

	sum = i - k;
	object *= 10;/*理論値*/
	difference = sum-object;/*誤差の計算*/
	if(difference < 0)difference *= (-1);/*絶対値*/
	printf("f(x)-g(x)より面積%.8f,理論値%.8f,誤差%.8f,\n",sum,object,difference);

	return 0;
}

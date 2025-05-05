#include <stdio.h>
#include <math.h>
double f(double x) {
	return (sqrt(-(4*x*x)/25 + 4));/*�ϕ��֐�*/
}

double g(double x) {
	return (-sqrt(-(4*x*x)/25 + 4));/*�ϕ��֐�*/
}

int main(void) {
	int n, m, N = 1000000;/*������*/
	double a = -5.0, b = 5.0;/*�ϕ��͈͂�-5����5*/
	double h, i, k, s = 0.0, t = 0.0;
	double sum, difference, object = 3.141592653;
	h = (b - a) / N;
	for (n = 1; n <= N-1; n++) s += f(a + n * h);
	i = h / 2.0 *(f(a) + 2.0 * s + f(b));
	printf("������N = %d, f(x) = %.8f\n", N, i);

	h = (b - a) / N;
	for (m = 1; m <= N-1; m++) t += g(a + m * h);
	k = h / 2.0 *(g(a) + 2.0 * t + g(b));
	printf("������N = %d, g(x) = %.8f\n", N, k);

	sum = i - k;
	object *= 10;/*���_�l*/
	difference = sum-object;/*�덷�̌v�Z*/
	if(difference < 0)difference *= (-1);/*��Βl*/
	printf("f(x)-g(x)���ʐ�%.8f,���_�l%.8f,�덷%.8f,\n",sum,object,difference);

	return 0;
}

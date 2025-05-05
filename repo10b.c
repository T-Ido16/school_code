#include <stdio.h>
#include <math.h>
double f(double x) {
	return (sqrt(-(4*x*x)/25 + 4));/*�ϕ��֐�*/
}

double g(double x) {
	return (-sqrt(-(4*x*x)/25 + 4));/*�ϕ��֐�*/
}

int main(void) {
	int n, m, N, N2 = 1000000;/*������*/
	double a = -5.0, b = 5.0;/*�ϕ��͈͂�-5����5*/
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
	object *= 10;/*���_�l*/
	cd = sum-object;/*�덷�̌v�Z*/
	if(cd < 0)cd *= (-1);/*��Βl*/
	printf("�ʐ�%.8f,��r%.8f,��%.8f,\n",sum,object,cd);
	/*�V���v�\���̌����̕����덷��������*/

	return 0;
}
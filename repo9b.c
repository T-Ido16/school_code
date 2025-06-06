#include <stdio.h>
#include <math.h>
#define LOWEER 1.5/*範囲の設定*/
#define UPEER 1.7
double f(double x) {
	return (sin(x*x + 1.0) + 0.5);/*関数*/
}
int main(void) {
	double xa = LOWEER, xb = UPEER, epsilon = 1.0e-8;/*epsilomは収束判定定数*/
	double xm;
	int n = 0;
	if (f(xa) * f(xb) >= 0.0) {
	printf("初期範囲が正しくありません\n");
	return 1;
	}
	printf(" n: x f(x)\n");
	do {/*導出*/
		xm = (xa + xb) / 2.0;
		if (f(xa) * f(xm) <= 0.0) xb = xm;
		else xa = xm;
	printf("%3d: %12.8f %10.2e\n", ++n, xm, f(xm));
	} while (fabs(xb - xa) >= epsilon);/*絶対値を求める関数*/
return 0;
}

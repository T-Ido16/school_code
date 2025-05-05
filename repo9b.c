#include <stdio.h>
#include <math.h>
#define LOWEER 1.5/*”ÍˆÍ‚Ìİ’è*/
#define UPEER 1.7
double f(double x) {
	return (sin(x*x + 1.0) + 0.5);/*ŠÖ”*/
}
int main(void) {
	double xa = LOWEER, xb = UPEER, epsilon = 1.0e-8;/*epsilom‚Íû‘©”»’è’è”*/
	double xm;
	int n = 0;
	if (f(xa) * f(xb) >= 0.0) {
	printf("‰Šú”ÍˆÍ‚ª³‚µ‚­‚ ‚è‚Ü‚¹‚ñ\n");
	return 1;
	}
	printf(" n: x f(x)\n");
	do {/*“±o*/
		xm = (xa + xb) / 2.0;
		if (f(xa) * f(xm) <= 0.0) xb = xm;
		else xa = xm;
	printf("%3d: %12.8f %10.2e\n", ++n, xm, f(xm));
	} while (fabs(xb - xa) >= epsilon);/*â‘Î’l‚ğ‹‚ß‚éŠÖ”*/
return 0;
}

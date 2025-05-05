#include <stdio.h>
#include <math.h>
#define NUMBER 1.0/*�����l*/

double f(double x){
	return (sin(x*x + 1.0) + 0.5);/*�֐�*/
}
double Df(double x){
	return (2.0 * x * cos(x*x + 1.0));/*���֐�*/
}
int main(void){
	double x0,x1 = NUMBER, epsilon = 1.0e-8;/*epsilom�͎�������萔*/
	int n = 0;
	printf("  n:	   x	   f(x)\n");
	do{
		x0 = x1;
		x1 = x0 - f(x0) / Df(x0);/*���o*/
		printf("%3d: %12.8f %.2e\n", ++n, x1, f(x1));
	} while (fabs(x1 - x0) >= epsilon);/*��Βl�����߂�֐�*/
	return 0;
}


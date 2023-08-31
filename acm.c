//#include <stdio.h>
//int main() {
//	int n = 0;
//	char c[10000] = { ' ' };
//	double dou[10000] = {0};
//	scanf("%d",&n);
//	getchar();
//	for (int i = 0; i < n;i++) {
//		scanf("%c %lf",&c[i],&dou[i]);
//		getchar();
//	}
//	for (int j = 0; j < n;j++) {
//		if (c[j]=='M') {
//			double dx = dou[j] / 1.09;
//			printf("%.2lf\n",dx);
//		}
//		if (c[j]=='F') {
//			double dx = dou[j] * 1.09;
//			printf("%.2lf\n",dx);
//		}
//	}
//}
// C5025
//#include <stdio.h>
//int main() {
//	int n = 0;
//	scanf("%d",&n);
//	static double alladd = 0;
//	for (double i = 1.0; i <= n;i++) {
//		static int jo = 0;
//		if (jo == 0) {
//			alladd = alladd +1.0 /(3*i-2);
//			jo = 1;
//		}else if(jo==1){
//			alladd = alladd - 1.0 / (3 * i - 2);
//			jo = 0;
//		}
//
//	}
//	printf("%.4lf",alladd);
//}
//
//#include <stdio.h>
//int main() {
	/*double m = 0;
	double m1 = 0;
	double n = 0;
	double answer = 0;
	scanf("%lf %lf",&m,&n);
	m1 = m;
	for (int i = 1; i <= n;i++) {
		 m = m1;
		int number = 0;
		for (int j = 1; j <= i;j++) {
			number = number + m;
			m = m * 10;
		 }
		answer = answer + number;
	}
	printf("%.0f",answer);*/
	/*int m = 0;
	int n = 0;
	scanf("%d %d",&m,&n);
	printf("%d",m+n);
}*/
//#include <stdio.h>
//int main() {
//	int a = 0, b = 0;
//	int all = 0;
//	int count = 0;
//	scanf("%d %d",&a,&b);
//	for (int i = a; i <= b;i++) {
//		int c = 0;
//		for (int j = 1; j <= i;j++) {
//			if (i%j==0) {
//				c++;
//			}
//		}
//		if (c == 2) {
//			count++;
//			all = all + i;
//		}
//	}
//	printf("%d %d",count,all);
//}
//#include <stdio.h>
//int main() {
//	double x = 0;
//	double answer = 1.0;
//	scanf("%lf",&x);
//	for (double i = 1.0; i++;) {
//		double fz = 1.0, fm = x;
//		for (double j = 1.0; j <= i;j++) {
//			fm = fm * fm;
//		}
//		double m = 1.0;
//		for (double o = 1.0; o <= i*1.0; o++) {
//			m = m * o;
//		}
//		fz = m;
//		if ((fz/fm)<0.000001) {
//			break;
//		}
//		answer = answer + fz / fm;
//	}
//	printf("%.5f",answer);
//}
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i = 1;
//	long double k = 1;
//	double x, sum = 1;
//	scanf("%lf", &x);
//	do {
//		k *= i;                       //累乘
//		sum += pow(x, i) * 1.0 / k;       //累加
//		i++;
//	} while (pow(x, i) * 1.0 / k > 0.00001);   //跳出循环的条件
//	printf("%.4f", sum);
//
//	return 0;
//}
#include <stdio.h>
#include <math.h>
int main() {
	int n = 0;
	int number = 1;
	int pd = 0;
	scanf("%d",&n);
		for (int i = 1; i <= n; i++) {
			number = 1;
			for (int j = 1; j <= i; j++) {
				number = number * 2;
			}
			number--;
			int l = 0;
			if (number==1) {
				continue;
			}
			for (int k = 1; k < sqrt(number)+1; k++) {
				if (number % k == 0) {
					l++;
				}
			}
			if (l == 1) {
				printf("%d\n", number);
				pd++;
			}
		}
		if (pd==0) {
			printf("None");
	  }
}
#include <stdio.h>
#include <stdio.h>
int main() {
	int n = 0;
	scanf("%d",&n);
	int shang = 1,xia = 1;
	for (int i=1; i <= n-1;i++) {
		shang = shang * 10;
	}
	xia = shang * 10 - 1;
	 for (int i = shang; i <= xia;i++) {
		int allnumber = 0;
		int o = 1;
		int c = i;
		int l = 1;
		for (int k = 1; k <= n;k++) {//689
			l = c % 10;
			int y = 1;
			for (int i = 1; i <= n;i++) {
				y = y * l;
			}
			allnumber = allnumber + y;
			c = c / 10;
		}
		if (allnumber==i) {
			printf("%d\n",i);
		}
        
	 };
}
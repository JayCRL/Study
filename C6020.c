#define _CRT_SECURE_NO_WARNINGS 1;
#include <stdio.h>
int main() {
	int in[99999];
	int n = 0;
	int b, c, d;
	int i, j, a;
	scanf("%d", &n);//输入总个数
	getchar();//清除缓存区
	for (int o = 0; o < n; o++) {
		scanf("%d", &in[o]);//读取的时候不用清除缓存区
	}
  //冒泡排序
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + 1 <= n - i; j++) {
			if (in[j] < in[j + 1]) {
				a = in[j];
				in[j] = in[j + 1];
				in[j + 1] = a;
			}
		}
	}
  //输出奇数
	for (int p = 0; p < n; p++) {
		if (in[n - 1 - p] % 2 != 0) {
			if (n - 1 - p == 0) {
				printf("%d", in[n - 1 - p]);
			}
			else {
				printf("%d ", in[n - 1 - p]);
			}

		}
	}
	printf(" ");//奇偶数直接一个空格分开
  //输出偶数
	for (int p = 0; p < n; p++) {
		static int count = 0;
		if (in[n - 1 - p] % 2 == 0) {
			if (count == 0) {
				printf("%d", in[n - 1 - p]);
				count++;
			}
			else {
				printf(" %d", in[n - 1 - p]);
			}

		}
	}
}

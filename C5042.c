#include <stdio.h>
int main() {
	int m = 0, n = 0;
	int count = 0;
	scanf("%d %d",&m,&n);
	for (int i = m; i <= n;i++) {
		if (i==1) {
			continue;
		}
	    int  sum = 0;
		for (int j = 1; j < i;j++) {
			if (i%j==0) {
				sum += j;
			}
		}
		if (sum == i) {
			printf("%d = ",sum);
			for (int j = 1; j < i; j++) {
				if (i % j == 0) {
					if (j == 1) {
						printf("1");
					}
					else {
						printf(" + %d", j);
					}
				}
			}
			printf("\n");
			count++;
		}
	}
	if (count == 0) {
		printf("None");
	}
}

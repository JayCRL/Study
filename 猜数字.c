#include <stdio.h>
int main() {
	int x;
	int five=0, two=0, one=0, all=0, sum=0;
	int count = 0;
	scanf("%d", &x);
	if (x > 8 && x < 100) {
		for (five = x / 5; five > 0; five--) {
			for (two = x / 2; two > 0; two--) {
				for (one = x; one > 0; one--) {
					if (5 * five + 2 * two + one == x) {
						count++;
						all = five + two + one;
						printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", five, two, one, all);
						sum = 0;
					}
				}
			}
		}
	}
	printf("count = %d", count);
	return 0;
}

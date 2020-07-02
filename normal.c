#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define BIG 100000000

short seive[BIG];
long lastIndex = 2;

void seivefn() {
	for (long i = 2; i < sqrt(BIG); ++i) {
		if (!seive[i]) {
			for (long j = 2; j < BIG/i; ++j) {
				seive[i*j] = 1;
			}
		}
	}
}

int main() {
	memset(seive, 0, sizeof(seive));
	seive[0] = seive[1] = 1;

	seivefn();

	return 0;
}

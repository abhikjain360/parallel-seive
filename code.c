#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define BIG 100000000

long seive[BIG],
     lastCount = 2;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* seivefn(void* args) {
	while (lastCount < BIG) {
		if (seive[lastCount]) {
			pthread_mutex_lock(&lock);
			lastCount++;
			pthread_mutex_unlock(&lock);
		} else {
			pthread_mutex_lock(&lock);
			long i = lastCount;
			lastCount++;
			pthread_mutex_unlock(&lock);
			for (long j = 2; j < BIG/i; ++j)
				seive[i*j] = 1;
		}
	}
	return NULL;
}

int main() {
	memset(seive, 0, BIG * sizeof(long));
	seive[0] = seive[1] = 1;

	pthread_t worker[4];
	pthread_create(&worker[0], NULL, seivefn, NULL);
	pthread_create(&worker[1], NULL, seivefn, NULL);
	pthread_create(&worker[2], NULL, seivefn, NULL);
	pthread_create(&worker[3], NULL, seivefn, NULL);

	pthread_join(worker[0], NULL);

	return 0;
}

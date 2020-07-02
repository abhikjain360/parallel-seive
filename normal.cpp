#include <thread>
#include <mutex>
#include <cmath>
#include <cstring>

#define BIG 100000000

bool seive[BIG];
long lastIndex = 2;

void seivefn() {
	for (long i = 2; i < std::sqrt(BIG); ++i) {
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

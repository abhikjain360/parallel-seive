#include <thread>
#include <mutex>
#include <cmath>
#include <cstring>

#define BIG 100000000

bool seive[BIG];
long lastIndex = 2;

std::mutex lock;

void seivefn() {
	while (lastIndex < std::sqrt(BIG)) {
		if (seive[lastIndex]) {
			lock.lock();
			lastIndex++;
			lock.unlock();
		} else {
			lock.lock();
			long i = lastIndex;
			lastIndex++;
			lock.unlock();

			for (long j = 2; j < BIG/i; ++j) {
				seive[i*j] = 1;
			}
		}
	}
}

int main() {
	memset(seive, 0, sizeof(seive));
	seive[0] = seive[1] = 1;

	std::thread t1(seivefn);
	std::thread t2(seivefn);
	std::thread t3(seivefn);
	std::thread t4(seivefn);

	t2.detach();
	t3.detach();
	t4.detach();

	t1.join();


	return 0;
}

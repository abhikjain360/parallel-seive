# Parallel Sieve of Eratosthenes

Your good ol' Sieve, just in parallel. Here are some benchmarks:

Conditions:
1. Intel i3-8145U (2 cores, 4 threads)
2. 1GB RAM alloted to program
3. primes upto 10,000,000
4. Averaged over 10 runs

Language | Single-threaded | Multi-threaded
--- | --- | ---
*C++* | 1.414 | 1.272
*C* | 1.735 | 12.508

In C++, parallel one is ever-so-slightly faster than single-threaded one. Both C programs perform poor than C++ one, parallel one doing especially bad. Means I write awesome C++ code (or much more likely _really_ bad C code).

Compiled using GNU compiler. Compile flags can be seen in makefile.

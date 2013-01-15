#include <array>
#include <ctime>
#include <cstdio>

#include "XORer.hpp"

static std::array<unsigned int, 1000000> sampleSet;

void initSet()
{
	for (size_t i = 0; i < sampleSet.size(); ++i)
		sampleSet[i] = i;
}

int main()
{
	{
		initSet();
		XORer x;
		printf("Base line (100 million calls)\n");
		clock_t start = clock();

		// for (v : sapmleSet) not used to accomodate for VS2010
		for (int i = 0; i < 100; ++i) {
			for (auto it = sampleSet.begin(); it != sampleSet.end(); ++it)
				x.doXOR(*it);
		}

		clock_t dt = clock() - start;
		printf("%u clocks, %4.2f secs\n", dt, (float)dt / (float)CLOCKS_PER_SEC);
	}
	return 0;
}

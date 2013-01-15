#include <array>
#include <ctime>
#include <cstdio>

#include "XORer.hpp"
#include "FunctionWrapper.hpp"
#include "TemplatedFunctionWrapper.hpp"

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
	{
		initSet();
		XORer x;
		FunctionWrapper<unsigned int> wrap(std::bind(&XORer::doXOR, &x, std::placeholders::_1));
		printf("Wrapper using std::function (100 million calls)\n");
		clock_t start = clock();

		// for (v : sapmleSet) not used to accomodate for VS2010
		for (int i = 0; i < 100; ++i) {
			for (auto it = sampleSet.begin(); it != sampleSet.end(); ++it)
				wrap.call(*it);
		}

		clock_t dt = clock() - start;
		printf("%u clocks, %4.2f secs\n", dt, (float)dt / (float)CLOCKS_PER_SEC);
	}
	{
		initSet();
		XORer x;
		auto func = std::bind(&XORer::doXOR, &x, std::placeholders::_1);
		TemplatedFunctionWrapper<decltype(func), unsigned int> wrap(std::move(func));
		printf("Wrapper using decltype(std::bind) (100 million calls)\n");
		clock_t start = clock();

		// for (v : sapmleSet) not used to accomodate for VS2010
		for (int i = 0; i < 100; ++i) {
			for (auto it = sampleSet.begin(); it != sampleSet.end(); ++it)
				wrap.call(*it);
		}

		clock_t dt = clock() - start;
		printf("%u clocks, %4.2f secs\n", dt, (float)dt / (float)CLOCKS_PER_SEC);
	}
	return 0;
}

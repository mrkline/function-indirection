#include "XORer.hpp"

void XORer::doXOR(unsigned int v)
{
	 result ^= v;
}

unsigned int XORer::getResult() const
{
	return result;
}

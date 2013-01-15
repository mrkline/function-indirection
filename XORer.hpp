#pragma once

class XORer {
public:
	XORer() : result(0) { }

	void doXOR(unsigned int v);

	unsigned int getResult() const;

private:
	unsigned int result;
};

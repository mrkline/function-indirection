#pragma once

#include <functional>

// Represents a class that might wrap a function,
// such as an object that issues callbacks.
// Here we'll use std::function
template <typename T>
class FunctionWrapper {
public:
	FunctionWrapper(std::function<void(T)>&& w)
		: wrapped(w)
	{ }

	void call(T v) { wrapped(v); }

private:
	std::function<void(T)> wrapped;
};

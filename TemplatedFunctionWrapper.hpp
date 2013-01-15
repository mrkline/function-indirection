
#include <functional>

// Represents a class that might wrap a function,
// such as an object that issues callbacks.
// Here we'll use a template,
// which should give less indirection than std::function.
template <typename F, typename T>
class TemplatedFunctionWrapper {
public:
	TemplatedFunctionWrapper(F&& w)
		: wrapped(w)
	{ }

	void call(T v) { wrapped(v); }

private:
	F wrapped;
};

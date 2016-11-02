#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H

#include <string>
#include <stdexcept>

class PreconditionViolationException: public std::runtime_error
{
	public:
	PreconditionViolationException(const char* message);
};

#endif

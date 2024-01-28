#ifndef ERRORS_H
#define ERRORS_H

#include <stdexcept>

class NotImplementedException : public std::logic_error
{
public:
    const char *what() const noexcept override { return "Function not yet implemented."; }
};

#endif

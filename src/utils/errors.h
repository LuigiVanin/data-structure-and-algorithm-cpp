#ifndef ERRORS_H
#define ERRORS_H

#include <stdexcept>

class NotImplementedException : public std::logic_error
{
public:
    NotImplementedException() : std::logic_error("Function not yet implemented"){};
};

#endif

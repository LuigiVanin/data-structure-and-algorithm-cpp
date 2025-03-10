#ifndef ERRORS_H
#define ERRORS_H

#include <stdexcept>

class NotImplementedException : public std::logic_error
{
public:
    NotImplementedException() : std::logic_error("Function not yet implemented") {};
};

class CouldNotFindItem : public std::range_error
{
public:
    CouldNotFindItem() : std::range_error("Could not find item") {};
};

#endif

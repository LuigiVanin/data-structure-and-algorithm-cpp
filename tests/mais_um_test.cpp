#include "../src/ArrayList/ArrayList.h"

int main()
{
    auto list = new ArrayList<int>();
    list->Push(10);

    if (list->length != 1)
    {
        return 1;
    }

    return 0;
}
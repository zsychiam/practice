#include "iterator.h"

int MyIterator::curr()
{
    if (this->is_done())
        return -1;
    else
        return list->get(pos);
}

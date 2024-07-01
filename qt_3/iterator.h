#pragma once
#include "list.h"
class MyList;

class MyIterator {
public:
    MyIterator(MyList* aList):list(aList), pos(0){}

    void first(){ pos = 0; }
    void next() { pos++; }
    bool is_done() { return pos >= list->get_size(); }
    int curr();
private:
    MyList * list;
    long pos;
};

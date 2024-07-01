#pragma once
#include "list.h"

class MyStack
{
public:
    MyStack() : list(new MyList()) {}
    MyStack(const std::initializer_list<int>& list_) : list(new MyList(list_)) {}
    ~MyStack() {delete list;}

    int pop() {return this->list->pop();}
    int get_size(){return list->get_size();}
    int get_first() { return list->get_first() ; }
    void push(int a) {this->list->push(a);}
    void print() {this->list->print();}
    bool is_empty() {return this->list->is_empty();}
    void to_vec (std::vector<int> &vec) { this->list->to_vec(vec); }

private:
    MyList* list;
};

#pragma once
#include <iostream>
#include <vector>

struct SElement
{
    int data;
    SElement* next;
    SElement(int data_, SElement* next_)
        : data{ data_ }, next{ next_ } {};
    ~SElement() = default;
};

class MyList
{
private:
    SElement* first;
    size_t size;
public:
    MyList() : first(nullptr), size(0) {}
    MyList(const std::initializer_list<int>&);

    ~MyList();

    void print();
    void push(int a);
    void to_vec (std::vector<int> &vec);
    int pop();
    int get_first() { return first->data ; }
    bool is_empty();
    int get_size() { return size; }
};

#include <iostream>
#include "list.h"

bool MyList::is_empty() {
    return (first == nullptr);
}

void MyList::push(int a) {
    SElement* temp = new SElement(a, this->first);
    this->first = temp;
    this->size++;
}

int MyList::pop() {
    if (this->first == nullptr)return -1;
    SElement* temp = this->first;
    int num = temp->data;
    first = first->next;
    delete temp;
    return num;
}

void MyList::to_vec(std::vector<int> &vec){
    vec.clear();
    for (SElement *temp = first; temp != nullptr; temp = temp->next)
        vec.push_back(temp->data);
}

void MyList::print()
{
    for (SElement* temp = first; temp != nullptr; temp = temp->next)
        std::cout << temp->data << " ";
}

MyList::MyList(const std::initializer_list<int>& list) :MyList()
{
    for (int i : list)
        this->push(i);
}

MyList::~MyList()
{
    while (this->size)
        this->pop();
}

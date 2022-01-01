#ifndef CONTAINER_H
#define CONTAINER_H

#include "node.h"
#include <iostream>

//The container is implemented as a class with input, output, data cleaning and filter output writing functions
class Container 
{
    node* head, * tail; 
    int len;
public:
    void In(std::ifstream& ifst);
    void Out(std::ofstream& ofst);
    void Clear();
	void Out_Only_Sphere(std::ofstream& ofst); 
    Container(); 
    ~Container() { Clear(); }
};

#endif //CONTAINER_H
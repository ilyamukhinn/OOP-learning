#ifndef NODE_H
#define NODE_H

#include "Figure.h"

struct node 
{
    node* next, * prev; 
    Figure* F;
};

#endif //NODE_H
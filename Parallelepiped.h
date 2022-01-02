#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "Figure.h"

//a special case of the base class (geometric shapes) is a parallelepiped with its own parameters - parallelepiped's sides
class Parallelepiped : public Figure 
{
    int A, B, C;
public:
    void In_Data(std::ifstream& ifst); 
    void Out_Data(const double& Density, const int& Temperature, std::ofstream& ofst);
    Parallelepiped() {};
};

#endif // PARALLELEPIPED_H

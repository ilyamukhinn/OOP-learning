#ifndef FIGURE_H
#define FIGURE_H

#include <fstream>

//a basic class of geometric shapes with a common parameter - the density of the material
class Figure 
{
    double Density;
public:
    double Get_Density();
    static Figure* In(std::ifstream& ifst);
    virtual void In_Data(std::ifstream& ifst) = 0;
    virtual void Out_Data(const double& Density, std::ofstream& ofst) = 0;
protected:
    Figure() {};
};

#endif // FIGURE_H

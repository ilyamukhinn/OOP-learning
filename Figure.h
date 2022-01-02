#ifndef FIGURE_H
#define FIGURE_H

#include <fstream>

//a basic class of geometric shapes with a common parameter - the density of the material
class Figure 
{
    double Density;
	int Temperature;
public:
    double Get_Density();
	int Get_Temperature();
    static Figure* In(std::ifstream& ifst);
    virtual void In_Data(std::ifstream& ifst) = 0;
    virtual void Out_Data(const double& Density, const int& Temperature, std::ofstream& ofst) = 0;
protected:
    Figure() {};
};

#endif // FIGURE_H

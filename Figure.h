#ifndef FIGURE_H
#define FIGURE_H

#include <fstream>
#include <iostream>
#include <string>

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
	virtual double Volume() = 0;
	bool Compare(Figure* other);
	virtual void Out_Only_Sphere(const double& Density, const int& Temperature, std::ofstream& ofst);
	bool is_Number(const std::string& str_num, const bool& check_Integer);
protected:
    Figure() {};
};

#endif // FIGURE_H

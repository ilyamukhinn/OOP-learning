#include "Parallelepiped.h"

void Parallelepiped::In_Data(std::ifstream& ifst) 
{
    ifst >> A >> B >> C;
}

void Parallelepiped::Out_Data(const double& Density, const int& Temperature, std::ofstream& ofst) 
{
    ofst << "It's a Parallelepiped with Edges: " << A << ", " << B
        << ", " << C << std::endl;
    ofst << "Its Density is " << Density << std::endl;
	ofst << "Its Temperature of melting/burning is " << Temperature << std::endl << std::endl;
}

double Parallelepiped::Volume() 
{
    return (A * B * C);
}
#include  "Tetrahedron.h"
#include <math.h>

void Tetrahedron::In_Data(std::ifstream& ifst) 
{
    ifst >> A; 
}

void Tetrahedron::Out_Data(const double& Density, const int& Temperature, std::ofstream& ofst) 
{
    ofst << "It's a Tetrahedron with Side length: " << A << std::endl;
    ofst << "Its Density is " << Density << std::endl;
    ofst << "Its Temperature of melting/burning is " << Temperature << std::endl << std::endl;
}

double Tetrahedron::Volume() 
{
	return (pow((double)A, 3) * sqrt(2) / 12);
}
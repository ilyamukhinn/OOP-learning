#include  "Tetrahedron.h"

void Tetrahedron::In_Data(std::ifstream& ifst) 
{
    ifst >> A; 
}

void Tetrahedron::Out_Data(const double& Density, std::ofstream& ofst) 
{
    ofst << "It's a Tetrahedron with Side length: " << A << std::endl;
    ofst << "Its Density is " << Density << std::endl << std::endl;
}
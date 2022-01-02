#include "Figure.h"
#include "Sphere.h"
#include "Parallelepiped.h"

Figure* Figure::In(std::ifstream& ifst) 
{
    Figure* F;
    int id;

    ifst >> id;

    switch (id)
    {
    case 1:
        F = new Sphere;
        break;
    case 2:
        F = new Parallelepiped;
        break;
    default:
        return 0;
    }

    F->In_Data(ifst);
    ifst >> F->Density;
	ifst >> F->Temperature;

    return F;
}

double Figure::Get_Density()
{
    return Density;
}

int Figure::Get_Temperature()
{
    return Temperature;
}
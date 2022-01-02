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

    return F;
}

double Figure::Get_Density()
{
    return Density;
}

bool Figure::Compare(Figure* other) 
{
    return Volume() > other->Volume();
}
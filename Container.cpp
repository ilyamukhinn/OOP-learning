#include "Container.h"
#include "Figure.h"

Container::Container() 
{
    head = tail = new node();
    head->F = tail->F = NULL;
    head->next = tail->next = NULL;
    head->prev = tail->prev = NULL;
    len = 0;
}

void Container::In(std::ifstream& ifst) 
{
    node* current;

    while (!ifst.eof()) 
    {
        current = new node();
        current->next = NULL;
        current->prev = NULL;

        if (len == 0) 
        {
            if ((head->F = Figure::In(ifst))) 
            {
                tail = head;
                len++;
            }
        }
        else 
        {
            if ((current->F = Figure::In(ifst))) 
            {
                tail->next = current;
                current->prev = tail;
                tail = current;
                len++;
            }
        }
    }
}

void Container::Out(std::ofstream& ofst)
{
    ofst << "Container contains " << len
        << " elements." << std::endl << std::endl;

    node* current = head;

    for (int i = 0; i < len; i++)
    {
        ofst << i << ": ";
        current->F->Out_Data(current->F->Get_Density(), current->F->Get_Temperature(), ofst);

        if (current->next)
        {
            current = current->next;
        }
    }
}

void Container::Clear() 
{
    node* current = head;

    for (int i = 0; i < len; i++) 
    {
        free(current->F);

        if (current->next) 
        {
            current = current->next;
            free(current->prev);
        }
    }

    len = 0;
}

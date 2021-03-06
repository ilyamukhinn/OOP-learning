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
		ofst << "The Figure's Volume is " << current->F->Volume() << std::endl << std::endl;

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

void Container::Sort() 
{
    if (len > 1) 
    {
        node* first = head;
        node* second = head->next;
        node* temp = new node;

        for (int i = 0; i < len - 1; i++) 
        {
            for (int j = 0; j < len - i - 1; j++) 
            {
                if (first->F->Compare(second->F)) 
                {
                    temp->F = first->F;
                    first->F = second->F;
                    second->F = temp->F;
                }

                second = second->next;
            }

            first = first->next;
            second = first->next;
        }
    }
}

void Container::Out_Only_Sphere(std::ofstream& ofst) {
    ofst << "Only Spheres." << std::endl << std::endl;

    node* current = head;

    for (int i = 0; i < len; i++) 
    {
        ofst << i << ": ";
        current->F->Out_Only_Sphere(current->F->Get_Density(), current->F->Get_Temperature(), ofst);

        if (current->next) {
            current = current->next;
        }
    }
}

#include<stdio.h>
#include<conio.h>
#define Size 5

int Stack[Size];
int Top = 0;

int Is_Stack_Full();
int Is_Stack_Empty();
void Push(int No);
void Pop();
void Display_Stack();
int Stack_Cnt();
int Search_Stack_Element(int Num);

int main()
{
    int No = 0;

    Push(32);
    Push(25);
    Push(74);
    Push(12);
    getch();

    Display_Stack();                      ///32   25   74   12
    getch();

    printf("\n\n Number a Elements in Stack = %d.\n",Stack_Cnt());

    Pop();
    Pop();
    Pop();

    Display_Stack();
    getch();

    return 0;
}

int Is_Stack_Top()
{
    if(Top == Size)
    {
        return 1;
    }
    return 0;
}

int Is_Stack_Empty()
{
    if(Top == 0)
    {
        return 1;
    }
    return 0;
}

void Push(int No)
{
    if(Is_Stack_Top())
    {
        printf("\n Stack is Already Full, Can't Insert New Element...!");
    }
    else
    {
        Stack[Top] = No;
        Top++;
        printf("\n Stack Element is %d \n",No);
    }
    return;
}

void Pop()
{
    if(Is_Stack_Empty())
    {
        printf("\n Stack is Already Empty, Can't Delete any Element...!");
    }
    else
    {
        printf("\n Deleted Element From Stack is = %d",Stack[Top - 1]);
        Stack[Top - 1] = 0;
        Top--;
    }
    return;
}

void Display_Stack()
{
    if(Is_Stack_Empty())
    {
        printf("\n Stack is Already Empty So We Can't Display any Element...");
    }
    else
    {
        int i = 0;

        printf("\n\n Current Element in Stack are => \n");

        for(i = Top - 1; i >= 0; i--)
        {
            printf("\t\t |%3d| \n",Stack[i]);
        }
    }
}

int Stack_Cnt()
{
    return Top;
}

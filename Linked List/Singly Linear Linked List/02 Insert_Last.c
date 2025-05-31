#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int Data;                                        ///Create 4 Byte Memory
    struct Node *Next;                               ///Create 4 Byte Memory
};

void Insert_Last(struct Node **First, int No)
{
    struct Node *NewN = NULL;

    NewN = (struct Node*)malloc(sizeof(struct Node));    ///Allocation Dynamic Memory for New Node in Data Section Heap

    NewN -> Data = No;
    NewN -> Next =NULL;

    if(NULL == *First)
    {
        *First = NewN;
        printf("\n\n Inside if Block of Insert Last");
    }
    else
    {
        struct Node *Temp = *First;

        while(Temp -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = NewN;
    }
    printf("\n %d Element Inserted at Last Position Successfully",No);

    return;
}

void Display_LL(struct Node *First)
{
    if(NULL == First)
    {
        printf("\n Given Link List is Already Empty!!!");
    }
    else
    {
        printf("\n\n Element in Given Link List are\n");

        while(First != NULL)
        {
            printf(" | %d | ->",First -> Data);
            First = First -> Next;
        }
        printf("NULL");
        return;
    }
}

int main()
{
    int Num = 95;
    struct Node *Head = NULL;

    Insert_Last(&Head,Num);
    Insert_Last(&Head,30);
    Insert_Last(&Head,50);
    Insert_Last(&Head,21);

    Display_LL(Head);
    getch();
    return 0;

}

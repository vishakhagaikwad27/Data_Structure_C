
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int Data;                                              ///Create 4 Byte
    struct Node *Next;                                     ///Create 4 Byte
};

void Insert_First(struct Node **First,int No)
{
    struct Node *NewN = NULL;                             ///Create pointer for New tab

    NewN = (struct Node*)malloc(sizeof(struct Node));     ///Allocation Dynamic memory for new Node in Data Section Heep

    NewN -> Data = No;
    NewN -> Next = NULL;                                  ///Setting value to New tab

    if(*First == NULL)                                    ///Only once means for inserting very 2st element in LL
    {
         *First = NewN;
        printf("\n\n Inside if block of Insert first");
    }
    else                                                  ///works for every next element from 1st Onwards
    {
        NewN -> Next = *First;
        *First = NewN;
        printf("\n\n Inside else block Insert first");
    }
    printf("\n %d Element Inserted Successfully",No);

    return ;
}

void Insert_Last(struct Node **First,int No)
{
    struct Node *NewN = NULL;

    NewN = (struct Node*)malloc(sizeof(struct Node));   ///Allocation Dynamic memory for new Node in Data Section Heep

    NewN -> Data = No;
    NewN -> Next = NULL;

    if(NULL == *First)
    {
        *First = NewN;
        printf("\n Inside if block of insert Last");
    }
    else
    {
        struct Node *Temp = *First;

        while (Temp -> Next != NULL)
        {
            Temp = Temp-> Next;
        }
        Temp -> Next = NewN;
    }
    printf("\n\n %d Element Inserted at Last Position Successfully",No);
    return ;
}

void Display_LL(struct Node *First)
{
    if(NULL == First)
    {
        printf("\n Given Link List is Already Empty");
    }
    else
    {
        printf("\n\n Element in Given Link List are\n");

        while(First !=NULL)
        {
            printf(" |%d| ->",First -> Data);
               First = First -> Next;
        }
        printf("\n\n NULL");
    }
    return ;
}

void Delete_First(struct Node **First)
{
    if(NULL == *First)
    {
      printf("\n Link List is Already Empty");
    }
    else
    {
        struct Node *Temp = *First;

        *First = Temp -> Next;

        printf("\n\n Deleted first element in Link List = %d",Temp -> Data);

        free(Temp);
    }
    return ;
}

void Delete_Last(struct Node **First)
{
    if(NULL == *First)
    {
      printf("\n Link List is Already Empty");
    }
    else
    {
        struct Node *Temp = *First;

        if(Temp -> Next != NULL)
        {
            while(Temp -> Next -> Next != NULL)
            {
                Temp = Temp -> Next;
            }
        }
        printf("\n\n Deleted Last element in LL is = %d",Temp -> Next -> Data);

        free(Temp -> Next);

        Temp -> Next = NULL;
    }
    return;
}
int main()
{
    int Num = 83;
    struct Node *Head = NULL;

    Insert_First(&Head,Num);
    Insert_First(&Head,25);
    Insert_First(&Head,28);

    Display_LL(Head);

    getch();

    Insert_Last(&Head,99);
    Insert_Last(&Head,74);

    getch();

    Display_LL(Head);

    Delete_First(&Head);

    getch();
    system ("cls");

   Display_LL(Head);

   Delete_Last(&Head);

   Display_LL(Head);

    getch();
    return 0;
}

//CSE_202_TASK_1_using c plus plus
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#define MAX_SIZE 100

using namespace std;

void clrscr();
void view_Elements(int array[], int size);
void insert_Element(int array[], int *size);
void leaner_search(int array[], int size);
void delete_Element(int array[], int *size);
void ascending_sort(int array[], int size);
void descending_sort(int array[], int size);
void mem_Loc(int array[], int size);
int main()
{
    int array[MAX_SIZE];
    int size,i,n;

    cout<<"Enter the size of the array\n";
    cin>>size;
    cout<<"Enter the elements of the array\n";

    for(i=0;i<size;i++)
    {
        cin>>array[i];
    }
    //size=sizeof(array)/sizeof(array[0]);
    cout<<"The array has been inserted\n";
    start:
    clrscr();
    cout<<"*****The main Menu*****\n";
    cout<<"0....Exit\n1....View all elements\n2....Insert new element\n3....Search an element\n";
    cout<<"4....Delete an element\n5....Sort elements in ascending order\n6....Sort elements in descending order\n";
    cout<<"7....Find memory location of an element\n";
    cout<<"\nPlease enter the key for what operation you want to do: ";

    cin>>n;
    if(n==0){
        return 0;
    }
    else if(n==1)
    {   clrscr();
        view_Elements(array,size);
        cout<<"\n\n\nPress any key for the main menu:\n";
        getch();
        goto start;
    }
    else if(n==2)
    {
        clrscr();
        insert_Element(array,&size);
        cout<<"\n\n\nPress any key for the main menu:\n";
        getch();
        goto start;
    }
    else if(n==3)
    {
        clrscr();
        leaner_search(array,size);
        cout<<"\n\n\nPress any key for the main menu:\n";
        getch();
        goto start;
    }
    else if(n==4)
    {
        clrscr();
        delete_Element(array,&size);
        cout<<"\n\n\nPress any key for the main menu:\n";
        getch();
        goto start;
    }
    else if(n==5)
    {
        clrscr();
        ascending_sort(array,size);
        cout<<"\n\n\nPress any key for the main menu:\n";
        getch();
        goto start;

    }
    else if(n==6)
    {
        clrscr();
        descending_sort(array,size);
        cout<<"\n\n\nPress any key for the main menu:\n";
        getch();
        goto start;

    }
    else if(n==7)
    {
        clrscr();
        mem_Loc(array,size);
        cout<<"\n\n\nPress any key for the main menu:\n";
        getch();
        goto start;

    }
    else
    {
        cout<<"\nSorry! You have entered the wrong key\n\nPress any key to back the main menu\n";
        getch();
        goto start;
    }

}
void clrscr()
{
    system("@cls||clear");
}
void view_Elements(int array[], int size)
{
    int i;
    cout<<"\n********All elements of the array are shown bellow********\n";
    for(i=0;i<size;i++)
    {
        cout<<array[i]<<endl;
    }

}
void insert_Element(int array[], int *size)
{
    int i,newm;
    int position;
    cout<<"Enter the position where you want to store the new member\n";
    cin>>position;
    cout<<"Enter the number that you want to store\n";
    cin>>newm;
    for(i=*size;i>=position;i--)
    {
        array[i]=array[i-1];
    }
    array[position-1]=newm;
    (*size)++;
    cout<<"The new member has been added to the Array\n";
}
void leaner_search(int array[], int size)
{

    int i,num,index;
    cout<<"Enter the element do you want to search\n";
    cin>>num;

    for(i=0;i<size;i++)
    {
        if(array[i]==num)
        {
            index=i;
            break;
        }
        else index=-1;
    }
    if(index>0)
    {
        cout<<"The serial of the member in array is "<<index+1;
         cout<<" and the member is "<<array[index]<<endl;
    }
    else cout<<"The number you have entered is not present in the array\n";
}
void delete_Element(int array[], int *size)
{

    int i,num,index;

    cout<<"Enter the element do you want to delete\n";
    cin>>num;

    for(i=0;i<*size;i++)
    {
        if(array[i]==num)
        {
            index=i;
            break;
        }
        else index=-1;
    }
    if(index>0)
    {
        for(i=index;i<*size;i++)
        {
            array[index]=array[index+1];
        }
        cout<<"The number has been deleted from the array..\n";
        (*size)--;
    }
    else cout<<"Sorry! The number you have entered is not present in the array.\n";
}
void ascending_sort(int array[], int size)
{
    int i,j,temp;


    for(i=0;i<size;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    cout<<"********The array after ascending sort********\n\n";
    for(i=0;i<size;i++)
    {
        cout<<array[i]<<endl;
    }
}
void descending_sort(int array[], int size)
{
    int i,j,temp;


    for(i=0;i<size;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(array[j]<array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    cout<<"********The array after descending sort********\n\n";
    for(i=0;i<size;i++)
    {
        cout<<array[i]<<endl;
    }
}
void mem_Loc(int array[], int size)
{
    cout<<"Enter the index number for what you want to know the memory location: ";
    int x;
    cin>>x;
    if(x<1 || x>size) cout<<"The index you have entered is not present in this array\n";
    else cout<<"The memory location is = "<<&array[x-1]<<endl;
}

#include <stdio.h>
#include <windows.h>                 //  header file for gotoxy
#include <time.h>                    // To use time library of C



void delay(int number_of_seconds);                 //declare function for delay
void gotoxy(int x,int y);                          //declare function for draw on the screen
int oddOrEven ( int number);                       //declare function that tell you odd Or Even int
void main(void)
{
    int row,col,value,size,check;
    printf("please enter the only odd size of magic square\n");
    scanf("%d",&size);
    check=oddOrEven(size);             // for check if value even the program doesn't continue
    if (check==-1)
        printf("");
        else
    {
        row=1;                        // initial inputs
        col=(size+1)/2;
        value=1;

        do
        {
              gotoxy(col*5,row*2);
              printf("%5d",value);
              delay(1);
              if (value%size==0) row++;
              else
              {
                  row--;
                  col--;
              }
              if (row==0) row=size;
              if (col==0) col=size;
              value++;
        } while(value<=size*size);

        }
        printf("\n \n");

}
void gotoxy(int x,int y)                              // function for draw on screen
{
    COORD coord= {0,0}; // this is global variable
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int oddOrEven ( int number)                           //function that tell you odd Or Even int
     {
         int check =-1;
         if (number%2==0&&number!=0)
         {
            printf("the Number is even \nplease enter odd number\n");
            return check;


         }
         else if (number==0)
         {
             printf("the Number is Zero\nplease enter odd number\n");
             return check;

         }
         else
         {
             printf("");
         }
     }
     void delay(int number_of_seconds)                // function for delay
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}


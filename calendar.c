//program to make a calendar with additional options
#include<stdio.h>
#include<stdlib.h>
#define zero 0
#define leap_year ((year%400 == 0) || (year%4 == 0 && year%100 !=0))

void clearScreen()
{
   system("clear");         //to clear the screen
}

void weekDayName()          //to display week days 
{
   printf("\t\t Mon  Tue  Wed  Thru  Fri  Sat  Sun\n");
}


void displayCalendar()
{
   clearScreen();
   weekDayName();  
}

void choiceDisplay()       //to display choices
{
   printf("CHOICES : \n");
   printf("Press 1 to view the current month calendar. \n");
   printf("Press 2 to view the calendar of the desired month. \n");
   printf("Press 3 to view which day on particular date.\n");
   printf("Press 4 to view national holidays.\n");
   printf("Press 5 to add a reminder to a particular date.\n");
}

int choiceSelector()       //to take user choice
{
   int ch;
   printf("Enter your choice : ");
   scanf("%d",&ch);
   return ch;
}

void choiceExecution()
{
   int choice;
   char con = 'y';
   do{
      clearScreen();
      choiceDisplay();
      choice = choiceSelector();
      switch(choice)
      { 
         case 1 :displayCalendar();
                 
                 break;
         case 2 :
                 break;
         case 3 : 
                 break;
         case 4 : 
                 break;
         case 5 : 
                 break;                                                        
         default: printf("Wrong choice."); 
                 break;              
      }
      printf("\nDo you wish to continue ? ");
      printf("\nPress y to continue or n to exit.");
      printf("\nEnter choice : ");
      fflush(stdin);
      scanf("%s",&con);
   }while(con == 'y' || con == 'Y');
}

int main()
{
   choiceExecution();
   return zero;
}

//this progran runs of linux
//program to make a calendar with additional options
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define zero 0

int republicDay=26, independenceDay=15, gandhiJayanti=2, ans;
int dateMonthDisplay, dateInMonthCalculate;

void clearScreen()
{
   system("clear");         //to clear the screen
}

void weekDayName()          //to display week days 
{
   printf("Sun\tMon\tTue\tWed\tThru\tFri\tSat\n");
}

void calendarDates()
{
   int i,c=0;
   for(i = 0; i<(dateMonthDisplay) ; i++)
   {
      printf("\t");
      c++;
   }
   for(i = 1; i<=dateInMonthCalculate; i++)
   {
      printf("%d\t",i);
      c++;
      if(c % 7 == 0)
      printf("\n");
   }
}

void displayCalendar()
{
   clearScreen();
   weekDayName();
   calendarDates();  
}

void choiceDisplay()       //to display choices
{
   printf("CHOICES : \n");
   printf("Press 1 to view the calendar of the desired month. \n");
   printf("Press 2 to view which day on particular date.\n");
   printf("Press 3 to view national holidays.\n");
   printf("Press 4 to add a reminder to a particular date.\n");
   printf("Press 5 to exit.\n");
}

int choiceSelector()       //to take user choice
{
   int ch;
   printf("Enter your choice : ");
   scanf("%d",&ch);
   return ch;
}


void whichDay(int d)      //to display day name
{
   if(d == 0)
      printf(" Sunday ");
   else if(d == 1)
      printf(" Monday ");
   else if(d == 2)
      printf(" Tuesday ");
   else if(d == 3)
      printf(" Wednesday ");
   else if(d == 4)
      printf(" Thrusday ");
   else if(d == 5)
      printf(" Friday ");
   else if(d == 6)
      printf(" Saturday ");                     
}


void whichMonth(int m)     //to display month name
{
   if(m == 1)
      printf(" January ");
   else if(m == 2)
      printf(" February ");
   else if(m == 3)
      printf(" March ");
   else if(m == 4)
      printf(" April ");
   else if(m == 5)
      printf(" May ");
   else if(m == 6)
      printf(" June ");
   else if(m == 7)
      printf(" July ");
   else if(m == 8)
      printf(" August ");
   else if(m == 9)
      printf(" September ");
   else if(m == 10)
      printf(" October ");
   else if(m == 11)
      printf(" November ");
   else if(m == 12)
      printf(" December ");   
}

void displayDayOnParticularDate(int month, int year, int caseDependent)   //to calculate day name on particular date by zeller algorithm
{
   int mdummy,ydummy,date = 1;
   if(caseDependent == 2)
      date = republicDay;
   else if(caseDependent == 3)
      date = independenceDay;
   else if(caseDependent == 4)
      date = gandhiJayanti;   
   mdummy = month;
   ydummy = year; 
      
   if(caseDependent == 1)
   { 
      printf("\n Enter the day : ");
      scanf("%d",&date);
      if(date < 1 || date > 31)
      {
         printf("\n Invalid date");
         return;
      }
      if(month == 2 && ((year%400 == 0) || (year%4 == 0 && year%100 !=0)) && date > 29)
      {
         printf("\n February doesnt' have more than 29 days in leap year.");
         return;
      }
   }
   
   if(month < 3)   
      month = month + 10;   
   else
      month = month -2;
   if(month > 10)   
      year = year - 1;   
   else
      year = year;
      
   ans = ((int)((13*month-1)/5)+date+(year%100)+(int)((year%100)/4)-2*(int)(year/100)+(int)(year/400)+77)%7;               //zeller algorithm

   if(caseDependent == 1 )
   {
      if(date == 1 || date == 21)
         printf("\n The day on %dst ",date);
      else if(date == 2 || date == 22)
         printf("\n The day on %dnd",date);  
      else if(date == 3 || date == 23)
         printf("\n The day on %drd",date);
      else
         printf("\n The day on %dth of",date); 
      whichMonth(mdummy);
      printf(" %d = ",ydummy);
      whichDay(ans);
   }
     
   else if(caseDependent == 2 || caseDependent == 3 || caseDependent == 4)
      return;
   
   else
   {  
      dateMonthDisplay = ans;
      if(mdummy == 1 || mdummy == 3 || mdummy == 5 || mdummy == 7 || mdummy == 8 || mdummy == 10 || mdummy == 12)
         dateInMonthCalculate = 31;
      else if(mdummy == 2 && ((ydummy%400 == 0) || (ydummy%4 == 0 && ydummy%100 !=0)))
         dateInMonthCalculate = 29;
      else if(mdummy == 2)
         dateInMonthCalculate = 28;
      else
         dateInMonthCalculate = 30;
      displayCalendar();  
   }
   
  
}


void getMonthName(int ch)
{
   int mon, year;
   clearScreen();
   printf("\n Enter the year : ");
   scanf("%d",&year);
   if(year < 100)
      year = year + 1900;
   printf("\n Enter the number of the month : ");
   scanf("%d",&mon);
   if(mon < 1 || mon > 12)
   {
      printf("\n Invalid month");
      return ;
   }   
   if(ch == 0)
   {
      displayDayOnParticularDate(mon,year,0);
   }
   
   else
   {
      displayDayOnParticularDate(mon,year,1);
   }
}

void displayMessageOfNationalHoliday(int date, int month, int year)
{
   if(date == 1 || date == 21)
      printf(" is on %dst ",date);
   else if(date == 2 || date == 22)
      printf(" is on %dnd",date);  
   else if(date == 3 || date == 23)
      printf(" is on %drd",date);
   else
      printf(" is on %dth of",date); 
   whichMonth(month);
   printf(" %d = ",year);
   whichDay(ans);
}


void nationalHoliday()
{
   int year;
   clearScreen();
   printf("\n Enter the year whose national holiday you wish to see : ");
   scanf("%d",&year);
   printf("\nRepublic day = ");
   displayDayOnParticularDate(1,year,2);
   displayMessageOfNationalHoliday(republicDay, 1, year);
   printf("\nIndependence day = ");
   displayDayOnParticularDate(8,year,3);
   displayMessageOfNationalHoliday(independenceDay, 8, year);
   printf("\nGandhi Jayanti = ");
   displayDayOnParticularDate(10,year,4);
   displayMessageOfNationalHoliday(gandhiJayanti, 10, year);
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
         case 1 :getMonthName(0);                 
                 break;
                 
         case 2 :getMonthName(1);
                 break;
                
         case 3 :nationalHoliday();
                 break;
                 
         case 4 : 
                 break;
         
         case 5: printf("\n End of program.");
                 exit(0);
                                                                         
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
   printf("\n This calendar works for year between 1952 and 4902.");
   choiceExecution();
   return zero;
}

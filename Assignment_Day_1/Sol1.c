#include<stdio.h>
struct Date{
 int day;
 int month;
 int year;
};

int  option(){
    int option;
    printf("0:For exit!\n");
    printf("1:For Initializing Date\n");
    printf("2:For printing date on console\n");
    printf("3:For accepting new date\n");
    printf("Enter your option\n");
    scanf("%d",&option);
    return option;
}

void initDate(struct Date* ptr){
    printf("Enter day\n");
    scanf("%d",&ptr->day);
    printf("Enter month\n");
    scanf("%d",&ptr->month);
    printf("Enter year\n");
    scanf("%d",&ptr->year);
}

void printDateOnConsole(struct Date* ptr){
    printf("Day: %d Month: %d Year: %d\n",ptr->day,ptr->month,ptr->year);
}

void acceptDateOnConsole(struct Date* ptr){
    printf("Enter date in Format: Day->Month->Year\n");
    scanf("%d %d %d",&ptr->day,&ptr->month,&ptr->year);
}


int main(){
    struct Date d;
    int menu;
    while((menu=option())!=0)
    {
        switch(menu)
        {
            case 1:
            initDate(&d);
            break;

            case 2:
            printDateOnConsole(&d);
            break;

            case 3:
            acceptDateOnConsole(&d);
            break;

            default:
            printf("Not a Valid Choice...\n");
        }

    }
    printf("Thank You!!");
    return 0;
}
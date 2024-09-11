#include <stdio.h>
struct Date
{
    int day;
    int month;
    int year;
};
void initDate(struct Date *ptrDate)
{
    printf("09/09/2024");
}
void printDateOnConsol(struct Date *ptrDate)
{
    printf("\nDate : %d/%d/%d ", ptrDate->day, ptrDate->month, ptrDate->year);
}
void acceptDateFromConsol(struct Date *ptrDate)
{
    printf("Enter Day :");
    scanf("%d", &ptrDate->day);
    printf("Enter Month :");
    scanf("%d", &ptrDate->month);
    printf("Enter Year :");
    scanf("%d", &ptrDate->year);
}

int main()
{
    struct Date D1;
    int ch;
    do
    {
        printf("\n0.EXIT\n1.Init Date\n2.Accept Date\n3.Display Date");
        printf("\nEnter your Choice :");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            printf("Program End....");
            break;

        case 1:
            initDate(&D1);
            break;
        case 2:
            acceptDateFromConsol(&D1);
            break;
        case 3:
            printDateOnConsol(&D1);
            break;

        default:
            printf("Invalid Choice...!");
            break;
        }
    } while (ch != 0);

    return 0;
}
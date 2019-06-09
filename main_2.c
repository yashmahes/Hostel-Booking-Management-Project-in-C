#include <stdio.h>
#include <stdlib.h>
#define MAX_HOSTELERS 100



struct Student
{
    int studentId;
    char name[50];
    char gender[100];
    char roomDetails[50];
    char paymentMode[20];
    int amountDue;
    int numberOfWeeks;
    int amountReceived;
};

struct Block
{

    char name[50];
    char gender[100];
    char roomType[50];
    int roomsAvailable;
    int mealRate;
    int gymRate;
    struct Student hostelers[MAX_HOSTELERS];
    int count;
} A1, A2, A3, A4;



void initializeBlocks()
{
    strcpy(A1.name, "A1");
    strcpy(A1.gender, "Male");
    strcpy(A1.roomType, "Single Bed");
    A1.roomsAvailable = 100;
    A1.mealRate = 120;
    A1.gymRate = 10;
    A1.count = 0;

    strcpy(A2.name, "A2");
    strcpy(A2.gender, "Male");
    strcpy(A2.roomType, "2-Bedded");
    A2.roomsAvailable = 100;
    A2.mealRate = 120;
    A2.gymRate = 10;
    A2.count = 0;

    strcpy(A3.name, "A3");
    strcpy(A3.gender, "Male");
    strcpy(A3.roomType, "3-Bedded");
    A3.roomsAvailable = 100;
    A3.mealRate = 120;
    A3.gymRate = 10;
    A3.count = 0;

    strcpy(A4.name, "A4");
    strcpy(A4.gender, "Male");
    strcpy(A4.roomType, "4-Bedded");
    A4.roomsAvailable = 100;
    A4.mealRate = 120;
    A4.gymRate = 10;
    A4.count = 0;
}

int getRoomType()
{

    int roomType;
    while(1)
    {
        printf("Select room Type \n");
        printf("1. Single Bed \n");
        printf("2. 2-Bedded\n");
        printf("3. 3-Bedded\n");
        printf("4. 4-Bedded\n");

        printf("Enter your choice : ");

        int choice;
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 4)
        {
            roomType = choice;
            break;
        }
        else
        {
            printf("\nInvalid choice. Try again.\n");
        }

    }
    return roomType;
}

// return 1 if id is valid. return 0 if id already exists.
int validId(int id)
{
    int i=0;
    for(i=0; i<A1.count; i++)
    {
        if (A1.hostelers[i].studentId == id)
        {
            return 0;
        }

    }
    for(i=0; i<A2.count; i++)
    {
        if (A2.hostelers[i].studentId == id)
        {
            return 0;
        }

    }
    for(i=0; i<A3.count; i++)
    {
        if (A3.hostelers[i].studentId == id)
        {
            return 0;
        }

    }
    for(i=0; i<A4.count; i++)
    {
        if (A4.hostelers[i].studentId == id)
        {
            return 0;
        }

    }

    return 1;

}

void bookRoom()
{
    struct Student temp;
    printf("Enter hosteler's Id : ");
    int id;
    scanf("%d", &id);
    if(validId(id) == 0)
    {
        printf("\nThis id already exists. Try again with different id. \n");
        return;
    }
    temp.studentId = id;

    printf("Enter hosteler's name : ");
    char name[50];
    scanf(" %s", &name);
    strcpy(temp.name, name);

    //printf("Enter hosteler's gender : ");
    //char gender[50];
    //scanf(" %s", &gender);
    strcpy(temp.gender, "Male");
    temp.amountReceived = 0;

    printf("Enter hosteler's payment Mode : ");
    char paymentMode[50];
    scanf(" %s", &paymentMode);
    strcpy(temp.paymentMode, paymentMode);

    printf("Enter number Of Weeks : ");
    int numberOfWeeks;
    scanf("%d", &numberOfWeeks);
    temp.numberOfWeeks = numberOfWeeks;


    //printf("Select hosteler's room Type : ");
    //char roomDetails[50];
    //scanf(" %s", &roomDetails);
    int roomType = getRoomType();

    if(roomType == 1)
    {
        strcpy(temp.roomDetails, "Single Bed");
        int amountDue = temp.numberOfWeeks*A1.mealRate + temp.numberOfWeeks*A1.gymRate;
        temp.amountDue = amountDue;
        if(A1.roomsAvailable > 0)
        {
            A1.hostelers[A1.count] = temp;
            A1.count += 1;
            A1.roomsAvailable -= 1;
        }
        else
        {
            printf("\nNo room available for this block. \n");
        }
    }
    if(roomType == 2)
    {
        strcpy(temp.roomDetails, "2-Bedded");
        int amountDue = temp.numberOfWeeks*A2.mealRate + temp.numberOfWeeks*A2.gymRate;
        temp.amountDue = amountDue;
        if(A2.roomsAvailable > 0)
        {
            A2.hostelers[A2.count] = temp;
            A2.count += 1;
            A2.roomsAvailable -= 1;
        }
        else
        {
            printf("\nNo room available for this block. \n");
        }
    }
    if(roomType == 3)
    {
        strcpy(temp.roomDetails, "3-Bedded");
        int amountDue = temp.numberOfWeeks*A3.mealRate + temp.numberOfWeeks*A3.gymRate;
        temp.amountDue = amountDue;
        if(A3.roomsAvailable > 0)
        {
            A3.hostelers[A3.count] = temp;
            A3.count += 1;
            A3.roomsAvailable -= 1;
        }
        else
        {
            printf("\nNo room available for this block. \n");
        }
    }
    if(roomType == 4)
    {
        strcpy(temp.roomDetails, "4-Bedded");
        int amountDue = temp.numberOfWeeks*A4.mealRate + temp.numberOfWeeks*A4.gymRate;
        temp.amountDue = amountDue;
        if(A4.roomsAvailable > 0)
        {
            A4.hostelers[A4.count] = temp;
            A4.count += 1;
            A4.roomsAvailable -= 1;
        }
        else
        {
            printf("\nNo room available for this block. \n");
        }
    }

    printf("%s hosteler successfully added. \n", temp.name);

}

void checkRoomAvailability()
{
    int gender;
    while(1)
    {
        printf("Select gender \n");
        printf("1. Male\n");
        printf("2. Female\n");

        printf("Enter your choice : ");

        int choice;
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 2)
        {
            gender = choice;
            break;
        }
        else
        {
            printf("\nInvalid choice. Try again.\n");
        }

    }

    int roomType = getRoomType();

    if(gender == 2)
    {
        printf("There are 0 rooms available for this room type and gender. \n");
    }
    else if(gender == 1)
    {
        if(roomType == 1)
        {
            printf("There are %d rooms available for this room type and gender. \n", A1.roomsAvailable);
        }
        if(roomType == 2)
        {
            printf("There are %d rooms available for this room type and gender. \n", A2.roomsAvailable);
        }
        if(roomType == 3)
        {
            printf("There are %d rooms available for this room type and gender. \n", A3.roomsAvailable);
        }
        if(roomType == 4)
        {
            printf("There are %d rooms available for this room type and gender. \n", A4.roomsAvailable);
        }
    }
}

struct Student getHostelerById()
{
    printf("Enter hosteler's Id : ");
    int id;
    scanf("%d", &id);

    int i=0;
    for(i=0; i<A1.count; i++)
    {
        if (A1.hostelers[i].studentId == id)
        {
            return A1.hostelers[i];
        }

    }
    for(i=0; i<A2.count; i++)
    {
        if (A2.hostelers[i].studentId == id)
        {
            return A2.hostelers[i];
        }

    }
    for(i=0; i<A3.count; i++)
    {
        if (A3.hostelers[i].studentId == id)
        {
            return A3.hostelers[i];
        }

    }
    for(i=0; i<A4.count; i++)
    {
        if (A4.hostelers[i].studentId == id)
        {
            return A4.hostelers[i];
        }

    }


}


void getBill()
{
    struct Student temp = getHostelerById();
    if(temp.studentId >= 1000000)
    {
        printf("There is no such hosteler with this Id.");
        return;
    }
    printf("\nThe bill for this student is %d \n", temp.amountDue);
}

void getAmountReceivableAndPaymentReceived()
{
    struct Student temp = getHostelerById();
    if(temp.studentId >= 1000000)
    {
        printf("There is no such hosteler with this Id.");
        return;
    }
    printf("\nId: %d , Name: %s , Total Amount receivable: %d \n", temp.studentId, temp.name, temp.amountDue);
    printf("\nTotal payment received: %d \n", temp.amountReceived);
}

void searchHostelerDetails()
{
    struct Student temp = getHostelerById();
    if(temp.studentId >= 1000000)
    {
        printf("There is no such hosteler with this Id.");
        return;
    }
    printf("Name: %s \n", temp.name);
    printf("Gender: %s \n", temp.gender);
    printf("Payment Mode: %s \n", temp.paymentMode);
    printf("Room Details: %s \n", temp.roomDetails);
    printf("\nThe bill for this student is %d \n", temp.amountDue);
}


void makePayment()
{
    printf("Enter Payment Amount : ");
    int payment;
    scanf("%d", &payment);

    printf("Enter hosteler's Id : ");
    int id;
    scanf("%d", &id);

    int i=0;
    for(i=0; i<A1.count; i++)
    {
        if (A1.hostelers[i].studentId == id)
        {
            A1.hostelers[i].amountReceived += payment;
            return;
        }

    }
    for(i=0; i<A2.count; i++)
    {
        if (A2.hostelers[i].studentId == id)
        {
            A2.hostelers[i].amountReceived += payment;
            return;
        }

    }
    for(i=0; i<A3.count; i++)
    {
        if (A3.hostelers[i].studentId == id)
        {
            A3.hostelers[i].amountReceived += payment;
            return;
        }

    }
    for(i=0; i<A4.count; i++)
    {
        if (A4.hostelers[i].studentId == id)
        {
            A4.hostelers[i].amountReceived += payment;
            return;
        }

    }

    printf("Payment has been successfully made \n");
}

void getDetailsByRoomType()
{
    int roomType = getRoomType();

    int i=0;
    struct Student temp;
    if(roomType == 1)
    {
        for(i=0; i<A1.count; i++)
        {
            temp = A1.hostelers[i];
            printf("\nId: %d , Name: %s , Amount receivable: %d \n", temp.studentId, temp.name, temp.amountDue);
        }
    }
    if(roomType == 2)
    {
        for(i=0; i<A2.count; i++)
        {
            temp = A2.hostelers[i];
            printf("\nId: %d , Name: %s , Amount receivable: %d \n", temp.studentId, temp.name, temp.amountDue);

        }
    }
    if(roomType == 3)
    {
        for(i=0; i<A3.count; i++)
        {
            temp = A3.hostelers[i];
            printf("\nId: %d , Name: %s , Amount receivable: %d \n", temp.studentId, temp.name, temp.amountDue);

        }
    }
    if(roomType == 4)
    {
        for(i=0; i<A4.count; i++)
        {
            temp = A4.hostelers[i];
            printf("\nId: %d , Name: %s , Amount receivable: %d \n", temp.studentId, temp.name, temp.amountDue);

        }
    }
}

void menu()
{
    initializeBlocks();

    //printf("%s", A1.roomType);

    while(1)
    {

        printf("\n\nMenu \n");
        printf("1. Book Room for Hosteler\n");
        printf("2. Check room availability by type and gender in each block.\n");
        printf("3. Bill based on number of weeks of booked by hosteler.\n");
        printf("4. Search hosteler's room detail.\n");
        printf("5. Make Payment.\n");
        printf("6. Print amount receivable from each hosteler by room type\n");
        printf("7. Print total amount receivable and total payment received.\n");
        printf("0. Quit \n");

        printf("Enter your choice : ");

        int choice;
        scanf("%d", &choice);

        if(choice==1)
        {
            bookRoom();

        }

        else if(choice==2)
        {
            checkRoomAvailability();
        }

        else if(choice==3)
        {
            getBill();
        }
        else if(choice==4)
        {
            searchHostelerDetails();
        }
        else if(choice==5)
        {
            makePayment();
        }
        else if(choice==6)
        {
            getDetailsByRoomType();
        }
        else if(choice==7)
        {
            getAmountReceivableAndPaymentReceived();
        }

        else if(choice==0)
        {
            printf("\n\nBye!!!");
            break;

        }

        else
        {
            printf("\nInvalid choice. Try again.\n");

        }

    }
}

int main()
{
    printf("Welcome!\n\n");
    menu();
    return 0;
}

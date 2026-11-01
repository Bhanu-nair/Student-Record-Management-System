#include <stdio.h>
#include <string.h>
#include "student.h"

void stud_mod(student *head)
{
    student *temp;
    student *selected = NULL;

    int roll, found = 0;
    float percentage;

    char choice, field;
    char name[30];

    if(head == NULL)
    {
        printf("No Records Found!\n");
        return;
    }


    printf("\nR/r : Roll Number\n");
    printf("N/n : Name\n");
    printf("P/p : Percentage\n");

    printf("\nEnter Your Choice: ");
    scanf(" %c", &choice);


    if(choice == 'R' || choice == 'r')
    {
        printf("Enter Roll Number: ");

        if(scanf("%d", &roll) != 1)
        {
            printf("Invalid Input!\n");
            return;
        }

        temp = head;

        while(temp != NULL)
        {
            if(temp->roll == roll)
            {
                selected = temp;
                break;
            }

            temp = temp->next;
        }
    }

    /* Search using Name */

    else if(choice == 'N' || choice == 'n')
    {
        printf("Enter Student Name: ");
        scanf(" %29[^\n]", name);

        temp = head;

        printf("\nMatching Records:\n");

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("%d  %s  %.2f\n",
                       temp->roll,
                       temp->name,
                       temp->percentage);

                found = 1;
            }

            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Student Not Found!\n");
            return;
        }

        printf("Enter Roll Number: ");

        if(scanf("%d", &roll) != 1)
        {
            printf("Invalid Input!\n");
            return;
        }

        temp = head;

        while(temp != NULL)
        {
            if(temp->roll == roll &&
               strcmp(temp->name, name) == 0)
            {
                selected = temp;
                break;
            }

            temp = temp->next;
        }
    }


    else if(choice == 'P' || choice == 'p')
    {
        printf("Enter Percentage: ");

        if(scanf("%f", &percentage) != 1 ||
           percentage < 0 || percentage > 100)
        {
            printf("Invalid Percentage!\n");
            return;
        }

        temp = head;

        printf("\nMatching Records:\n");

        while(temp != NULL)
        {
            if(temp->percentage - percentage < 0.01f &&
               percentage - temp->percentage < 0.01f)
            {
                printf("%d  %s  %.2f\n",
                       temp->roll,
                       temp->name,
                       temp->percentage);

                found = 1;
            }

            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Student Not Found!\n");
            return;
        }

        printf("Enter Roll Number: ");

        if(scanf("%d", &roll) != 1)
        {
            printf("Invalid Input!\n");
            return;
        }

        temp = head;

        while(temp != NULL)
        {
            if(temp->roll == roll &&
               temp->percentage - percentage < 0.01f &&
               percentage - temp->percentage < 0.01f)
            {
                selected = temp;
                break;
            }

            temp = temp->next;
        }
    }

    else
    {
        printf("Invalid Choice!\n");
        return;
    }

    if(selected == NULL)
    {
        printf("Student Not Found!\n");
        return;
    }


    printf("\nN/n : Modify Name\n");
    printf("P/p : Modify Percentage\n");

    printf("\nEnter Your Choice: ");
    scanf(" %c", &field);


    if(field == 'N' || field == 'n')
    {
        printf("Enter New Name: ");
        scanf(" %29[^\n]", selected->name);

        printf("Name Modified Successfully!\n");
    }


    else if(field == 'P' || field == 'p')
    {
        printf("Enter New Percentage: ");

        if(scanf("%f", &percentage) != 1 ||
           percentage < 0 || percentage > 100)
        {
            printf("Invalid Percentage!\n");
            return;
        }

        selected->percentage = percentage;

        printf("Percentage Modified Successfully!\n");
    }

    else
    {
        printf("Invalid Choice!\n");
    }
}

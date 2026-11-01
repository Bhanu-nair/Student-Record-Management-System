#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void stud_del(student **head)
{
    student *temp, *prev;
    int roll, found = 0;
    char choice;
    char name[30];

    if(*head == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\nR/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");

    printf("\nEnter Your Choice: ");
    scanf(" %c", &choice);

    /* Delete using Roll Number */

    if(choice == 'R' || choice == 'r')
    {
        printf("Enter Roll Number: ");

        if(scanf("%d", &roll) != 1)
        {
            printf("Invalid Input!\n");
            return;
        }
    }

    /* Delete using Name */

    else if(choice == 'N' || choice == 'n')
    {
        printf("Enter Student Name: ");
        scanf(" %29[^\n]", name);

        temp = *head;

        printf("\nMatching Records:\n");

        printf("-----------------------------------------------\n");
        printf("%-12s %-20s %-12s\n",
               "Roll No", "Name", "Percentage");
        printf("-----------------------------------------------\n");

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("%-12d %-20s %-12.2f\n",
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

        printf("-----------------------------------------------\n");

        printf("Enter Roll Number to Delete: ");

        if(scanf("%d", &roll) != 1)
        {
            printf("Invalid Input!\n");
            return;
        }
    }

    else
    {
        printf("Invalid Choice!\n");
        return;
    }

    /* Search and delete node */

    temp = *head;
    prev = NULL;

    while(temp != NULL)
    {
        if(temp->roll == roll)
        {
            if(choice == 'N' || choice == 'n')
            {
                if(strcmp(temp->name, name) != 0)
                {
                    temp = temp->next;
                    continue;
                }
            }

            found = 1;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Student Not Found!\n");
        return;
    }

    if(prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);

    printf("Student Deleted Successfully!\n");
}

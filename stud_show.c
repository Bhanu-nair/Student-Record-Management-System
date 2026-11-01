#include <stdio.h>
#include <string.h>
#include "student.h"


void stud_show(student *head)
{
    student *temp = head;

    if(temp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\n-----------------------------------------------\n");

    printf("%-12s %-20s %-12s\n",
           "Roll No", "Name", "Percentage");

    printf("-----------------------------------------------\n");

    while(temp != NULL)
    {
        printf("%-12d %-20s %-12.2f\n",
               temp->roll,
               temp->name,
               temp->percentage);

        temp = temp->next;
    }

    printf("-----------------------------------------------\n");
}



void stud_sort(student *head)
{
    student *i, *j;


char     choice;
    int temp_roll;

    char temp_name[30];
    float temp_percentage;

    if(head == NULL || head->next == NULL)
    {
        printf("Not Enough Records to Sort!\n");
        return;
    }

    printf("\nN/n : Sort by Name\n");
    printf("P/p : Sort by Percentage\n");

    printf("\nEnter Your Choice: ");
scanf(" %c", &choice);
    /* Sort by Name */

    if(choice == 'N' || choice == 'n')
    {
        for(i = head; i->next != NULL; i = i->next)
        {
            for(j = i->next; j != NULL; j = j->next)
            {
                if(strcmp(i->name, j->name) > 0)
                {
                    temp_roll = i->roll;
                    i->roll = j->roll;
                    j->roll = temp_roll;

                    strcpy(temp_name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, temp_name);

                    temp_percentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = temp_percentage;
                }
            }
        }

        printf("Records Sorted by Name Successfully!\n");
    }


    else if(choice == 'P' || choice == 'p')
    {
        for(i = head; i->next != NULL; i = i->next)
        {
            for(j = i->next; j != NULL; j = j->next)
            {
                if(i->percentage > j->percentage)
                {
                    temp_roll = i->roll;
                    i->roll = j->roll;
                    j->roll = temp_roll;

                    strcpy(temp_name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, temp_name);

                    temp_percentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = temp_percentage;
                }
            }
        }

        printf("Records Sorted by Percentage Successfully!\n");
    }

    else
    {
        printf("Invalid Choice!\n");
    }
}

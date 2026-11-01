#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stud_add(student **head)
{
    student *newnode, *temp;
    int roll, found;
    
    newnode = malloc(sizeof(student));

    if(newnode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }


    roll = 1;

    while(1)
    {
        found = 0;
        temp = *head;

        while(temp != NULL)
        {
            if(temp->roll == roll)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }

        if(found == 0)
            break;

        roll++;
    }

    newnode->roll = roll;

    printf("Enter Student Name: ");
    scanf(" %29[^\n]", newnode->name);

    printf("Enter Percentage: ");

    if(scanf("%f", &newnode->percentage) != 1 ||
       newnode->percentage < 0 ||
       newnode->percentage > 100)
    {
        printf("Invalid Percentage!\n");
        free(newnode);
        return;
    }

    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("\nStudent Added Successfully!\n");
    printf("Assigned Roll Number: %d\n", newnode->roll);
}

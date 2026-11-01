#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"


/* Save all student records */

void stud_save(student *head)
{
    FILE *fp;
    student *temp = head;

    fp = fopen("student.dat", "wb");

    if(fp == NULL)
    {
        printf("File Opening Failed!\n");
        return;
    }

    while(temp != NULL)
    {
        fwrite(&temp->roll, sizeof(int), 1, fp);

        fwrite(temp->name, sizeof(temp->name), 1, fp);

        fwrite(&temp->percentage, sizeof(float), 1, fp);

        temp = temp->next;
    }

    fclose(fp);

    printf("All Records Saved Successfully!\n");
}


/* Load records when program starts */

void stud_load(student **head)
{
    FILE *fp;

    student *newnode, *temp;

    int roll;
    char name[30];
    float percentage;

    fp = fopen("student.dat", "rb");

    if(fp == NULL)
    {
        return;
    }

    while(fread(&roll, sizeof(int), 1, fp) == 1)
    {
        if(fread(name, sizeof(name), 1, fp) != 1)
            break;

        if(fread(&percentage, sizeof(float), 1, fp) != 1)
            break;

        newnode = malloc(sizeof(student));

        if(newnode == NULL)
        {
            printf("Memory Allocation Failed!\n");
            break;
        }

        newnode->roll = roll;

        memcpy(newnode->name, name, sizeof(name));

        newnode->name[29] = '\0';

        newnode->percentage = percentage;

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
    }

    fclose(fp);

    printf("Records Loaded Successfully!\n");
}


/* Free allocated memory */

void free_list(student **head)
{
    student *temp;

    while(*head != NULL)
    {
        temp = *head;

        *head = (*head)->next;

        free(temp);
    }
}

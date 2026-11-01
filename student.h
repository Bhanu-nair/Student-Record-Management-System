#ifndef STUDENT_H
#define STUDENT_H

typedef struct student
{
    int roll;
    char name[30];
    float percentage;
    struct student *next;
} student;

void stud_add(student **head);
void stud_del(student **head);
void stud_show(student *head);
void stud_sort(student *head);
void stud_mod(student *head);

void stud_save(student *head);
void stud_load(student **head);
void free_list(student **head);

#endif

















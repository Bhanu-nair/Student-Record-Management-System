#include <stdio.h>
#include "student.h"

int main()
{
    student *head = NULL;
    char choice, exit_choice;



    stud_load(&head);

    while(1)
    {
        printf("\n**** STUDENT RECORD MENU ****\n\n");

        printf("A/a : Add New Record\n");
        printf("D/d : Delete a Record\n");
        printf("S/s : Show the List\n");
        printf("M/m : Modify a Record\n");
        printf("V/v : Save\n");
        printf("T/t : Sort the List\n");
        printf("E/e : Exit\n");

        printf("\nEnter Your Choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case 'A':
            case 'a':
                stud_add(&head);
                break;

            case 'D':
            case 'd':
                stud_del(&head);
                break;

            case 'S':
            case 's':
                stud_show(head);
                break;

            case 'M':
            case 'm':
                stud_mod(head);
                break;

            case 'V':
            case 'v':
                stud_save(head);
                break;

            case 'T':
            case 't':
                stud_sort(head);
                break;

            case 'E':
            case 'e':

                printf("\nS/s : Save and Exit\n");
                printf("E/e : Exit Without Saving\n");

                printf("\nEnter Your Choice: ");
                scanf(" %c", &exit_choice);

                if(exit_choice == 'S' || exit_choice == 's')
                {
                    stud_save(head);
                    free_list(&head);

                    printf("Saved and Exited Successfully!\n");
                    return 0;
                }

                else if(exit_choice == 'E' || exit_choice == 'e')
                {
                    free_list(&head);

                    printf("Exited Without Saving!\n");
                    return 0;
                }

                else
                {
                    printf("Invalid Choice!\n");
                }

                break;

            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }

return 0;
}

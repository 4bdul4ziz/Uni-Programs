#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    struct node *head = NULL;
    int choice, data, item, pos;

    while (1)
    {
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Add to empty list / Add at beginning\n");
        printf("6.Add at end\n");
        printf("7.Add after node\n");
        printf("8.Add before node\n");
        printf("9.Add at position\n");
        printf("10.Delete\n");
        printf("11.Reverse\n");
        printf("12.Destroy list\n");
        printf("13.Quit\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_list(&head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            count(head);
            break;
        case 4:
            printf("Enter the element to be searched : ");
            scanf("%d", &data);
            search(head, data);
            break;
        case 5:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            addatbeg(&head, data);
            break;
        case 6:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            addatend(&head, data);
            break;
        case 7:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element after which to insert : ");
            scanf("%d", &item);
            addafter(&head, data, item);
            break;
        case 8:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element before which to insert : ");
            scanf("%d", &item);
            addbefore(&head, data, item);
            break;
        case 9:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the position at which to insert : ");
            scanf("%d", &pos);
            addatpos(&head, data, pos);
            break;
        case 10:
            printf("Enter the element to be deleted : ");
            scanf("%d", &data);
            del(&head, data);
            break;
        case 11:
            head = reverse(head);
            break;
        case 12:
            destroy_list(&head);
            break;
        case 13:
            exit(1);
        default:
            printf("Wrong choice\n");
        } /*End of switch */
    }     /*End of while */

    return 0;
} /*End of main()*/
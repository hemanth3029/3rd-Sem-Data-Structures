#include <stdio.h>
#define MAX 5

int queue[MAX];
int FRONT = -1, REAR = -1;

void insert()
{
    int ITEM;

    if (REAR == MAX - 1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        printf("Enter the element:");
        scanf("%d", &ITEM);

        if (FRONT == -1)
        {
            FRONT = 0;
        }

        REAR = REAR + 1;
        queue[REAR] = ITEM;

        printf("Element inserted successfully\n");
    }
}

void delete()
{
    int ITEM;

    if (FRONT == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        ITEM = queue[FRONT];
        printf("Deleted element%d\n", ITEM);

        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            FRONT = FRONT + 1;
        }
    }
}

void display()
{
    int i;

    if (FRONT == -1)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Queue elements are:\n");

        for (i = FRONT; i <= REAR; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("Queue operation:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

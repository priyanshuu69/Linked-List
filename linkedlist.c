#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct stack
{
    int info;
    struct stack *next;
} st;

void push(st **top)
{
    st *temp;
    int x;
    temp = (st *)malloc(sizeof(st));
    if (temp == NULL)
    {
        printf("overflow\n");
    }
    else if (*top == NULL)
    {
        printf("enter info\n");
        getchar();
        scanf("%d", &x);
        temp->info = x;
        *top = temp;
        temp->next = NULL;
    }
    else
    {
        printf("enter info\n");
        getchar();
        scanf("%d", &x);
        temp->info = x;
        temp->next = *top;
        *top = temp;
    }
}

void pop(st **top)
{
    if (*top == NULL)
    {
        printf("LL is empty");
    }
    else
    {
        st *p1;
        p1 = *top;
        *top = p1->next;
        free(p1);
    }
}

void traverse(st **top)
{
    st *p1;
    p1 = *top;
    if (*top == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        while (p1 != NULL)
        {
            printf("%d", p1->info);
            p1 = p1->next;
        }
    }
}

int main()
{
    st *top = NULL;
    int ch;
    do
    {
        printf("\n1.push\n");
        printf("2.pop\n");
        printf("3.traverse\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            traverse(&top);
            break;
        default:
            printf("invalid choice\n");
            exit(0);
        }
    } while (ch < 4);
}

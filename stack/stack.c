#include <stdio.h>
#include <stdlib.h>

struct stack_elem_t
{
    int value;
    struct stack_elem_t *next;
};

struct stack_elem_t *stack_p;

void push(int i_value, struct stack_elem_t **stack_p)
{
    struct stack_elem_t *new_elem = (struct stack_elem_t *) malloc(sizeof(struct stack_elem_t));
    new_elem->value = i_value; 
    new_elem->next = *stack_p;
    // *stack_p = &new_elem;
    // greshka    ^   - tova e adresa na new_elem, a nie iskame da vzemem kadeto sochi new_elem
    // tova otdolu e pravilnoto
    *stack_p = new_elem;
}

int pop(struct stack_elem_t **stack_p)
{
    int result = 0;
    if(stack_p != 0 && *stack_p != 0)
    {
        result = (*stack_p)->value;
        struct stack_elem_t *tmp = *stack_p;
        *stack_p = (*stack_p)->next;
        free(tmp);    
    }

    return result;
}

void print_stack(struct stack_elem_t *stack_p)
{
    printf("\n - - - = = = STACK = = = - - -\n");
    struct stack_elem_t *tmp = stack_p;
    while (tmp!=NULL)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
    printf(" - - - = = = ^ ^^ ^ = = = - - -\n");
}

int main()
{
    stack_p = NULL;
    push(1,&stack_p);
    push(2,&stack_p);
    push(3,&stack_p);
    print_stack(stack_p);
    printf("\npop: %d\n", pop(&stack_p));
    push(4,&stack_p);
    push(5,&stack_p);
    print_stack(stack_p);
    printf("\npop: %d\n", pop(&stack_p));
    print_stack(stack_p); 
    return 0;
}

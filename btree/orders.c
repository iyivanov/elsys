#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum order {
    
}

struct queue_t
{
    int value;
    struct node_t* head;
    struct node_t* tail;
};

// order = M,L,X
// type = C,P,H
typedef struct node_t
{
    struct node_t* next;
    struct node_t* prev;
    char name[41];
    char order;
    char type;
} *node_p;

void insert_element(struct node_t* *list, struct node_t* value, int index)
{
    if(list!=NULL)
    {
        if(*list!=NULL)
        {
           
            if(index == 0)
            {
                value->next = *list;
                (*list)->prev = value;
                *list = value;
            }
            else
            {
                struct node_t* current = *list;
                int current_index = 0;
                while(current->next != NULL && current_index < index)
                {
                    current = current->next;
                    current_index++;
                }
                if(current_index < index)
                {
                    current->next = value;
                    value->prev = current;
                }
                else
                {
                    current->next->prev = value;
                    value->next = current->next;
                    current->next = value;
                    value->prev = current;      
                }
            }
           

        }
        else
        {
            *list = value;
        }
       
    }
}

void print_list(struct queue_t* list)
{
    if (list!=NULL)
    {
        printf("start ================ \n");
        struct node_t* current = list->head;
        while (current != NULL)
        {
            printf("value = %s\n", current->name);
            current = current->next;
           
        }
        printf("end------------------------\n");
       
    }
   
}

node_p new_person(char* name, char order, char type)
{
    node_p current = (node_p)malloc(sizeof(struct node_t));
    strcpy(current->name, name);
    current->order = order;
    current->type = type;
    current->prev = current->next = NULL;
   
    return current;
}

void remove_person(struct queue_t* queue)
{
    node_p current = queue->head;
    while(current != NULL)
    {
        if(current->type == 'H')
        {
            if(queue->head == current)
            {
                queue->head = current->next;
                if(queue->tail == current)
                {
                    queue->tail = current->next;
                }
                current->next->prev = NULL;
            }
            else if (queue->tail == current)
            {
                queue->tail = current->prev;
                current->prev->next = NULL;
            }
            else
            {
                if(current->prev != NULL)
                {
                    current->prev->next = current->next;
                }
                current->next->prev = current->prev;
            }
            queue->value--;
            current = current->next;
        }
        else
        {
            current = current->next;
        }
       
    }
}

int find_by_order(struct queue_t* queue, char order)
{
    int index = 0;
    node_p current = queue->head;
    while (current != NULL)
    {
        if(current->type == 'H')
        {
            if(current->order == 'M' && (order == 'L' || order == 'X'))
            {
                break;
            }
            if(current->order == 'L' && (order == 'X'))
            {
                break;
            }
        }
        if (current->type == 'C')
        {
         
            break;
        }
       
        current = current->next;
    }
   
    return index;
}

void add_person(node_p person, struct queue_t* queue)
{
    int index = 0;
    switch (person->type)
    {
    case 'P':
        remove_person(queue);
        insert_element(&queue->head, person, queue->value);
        break;
    case 'C':
        insert_element(&queue->head, person, queue->value);    
        break;
    case 'H':
        index = find_by_order(queue, person->order);
        insert_element(&queue->head, person, index);
        break;
    default:
        break;
    }
}

int main()
{

    struct queue_t queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.value = 0;
    add_person(new_person("Gosho", 'L', 'C'), &queue);
    print_list(&queue);
    add_person(new_person("Robin", 'M', 'H'), &queue);
    print_list(&queue);
    add_person(new_person("Ivan", 'L', 'H'), &queue);
    print_list(&queue);
    add_person(new_person("Bobi", 'M', 'P'), &queue);
    print_list(&queue);
   
    return 0;
}
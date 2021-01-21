// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Domashna rabota Nr 1.
// Avtor: Yordan Hristov (10a klas Nr 16)
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// definition for true/false type
typedef 
enum boolean_e 
{
    false = 0, true = 1
} boolean;

//izbroqvame stoinostite koito poleto theme ot structurata puzzle_t moje da priema 
typedef 
enum theme_e
{
    animals = 0, animations, cars, cities, games, history, landscapes, movies, space, sports
} theme_t;

// imena za stoinostite na temite
char* theme_names[] = {"animals", "animations", "cars", "cities", "games", "history", "landscapes", "movies", "space", "sports" };

// ukazatel kum structurata puzzle_t
typedef struct puzzle_t* puzzle_p;

// struktura za puzel - ima poleta tema, zaglavie i broi  chasti.
struct puzzle_t
{
    theme_t theme;
    char* title;
    unsigned int parts_count;
    puzzle_p next;
};

// definition of the linked list with puzzles
typedef
struct __puzzle_list_t
{
    puzzle_p head;
    unsigned int size;
} puzzle_list_t;
// pointer to structure puzzle_list_t
typedef puzzle_list_t* puzzle_list_p;

// generates a random number between = [0, 10)
int random10()
{
    return rand() % 10;
}

// reads a line of text
char* read_line(char** line) 
{
    if (line == NULL)
    {
        return NULL;
    }

    char ch = getchar();
    char sentence[1024] = { 0 };
    scanf( "%1023[^\n]%c", sentence, &ch );

    *line = (char*) malloc(sizeof(char) * strlen(sentence));
    strcpy(*line, sentence);
    return *line;
}

// suzdava puzel samo i edinstveno s tema.
// poleto theme priema stoinost samo ot enum theme_e
puzzle_p create()
{
    puzzle_p result;
    result = (puzzle_p) malloc(sizeof(struct puzzle_t));
    result->parts_count = 0;
    result->title = NULL;
    result->theme = random10();
    return result; 
}

// adds a puzzle to the list
// returns 'true' if puzzle is a unique in the list; otherwise 'false'
boolean add_puzzle(puzzle_list_p list, puzzle_p puzzle, boolean unique)
{
    // check that the new puzzle to be added is valid
    if (puzzle == NULL)
    {
        return false;
    }

    boolean result = true;

    // point to the head of the list
    puzzle_p tmp_puzzle = list->head;
    // walk through the puzzles in the list and ...
    for (; tmp_puzzle != NULL; tmp_puzzle = tmp_puzzle->next)
    {
        // ... if there is a duplicate ...
        if (tmp_puzzle->theme == puzzle->theme) 
        {
            // ... then we do not want to add the new puzzle to the list
            result = false;
        }
    }

    if ((! result) && unique)
    {
        // the new puzzle is a duplicate of another one in the list, but it has to be unique
        return false;
    }

    // we can add the new puzzle to the end of the list
    if (list->head == NULL)
    {
        // list is empty, so just add the puzzle
        list->head = puzzle;
    }
    else
    {
        // find the last puzzle in the list
        tmp_puzzle = list->head;
        while (tmp_puzzle->next != NULL)
        {
            tmp_puzzle = tmp_puzzle->next;
        }
        tmp_puzzle->next = puzzle;
    }
    // mark the end of the list
    puzzle->next = NULL;
    // increase the size of the list
    list->size++;

    return result;
}

// fills the list with only 1 duplicated puzzle or max 10 puzzles
void fill_with_duplicate_or_max_ten(puzzle_list_p list)
{
    if (list != NULL)
    {
        while (list->size < 10)
        {
            puzzle_p tmp_puzzle = create();
            if (! add_puzzle(list, tmp_puzzle, false))
            {
                break;
            }
        }
    }
} 

// fills the list with only 1 duplicated puzzle or max 10 puzzles
void fill_with_unique_max_ten(puzzle_list_p list)
{
    if (list != NULL)
    {
        while (list->size < 10)
        {
            puzzle_p tmp_puzzle = create();
            if (! add_puzzle(list, tmp_puzzle, true))
            {
                free(tmp_puzzle);
            }
        }
    }
} 

// fills in the data of the given puzzle
void fill_puzzle_params(puzzle_p puzzle)
{
    if (puzzle != NULL)
    {
        printf("theme is '%s'\n", theme_names[puzzle->theme]);
        printf("enter parts count: ");
        scanf("%u", &(puzzle->parts_count));
        printf("enter title: ");
        read_line(&(puzzle->title));
    }
}

// sort the given list with puzzles by the themes
// using bubble sort
void sort_list(puzzle_list_p list)
{
    // if the list is not NULL and there are more than 1 puzzles in the list
    // then it makes sense to sort it
    if (list != NULL && list->size > 1)
    {
        // copy the list into an array for easier manipulation
        puzzle_p tmp_array[list->size];
        puzzle_p tmp_elem = list->head;
        for (unsigned int i = 0; i < list->size; i++)
        {
            tmp_array[i] = tmp_elem;
            tmp_elem = tmp_elem->next;
        }

        // sort the array using bubble sort
        for (unsigned int k = list->size; k > 0; k--)
        {
            for (unsigned int i = 0; i < k - 1; i++)
            {
                if (tmp_array[i]->theme > tmp_array[i + 1]->theme)
                {
                    tmp_elem = tmp_array[i];
                    tmp_array[i] = tmp_array[i + 1];
                    tmp_array[i + 1] = tmp_elem;
                }
            }
        }

        // link the elements according to the new order
        for (unsigned int i = 0; i < list->size - 1; i++)
        {
            tmp_array[i]->next = tmp_array[i + 1];
        }
        // point the list to the new head
        list->head = tmp_array[0];
        // mark the end of the new tail
        tmp_array[list->size - 1]->next = NULL;
    }
}

// print puzzles data
// the list is modified if sorted is 'true'
void show_puzzles(puzzle_list_p list, boolean sorted)
{
    if (sorted)
    {
        sort_list(list);
    }

    printf("\n=======================\n");
    puzzle_p tmp_puzzle = list->head;
    while (tmp_puzzle != NULL)
    {
        printf("%d %s %s \n", tmp_puzzle->parts_count, theme_names[tmp_puzzle->theme], tmp_puzzle->title);
        tmp_puzzle = tmp_puzzle->next;
    }
    printf("\n=^=^=^=^=^=^=^=^=^=^=^=\n");
}

// frees the memory occupied by the puzzles in the list
void clear_list(puzzle_list_p list)
{
    if (list != NULL)
    {
        puzzle_p tmp = list->head;
        while (tmp != NULL)
        {
            puzzle_p del = tmp;
            tmp = tmp->next;
            free(del->title);
            free(del);
        }
        list->head = NULL;
        list->size = 0;
    }
}

// this is the list with puzzles
puzzle_list_t list_with_puzzles;

// Vhodna tochka
int main()
{
    // initialise the seed for random numbers
    srand((unsigned int) time(0));

    // initialise the list with puzzles
    list_with_puzzles.head = NULL;
    list_with_puzzles.size = 0;

    // fill in the list with puzzles until its size is 10 or a theme is duplicated
    fill_with_duplicate_or_max_ten(&list_with_puzzles);
    
    // BONUS
    // fill the list with 10 unique puzzles
    // fill_with_unique_max_ten(&list_with_puzzles);

    // fill in the details of each puzzle
    printf("list has %u puzzles\n", list_with_puzzles.size);
    puzzle_p tmp_puzzle = list_with_puzzles.head;
    while (tmp_puzzle != NULL)
    {
        fill_puzzle_params(tmp_puzzle);
        tmp_puzzle = tmp_puzzle->next;
    }
    printf("<<<\n");
    
    // show the puzzles
    show_puzzles(&list_with_puzzles, false);
    // BONUS
    show_puzzles(&list_with_puzzles, true);
    
    // done
    clear_list(&list_with_puzzles);

    return 0;
}
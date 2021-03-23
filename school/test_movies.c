#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// structure for movies
typedef 
struct movie_t {
    char title[101];
    char director[21];
    int duration;
} * movie_p;

// dynamic array that contains the entered movies
struct movie_t movies[100];
// number of movies in the array
int movies_count;

// function to enter the information of a movie
void enter_movie(struct movie_t * movies) 
{

    char ch = 0;

    char title[101];
    char director[21];
    int duration = 0;

    printf("enter title: \n");
    scanf("%100[^\n]%c", title, &ch);

    printf("enter director: \n");
    scanf("%20[^\n]%c", director, &ch);

    printf("enter duration: \n");
    scanf("%d", &duration);

    // read the last enter key
    ch = getchar();

    strcpy((movies)->title, title);
    strcpy((movies)->director, director);
    (movies)->duration = duration;
}

struct movie_t* find_movie(struct movie_t* movies, char* to_find)
{
    movie_p result = movies;

    int i = 0;
    for (; i < movies_count; i++)
    {
        if (strstr(result->title, to_find) != NULL)
        {
            break;
        }
        result++;
    }

    if (i == movies_count) 
    {
        return NULL;
    }

    return result;
}

void print_movie(movie_p movie)
{
    printf("=== +++ ===\n");
    printf("title: %s\n", movie->title);
    printf("director: %s\n", movie->director);
    printf("duration: %d\n", movie->duration);
    printf("=== ^ ^ ===\n");
}

// MAIN ENTRY point
int main(int argc, char const *argv[])
{
    movies_count = 3;
    for (int i = 0; i < movies_count; i++) 
    {
        enter_movie(&movies[i]);
        print_movie(&movies[i]);
    }

    movie_p found_movie = find_movie(movies, "bryan");
    if (found_movie != NULL)
    {
        printf("we found movie\n");
        print_movie(found_movie);
    }
    else
    {
        printf("we did not find movie\n");
    }
    
    return 0;
}

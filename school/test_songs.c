#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// structure for movies
typedef 
struct song_t {
    char title[101];
    char singer[31];
    int duration;
} * song_p;

// dynamic array that contains the entered songs
struct song_t songs[100];
// number of songs in the array
int songs_count;

// function to enter the information of a song
void enter_song(struct song_t * songs) 
{

    char ch = 0;

    char title[101];
    char singer[31];
    int duration = 0;

    printf("enter title: \n");
    scanf("%100[^\n]%c", title, &ch);

    printf("enter singer: \n");
    scanf("%30[^\n]%c", singer, &ch);

    printf("enter duration: \n");
    scanf("%d", &duration);

    // read the last enter key
    ch = getchar();

    strcpy((songs)->title, title);
    strcpy((songs)->singer, singer);
    (songs)->duration = duration;
}

struct song_t* find_song_by_title(struct song_t* songs, char* to_find)
{
    song_p result = songs;

    int i = 0;
    for (; i < songs_count; i++)
    {
        if (strstr(result->title, to_find) != NULL)
        {
            break;
        }
        result++;
    }

    if (i == songs_count) 
    {
        return NULL;
    }

    return result;
}

struct song_t* find_song_by_author(struct song_t* songs, char* author)
{
    song_p result = songs;

    int i = 0;
    for (; i < songs_count; i++)
    {
        if (strstr(result->singer, author) != NULL)
        {
            break;
        }
        result++;
    }

    if (i == songs_count) 
    {
        return NULL;
    }

    return result;
}

void print_song(song_p song)
{
    printf("=== +++ ===\n");
    printf("title: %s\n", song->title);
    printf("singer: %s\n", song->singer);
    printf("duration: %d\n", song->duration);
    printf("=== ^ ^ ===\n");
}

// MAIN ENTRY point
int main(int argc, char const *argv[])
{
    songs_count = 3;
    for (int i = 0; i < songs_count; i++) 
    {
        enter_song(&songs[i]);
        print_song(&songs[i]);
    }

    song_p found_song = find_song_by_title(songs, "desire");
    if (found_song != NULL)
    {
        printf("we found song\n");
        print_song(found_song);
    }
    else
    {
        printf("we did not find song\n");
    }

    found_song = find_song_by_author(songs, "jovi");
    if (found_song != NULL)
    {
        printf("we found singer\n");
        print_song(found_song);
    }
    else
    {
        printf("we did not find singer\n");
    }
    
    return 0;
}

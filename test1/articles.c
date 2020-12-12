// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Programme that works with newspaper articles in C language
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines an article with title of 50 characters, author of 20 characters and text of 200 characters max.
typedef
struct article_s
{
    char title[51];
    char author[21];
    char text[201];
} article_t;
typedef article_t* article_p;

// number of articles that the user enters
int count = 0;

// Calculates the length of the given string
int str_len(const char *str)
{
    int len = 0;
    if (str != NULL) {
        for (const char *c = str; *c != 0; c++)
        {
            len++;
        }
    }
    return len;
}

// reads a line from the stdin that contains maximum maxlen characters
// if the line is longer than maxlen then an error message is shown and user is prompter again
char * read_line(const char * prompt, const unsigned int maxlen, char *line) 
{
    char * buffer;
    size_t size;
    ssize_t readchars = 0;
    do {
        buffer = NULL;
        size = 0;
        puts(prompt);
        readchars = getline(&buffer, &size, stdin);
        if (readchars > maxlen)
        {
            printf("ERROR! You entered %ld characters, max %u characters are allowed. Try again\n", readchars, maxlen);
            free(buffer);
        }
    } while (readchars > maxlen);
    // copy the end-of-line '\0' character, too
    memcpy(line, buffer, readchars + 1); 
    return line;
}

// asks the user to enter the articles
article_p enter_article()
{
    article_p result = NULL;

    puts("\nhow many articles?");
    scanf("%d", &count);
    getc(stdin);

    result = (article_p) malloc(count * sizeof(article_t));
    printf("\nenter the details for %d articles:\n", count);

    for (int i = 0; i < count; i++)
    {
        printf("\nenter details for article %d\n", i);
        read_line("\ntitle:", 50, result[i].title);
        read_line("\nauthor:", 20, result[i].author);
        read_line("\ntext:", 200, result[i].text);
    }

    return result;
}



// MAIN ENTRY POINT
int main()
{

    // reference to the articles
    article_p articles = enter_article();

    printf("\nYou entered %d articles.\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("\narticle %d :", i);
        printf("\ntitle: %s", articles[i].title);
        printf("\nauthor: %s", articles[i].author);
        printf("\ntext: %s\n", articles[i].text);
    }

    free(articles);

    return 0;
}
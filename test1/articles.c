// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Programme that works with newspaper articles in C language
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Define a structure with the following members:
// - title - string that can contain up to 50 characfters,
// - author - string that can contain up to 20 characfters,
// - text - string that can contain up to 200 characfters.
// Implement a fuction called enter_article that:
// - reads an interger from the user,
// - creates a dynamic array with size the integer that was read
//   from the user at the previous step,
// - reads the values of the articles and stores them in the attay,
// - returns the array with articles as a result.
//
// Define a function called find_longest, which receives as a parameter
// an array with articles and returns as a result the article with
// the longest text; if 2 articles have tekst with the same length
// then the one with longest title is returned.
// Use the two functions in the main function.
//
// struct article_t* enter_article();
// struct article_t find_longest(struct article_t *articles, int length);
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines an article with title of 50 characters, author of 20 characters and text of 200 characters max.
typedef
struct article_t
{
    char title[51];
    char author[21];
    char text[201];
} article_tt;
typedef article_tt* article_p;

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

    result = (article_p) malloc(count * sizeof(article_tt));
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

article_tt find_longest(article_p articles, int length)
{
    // empty article
    article_tt result = { { 0 }, { 0 }, { 0 } };

    if (articles != NULL && length > 0) 
    {
        int max_article = 0;
        int max_len_text = str_len(articles[max_article].text);
        int max_len_title = str_len(articles[max_article].title);

        for (int i = 1; i < length; i++)
        {
            int curr_len = str_len(articles[i].text);
            if (curr_len > max_len_text 
                || (curr_len == max_len_text && str_len(articles[i].title) > max_len_title))
            {
                max_article = i;
                max_len_text = str_len(articles[max_article].text);
                max_len_title = str_len(articles[max_article].title);
            }
        }

        // copy the article in the result variable
        memcpy(result.title, articles[max_article].title, str_len(articles[max_article].title) + 1);
        memcpy(result.author, articles[max_article].author, str_len(articles[max_article].author) + 1);
        memcpy(result.text, articles[max_article].text, str_len(articles[max_article].text) + 1);
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

    article_tt article = find_longest(articles, count);
    printf("\nlongest article is:\n");
    printf("\ntitle: %s", article.title);
    printf("\nauthor: %s", article.author);
    printf("\ntext: %s\n", article.text);

    free(articles);

    return 0;
}
#include <stdio.h>
#include "database.h"

/*
 *  read_int()
 *
 *  Ask the user a question and prompt for an integer answer
 */
int read_int(char prompt[])
{
    int     answer;

    fputs(prompt, stdout);
    fflush(stdin);
    scanf("%d", &answer);

    return answer;
}

/*
 *  read_float()
 *
 *  Ask the user a question and prompt for a float answer
 */
float read_float(char prompt[])
{
    float     answer;

    fputs(prompt, stdout);
    fflush(stdin);
    scanf("%f", &answer);

    return answer;
}

/*
 *  read_string()
 *
 *  Ask the user a question and prompt for a string answer
 *  MAX = size of "answer" including NULL terminating character
 *  Note: The answer parameter is MODIFIED by the function
 */
read_string(char prompt[], char answer[], int MAX)
{
    fputs(prompt, stdout);
    fflush(stdin);
    fgets(answer, MAX, stdin);

    trim_newline(answer);
}

/*
 *  read_cd()
 *
 *  Read the details of one CD
 */
 cd_t read_cd()
 {
     cd_t   cd;

#ifndef NOARTIST
    read_string("Artist? ", cd.artist, sizeof cd.artist);
#endif
    read_string("Title? ", cd.title, sizeof cd.title);
    cd.tracks = read_int("Number of tracks? ");
    cd.album = yesno("Is the CD an Album");
    cd.price = read_float("Retail price (e.g. 4.65)? ");

    return cd;
}

/*
 *  yesno()
 *
 *  Ask the user a question and prompt for a Y or N (or y or n) answer
 *  No other answer will be acceptable
 *  If y/Y is given the function returns 1. n/N gives 0
 */
int yesno(char prompt[])    // Prompt should not include a question mark
{
    char    answer;

    // Loop until correct answer is given
    for(;;)
    {
        fputs(prompt, stdout);          // Display the question
        fputs(" (Y/N)? ", stdout);      // Add a helpful prompt
        fflush(stdin);
        scanf("%c", &answer);

        // Process the answer
        answer = toupper(answer);       // Convert to uppercase
        if (answer == 'Y')
            return 1;
        if (answer == 'N')
            return 0;

        printf("Error - Only 'y/Y' or 'n/N' are allowed\n");
    }
}

/*
 *  enter()
 *
 *  Give the user a piece of information and ask them to press ENTER
 */
enter(char prompt[])
{
    fputs(prompt, stdout);
    fflush(stdin);
    getchar();
}

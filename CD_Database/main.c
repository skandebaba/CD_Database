/*
 *  Program to maintain a database of CDs for a record store.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "database.h"

/*
 *  trim_newline()
 *
 *  Remove the newline character from a string (if there is one)
 *  It is assumed that if there is a new line character on the string,
 *  it will be the last character in the string (except for the null)
 */
trim_newline(char string[])
 {
     if(string[strlen(string)-1] = '\n')
        string[strlen(string)-1] = '\0';
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
 *  print_cd()
 *
 *  Display (using printf) the details of one CD
 */
print_cd(cd_t cd)
{
    puts("=========================================");
#ifndef NOARTIST
    printf("Artist: %s\n", cd.artist);
#endif
    printf("Title: %s\n", cd.title);
    printf("Number of tracks: %d\n", cd.tracks);
    puts(cd.album == 1 ? ("Album") : ("Single"));       // album[i] == 1 ? puts("Album") : puts("Single");
    printf("Price: %.2f\n", cd.price);
    puts("=========================================");
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

int main()
{
    cd_t    cds[MAX_CDS];        // Create an array of CD stuctures
    int     count = 0;          // How many CDs are being tracked
    int     i;                  // Loop counter

    puts("Welcome to the CD database");
    printf("You can store a maximum of %d CDs\n\n", sizeof cds / sizeof cds[0]);

    // Loop until user no longer wish to enter any more CDs
    for (;;)
    {
        // Ask the user if they want to enter another CD
        if (!yesno("\nDo you have any more CDs to enter"))
            break;

        printf("Please enter the details of CD %d...\n", count+1);

        // Read all the CD details
        cds[count] = read_cd();

        // Check if array has been filled up
        if (++count == MAX_CDS) // Note increment happens before the test
        {
            enter("You have reached the limits of this program\n"
                  "Press ENTER to exit the program");
            break;
        }
    }

    // Output the details of the CD
    for (i = 0; i < count; i++)
    {
        printf("\nThe details of CD %d are:\n", i+1);
        print_cd(cds[i]);

        // Only do this if there are more CDs to see
        if (i < count - 1)
        {
            // User-friendly way to progress to the next CD
            enter("\nPress ENTER to see the next set of details: ");
        }
    }

    // User-friendly way to exit the program
    enter("\nPress ENTER to exit the program ");
}

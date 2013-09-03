/*
 *  Program to maintain a database of CDs for a record store.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char    artist[100][61];         // Store the artist of the CD
    char    title[100][61];          // Store the title of the CD
    int     tracks[100];             // Store number of tracks on CD
    char    type;                    // Used as a boolean
    int     album[100];              // boolean - album or single?
    float   price[100];              // Store the price of the CD
    int     count = 0;               // How many CDs are being tracked
    int     i;                       // Loop counter

    puts("Welcome to the CD database");
    printf("You can store a maximum of %d CDs", sizeof album/sizeof album[0]);

    // Loop until user no longer wish to enter any more CDs

    for (;;)
    {
        // Ask the user if they want to enter another CD
        // Any answer other than y or Y will be treated as a NO
        fputs("\nDo you have any more CDs to enter (y/n)? ", stdout);
        fflush(stdin);
        scanf("%c", &type);

        if (toupper(type) != 'Y')
            break;

        puts("");       // newline - for neat output

        // Prompt user to enter ARTIST of the CD
        printf("Please enter the details of CD %d...\n", count+1);
        fputs("Artist? ", stdout);
        fflush(stdin);
        fgets(artist[count], sizeof artist[count], stdin);
        artist[count][strlen(artist[count])-1] = '\0';  // Remove newline

        // Prompt user to enter TITLE of the CD
        fputs("Title? ", stdout);
        fflush(stdin);
        fgets(title[count], sizeof title[count], stdin);
        title[count][strlen(title[count])-1] = '\0';    // Remove newline

        // Number of tracks on the CD
        fputs("Tracks? ", stdout);
        fflush(stdin);
        scanf("%d", &tracks[count]);

        // Album or a single?
        for (;;)
        {
            fputs("Album or single (a for album, s for single)? ", stdout);
            fflush(stdin);
            scanf("%c", &type);
            type = toupper(type);

            if (type == 'A' || type == 'S')
                break;
            puts("Error - only 'a' or 's' are allowed");
        }
        album[count] = type == 'A';    // If we get here it must be 'a' or 's'

        // Price of the CD
        fputs("Price? ", stdout);
        fflush(stdin);
        scanf("%f", &price[count]);

        // Check if array has been filled up
        if (++count == 100)
        {
            puts("You have reached the limits of this program\n");
            break;
        }
    }

    for (i = 0; i < count; i++)
    {
        // Output the details of the CD
        printf("\nThe details you have entered for CD %d are:\n", i+1);
        puts("=========================================");
        printf("Artist: %s\n", artist[i]);
        printf("Title: %s\n", title[i]);
        printf("Number of tracks: %d\n", tracks[i]);
        puts(album[i] == 1 ? ("Album") : ("Single"));       // album[i] == 1 ? puts("Album") : puts("Single");
        printf("Price: %.2f\n", price[i]);
        puts("=========================================");

        if (i < count - 1)  // Only do this if there are more CDs to see
        {
            // User-friendly way to progress to the next CD
            puts("");
            fputs("\nPress ENTER to see the next set of details: ", stdout);
            fflush(stdin);
            getchar();
        }
    }

    // User-friendly way to exit the program
    fputs("\nPress ENTER to exit the program ", stdout);
    fflush(stdin);
    getchar();
}

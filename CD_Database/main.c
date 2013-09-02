/*
 *  Program to maintain a database of CDs for a record store.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char    artist[100][61];         // Store the artist of the CD
    char    title[100][61];          // Store the title of the CD
    int     tracks[100];             // Store number of tracks on CD
    char    type;                    // Used to read in album/single info
    int     album[100];              // boolean - album or single?
    float   price[100];              // Store the price of the CD
    int     count = 0;               // How many CDs are being tracked
    int     i;                       // Loop counter

    printf("Welcome to the CD database\n");
    printf("You can store a maximum of 100 CDs\n");

    // Loop until user no longer wish to enter any more CDs

    for (;;)
    {
        // Ask the user if they want to enter another CD
        // Any answer other than y or Y will be treated as a NO
        printf("\nDo you have any more CDs to enter (y/n)? ");
        fflush(stdin);
        scanf("%c", &type);
        if (type != 'y' && type != 'Y')
            break;

        printf("\n");       // Neat output


        // Prompt user to enter ARTIST of the CD
        printf("Please enter the details of CD %d...\n\n", count+1);
        printf("Artist? ");
        fflush(stdin);
        scanf("%[^\n]", artist[count]);

        // Prompt user to enter TITLE of the CD
        printf("Title? ");
        fflush(stdin);
        scanf("%[^\n]", title[count]);

        // Number of tracks on the CD
        printf("Tracks? ");
        fflush(stdin);
        scanf("%d", &tracks[count]);

        // Album or a single?
        for (;;)
        {
            printf("Album or single (a for album, s for single)? ");
            fflush(stdin);
            scanf("%c", &type);
            if (type == 'a' || type == 's')
                break;
            printf("Error - only 'a' or 's' are allowed\n");
        }
        album[count] = type == 'a';    // If we get here it must be 'a' or 's'

        // Price of the CD
        printf("Price? ");
        fflush(stdin);
        scanf("%f", &price[count]);

        count = count + 1;

        // Check if array has been filled up
        if (count == 100)
        {
            printf("You have reached the limits of this program\n\n");
            break;
        }
    }

    for (i = 0; i < count; i = i + 1)
    {
        // Output the details of the CD
        printf("\nThe details you have entered for CD %d are:\n", i+1);
        printf("=========================================\n");
        printf("Artist: %s\n", artist[i]);
        printf("Title: %s\n", title[i]);
        printf("Number of tracks: %d\n", tracks[i]);
        if (album[i])
            printf("Album\n");
        else
            printf("Single\n");
        printf("Price: %.2f\n", price[i]);
        printf("=========================================\n");

        if (i < count - 1)  // Only do this if there are more CDs to see
        {
            // User-friendly way to progress to the next CD
            printf("\nPress ENTER to see the next set of details: ");
            fflush(stdin);
            getchar();
        }
    }

    // User-friendly way to exit the program
    printf("\nPress ENTER to exit the program ");
    fflush(stdin);
    getchar();
}

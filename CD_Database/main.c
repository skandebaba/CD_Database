/*
 *  Program to maintain a database of CDs for a record store.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char    artist[61];         // Store the artist of the CD
    char    title[61];          // Store the title of the CD
    int     tracks;             // Store number of tracks on CD
    char    type;               // Used to read in album/single info
    int     album;              // boolean - album or single?
    float   price;              // Store the price of the CD

    printf("Welcome to the CD database\n\n");

    // Prompt user to enter ARTIST of the CD
    printf("Please enter the details of the CD...\n");
    printf("Artist? ");
    scanf("%[^\n]", artist);

    // Prompt user to enter TITLE of the CD
    printf("Title? ");
    fflush(stdin);
    scanf("%[^\n]", title);

    // Number of tracks on the CD
    printf("Tracks? ");
    fflush(stdin);
    scanf("%d", &tracks);

    // Album or a single?
    printf("Album or single (a for album, s for single)? ");
    fflush(stdin);
    scanf("%c", &type);
    album = type == 'a';    // If user didn't type 'a' or 's' it assumes 's'

    // Price of the CD
    printf("Price? ");
    fflush(stdin);
    scanf("%f", &price);

    // Output the details of the CD
    printf("\nThe CD details you have entered are:\n");
    printf("=========================================\n");
    printf("Artist: %s\n", artist);
    printf("Title: %s\n", title);
    printf("Number of tracks: %d\n", tracks);
    if (album)
        printf("Album\n");
    else
        printf("Single\n");
    printf("Price: %.2f\n", price);
    printf("=========================================\n");

    // User-friendly exit of the program
    printf("\nPress ENTER to exit the program...");

    fflush(stdin);
    getchar();
}

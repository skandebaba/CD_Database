/*
 *  Program to maintain a database of CDs for a record store.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "database.h"

static  cd_t    cds[MAX_CDS];   // Create an array of CD stuctures

int main()
{
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
        read_cd(&cds[count]);

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
        print_cd(&cds[i]);

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

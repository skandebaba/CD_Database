#include <stdio.h>
#include "database.h"

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

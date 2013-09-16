/*
 *  database.h
 *
 *  Header file for use with main.c
 *
 */

#define     MAX_CDS          100
#define     ARTIST_SIZE      60     // This is not including the null character
#define     TITLE_SIZE       60     // This is not including the null character
// #define     NOARTIST                // Comment out if you want no artist


// ==============================================================================
// STRUCTURES
// ==============================================================================

struct cd_type
{
#ifndef NOARTIST
    char    artist[ARTIST_SIZE+1];         // Store the artist of the CD
#endif
    char    title[TITLE_SIZE+1];           // Store the title of the CD
    int     tracks;                        // Store number of tracks on CD
    int     album;                         // boolean - album or single?
    float   price;                         // Store the price of the CD
};

typedef struct cd_type  cd_t;

// ==============================================================================
// FUNCTION PROTOTYPES
// ==============================================================================

int trim_newline(char string[]);
int enter(char prompt[]);
int yesno(char prompt[]);    // Prompt should not include a question mark
int read_int(char prompt[]);
float read_float(char prompt[]);
int read_string(char prompt[], char answer[], int MAX);
int print_cd(cd_t cd);
 cd_t read_cd();

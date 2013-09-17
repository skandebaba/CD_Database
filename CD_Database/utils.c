#include "database.h"
#include <stdio.h>

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

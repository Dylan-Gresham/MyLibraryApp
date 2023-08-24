//
// Created by Dylan Gresham on 08/22/2023
//

#ifndef INC_MYLIBRARYAPP_BOOK_H
#define INC_MYLIBRARYAPP_BOOK_H

#include <stdbool.h>
typedef struct Book {
    char * title;
    char * author;
    int * numPages;
    int * rating;
    int * status;
} Book;

/**
 * Creates a new Book struct containing the specified information.
 * 
 * @param title - A C-string representing the title of the book.
 * @param author - A C-string representing the author of the book.
 * @param numPages - An int representing the number of pages in the book.
 * @param rating - An int representing the rating of the book (-1 [negative one] if you don't want to give a rating yet).
 * @param status - An int representing your reading status of the book. 0 = planned, 1 = reading, 2 = dropped, 3 = aside, 4 = completed 
 * 
 * @return A pointer to the newly created Book struct, NULL on error.
*/
Book * CreateBook(char title[], char author[], int numPages, int rating, int status);

/**
 * Destroys the specified Book struct, free'ing all used memory in the process.
 * 
 * @param book A pointer to the Book struct to destroy.
 * 
 * @return 0 on success, nonzero on error, -1 if the parameter was invalid
*/
int DestroyBook(Book * book);

/**
 * Gets the title of the specified Book.
 * 
 * @param book - A pointer to the Book struct to get the title from.
 * 
 * @return The title of the book or NULL on an error.
*/
char * GetTitle(Book * book);

/**
 * Gets the author of the specified Book.
 * 
 * @param book - A pointer to the Book struct to get the author from.
 * 
 * @return The author of the book or NULL on an error.
*/
char * GetAuthor(Book * book);

/**
 * Gets the total number of pages of the specified Book.
 * 
 * @param book - A pointer to the Book struct to get the number of pages from.
 * 
 * @return The total number of pages of the book, -1 if the parameters are invalid, -2 if malloc fails
*/
int GetNumPages(Book * book);

/**
 * Gets the rating of the specified Book.
 * 
 * @param book - A pointer to the Book struct to get the rating from.
 * 
 * @return The total number of pages of the book, -1 if the parameters are invalid, -2 if malloc fails
*/
int GetRating(Book * book);

/**
 * Gets the current reading status of the Book.
 * 
 * @param book - A pointer to the Book struct to get the reading status from.
 * 
 * @return The total number of pages of the book, -1 if the parameters are invalid, -2 if malloc fails
*/
int GetReadingStatus(Book * book);

/**
 * Sets the title of the specified Book to the specified title.
 * 
 * @param book - A pointer to the Book struct to update.
 * @param newTitle - A pointer to the C-string to replace the current title of the Book.
 * 
 * @return The total number of pages of the book, -1 if the parameters are invalid, -2 if malloc fails, -3 if replacing fails
*/
int SetTitle(Book * book, char * newTitle);

/**
 * Sets the author of the specified Book to the specified author.
 * 
 * @param book - A pointer to the Book struct to update.
 * @param newAuthor - A pointer to the C-string to replace the current author of the Book.
 * 
 * @return The total number of pages of the book, -1 if the parameters are invalid, -2 if malloc fails, -3 if replacing fails
*/
int SetAuthor(Book * book, char * newAuthor);

/**
 * Sets the total number of pages of the specified Book to the specified total number of pages.
 * 
 * @param book - A pointer to the Book struct to update.
 * @param newNumPages - An int representing the new total number of pages of the specified book. Must be greater than 0 (newNumPages > 0).
 * 
 * @return The total number of pages of the book, -1 if the parameters are invalid, -2 if malloc fails, -3 if replacing fails
*/
int SetNumPages(Book * book, int newNumPages);

/**
 * Sets the rating of the specified Book to the specified new rating.
 * 
 * @param book - A pointer to the Book struct to update.
 * @param newRating - An int representing the new rating to replace the current rating. Must be between 0 & 100 inclusive (0 <= newRating >= 100).
 * 
 * @return The total number of pages of the book, -1 if the parameters are invalid, -2 if malloc fails, -3 if replacing fails
*/
int SetRating(Book * book, int newRating);

/**
 * Sets the reading status of the specified Book to the specified new status.
 * 
 * @param book - A pointer to the Book struct to update.
 * @param newStatus - An int representing the new completion status of the specified book. Will replace the old status. 0 = planned, 1 = reading, 2 = dropped, 3 = aside, 4 = completed 
 * 
 * @return The total number of pages of the book, -1 if the parameters are invalid, -2 if malloc fails, -3 if replacing fails
*/
int SetStatus(Book * book, int newStatus);

#endif //INC_MYLIBRARYAPP_BOOK_H

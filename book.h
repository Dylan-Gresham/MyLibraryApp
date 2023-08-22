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
    bool * readingStatus;
} Book;

/**
 * Creates a new Book struct containing the specified information.
 * 
 * @param title - A C-string representing the title of the book.
 * @param author - A C-string representing the author of the book.
 * @param numPages - An int representing the number of pages in the book.
 * @param rating - An int representing the rating of the book (-1 [negative one] if you don't want to give a rating yet).
 * @param completed - A boolean representing your completion status of the book. True if completed, False if still reading/planned.
 * 
 * @return A pointer to the newly created Book struct, NULL on error.
*/
Book * CreateBook(char title[], char author[], int numPages, int rating, bool completed);

/**
 * Destroys the specified Book struct, free'ing all used memory in the process.
 * 
 * @param book - A pointer to the Book struct to destroy.
 * 
 * @return 0 on success, nonzero on error (TODO: List all possible nonzero errors and what they mean).
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
 * @return The total number of pages of the book, nonzero on error (TODO: List all possible nonzero errors and what they mean).
*/
int GetNumPages(Book * book);

/**
 * Gets the rating of the specified Book.
 * 
 * @param book - A pointer to the Book struct to get the rating from.
 * 
 * @return The rating of the book, nonzero on error (TODO: List all possible nonzero errors and what they mean).
*/
int GetRating(Book * book);

/**
 * Gets the current reading status of the Book.
 * 
 * @param book - A pointer to the Book struct to get the reading status from.
 * 
 * @return The reading status of the book, nonzero on error (TODO: List all possible nonzero errors and what they mean).
*/
bool GetReadingStatus(Book * book);

/**
 * Sets the title of the specified Book to the specified title.
 * 
 * @param book - A pointer to the Book struct to update.
 * @param newTitle - A pointer to the C-string to replace the current title of the Book.
 * 
 * @return 0 on success, nonzero on error (TODO: List all possible nonzero errors and what they mean).
*/
int SetTitle(Book * book, char * newTitle);

/**
 * Sets the author of the specified Book to the specified author.
 * 
 * @param book - A pointer to the Book struct to update.
 * @param newAuthor - A pointer to the C-string to replace the current author of the Book.
 * 
 * @return 0 on success, nonzero on error (TODO: List all possible nonzero errors and what they mean).
*/
int SetAuthor(Book * book, char * newAuthor);

/**
 * Sets the total number of pages of the specified Book to the specified total number of pages.
 * 
 * @param book - A pointer to the Book struct to update.
 * @param newNumPages - An int representing the new total number of pages of the specified book. Must be greater than 0 (newNumPages > 0).
 * 
 * @return 0 on success, nonzero on error (TODO: List all possible nonzero errors and what they mean).
*/
int SetNumPages(Book * book, int newNumPages);

/**
 * Sets the rating of the specified Book to the specified new rating.
 * 
 * @param book - A pointer to the Book struct to update.
 * @param newRating - An int representing the new rating to replace the current rating. Must be between 0 & 100 inclusive (0 <= newRating >= 100).
 * 
 * @return 0 on success, nonzero on error (TODO: List all possible nonzero errors and what they mean).
*/
int SetRating(Book * book, int newRating);

/**
 * Sets the reading status of the specified Book to the specified new status.
 * 
 * @param book - A pointer to the Book struct to update.
 * @param newStatus - A bool representing the new completion status of the specified book. Will replace the old status. True means you have finished reading the book, False means you have NOT finished reading the book.
 * 
 * @return 0 on success, nonzero on error (TODO: List all possible nonzero errors and what they mean).
*/
int SetReadingStatus(Book * book, bool newStatus);

#endif //INC_MYLIBRARYAPP_BOOK_H

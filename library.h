//
// Created by Dylan Gresham on 08/22/2023
//

#ifndef INC_MYLIBRARYAPP_LIBRARY_H
#define INC_MYLIBRARYAPP_LIBRARY_H

#include "./book.h"

#include <stdbool.h>

typedef struct Library {
    int * numBooks;
    int * numAuthors;
    Book ** booksArray;
    char ** authorsArray;
} Library;

/**
 * Creates a new Library struct with the specified initial capacity for books.
 * 
 * @param initialSize - The initial capacity of the library
 * 
 * @return A pointer to the newly created Library struct, NULL on error
 */
Library * CreateLibrary(int initialSize);

/**
 * Destroys an already created library, free'ing all memory in the process.
 * 
 * @param library - A pointer to the library to be destroyed, will be set to NULL if successfully deleted.
 * 
 * @return 0 on success, nonzero on error (TODO: List all possible nonzero errors and what they mean).
*/
int DestroyLibrary(Library * library);

/**
 * Adds the specified book to the specified library.
 * 
 * @param library - A pointer to the library to add the book into.
 * @param book - A pointer to the book to be added to the library.
 * 
 * @return - 0 on success, nonzero on error (TODO: List all possible nonzero errors and what they mean).
*/
int AddBook(Library * library, Book * book);

/**
 * Gets the list of books in the specified library.
 * 
 * @param library - The library to get the books from.
 * 
 * @return An array containing all the books currently in the library or NULL on error.
*/
Book ** GetBooks(Library * library);

/**
 * Gets the total number of books in the library.
 * 
 * @param library - A pointer to the library to get the number of books from.
 * 
 * @return An integer (int) representing the total number of books in the library, nonzero on error (TODO: List all possible nonzero errors and what they mean).
*/
int GetNumBooks(Library * library);

/**
 * Gets the total number of authors in the library.
 * 
 * @param library - A pointer to the library to get the number of authors from.
 * 
 * @return An integer (int) representing the total number of authors in the library, nonzero on error (TODO: List all possible nonzero errors and what they mean).
*/
int GetNumAuthors(Library * library);

/**
 * Sets the specified library's number of authors to the specified number of authors.
 * 
 * @param library - A pointer to the library of which the number of authors will be modified.
 * 
 * @param newNumAuthors - The new number of authors. Should be a positive integer or zero (0 <= newNumAuthors > 2147483647).
*/
int SetNumAuthors(Library * library, int newNumAuthors);

/**
 * Checks if the specified library is empty or not.
 * 
 * @param library - A pointer to the library to check the emptiness of.
 * 
 * @return True if the library is empty, false if non-empty.
*/
bool IsEmpty(Library * library);

#endif //INC_MYLIBRARYAPP_LIBRARY_H

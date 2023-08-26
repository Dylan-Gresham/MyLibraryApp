//
// Created by Dylan Gresham on 08/22/2023
//

#include "oldLibrary.h"

#include <stdlib.h>

Library * CreateLibrary(int initialSize) {
    // Invalid parameter handling
    if(initialSize < 0) {
        return NULL;
    }

    Library * newLibrary = malloc(sizeof(Library));
    if(newLibrary == NULL) {
        free(newLibrary);
        
        return NULL;
    }

    // Create and validate new member pointers
    int * newNumBooksMember = malloc(sizeof(int));
    if(newNumBooksMember == NULL) {
        free(newNumBooksMember);
        free(newLibrary);
        
        return NULL;
    }

    int * newNumAuthorsMember = malloc(sizeof(int));
    if(newNumAuthorsMember == NULL) {
        free(newNumAuthorsMember);
        free(newNumBooksMember);
        free(newLibrary);

        return NULL;
    }

    Book ** newBooksArrayMember = malloc(sizeof(Book*) * initialSize); // Allocate memory for Book pointers
    if(newBooksArrayMember == NULL) {
        free(newBooksArrayMember);
        free(newNumAuthorsMember);
        free(newNumBooksMember);
        free(newLibrary);

        return NULL;
    }

    // Allocate memory for Books
    for(int i = 0; i < initialSize; i++) {
        newBooksArrayMember[i] = malloc(sizeof(Book));
        if(newBooksArrayMember[i] == NULL) {
            for(int j = 0; j < i; j++) {
                free(newBooksArrayMember[j]);
            }
            free(newBooksArrayMember[i]);
            free(newBooksArrayMember);
            free(newNumAuthorsMember);
            free(newNumBooksMember);
            free(newLibrary);
            
            return NULL;
        }
    }

    char ** newAuthorsArrayMember = malloc(sizeof(char*) * initialSize); // Allocate memory for char pointers
    if(newAuthorsArrayMember == NULL) {
        free(newAuthorsArrayMember);
        for(int i = 0; i < initialSize; i++) {
            free(newBooksArrayMember[i]);
        }
        free(newBooksArrayMember);
        free(newNumAuthorsMember);
        free(newNumBooksMember);
        free(newLibrary);
        
        return NULL;
    }

    // Allocate memory for author names
    for(int i = 0; i < initialSize; i++) {
        /* Using 31 as a default value for name length (30 chars for author's name, 1 for null terminating, 
         * will realloc as necessary) */
        newAuthorsArrayMember[i] = malloc(sizeof(char) * 31);
        if(newAuthorsArrayMember[i] == NULL) {
            for(int j = 0; j < i; j++) {
                free(newAuthorsArrayMember[j]);
            }
            free(newAuthorsArrayMember[i]);
            free(newAuthorsArrayMember);
            for(int i = 0; i < initialSize; i++) {
                free(newBooksArrayMember[i]);
            }
            free(newBooksArrayMember);
            free(newNumAuthorsMember);
            free(newNumBooksMember);
            free(newLibrary);
            
            return NULL;
        }
    }

    // Assign malloc'd members to Library struct
    newLibrary->authorsArray = newAuthorsArrayMember;
    newLibrary->booksArray = newBooksArrayMember;
    newLibrary->numAuthors = newNumAuthorsMember;
    newLibrary->numBooks = newNumBooksMember;

    // Assign default values
    *(newLibrary->numBooks) = 0;
    *(newLibrary->numAuthors) = 0;

    return newLibrary;
}

int DestroyLibrary(Library * library) {
    // Invalid parameter handling
    if(library == NULL) {
        return -1;
    }

    free(library->numBooks);
    free(library->numAuthors);
    
    int bookArraySize = sizeof(library->booksArray) / sizeof(library->booksArray[0]);
    for(int i = 0; i < bookArraySize; i++) {
        free(library->booksArray[i]);
    }
    free(library->booksArray);
    
    int authorArraySize = sizeof(library->authorsArray) / sizeof(library->authorsArray[0]);
    for(int i = 0; i < authorArraySize; i++) {
        free(library->authorsArray[i]);
    }
    free(library->authorsArray);

    free(library);
    library = NULL;

    return 0;
}

int AddBook(Library * library, char title[], char author[], int numPages, int rating, int status) {
    // TODO
}

Book ** GetBooks(Library * library) {
    // TODO
}

int GetNumBooks(Library * library) {
    // TODO
}

int GetNumAuthors(Library * library) {
    // TODO
}

int SetNumAuthors(Library * library, int newNumAuthors) {
    // TODO
}

bool IsEmpty(Library * library) {
    // TODO
}

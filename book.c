//
// Created by Dylan Gresham on 08/22/2023
//

#include "./book.h"

#include <stdlib.h>
#include <string.h>

Book * CreateBook(char title[], char author[], int numPages, int rating, bool completed) {
    // Invalid parameter handling
    if(title == NULL || author == NULL || numPages == NULL || rating == NULL || completed == NULL) {
        return NULL;
    } else if(numPages < 1) {
        return NULL;
    } else if(rating < -1 || rating > 100) {
        return NULL;
    }
    
    Book * newBook = malloc(sizeof(Book)); // Create new Book pointer
    // Check that the pointer was malloc'd without error
    if(newBook == NULL) {
        return NULL;
    }

    // Create new bookTitle pointer with 1 more for null terminating
    newBook->title = malloc(sizeof(char) * strlen(title) + sizeof(char));
    // Check that the pointer was malloc'd without error
    if(newBook->title == NULL) {
        return NULL;
    } else {
        strcpy(newBook->title, title); // Copy the title into the pointer
    }

    // Create new bookAuthor pointer with 1 more for null terminating
    newBook->author = malloc(sizeof(char) * strlen(author) + sizeof(char));
    // Check that the pointer was malloc'd without error
    if(newBook->author == NULL) {
        return NULL;
    } else {
        strcpy(newBook->author, author); // Copy the author into the pointer;
    }

    // Create new bookNumPages pointer
    newBook->numPages = malloc(sizeof(int));
    // Check that the pointer was malloc'd without error
    if(newBook->numPages == NULL) {
        return NULL;
    } else {
        *(newBook->numPages) = numPages; // Dereference then store the number of pages
    }

    // Create new bookRating pointer
    newBook->rating = malloc(sizeof(int));
    // Check that the pointer was malloc'd without error
    if(newBook->rating == NULL) {
        return NULL;
    } else {
        *(newBook->rating) = rating; // Dereference then store the rating
    }

    // Create new bookCompleted pointer
    newBook->readingStatus = malloc(sizeof(bool));
    if(newBook->readingStatus == NULL) {
        return NULL;
    } else {
        *(newBook->readingStatus) = completed; // Dereference then store the completion status
    }

    return newBook; // If reaching this point, everything else above passed so it's fine to do no checks.
}

int DestroyBook(Book * book) {
    // Invalid parameter handling
    if(book == NULL) {
        return -1;
    }

    // free returns no value so nothing to check for error handling
    free(book->title);
    free(book->author);
    free(book->numPages);
    free(book->rating);
    free(book->readingStatus);
    free(book);
    book = NULL; // Set pointer to NULL so it can't be used by accident anymore.

    return 0; // Success
}

char * GetTitle(Book * book) {
    // Invalid parameter handling
    if(book == NULL || book->title == NULL) {
        return NULL;
    }

    // Preserve encapsulation by returning a copy of the title and not the title itself
    char * retStr = malloc(sizeof(char) * strlen(book->title) + sizeof(char)); // Add 1 for the null terminating
    // Check the variable was malloc'd correctly
    if(retStr == NULL) {
        return NULL;
    } else {
        strcpy(retStr, book->title); // Copy the title into the return string.
    }

    return retStr;
}

char * GetAuthor(Book * book) {
    // Invalid parameter handling
    if(book == NULL || book->author == NULL) {
        return NULL;
    }

    // Preserve encapsulation by returning a copy of the title and not the title itself
    char * retStr = malloc(sizeof(char) * strlen(book->author) + sizeof(char)); // Add 1 for the null terminating
    // Check the variable was malloc'd correctly
    if(retStr == NULL) {
        return NULL;
    } else {
        strcpy(retStr, book->author); // Copy the title into the return string.
    }

    return retStr;
}

int GetNumPages(Book * book) {
    // Invalid parameter handling
    if(book == NULL || book->numPages == NULL) {
        return NULL;
    }

    // Preserve encapsulation by returning a copy of the title and not the title itself
    int * retNum = malloc(sizeof(int));
    if(retNum == NULL) {
        return NULL;
    } else {
        memcpy(retNum, book->numPages, sizeof(int)); // Copy the number of pages
    }

    return retNum;
}

int GetRating(Book * book) {
    // TODO
}

bool GetReadingStatus(Book * book) {
    // TODO
}

int SetTitle(Book * book, char * newTitle) {
    // TODO
}

int SetAuthor(Book * book, char * newAuthor) {
    // TODO
}

int SetNumPages(Book * book, int newNumPages) {
    // TODO
}

int SetRating(Book * book, int newRating) {
    // TODO
}

int SetReadingStatus(Book * book, bool newStatus) {
    // TODO
}

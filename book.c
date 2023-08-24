//
// Created by Dylan Gresham on 08/22/2023
//

#include "./book.h"

#include <stdlib.h>
#include <string.h>

Book * CreateBook(char title[], char author[], int numPages, int rating, int status) {
    // Invalid parameter handling
    if(title == NULL || author == NULL || numPages == NULL || rating == NULL || status == NULL) {
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
    newBook->status = malloc(sizeof(int));
    if(newBook->status == NULL) {
        return NULL;
    } else {
        *(newBook->status) = status; // Dereference then store the completion status
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
    free(book->status);
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

    return *retNum;
}

int GetRating(Book * book) {
    // Invalid parameter handling
    if(book == NULL || book->rating == NULL) {
        return NULL;
    }

    // Preserve encapsulation by returning a copy of the title and not the title itself
    int * retRating = malloc(sizeof(int));
    if(retRating == NULL) {
        return NULL;
    } else {
        memcpy(retRating, book->rating, sizeof(int)); // Copy the rating
    }

    return *retRating;
}

int GetReadingStatus(Book * book) {
    // Invalid parameter handling
    if(book == NULL || book->status == NULL) {
        return NULL;
    }

    // Preserve encapsulation by returning a copy of the title and not the title itself
    int * retStatus = malloc(sizeof(int));
    if(retStatus == NULL) {
        return NULL;
    } else {
        memcpy(retStatus, book->status, sizeof(int)); // Copy the status
    }

    return *retStatus;
}

int SetTitle(Book * book, char * newTitle) {
    // Invalid parameter handling
    if(book == NULL || newTitle == NULL) {
        return -1;
    }

    // Check if the book's title member is null, if it is, create a new one via malloc.
    if(book->title == NULL) {
        char * newTitleMember = malloc(sizeof(char) * strlen(newTitle) + sizeof(char)); // + 1 for null terminating
        if(newTitleMember == NULL) {
            return -2;
        } else {
            book->title = newTitleMember;
        }
    }

    // Replace old title with new title
    strcpy(book->title, newTitle); // strcpy copies the null terminating and we want to replace so no need to use `strncpy`

    // Validate that strcpy copied the correct string.
    if(strcmp(book->title, newTitle)) {
        return 0; // Return success if copied correctly.
    } else {
        return -3; // Return nonzero if copied incorrectly.
    }
}

int SetAuthor(Book * book, char * newAuthor) {
    // Invalid parameter handling
    if(book == NULL || newAuthor == NULL) {
        return -1;
    }

    // Check if the book's author member is null, if it is, create a new one via malloc.
    if(book->author == NULL) {
        char * newAuthorMember = malloc(sizeof(char) * strlen(newAuthor) + sizeof(char)); // + 1 for null terminating
        if(newAuthorMember == NULL) {
            return -2;
        } else {
            book->author = newAuthorMember;
        }
    }

    // Replace old title with new title
    strcpy(book->author, newAuthor); // `strcpy` copies the null terminating and we want to replace so no need to use `strncpy`

    // Validate that `strcpy` copied the correct string.
    if(strcmp(book->author, newAuthor)) {
        return 0; // Return success if copied correctly.
    } else {
        return -3; // Return nonzero if copied incorrectly.
    }
}

int SetNumPages(Book * book, int newNumPages) {
    // Invalid parameter handling
    if(book == NULL || newNumPages == NULL) {
        return -1;
    }

    // Check if the book's numPages member is null, if it is, create a new one via malloc.
    if(book->numPages == NULL) {
        int * newNumPagesMember = malloc(sizeof(int));
        // Validate that the new numPages member was malloc'd properly.
        if(newNumPagesMember == NULL) {
            return -2;
        } else {
            book->numPages = newNumPagesMember; // Assign
        }
    }

    // Replace old numPages with newNumPages
    *(book->numPages) = newNumPages;

    // Validate the value was actually copied.
    if(*(book->numPages) == newNumPages) {
        return 0;
    } else {
        return -3;
    }
}

int SetRating(Book * book, int newRating) {
    // Invalid parameter handling
    if(book == NULL || newRating == NULL) {
        return -1;
    }

    // Check if the book's rating member is null, if it is, create a new one via malloc.
    if(book->rating == NULL) {
        int * newRatingMember = malloc(sizeof(int));
        // Validate that the new rating member was malloc'd properly.
        if(newRatingMember == NULL) {
            return -2;
        } else {
            book->rating = newRatingMember; // Assign
        }
    }

    // Replace old numPages with newRating
    *(book->rating) = newRating;

    // Validate the value was actually copied.
    if(*(book->rating) == newRating) {
        return 0;
    } else {
        return -3;
    }
}

int SetStatus(Book * book, int newStatus) {
    // TODO
}

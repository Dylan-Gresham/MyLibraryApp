//
// Created by Dylan Gresham on 08/22/2023
//

#include "./oldBook.h"

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
        free(newBook);

        return NULL;
    }

    // Create new bookTitle pointer with 1 more for null terminating
    newBook->title = malloc(sizeof(char) * strlen(title) + sizeof(char));
    // Check that the pointer was malloc'd without error
    if(newBook->title == NULL) {
        free(newBook->title);
        free(newBook);

        return NULL;
    } else {
        strcpy(newBook->title, title); // Copy the title into the pointer
    }

    // Create new bookAuthor pointer with 1 more for null terminating
    newBook->author = malloc(sizeof(char) * strlen(author) + sizeof(char));
    // Check that the pointer was malloc'd without error
    if(newBook->author == NULL) {
        free(newBook->author);
        free(newBook->title);
        free(newBook);

        return NULL;
    } else {
        strcpy(newBook->author, author); // Copy the author into the pointer;
    }

    // Create new bookNumPages pointer
    newBook->numPages = malloc(sizeof(int));
    // Check that the pointer was malloc'd without error
    if(newBook->numPages == NULL) {
        free(newBook->numPages);
        free(newBook->author);
        free(newBook->title);
        free(newBook);

        return NULL;
    } else {
        *(newBook->numPages) = numPages; // Dereference then store the number of pages
    }

    // Create new bookRating pointer
    newBook->rating = malloc(sizeof(int));
    // Check that the pointer was malloc'd without error
    if(newBook->rating == NULL) {
        free(newBook->rating);
        free(newBook->numPages);
        free(newBook->author);
        free(newBook->title);
        free(newBook);

        return NULL;
    } else {
        *(newBook->rating) = rating; // Dereference then store the rating
    }

    // Create new bookCompleted pointer
    newBook->status = malloc(sizeof(int));
    if(newBook->status == NULL) {
        free(newBook->status);
        free(newBook->rating);
        free(newBook->numPages);
        free(newBook->author);
        free(newBook->title);
        free(newBook);

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
    char retStr[strlen(book->title) + 1];
    strcpy(retStr, book->title);

    return retStr;
}

char * GetAuthor(Book * book) {
    // Invalid parameter handling
    if(book == NULL || book->author == NULL) {
        return NULL;
    }

    // Preserve encapsulation by returning a copy of the author and not the author itself
    char retStr[strlen(book->author) + 1];
    strcpy(retStr, book->author);

    return retStr; 
}

int GetNumPages(Book * book) {
    // Invalid parameter handling
    if(book == NULL || book->numPages == NULL) {
        return -1;
    }

    // Preserve encapsulation by returning a copy of the number of pages and not the number of pages itself
    int retNum = *(book->numPages);

    return retNum;
}

int GetRating(Book * book) {
    // Invalid parameter handling
    if(book == NULL || book->rating == NULL) {
        return -1;
    }

    // Preserve encapsulation by returning a copy of the rating and not the rating itself
    int retRating = *(book->rating);

    return retRating;
}

int GetReadingStatus(Book * book) {
    // Invalid parameter handling
    if(book == NULL || book->status == NULL) {
        return -1;
    }

    // Preserve encapsulation by returning a copy of the status and not the status itself
    int retStatus = *(book->status);

    return retStatus;
}

int SetTitle(Book * book, char * newTitle) {
    // Invalid parameter handling
    if(book == NULL || newTitle == NULL) {
        return -1;
    }

    char oldTitle[] = NULL;
    if(book->title != NULL) {
        oldTitle[strlen(book->title) + 1];
    }

    // Allocate memory for the new title
    char * newTitleMember = malloc(sizeof(char) * strlen(newTitle) + sizeof(char)); // + 1 for null terminating
    if(newTitleMember == NULL) {
        free(newTitleMember);

        return -2;
    } else {
        free(book->title); // Free old title
        book->title = newTitleMember; // Assign new title
    }

    // Replace old title with new title
    strcpy(book->title, newTitle); // strcpy copies the null terminating and we want to replace so no need to use `strncpy`

    // Validate that strcpy copied the correct string.
    if(strcmp(book->title, newTitle)) {
        return 0; // Return success if copied correctly.
    } else {
        free(book->title); // Free whatever got copied over
        book->title = malloc(sizeof(char) * strlen(oldTitle) + sizeof(char));
        strcpy(book->title, oldTitle); // Put old title back

        return -3; // Return nonzero if copied incorrectly.
    }
}

int SetAuthor(Book * book, char * newAuthor) {
    // Invalid parameter handling
    if(book == NULL || newAuthor == NULL) {
        return -1;
    }

    char oldAuthor[] = NULL;
    if(book->author != NULL) {
        oldAuthor[strlen(book->author) + 1];
    }

    // Allocate memory for the new author
    char * newAuthorMember = malloc(sizeof(char) * strlen(newAuthor) + sizeof(char)); // + 1 for null terminating
    if(newAuthorMember == NULL) {
        free(newAuthorMember);

        return -2;
    } else {
        free(book->author); // Free old author
        book->author = newAuthorMember; // Assign new author
    }

    // Replace old author with new author
    strcpy(book->author, newAuthor); // `strcpy` copies the null terminating and we want to replace so no need to use `strncpy`

    // Validate that strcpy copied the correct string.
    if(strcmp(book->author, newAuthor)) {
        return 0; // Return success if copied correctly.
    } else {
        free(book->author); // Free whatever got copied over
        book->author = malloc(sizeof(char) * strlen(oldAuthor) + sizeof(char));
        strcpy(book->author, oldAuthor); // Put old author back

        return -3; // Return nonzero if copied incorrectly.
    }
}

int SetNumPages(Book * book, int newNumPages) {
    // Invalid parameter handling
    if(book == NULL || newNumPages == NULL) {
        return -1;
    }

    int oldNumPages = NULL;

    // Check if the book's numPages member is null, if it is, create a new one via malloc.
    if(book->numPages == NULL) {
        free(book->numPages); // Just in case

        int * newNumPagesMember = malloc(sizeof(int));
        // Validate that the new numPages member was malloc'd properly.
        if(newNumPagesMember == NULL) {
            free(newNumPagesMember);

            return -2;
        } else {
            *newNumPagesMember = newNumPages;
            book->numPages = newNumPagesMember; // Assign
        }
    } else {
        oldNumPages = *(book->numPages);
        *(book->numPages) = newNumPages;
    }
    
    // Validate the value was actually copied.
    if(*(book->numPages) == newNumPages) {
        return 0;
    } else {
        *(book->numPages) = oldNumPages;

        return -3;
    }
}

int SetRating(Book * book, int newRating) {
    // Invalid parameter handling
    if(book == NULL || newRating == NULL) {
        return -1;
    }

    int oldRating = NULL;

    // Check if the book's rating member is null, if it is, create a new one via malloc.
    if(book->rating == NULL) {
        free(book->rating); // Just in case

        int * newRatingMember = malloc(sizeof(int));
        // Validate that the new rating member was malloc'd properly.
        if(newRatingMember == NULL) {
            free(newRatingMember);

            return -2;
        } else {
            *newRatingMember = newRating;
            book->rating = newRatingMember; // Assign
        }
    } else {
        oldRating = *(book->rating);
        *(book->rating) = newRating;
    }

    // Validate the value was actually copied.
    if(*(book->rating) == newRating) {
        return 0;
    } else {
        *(book->rating) = oldRating;

        return -3;
    }
}

int SetStatus(Book * book, int newStatus) {
    // Invalid parameter handling
    if(book == NULL || newStatus == NULL) {
        return -1;
    }

    int oldStatus = NULL;

    // Check if the book's status member is null, if it is, create a new one via malloc.
    if(book->status == NULL) {
        free(book->status); // Just in case

        int * newStatusMember = malloc(sizeof(int));
        // Validate that the newStatusMember was malloc'd correctly
        if(newStatusMember == NULL) {
            free(newStatusMember);

            return -2;
        } else {
            *newStatusMember = newStatus;
            book->status = newStatusMember; // Assign
        }
    } else {
        oldStatus = *(book->status);
        *(book->status) = newStatus;
    }

    // Validate that the status was copied correctly
    if(*(book->status) == newStatus) {
        return 0;
    } else {
        *(book->status) = oldStatus;

        return -3;
    }
}

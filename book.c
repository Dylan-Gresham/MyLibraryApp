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
    // TODO
}

char * GetTitle(Book * book) {
    // TODO
}

char * GetAuthor(Book * book) {
    // TODO
}

int GetNumPages(Book * book) {
    // TODO
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

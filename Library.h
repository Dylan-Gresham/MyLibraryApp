//
// Library.h
// Created by Dylan Gresham on 8/26/23.
//

#ifndef LIBRARYAPP_LIBRARY_H
#define LIBRARYAPP_LIBRARY_H

#include "./Book.h"

#include <vector>
#include <map>
using namespace std;

class Library {
    private:
        int numBooks;
        int numAuthors;
        std::vector<Book> booksVector;
        std::map<string, int> authorsMap;
    public:
        /**
         * Creates a new Library object for books.
         *
         * @return A newly created Library object
         */
        Library();

        /**
         * Adds the specified book to the library.
         *
         * @param title A string containing the title of the book to be added
         * @param author A string containing the author of the book to be added
         * @param numPages An int representing the total number of pages in the book
         * @param rating An int representing the rating of the book (-1 [negative one] if you don't want to give a rating yet).
         * @param status An int representing your reading status of the book. 0 = planned, 1 = reading, 2 = dropped, 3 = aside, 4 = completed
         *
         * @return 0 on success, nonzero on error
         */
        void addBook(string title, string author, int numPages, int rating, int status);

        /**
         * Gets the list of books in the library.
         *
         * @return A vector containing all the books currently in the library.
         */
        std::vector<Book> getBooks();

        /**
         * Gets the list of authors in the library.
         *
         * @return A vector containing all the authors currently in the library.
         */
        std::map<string, int> getAuthors();

        /**
         * Gets the total number of books in the library.
         *
         * @return An integer (int) representing the total number of books in the library, nonzero on error
         */
        int getNumBooks();

        /**
         * Gets the total number of authors in the library.
         *
         * @return An integer (int) representing the total number of authors in the library, nonzero on error
        */
        int getNumAuthors();

        /**
         * Checks if the library is empty or not
         *
         * @return True if the library is empty, false if non-empty.
        */
        bool isEmpty();
};


#endif // LIBRARYAPP_LIBRARY_H

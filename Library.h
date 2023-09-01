//
// Library.h
// Created by Dylan Gresham on 8/26/23.
//

#ifndef LIBRARYAPP_LIBRARY_H
#define LIBRARYAPP_LIBRARY_H

#include "./Book.h"

#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Library {
    private:
        int numBooks;
        int numAuthors;
        std::vector<Book> booksVector;
        std::map<string, int> authorsMap;
        int sortFunction;

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
         */
        void addBook(string title, string author, int numPages, int rating, int status);

        /**
         * Deletes the specified Book from the Library
         *
         * @param title A string containing the title of the book to be deleted
         * @return 0 if the Book was found and deleted, -1 if the Book wasn't found
         */
        int deleteBook(string title);

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
         * Returns an int representing the current sorting function.
         *
         * 0 = Alphabetical by Author
         * 1 = Alphabetical by Title
         * 2 = Reverse Alphabetical by Author
         * 3 = Reverse Alphabeetical by Title
         * 4 = Descending by Total Page Number
         * 5 = Descending by Rating
         * 6 = Ascending by Total Page Number
         * 7 = Ascending by Rating
         *
         * @return An int representing the current sorting function
         */
        int getSortingFunction();

        /**
         * Set the current sorting function.
         *
         * Valid ints for sorting functions:
         * 0 = Alphabetical by Author
         * 1 = Alphabetical by Title
         * 2 = Reverse Alphabetical by Author
         * 3 = Reverse Alphabeetical by Title
         * 4 = Descending by Total Page Number
         * 5 = Descending by Rating
         * 6 = Ascending by Total Page Number
         * 7 = Ascending by Rating
         *
         * @param sortFunction An int representing the sorting function to set the current sorting function to
         */
        void setSortingFunction(int sortFunction);

        /**
         * Checks if the library is empty or not
         *
         * @return True if the library is empty, false if non-empty.
        */
        bool isEmpty();

        /**
         * Sort the Library using the current sorting method.
         *
         * This method modifies the bookVector itself instead of creating and returning a new, sorted vector.
         */
        void sortLibrary();

        /**
         * Sort the Library using the designated sorting method.
         *
         * Valid ints for sorting functions:
         * 0 = Alphabetical by Author
         * 1 = Alphabetical by Title
         * 2 = Reverse Alphabetical by Author
         * 3 = Reverse Alphabeetical by Title
         * 4 = Descending by Total Page Number
         * 5 = Descending by Rating
         * 6 = Ascending by Total Page Number
         * 7 = Ascending by Rating
         *
         * @param sort An int representnig the sorting function to use
         */
        void sortLibrary(int sortFunction);

        /**
         * Search through the Library's bookVector member to find a Book with the matching title
         *
         * @param title A string representing the title of the Book to search for
         * @return The Book object with the matching title or a newly constructed Book object with a blank title and author
         */
        Book findBook(std::string title);
};


#endif // LIBRARYAPP_LIBRARY_H

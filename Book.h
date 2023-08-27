//
// Book.h
// Created by Dylan Gresham on 8/25/23.
//

#ifndef MYLIBRARYAPP_BOOK_H
#define MYLIBRARYAPP_BOOK_H

#include <string>
using namespace std;

class Book {
    private:
        std::string title;
        std::string author;
        int numPages;
        int rating;
        int status;
    public:
        /**
         * Creates a new Book object containing the specified information.
         *
         * @param title A string representing the title of the book.
         * @param author A string representing the author of the book.
         * @param numPages An int representing the number of pages in the book.
         * @param rating An int representing the rating of the book (-1 [negative one] if you don't want to give a rating yet).
         * @param status An int representing your reading status of the book. 0 = planned, 1 = reading, 2 = dropped, 3 = aside, 4 = completed
         *
         * @return A Book object to the newly created Book object
        */
        Book(std::string title, std::string author, int numPages, int rating, int status);

        /**
        * Gets the title of this Book.
        *
        * @return The title of the book
        */
        std::string getTitle();

        /**
         * Gets the author of this Book
         *
         * @return The author of the Book
         */
        std::string getAuthor();

        /**
        * Gets the total number of pages of this Book.
        *
        * @return The total number of pages of the book
        */
        int getNumPages();

        /**
         * Gets the rating of this Book.
         *
         * @return The total number of pages of this book
        */
        int getRating();


        /**
         * Gets the current reading status of this Book.
         *
         * @return The total number of pages of this book
        */
        int getReadingStatus();

        /**
         * Sets the title of this Book to the specified title.
         *
         * @param newTitle - A string to replace the current title of the Book.
         *
         * @return 0 on success, nonzero on error
        */
        void setTitle(std::string newTitle);

        /**
         * Sets the author of this Book to the specified author.
         *
         * @param newAuthor - A string to replace the current author of the Book.
         *
         * @return 0 on success, nonzero on error
        */
        void setAuthor(std::string newAuthor);

        /**
         * Sets the total number of pages of this Book to the specified total number of pages.
         *
         * @param newNumPages - An int representing the new total number of pages of the specified book. Must be greater than 0 (newNumPages > 0).
         *
         * @return 0 on success, nonzero on error
        */
        void setNumPages(int newNumPages);

        /**
         * Sets the rating of this Book to the specified new rating.
         *
         * @param newRating - An int representing the new rating to replace the current rating. Must be between 0 & 100 inclusive (0 <= newRating >= 100).
         *
         * @return 0 on success, nonzero on error
        */
        void setRating(int newRating);

        /**
         * Sets the reading status of this Book to the specified new status.
         *
         * @param newStatus - An int representing the new completion status of the specified book. Will replace the old status. 0 = planned, 1 = reading, 2 = dropped, 3 = aside, 4 = completed
         *
         * @return 0 on success, nonzero on error
        */
        void setStatus(int newStatus);
};

#endif //MYLIBRARYAPP_BOOK_H

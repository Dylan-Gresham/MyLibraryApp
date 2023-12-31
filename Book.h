//
// Book.h
// Created by Dylan Gresham on 8/25/23.
//

#ifndef LIBRARYAPP_BOOK_H
#define LIBRARYAPP_BOOK_H

#include <string>
using namespace std;

class Book {
    private:
        std::string title;
        std::string authorFirstName;
        std::string authorLastName;
        int numPages;
        int rating;
        int status;
    public:
        /**
         * Creates a new Book object containing the specified information.
         *
         * @param title A string representing the title of the book.
         * @param authorFirstName A string representing the first name of the author of the book.
         * @param authorLastName A string representing the last name of the author of the book.
         * @param numPages An int representing the number of pages in the book.
         * @param rating An int representing the rating of the book (-1 [negative one] if you don't want to give a rating yet).
         * @param status An int representing your reading status of the book. 0 = planned, 1 = reading, 2 = completed, 3 = aside, 4 = dropped
         *
         * @return A Book object to the newly created Book object
        */
        Book(std::string title, std::string authorFirstName, std::string authorLastName, int numPages, int rating, int status);

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
         * Gets the first name of the author of this Book
         *
         * @return The first name of the author of the Book
         */
        std::string getAuthorFirstName();

        /**
         * Gets the last name of the author of this Book
         *
         * @return The last name of the author of the Book
         */
        std::string getAuthorLastName();

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
         * @return An int representing the current reading status of the Book. 0 = plan to read, 1 = reading, 2 = completed, 3 = aside, and 4 = dropped
        */
        int getReadingStatus();

        /**
         * Converts this Book's status to the corresponding string
         *
         * @return A string representing the decoded status code
         */
        std::string statusToStr();

        /**
         * Converts the provided status to the corresponding string
         * @param status An int representing the status code to decode into a string
         * @return A string representing the decoded status code
         */
        std::string statusToStr(int status);

        /**
         * Sets the title of this Book to the specified title.
         *
         * @param newTitle A string to replace the current title of the Book.
        */
        void setTitle(std::string newTitle);

        /**
         * Sets the authorFirstName of this Book to the specified first name.
         *
         * @param newAuthorFirstName A string representing the new first name of the author.
         */
        void setAuthorFirstName(std::string newAuthorFirstName);

        /**
         * Sets the authorLastName of this Book to the specified last name.
         *
         * @param newAuthorLastName A string representing the new last name of the author.
         */
        void setAuthorLastName(std::string newAuthorLastName);

        /**
         * Sets the total number of pages of this Book to the specified total number of pages.
         *
         * @param newNumPages An int representing the new total number of pages of the specified book. Must be greater than 0 (newNumPages > 0).
        */
        void setNumPages(int newNumPages);

        /**
         * Sets the rating of this Book to the specified new rating.
         *
         * @param newRating An int representing the new rating to replace the current rating. Must be between 0 & 100 inclusive (0 <= newRating >= 100).
        */
        void setRating(int newRating);

        /**
         * Sets the reading status of this Book to the specified new status.
         *
         * @param newStatus An int representing the new completion status of the specified book. Will replace the old status. 0 = plan to read, 1 = reading, 2 = completed, 3 = aside, and 4 = dropped
        */
        void setStatus(int newStatus);
};

#endif // LIBRARYAPP_BOOK_H

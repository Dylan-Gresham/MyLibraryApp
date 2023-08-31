//
// Library.cpp
// Created by Dylan Gresham on 8/26/23.
//

#include "Library.h"
#include "globalvars.h"

#include <cstring>
using namespace std;

// Sorting functions
bool sortAlphabeticalAuthor(Book one, Book two) {
    if(one.getAuthor().compare(two.getAuthor()) > 0) {
        return 1;
    } else if(one.getAuthor().compare(two.getAuthor()) < 0) {
        return -1;
    } else {
        return 0;
    }
}

bool sortAlphabeticalTitle(Book one, Book two) {
    if(one.getTitle().compare(two.getTitle()) > 0) {
        return 1;
    } else if(one.getTitle().compare(two.getTitle()) < 0) {
        return -1;
    } else {
        return 0;
    }
}

bool reverseSortAlphabeticalAuthor(Book one, Book two) {
    if(one.getAuthor().compare(two.getAuthor()) > 0) {
        return -1;
    } else if(one.getAuthor().compare(two.getAuthor()) < 0) {
        return 1;
    } else {
        return 0;
    }
}


bool reverseSortAlphabeticalTitle(Book one, Book two) {
    if(one.getTitle().compare(two.getTitle()) > 0) {
        return -1;
    } else if(one.getTitle().compare(two.getTitle()) < 0) {
        return 1;
    } else {
        return 0;
    }
}

bool sortDescendingNumPages(Book one, Book two) {
    if(one.getNumPages() > two.getNumPages()) {
        return 1;
    } else if(one.getNumPages() < two.getNumPages()) {
        return -1;
    } else {
        return 0;
    }
}

bool sortDescendingRating(Book one, Book two) {
    if(one.getRating() > two.getRating()) {
        return 1;
    } else if(one.getRating() < two.getRating()) {
        return -1;
    } else {
        return 0;
    }
}

bool sortAscendingNumPages(Book one, Book two) {
    if(one.getNumPages() > two.getNumPages()) {
        return -1;
    } else if(one.getNumPages() < two.getNumPages()) {
        return 1;
    } else {
        return 0;
    }
}

bool sortAscendingRating(Book one, Book two) {
    if(one.getRating() > two.getRating()) {
        return -1;
    } else if(one.getRating() < two.getRating()) {
        return 1;
    } else {
        return 0;
    }
}

Library::Library() {
    this->numBooks = 0;
    this->numAuthors = 0;
    this->sortFunction = 0;
    // Don't need to initialize booksVector or authorsMap as they are created as empty
    // when the constructor is called
}

void Library::addBook(std::string title, std::string author, int numPages, int rating, int status) {
    Book newBook = Book(title, author, numPages, rating, status);
    this->booksVector.push_back(newBook);
    this->numBooks = this->booksVector.size();
    /*
     *  According to
     *  https://stackoverflow.com/questions/72841438/how-to-store-array-data-as-map-key-or-increment-frequency-if-array-already-in-ma
     *  if you just use the increment operator on a map key it'll increment it if it's in the map
     *  and if it isn't in the map it adds it with default value of 0 and then increments it
     *  to 1 which is exactly what I want to do. TODO: Will need to test this.
     */
    this->authorsMap[title]++;
    this->numAuthors = this->authorsMap.size();

    sortLibrary();
}

std::vector<Book> Library::getBooks() {
    return this->booksVector;
}

std::map<string, int> Library::getAuthors() {
    return this->authorsMap;
}

int Library::getNumBooks() {
    return this->numBooks;
}

int Library::getNumAuthors() {
    return this->numAuthors;
}

int Library::getSortingFunction() {
    return this->sortFunction;
}

void Library::setSortingFunction(int sortFunction) {
    if(sortFunction < 0 || sortFunction > 7) {
        return;
    } else {
        this->sortFunction = sortFunction;

        return;
    }
}

bool Library::isEmpty() {
    return (this->booksVector.size() == 0);
}

void Library::sortLibrary() {
    if(this->sortFunction == 0) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), sortAlphabeticalAuthor);
    } else if(this->sortFunction == 1) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), sortAlphabeticalTitle);
    } else if(this->sortFunction == 2) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), reverseSortAlphabeticalAuthor);
    } else if(this->sortFunction == 3) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), reverseSortAlphabeticalTitle);
    } else if(this->sortFunction == 4) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), sortDescendingNumPages);
    } else if(this->sortFunction == 5) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), sortDescendingRating);
    } else if(this->sortFunction == 6) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), sortAscendingNumPages);
    } else {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), sortAscendingRating);
    }
}

void Library::sortLibrary(int sortFunction) {
    if(sortFunction < 0 || sortFunction > 7) {
        return;
    } else if(sortFunction == 0) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), sortAlphabeticalAuthor);
    } else if(sortFunction == 1) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), sortAlphabeticalTitle);
    } else if(sortFunction == 2) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), reverseSortAlphabeticalAuthor);
    } else if(sortFunction == 3) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), reverseSortAlphabeticalTitle);
    } else if(sortFunction == 4) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), sortDescendingNumPages);
    } else if(sortFunction == 5) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), sortDescendingRating);
    } else if(sortFunction == 6) {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), sortAscendingNumPages);
    } else {
        return std::sort(lib.getBooks().begin(), lib.getBooks().end(), sortAscendingRating);
    }
}

/**
 * Method from StackOverflow:
 * https://stackoverflow.com/a/313990/18649233
 *
 * Converts the designated string to lowercase
 *
 * @param str The string to convert to lowercase
 * @return A lowercase copy of the parameter string
 */
std::string strToLower(std::string str) {
    std::string retStr = str.substr(0, str.length());
    transform(retStr.begin(), retStr.end(), retStr.begin(), [](unsigned char c){return std::tolower(c);});

    return retStr;
}

/**
 * Helper function for the vectorBinarySearch() method
 *
 * @param vector The vector to perform the binary search on
 * @param startItr The iterator to start this portion of the search
 * @param endItr The iterator to search up to for this portion of the search
 * @param vectorSize The size of the vector to search through
 * @param searchValue The value to search for
 * @return A pointer to the Book if found, otherwise returns nullptr
 */
Book* vectorBSHelper(std::vector<Book> vector, std::vector<Book>::iterator startItr, std::vector<Book>::iterator endItr, size_t vectorSize, std::string searchValue) {
    if(strToLower(startItr->getTitle()).compare(strToLower(searchValue)) == 0) { // If it's the first Book
        return startItr.base();
    } else if(strToLower(endItr->getTitle()).compare(strToLower(searchValue)) == 0) { // If it's the last Book
        return endItr.base();
    } else if(vectorSize <= 2) { // If it's not the first or last Book but there's only 2 Books left to search through
        return nullptr;
    } else { // If it's between the first and last Book and the vectorSize is greater than 2
        advance(startItr, 1); // Already checked first index so move iterator past it

        // Get an iterator for the middle Book
        std::vector<Book>::iterator midItr = vector.begin();
        advance(midItr, (vectorSize - 2) / 2); // - 2 on the vectorSize since we already checked the first and last books

        if(strToLower(midItr->getTitle()).compare(strToLower(searchValue)) > 0) {
            // If the middle Book is greater (alphabetically comes after), only search from the starItr --> midItr
            return vectorBSHelper(vector, startItr, midItr, (vectorSize - 2) / 2, searchValue);
        } else if(strToLower(midItr->getTitle()).compare(strToLower(searchValue)) < 0) {
            // If the middle Book is lesser (alphabetically comes before), only search from the starItr --> vector.end() - 1
            advance(midItr, 1);

            std::vector<Book>::iterator endItr = vector.end();
            advance(endItr, -1); // Since we already check the last Book
            return vectorBSHelper(vector, midItr, endItr, ((vectorSize - 2) / 2) - 1, searchValue);
        } else {
            return midItr.base(); // Return middle if midItr->getTitle().compare(searchValue) == 0
        }
    }
}

/**
 * A binary search algorithm to find a Book object in the Library's bookVector
 *
 * @param vector The vector of Books to perform the binary search on
 * @param startItr An iterator set to the starting point of the binary search
 * @param vectorSize The size of the vector to search through. If the startItr isn't the vector.begin() iterator, this value should be vector.size() - <index that startItr is at>
 * @param searchValue The value to search for
 * @return A pointer to the Book object if it's found in the vector, nullptr if not found
 */
Book* vectorBinarySearch(std::vector<Book> vector, std::vector<Book>::iterator startItr, size_t vectorSize, std::string searchValue) {
    if(strToLower(startItr->getTitle()).compare(strToLower(searchValue)) == 0) { // If it's the first Book
        return startItr.base();
    } else if(strToLower(vector.end()->getTitle()).compare(strToLower(searchValue)) == 0) { // If it's the last Book
        return vector.end().base();
    } else if(vector.size() <= 2) {
        return nullptr;
    } else { // If it's somewhere between the first and last Books and the size of the vector is greater than 2:
        advance(startItr, 1); // Already checked first index so move iterator past it

        // Get an iterator for the middle Book
        std::vector<Book>::iterator midItr = vector.begin();
        advance(midItr, (vectorSize - 2) / 2); // - 2 on the vectorSize since we already checked the first and last books

        if(strToLower(midItr->getTitle()).compare(strToLower(searchValue)) > 0) {
            // If the middle Book is greater (alphabetically comes after), only search from the starItr --> midItr
            return vectorBSHelper(vector, startItr, midItr, (vectorSize - 2) / 2, searchValue);
        } else if(strToLower(midItr->getTitle()).compare(strToLower(searchValue)) < 0) {
            // If the middle Book is lesser (alphabetically comes before), only search from the starItr --> vector.end() - 1
            advance(midItr, 1);

            std::vector<Book>::iterator endItr = vector.end();
            advance(endItr, -1); // Since we already check the last Book
            return vectorBSHelper(vector, midItr, endItr, ((vectorSize - 2) / 2) - 1, searchValue);
        } else {
            return midItr.base(); // Return middle if midItr->getTitle().compare(searchValue) == 0
        }
    }
}

Book Library::findBook(std::string title) {
    if(title.compare("") == 0) {
        return Book("", "", 0, -1, 4);
    }

    int currSortingFunc = this->getSortingFunction(); // Get the original sorting order
    if(currSortingFunc != 1) {
        sortLibrary(1); // Alphabetical by Title
    }

    //  Perform a binary search
    Book* foundBookPtr = vectorBinarySearch(this->booksVector, this->booksVector.begin(), this->booksVector.size(), title);

    sortLibrary(currSortingFunc); // Restore to the original sorting order

    // If it's a nullptr (aka not found in the bookVector) return newly constructed Book with blank title and author
    // If it's not a nullptr (aka it WAS found in the bookVector) return the dereferenced Book pointer that was found
    if(foundBookPtr == nullptr) {
        return Book("", "", 0 , -1, 4);
    } else {
        return *foundBookPtr;
    }
}

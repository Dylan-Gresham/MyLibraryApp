//
// Library.cpp
// Created by Dylan Gresham on 8/26/23.
//

#include "Library.h"

#include <cstring>
using namespace std;

// Sorting functions
int sortAlphabeticalAuthor(Book& one, Book& two) {
    // Get Author names
    char oneFirstName[one.getAuthorFirstName().length() + 1];
    strncpy(oneFirstName, one.getAuthorFirstName().c_str(), one.getAuthorFirstName().length());
    char oneLastName[one.getAuthorLastName().length() + 1];
    strncpy(oneLastName, one.getAuthorLastName().c_str(), one.getAuthorLastName().length());

    char twoFirstName[two.getAuthorFirstName().length() + 1];
    strncpy(twoFirstName, two.getAuthorFirstName().c_str(), two.getAuthorFirstName().length());
    char twoLastName[two.getAuthorLastName().length() + 1];
    strncpy(twoLastName, two.getAuthorLastName().c_str(), two.getAuthorLastName().length());

    // Check if last names are equal:
    int lastNameCompare = strcasecmp(oneLastName, twoLastName);

    // Determine return value
    if(lastNameCompare == 0) { // If one.last() == two.last(), check first names
        // Check if first names are equal:
        int firstNameCompare = strcasecmp(oneFirstName, twoFirstName);

        // Determine return value
        if(firstNameCompare == 0) { // If one.first() == two.first()
            return 0;
        } else if(firstNameCompare < 0) { // If one.first() < two.first()
            return -1;
        } else { // If one.first() > two.first()
            return 1;
        }
    } else if(lastNameCompare > 0) { // If one.last() > two.last()
        return 1;
    } else { // If one.last() < two.last()
        return -1;
    }
}

int sortAlphabeticalTitle(Book one, Book two) {
    if(strcasecmp(one.getTitle().c_str(), two.getTitle().c_str()) > 0) {
        return 1;
    } else if(strcasecmp(one.getTitle().c_str(), two.getTitle().c_str()) < 0) {
        return -1;
    } else {
        return 0;
    }
}

int reverseSortAlphabeticalAuthor(Book one, Book two) {
    // Get Author names
    char oneFirstName[one.getAuthorFirstName().length() + 1];
    strncpy(oneFirstName, one.getAuthorFirstName().c_str(), one.getAuthorFirstName().length());
    char oneLastName[one.getAuthorLastName().length() + 1];
    strncpy(oneLastName, one.getAuthorLastName().c_str(), one.getAuthorLastName().length());

    char twoFirstName[two.getAuthorFirstName().length() + 1];
    strncpy(twoFirstName, two.getAuthorFirstName().c_str(), two.getAuthorFirstName().length());
    char twoLastName[two.getAuthorLastName().length() + 1];
    strncpy(twoLastName, two.getAuthorLastName().c_str(), two.getAuthorLastName().length());

    // Check if last names are equal:
    int lastNameCompare = strcasecmp(oneLastName, twoLastName);

    // Determine return value
    if(lastNameCompare == 0) { // If one.last() == two.last(), check first names
        // Check if first names are equal:
        int firstNameCompare = strcasecmp(oneFirstName, twoFirstName);

        // Determine return value
        if(firstNameCompare == 0) { // If one.first() == two.first()
            return 0;
        } else if(firstNameCompare < 0) { // If one.first() < two.first()
            return -1;
        } else { // If one.first() > two.first()
            return 1;
        }
    } else if(lastNameCompare > 0) { // If one.last() > two.last()
        return 1;
    } else { // If one.last() < two.last()
        return -1;
    }
}


int reverseSortAlphabeticalTitle(Book one, Book two) {
    if(strcasecmp(one.getTitle().c_str(), two.getTitle().c_str()) > 0) {
        return -1;
    } else if(strcasecmp(one.getTitle().c_str(), two.getTitle().c_str()) < 0) {
        return 1;
    } else {
        return 0;
    }
}

int sortDescendingNumPages(Book one, Book two) {
    if(one.getNumPages() > two.getNumPages()) {
        return 1;
    } else if(one.getNumPages() < two.getNumPages()) {
        return -1;
    } else {
        return 0;
    }
}

int sortDescendingRating(Book one, Book two) {
    if(one.getRating() > two.getRating()) {
        return 1;
    } else if(one.getRating() < two.getRating()) {
        return -1;
    } else {
        return 0;
    }
}

int sortAscendingNumPages(Book one, Book two) {
    if(one.getNumPages() > two.getNumPages()) {
        return -1;
    } else if(one.getNumPages() < two.getNumPages()) {
        return 1;
    } else {
        return 0;
    }
}

int sortAscendingRating(Book one, Book two) {
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

void Library::addBook(std::string title, std::string authorFirstName, std::string authorLastName, int numPages, int rating, int status) {
    Book newBook = Book(title, authorFirstName, authorLastName, numPages, rating, status);
    this->booksVector.push_back(newBook);
    this->numBooks++;

    /*
     *  According to
     *  https://stackoverflow.com/questions/72841438/how-to-store-array-data-as-map-key-or-increment-frequency-if-array-already-in-ma
     *  if you just use the increment operator on a map key it'll increment it if it's in the map
     *  and if it isn't in the map it adds it with default value of 0 and then increments it
     *  to 1 which is exactly what I want to do. TODO: Will need to test this.
     */
    this->authorsMap[title]++;
    this->numAuthors = this->authorsMap.size();

    if(this->booksVector.size() >= 2) {
        sortLibrary();
    }

    return;
}

int Library::deleteBook(std::string title) {
    std::vector<Book>::iterator currItr = this->booksVector.begin();
    std::vector<Book>::iterator endItr = this->booksVector.end();

    while(currItr.base() != endItr.base()) { // While the current iterator isn't pointing to the last Book
        if(currItr->getTitle().compare(title) == 0) { // If the Book is found
            this->booksVector.erase(currItr); // Erase it
            this->numBooks--;
            return 0; // Stop looking and return success
        } else { // If the Book isn't found yet
            advance(currItr, 1); // Advance to the next index
        }
    }

    return -1; // Book wasn't found, return fail
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
        return std::sort(this->booksVector.begin(), this->booksVector.end(), sortAlphabeticalAuthor);
    } else if(this->sortFunction == 1) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), sortAlphabeticalTitle);
    } else if(this->sortFunction == 2) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), reverseSortAlphabeticalAuthor);
    } else if(this->sortFunction == 3) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), reverseSortAlphabeticalTitle);
    } else if(this->sortFunction == 4) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), sortDescendingNumPages);
    } else if(this->sortFunction == 5) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), sortDescendingRating);
    } else if(this->sortFunction == 6) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), sortAscendingNumPages);
    } else {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), sortAscendingRating);
    }
}

void Library::sortLibrary(int sortFunction) {
    if(this->numBooks < 2) {
        return;
    }

    if(sortFunction < 0 || sortFunction > 7) {
        return;
    } else if(sortFunction == 0) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), sortAlphabeticalAuthor);
    } else if(sortFunction == 1) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), sortAlphabeticalTitle);
    } else if(sortFunction == 2) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), reverseSortAlphabeticalAuthor);
    } else if(sortFunction == 3) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), reverseSortAlphabeticalTitle);
    } else if(sortFunction == 4) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), sortDescendingNumPages);
    } else if(sortFunction == 5) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), sortDescendingRating);
    } else if(sortFunction == 6) {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), sortAscendingNumPages);
    } else {
        return std::sort(this->booksVector.begin(), this->booksVector.end(), sortAscendingRating);
    }
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
    if(strcasecmp(startItr->getTitle().c_str(), searchValue.c_str()) == 0) { // If it's the first Book
        return startItr.base();
    } else if(strcasecmp(endItr->getTitle().c_str(), searchValue.c_str()) == 0) { // If it's the last Book
        return endItr.base();
    } else if(vectorSize <= 2) { // If it's not the first or last Book but there's only 2 Books left to search through
        return nullptr;
    } else { // If it's between the first and last Book and the vectorSize is greater than 2
        advance(startItr, 1); // Already checked first index so move iterator past it

        // Get an iterator for the middle Book
        std::vector<Book>::iterator midItr = vector.begin();
        advance(midItr, (vectorSize - 2) / 2); // - 2 on the vectorSize since we already checked the first and last books

        if(strcasecmp(midItr->getTitle().c_str(), searchValue.c_str()) > 0) {
            // If the middle Book is greater (alphabetically comes after), only search from the starItr --> midItr
            return vectorBSHelper(vector, startItr, midItr, (vectorSize - 2) / 2, searchValue);
        } else if(strcasecmp(midItr->getTitle().c_str(), searchValue.c_str()) < 0) {
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
    if(strcasecmp(startItr->getTitle().c_str(), searchValue.c_str()) == 0) { // If it's the first Book
        return startItr.base();
    } else if(strcasecmp(vector.end()->getTitle().c_str(), searchValue.c_str()) == 0) { // If it's the last Book
        return vector.end().base();
    } else if(vector.size() <= 2) {
        return nullptr;
    } else { // If it's somewhere between the first and last Books and the size of the vector is greater than 2:
        advance(startItr, 1); // Already checked first index so move iterator past it

        // Get an iterator for the middle Book
        std::vector<Book>::iterator midItr = vector.begin();
        advance(midItr, (vectorSize - 2) / 2); // - 2 on the vectorSize since we already checked the first and last books

        if(strcasecmp(midItr->getTitle().c_str(), searchValue.c_str()) > 0) {
            // If the middle Book is greater (alphabetically comes after), only search from the starItr --> midItr
            return vectorBSHelper(vector, startItr, midItr, (vectorSize - 2) / 2, searchValue);
        } else if(strcasecmp(midItr->getTitle().c_str(), searchValue.c_str()) < 0) {
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
        return Book("", "", "", 0, -1, 4);
    }

    int currSortingFunc = this->getSortingFunction(); // Get the original sorting order
    if(currSortingFunc != 1) {
        // Sort if the booksVector has at least 2 Books in it
        if(this->booksVector.size() >= 2) {
            sortLibrary(1); // Alphabetical by Title
        }
    }

    //  Perform a binary search
    Book* foundBookPtr = vectorBinarySearch(this->booksVector, this->booksVector.begin(), this->booksVector.size(), title);

    sortLibrary(currSortingFunc); // Restore to the original sorting order

    // If it's a nullptr (aka not found in the bookVector) return newly constructed Book with blank title and author
    // If it's not a nullptr (aka it WAS found in the bookVector) return the dereferenced Book pointer that was found
    if(foundBookPtr == nullptr) {
        return Book("", "", "", 0 , -1, 4);
    } else {
        return *foundBookPtr;
    }
}

//
// Library.cpp
// Created by Dylan Gresham on 8/26/23.
//

#include "Library.h"
using namespace std;

Library::Library() {
    this->numBooks = 0;
    this->numAuthors = 0;
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

bool Library::isEmpty() {
    return (this->booksVector.size() == 0);
}

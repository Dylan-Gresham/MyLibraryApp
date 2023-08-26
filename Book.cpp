//
// Created by Dylan Gresham on 8/25/23.
//

#include "Book.h"

Book::Book(std::string title, std::string author, int numPages, int rating, int status) {
    this->title = title;
    this->author = author;
    this->numPages = numPages;
    this->rating = rating;
    this->status = status;
}

std::string Book::GetTitle() {
    return this->title;
}

std::string Book::GetAuthor() {
    return this->author;
}

int Book::GetNumPages() {
    return this->numPages;
}

int Book::GetRating() {
    return this->rating;
}

int Book::GetReadingStatus() {
    return this->status;
}

int Book::SetTitle(std::string newTitle) {
    this->title = newTitle;

    return 0;
}

int Book::SetAuthor(std::string newAuthor) {
    this->author = newAuthor;

    return 0;
}

int Book::SetNumPages(int newNumPages) {
    this->numPages = newNumPages;

    return 0;
}

int Book::SetRating(int newRating) {
    this->rating = newRating;

    return 0;
}

int Book::SetStatus(int newStatus) {
    this->status = newStatus;

    return 0;
}

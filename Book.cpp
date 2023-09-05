//
// Book.cpp
// Created by Dylan Gresham on 8/25/23.
//

#include "Book.h"

Book::Book(std::string title, std::string authorFirstName, std::string authorLastName, int numPages, int rating, int status) {
    this->title = title;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
    this->numPages = numPages;
    this->rating = rating;
    this->status = status;
}

std::string Book::getTitle() {
    return this->title;
}

std::string Book::getAuthor() {
    return this->authorFirstName + " " + this->authorLastName;
}

std::string Book::getAuthorFirstName() {
    return this->authorFirstName;
}

std::string Book::getAuthorLastName() {
    return this->authorFirstName;
}

int Book::getNumPages() {
    return this->numPages;
}

int Book::getRating() {
    return this->rating;
}

int Book::getReadingStatus() {
    return this->status;
}

std::string Book::statusToStr() {
    if(this->status == 0) {
        return "Plan to Read";
    } else if(this->status == 1) {
        return "Reading";
    } else if(this->status == 2) {
        return "Completed";
    } else if(this->status == 3) {
        return "Aside";
    } else if(this->status == 4) {
        return "Dropped";
    } else {
        return "Unknown";
    }
}

std::string Book::statusToStr(int status) {
    if(status == 0) {
        return "Plan to Read";
    } else if(status == 1) {
        return "Reading";
    } else if(status == 2) {
        return "Completed";
    } else if(status == 3) {
        return "Aside";
    } else if(status == 4) {
        return "Dropped";
    } else {
        return "Unknown";
    }
}

void Book::setTitle(std::string newTitle) {
    this->title = newTitle;
}

void Book::setAuthorFirstName(std::string newAuthorFirstName) {
    this->authorFirstName = newAuthorFirstName;
}

void Book::setAuthorLastName(std::string newAuthorLastName) {
    this->authorLastName = newAuthorLastName;
}

void Book::setNumPages(int newNumPages) {
    this->numPages = newNumPages;
}

void Book::setRating(int newRating) {
    this->rating = newRating;
}

void Book::setStatus(int newStatus) {
    this->status = newStatus;
}

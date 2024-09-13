#include <iostream>
#include <string>
using namespace std;

class Book{
private:
    string title;
    string author;
    int publicationYear;

public:
    Book(string title, string author, int publicationYear){
        this->title = title;
        this->author = author;
        this->publicationYear = publicationYear;
    }

    void getBookDetails(){
        cout << "Title: " << title << ", Author: " << author << ", Publication Year: " << publicationYear << endl;
    }

    void updatePublicationYear(int newYear){
        publicationYear = newYear;
        cout << "Updated Publication Year: " << publicationYear << endl;
    }
};

class BookStore{
private:
    string storeName;
    string location;
    int totalBooksInStock;

public:
    BookStore(string storeName, string location, int totalBooksInStock){
        this->storeName = storeName;
        this->location = location;
        this->totalBooksInStock = totalBooksInStock;
    }

    void getStoreDetails(){
        cout << "Book Store: " << storeName << ", Location: " << location << ", Total Books in Stock: " << totalBooksInStock << endl;
    }

    void updateTotalBooksInStock(int newTotal){
        totalBooksInStock = newTotal;
        cout << "Updated Total Books in Stock: " << totalBooksInStock << endl;
    }
};

int main(){
    
    Book books[3] = {
        Book("Ikigai", "Hector Garcia and Francesc Miralles", 2017),
        Book("Atomic Habits", "James Clear", 2018),
        Book("Rich Dad Poor Dad", "Robert T. Kiyosaki and Sharon Lechter", 1997),
    };

    for (int i = 0; i < 3; i++) {
        books[i].getBookDetails();
    };

    BookStore stores[3] = {
        BookStore("Book Haven", "456 Elm St", 5000),
        BookStore("Readers' Corner", "789 Maple Ave", 3500),
        BookStore("Page Turners", "123 Oak Blvd", 4200),
    };

    for (int i = 0; i < 3; i++) {
        stores[i].getStoreDetails();
    };

    return 0;
}
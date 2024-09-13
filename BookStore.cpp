#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int publicationYear;

public:
    Book(string t, string a, int pYear) {
        title = t;
        author = a;
        publicationYear = pYear;
    }

    void getBookDetails() {
        cout << "Title: " << title << ", Author: " << author << ", Publication Year: " << publicationYear << endl;
    }

    void updatePublicationYear(int newYear) {
        publicationYear = newYear;
        cout << "Updated Publication Year: " << publicationYear << endl;
    }
};

class BookStore {
private:
    string storeName;
    string location;
    int totalBooksInStock;

public:
    BookStore(string sName, string loc, int total) {
        storeName = sName;
        location = loc;
        totalBooksInStock = total;
    }

    void getStoreDetails() {
        cout << "Book Store: " << storeName << ", Location: " << location << ", Total Books in Stock: " << totalBooksInStock << endl;
    }

    void updateTotalBooksInStock(int newTotal) {
        totalBooksInStock = newTotal;
        cout << "Updated Total Books in Stock: " << totalBooksInStock << endl;
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 1951);
    book1.getBookDetails();
    book1.updatePublicationYear(1952);

    BookStore store1("Book Haven", "456 Elm St", 5000);
    store1.getStoreDetails();
    store1.updateTotalBooksInStock(5200);

    return 0;
}
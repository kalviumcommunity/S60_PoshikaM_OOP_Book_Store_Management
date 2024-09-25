#include <iostream>
#include <string>
using namespace std;

class Book{
private:
    string title;
    string author;
    string genre;
    int publicationYear;

public:
    static int totalBooks;

    Book(){
        totalBooks++;
    }

    void setBookDetails(string title, string author, int publicationYear, string genre){
        this->title = title;
        this->author = author;
        this->genre = genre;
        this->publicationYear = publicationYear;
    }

    // Accessors (Getters)
    string getTitle(){
        return title;
    }

    string getAuthor(){
        return author;
    }

    string getGenre(){
        return genre;
    }

    int getPublicationYear(){
        return publicationYear;
    }

    void getBookDetails(){
        cout << "Title: " << getTitle() << ", Author: " << getAuthor() << ", Publication Year: " << getPublicationYear() << ", Genre: " << getGenre() << endl;
    }

    void updatePublicationYear(int newYear){
        publicationYear = newYear;
        cout << "Updated Publication Year: " << getPublicationYear() << endl;
    }

    static int getTotalBooks(){
        return totalBooks;
    }
};

int Book::totalBooks = 0;

class BookStore{
private:
    string storeName;
    string location;
    int totalBooksInStock;
    string owner;

public:
    static int totalStores;

    BookStore(){
        totalStores++;
    }

    void setStoreDetails(string storeName, string location, int totalBooksInStock, string owner) {
        this->storeName = storeName;
        this->location = location;
        this->totalBooksInStock = totalBooksInStock;
        this->owner = owner;
    }

    // Accessors (Getters)
    string getStoreName() {
        return storeName;
    }

    string getLocation() {
        return location;
    }

    int getTotalBooksInStock() {
        return totalBooksInStock;
    }

    string getOwner(){
        return owner;
    }

    void getStoreDetails(){
        cout << "Book Store: " << getStoreName() << ", Location: " << getLocation() << ", Total Books in Stock: " << getTotalBooksInStock() << ", Owner: " << getOwner() << endl;
    }

    void updateTotalBooksInStock(int newTotal){
        totalBooksInStock = newTotal;
        cout << "Updated Total Books in Stock: " << getTotalBooksInStock() << endl;
    }

    static int getTotalStores(){
        return totalStores;
    }
};

int BookStore::totalStores = 0;

int main(){
    
    Book books[3];
    books[0].setBookDetails("Ikigai", "Hector Garcia and Francesc Miralles", 2017, "Self-help");
    books[1].setBookDetails("Atomic Habits", "James Clear", 2018, "Self-help");
    books[2].setBookDetails("Rich Dad Poor Dad", "Robert T. Kiyosaki and Sharon Lechter", 1997, "Finance");

    for (int i = 0; i < 3; i++) {
        books[i].getBookDetails();
    };

    cout << "Total Books Created : " << Book::getTotalBooks() << endl;

    BookStore stores[3];
    stores[0].setStoreDetails("Book Haven", "456 Elm St", 5000, "Alice Johnson");
    stores[1].setStoreDetails("Readers' Corner", "789 Maple Ave", 3500, "Bob Smith");
    stores[2].setStoreDetails("Page Turners", "123 Oak Blvd", 4200, "Charlie Brown");

    for (int i = 0; i < 3; i++) {
        stores[i].getStoreDetails();
    };

    cout << "Total Book Stores Created : " << BookStore::getTotalStores() << endl;

    return 0;
}
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

    // Default constructor
    Book(){
        totalBooks++;
    }

    // Parameterized constructor
    Book(string title, string author, int publicationYear, string genre) {
        this->title = title;
        this->author = author;
        this->genre = genre;
        this->publicationYear = publicationYear;
        totalBooks++;
    }

    // Destructor
    ~Book() {
        totalBooks--;
        cout << "Book '" << title << "' destroyed." << endl;
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

    // Default constructor
    BookStore(){
        totalStores++;
    }

    // Parameterized constructor
    BookStore(string storeName, string location, int totalBooksInStock, string owner) {
        this->storeName = storeName;
        this->location = location;
        this->totalBooksInStock = totalBooksInStock;
        this->owner = owner;
        totalStores++;
    }

    // Destructor
    ~BookStore() {
        totalStores--;
        cout << "Book Store '" << storeName << "' destroyed." << endl;
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
    
    // Using parameterized constructor
    Book book[3] = {
        Book("Ikigai", "Hector Garcia and Francesc Miralles", 2017, "Self-help"),
        Book("Atomic Habits", "James Clear", 2018, "Self-help"),
        Book("Rich Dad Poor Dad", "Robert T. Kiyosaki and Sharon Lechter", 1997, "Finance")
    };

    for (int i = 0; i < 3; i++) {
        book[i].getBookDetails();
    };

    cout << "Total Books Created : " << Book::getTotalBooks() << endl;

    // Using parameterized constructor
    BookStore stores[3] = {
        BookStore("Book Haven", "456 Elm St", 5000, "Alice Johnson"),
        BookStore("Readers' Corner", "789 Maple Ave", 3500, "Bob Smith"),
        BookStore("Page Turners", "123 Oak Blvd", 4200, "Charlie Brown")
    };

    for (int i = 0; i < 3; i++) {
        stores[i].getStoreDetails();
    };

    cout << "Total Book Stores Created : " << BookStore::getTotalStores() << endl;

    return 0;
}
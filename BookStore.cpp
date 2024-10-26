#include <iostream>
#include <string>
using namespace std;

// Abstract class
class Entity {
protected:
    string name;
    string location;

public:
    Entity() {}
    Entity(string name, string location) {
        this->name = name;
        this->location = location;
    }

    string getName() {
        return name;
    }

    string getLocation() {
        return location;
    }

    // Pure virtual function making this class abstract
    virtual void displayDetails() = 0; // Must be implemented by derived classes
};

class Book : public Entity {
private:
    string author;
    string genre;
    int publicationYear;

public:
    static int totalBooks;

    // Default constructor
    Book() {
        totalBooks++;
    }

    // Parameterized constructor
    Book(string title, string author, int publicationYear, string genre) : Entity(title, "") {
        this->author = author;
        this->genre = genre;
        this->publicationYear = publicationYear;
        totalBooks++;
    }

    // Destructor
    ~Book() {
        totalBooks--;
        cout << "Book '" << getName() << "' destroyed." << endl;
    }

    // Accessors (Getters)
    string getAuthor() {
        return author;
    }

    string getGenre() {
        return genre;
    }

    int getPublicationYear() {
        return publicationYear;
    }

    // Overriding displayDetails from Entity
    void displayDetails() override {
        cout << "Title: " << getName() << ", Author: " << getAuthor()
             << ", Publication Year: " << getPublicationYear()
             << ", Genre: " << getGenre() << endl;
    }

    void updatePublicationYear(int newYear) {
        publicationYear = newYear;
        cout << "Updated Publication Year: " << getPublicationYear() << endl;
    }

    static int getTotalBooks() {
        return totalBooks;
    }
};

int Book::totalBooks = 0;

class BookStore : public Entity {
private:
    int totalBooksInStock;
    string owner;

public:
    static int totalStores;

    // Default constructor
    BookStore() {
        totalStores++;
    }

    // Parameterized constructor
    BookStore(string storeName, string location, int totalBooksInStock, string owner) : Entity(storeName, location) {
        this->totalBooksInStock = totalBooksInStock;
        this->owner = owner;
        totalStores++;
    }

    // Destructor
    ~BookStore() {
        totalStores--;
        cout << "Book Store '" << name << "' destroyed." << endl;
    }

    // Accessors (Getters)
    int getTotalBooksInStock() {
        return totalBooksInStock;
    }

    string getOwner() {
        return owner;
    }

    // Overriding displayDetails from Entity
    void displayDetails() override {
        cout << "Book Store: " << getName() << ", Location: " << getLocation()
             << ", Total Books in Stock: " << getTotalBooksInStock()
             << ", Owner: " << getOwner() << endl;
    }

    void updateTotalBooksInStock(int newTotal) {
        totalBooksInStock = newTotal;
        cout << "Updated Total Books in Stock: " << getTotalBooksInStock() << endl;
    }

    static int getTotalStores() {
        return totalStores;
    }
};

int BookStore::totalStores = 0;

int main() {
    // Using parameterized constructor to create Book objects
    Book book[3] = {
        Book("Ikigai", "Hector Garcia and Francesc Miralles", 2017, "Self-help"),
        Book("Atomic Habits", "James Clear", 2018, "Self-help"),
        Book("Rich Dad Poor Dad", "Robert T. Kiyosaki and Sharon Lechter", 1997, "Finance")
    };

    // Display details of each book
    for (int i = 0; i < 3; i++) {
        book[i].displayDetails();
    }

    cout << "Total Books Created: " << Book::getTotalBooks() << endl;

    // Using parameterized constructor to create BookStore objects
    BookStore stores[3] = {
        BookStore("Book Haven", "456 Elm St", 5000, "Alice Johnson"),
        BookStore("Readers' Corner", "789 Maple Ave", 3500, "Bob Smith"),
        BookStore("Page Turners", "123 Oak Blvd", 4200, "Charlie Brown")
    };

    // Display details of each bookstore
    for (int i = 0; i < 3; i++) {
        stores[i].displayDetails();
    }

    cout << "Total Book Stores Created: " << BookStore::getTotalStores() << endl;

    return 0;
}
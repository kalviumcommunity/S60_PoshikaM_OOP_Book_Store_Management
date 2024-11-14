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
    virtual void displayDetails() = 0; // Abstract display function
};

// Separate class to handle display of book details
class BookDisplay {
public:
    static void display(class Book &book);
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

    // Use BookDisplay class for displaying details
    void displayDetails() override {
        BookDisplay::display(*this);
    }

    void updatePublicationYear(int newYear) {
        publicationYear = newYear;
        cout << "Updated Publication Year: " << getPublicationYear() << endl;
    }

    static int getTotalBooks() {
        return totalBooks;
    }
};

void BookDisplay::display(Book &book) {
    cout << "Title: " << book.getName() << ", Author: " << book.getAuthor()
         << ", Publication Year: " << book.getPublicationYear()
         << ", Genre: " << book.getGenre() << endl;
}

int Book::totalBooks = 0;

// Separate class to handle display of bookstore details
class BookStoreDisplay {
public:
    static void display(class BookStore &store);
};

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

    // Use BookStoreDisplay class for displaying details
    void displayDetails() override {
        BookStoreDisplay::display(*this);
    }

    void updateTotalBooksInStock(int newTotal) {
        totalBooksInStock = newTotal;
        cout << "Updated Total Books in Stock: " << getTotalBooksInStock() << endl;
    }

    static int getTotalStores() {
        return totalStores;
    }
};

void BookStoreDisplay::display(BookStore &store) {
    cout << "Book Store: " << store.getName() << ", Location: " << store.getLocation()
         << ", Total Books in Stock: " << store.getTotalBooksInStock()
         << ", Owner: " << store.getOwner() << endl;
}

int BookStore::totalStores = 0;

// Extending with a Magazine Class
class Magazine : public Entity {
private:
    int issueNumber;
    string publisher;

public:
    Magazine(string title, int issueNumber, string publisher) : Entity(title, "") {
        this->issueNumber = issueNumber;
        this->publisher = publisher;
    }

    int getIssueNumber() {
        return issueNumber;
    }

    string getPublisher() {
        return publisher;
    }

    void displayDetails() override {
        cout << "Magazine: " << getName() << ", Issue: " << getIssueNumber()
             << ", Publisher: " << getPublisher() << endl;
    }
};

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

    Magazine mag("National Geographic", 202, "National Geographic Society");
    mag.displayDetails();

    return 0;
}
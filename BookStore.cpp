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

    virtual ~Entity() {}
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
    // Create a dynamic array of Entity pointers to hold all types of entities
    Entity* entities[6];

    // Create Book objects
    entities[0] = new Book("Ikigai", "Hector Garcia and Francesc Miralles", 2017, "Self-help");
    entities[1] = new Book("Atomic Habits", "James Clear", 2018, "Self-help");
    entities[2] = new Book("Rich Dad Poor Dad", "Robert T. Kiyosaki and Sharon Lechter", 1997, "Finance");

    // Create BookStore objects
    entities[3] = new BookStore("Book Haven", "456 Elm St", 5000, "Alice Johnson");
    entities[4] = new BookStore("Readers' Corner", "789 Maple Ave", 3500, "Bob Smith");

    // Create Magazine object
    entities[5] = new Magazine("National Geographic", 202, "National Geographic Society");

    // Display details of all entities
    for (int i = 0; i < 6; i++) {
        entities[i]->displayDetails();
    }

    // Clean up memory
    for (int i = 0; i < 6; i++) {
        delete entities[i];
    }

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    bool isBorrowed;

public:
    Book(std::string title, std::string author) : title(title), author(author), isBorrowed(false) {}

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    bool getIsBorrowed() const {
        return isBorrowed;
    }

    void setIsBorrowed(bool borrowed) {
        isBorrowed = borrowed;
    }
};

class Patron {
private:
    std::string name;
    int patronId;
    std::vector<Book*> borrowedBooks;

public:
    Patron(std::string name, int patronId) : name(name), patronId(patronId) {}

    std::string getName() const {
        return name;
    }

    int getPatronId() const {
        return patronId;
    }

    std::vector<Book*>& getBorrowedBooks() {
        return borrowedBooks;
    }

    void borrowBook(Book* book) {
        borrowedBooks.push_back(book);
        book->setIsBorrowed(true);
    }

    void returnBook(Book* book) {
        for (size_t i = 0; i < borrowedBooks.size(); i++) {
            if (borrowedBooks[i] == book) {
                borrowedBooks.erase(borrowedBooks.begin() + i);
                book->setIsBorrowed(false);
                std::cout << "Book returned successfully." << std::endl;
                return;
            }
        }
        std::cout << "Book not found in the patron's borrowed books." << std::endl;
    }
};

class Library {
private:
    std::vector<Book> books;
    std::vector<Patron> patrons;

public:
    void addBook(std::string title, std::string author) {
        Book newBook(title, author);
        books.push_back(newBook);
    }

    void addPatron(std::string name, int patronId) {
        Patron newPatron(name, patronId);
        patrons.push_back(newPatron);
    }

    Book* findBookByTitle(std::string title) {
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].getTitle() == title) {
                return &books[i];
            }
        }
        return nullptr;
    }

    Patron* findPatronById(int patronId) {
        for (size_t i = 0; i < patrons.size(); i++) {
            if (patrons[i].getPatronId() == patronId) {
                return &patrons[i];
            }
        }
        return nullptr;
    }
};

int main() {
    Library library;

    // Adding books to the library
    library.addBook("The Catcher in the Rye", "J.D. Salinger");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");
    library.addBook("Pride and Prejudice", "Jane Austen");

    // Adding patrons to the library
    library.addPatron("John Doe", 101);
    library.addPatron("Jane Smith", 102);
    library.addPatron("Michael Brown", 103);

    // Patron 101 borrows a book
    Patron* patron1 = library.findPatronById(101);
    Book* book1 = library.findBookByTitle("The Catcher in the Rye");
    patron1->borrowBook(book1);

    // Patron 102 borrows a book
    Patron* patron2 = library.findPatronById(102);
    Book* book2 = library.findBookByTitle("To Kill a Mockingbird");
    patron2->borrowBook(book2);

    // Patron 103 borrows a book
    Patron* patron3 = library.findPatronById(103);
    Book* book3 = library.findBookByTitle("1984");
    patron3->borrowBook(book3);

    // Patron 101 returns the book
    patron1->returnBook(book1);

    return 0;
}


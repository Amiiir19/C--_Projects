#include <iostream>
#include <vector>
class Book {
  std::string title;
  std::string author;
  unsigned int year;

public:
  Book(std::string mytitle, std::string myauthor, int myyear)
      : title(mytitle), author(myauthor), year(myyear) {}
  std::string getTitle() { return title; }
  std::string getAuthor() { return author; }
  unsigned int getYear() { return year; }
  void displayInfo() {
    std::cout << "Title: " << title << " , Author: " << author
              << " , Year: " << year << std::endl;
  }
};

class LibraryCatalog {
  std::vector<Book> books;

public:
  LibraryCatalog() = default;
  void addBook(std::string mytitle, std::string myauthor, int myyear) {
    Book book(mytitle, myauthor, myyear);
    books.emplace_back(book);
  }
  void searchByAuthor(std::string author) {
    for (auto v : books) {
      if (!(author.compare(v.getAuthor()))) {
        v.displayInfo();
        std::cout << "____________________________________" << std::endl;
      }
    }
  }
  void displayCatalog(void) {
    for (auto v : books) {
      v.displayInfo();
      std::cout << "____________________________________" << std::endl;
    }
  }
  ~LibraryCatalog() {}
};
int main() {
  LibraryCatalog lib;
  for (;;) {
    int choice = 0;
    std::cout << "____________________________________" << std::endl
              << "   Hello To Library " << std::endl
              << "   Keep your voice down " << std::endl
              << "____________________________________" << std::endl
              << "   Enter Your Choice " << std::endl;
    std::cout << "1- Add Book  " << std::endl
              << "2- Search By author" << std::endl
              << "3- Display the catalog" << std::endl
              << "4- EXIT" << std::endl
              << "____________________________________" << std::endl;
    std::cin >> choice;
    std::string title, author;
    int year;
    switch (choice) {
    case 1:
      std::cout << "Enter Book Title:";
      std::cin >> title;
      std::cout << "Enter Book Author:";
      std::cin >> author;
      std::cout << "Enter Book Year:";
      std::cin >> year;
      lib.addBook(title, author, year);
      break;
    case 2:
      std::cout << "Enter Book Author:";
      std::cout<< "____________________________________" << std::endl;
      std::cin >> author;
      lib.searchByAuthor(author);
      break;
    case 3:
      lib.displayCatalog();
      break;
    case 4:
      return 0;
    }
  }
}
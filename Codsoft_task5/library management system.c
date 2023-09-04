#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Book {
    public:
    string title;
    string author;
    string isb;
    bool ischeckedOut;
    time_t due;
    Book (string t, string a, string i) : title(t), author(a), isb(i), ischeckedOut(false), due(0) {}
};

class library {
    private:
    vector<Book> books;

    public:
    void addbook(string title, string author, string isb) {
        Book book (title, author, isb);
        books.push_back(book);
    }
    vector <Book> searchBooks(string query) {
        vector<Book> results;
        for (const Book& book : books) {
            if (book.title.find(query)!= string::npos||
                book.author.find(query)!= string::npos||
                book.isb.find(query)!= string::npos) {
                    results.push_back(book);
                }
        }
        return results;    
        }
        bool checkedOutBook(int index) {
            if (index >=0 && index <books.size() && !books[index].ischeckedOut) {
            books[index].ischeckedOut=true;
            time_t now= time(nullptr);
            books[index].due= now + 325;
            return true;
            }
            return false;
        }

        bool returnbook(int index) {
            if(index >= 0 && index <books.size() && books[index].ischeckedOut) {
                books[index].ischeckedOut=false;
                books[index].due=0;
                return true;
            }
            return false;
        }
    };

    int main() {
        library library;
        
        library.addbook("Drowning", "TJ Newman", "45677");
        library.addbook("Every Summer After", "Carley Fortune", "56478");
        library.addbook("The Two of Us", "Taylor Torres", "67536");
        library.addbook("One True Loves", "Taylor Jenkins Reid", "45423");
        library.addbook("Meet Me Halfway ", "Lillian James", "64537");

        while (true) {
            cout<<"Library Management System\n";
            cout<<"1. search a book\n";
            cout<<"2. check out book\n";
            cout<<"3. return book\n";
            cout<<"4. exit\n";
            cout<<"enter your choice";

            int choice;
            cin>> choice;

            switch(choice){
                case 1: {
                    cin.ignore();
                    cout<<"enter title, author or isb of the book to search";
                    string query;
                    getline(cin, query);
                    vector<Book> results= library.searchBooks(query);
                    if (results.empty()) {
                        cout <<"no such book\n";
                    }else {
                        cout<<"search results:\n";
                        for (size_t i=0; i< results.size(); ++i) {
                            cout<<i+1<<"."<<results[i].title<<"by"<< results[i].author <<" isb:" << results[i].isb<<"\n";
                        }
                    }
                    break;
                }
                case 2: {
                    cout<<"enter index of the book for check out:";
                    int index;
                    cin>> index;
                    bool success= library.checkedOutBook(index-1);
                    if(success) {
                        cout<<"book checked out\n";
                    }else {
                        cout<<"invalid book index or book already checked out\n";
                    }
                    break;
                }
                case 3: {
                     cout<<"enter index of the book for return:";
                    int index;
                    cin>> index;
                    bool success= library.checkedOutBook(index-1);
                    if(success) {
                        cout<<"book return successful\n";
                    }else {
			    cout<<"invalid book index or book not checked out\n";
                    }
                    break;
                }
                case 4:
                cout<<"exit\n";
                return 0;
                default:
                cout<<"invalid choice\n";
            }
        }
        return 0;
    }

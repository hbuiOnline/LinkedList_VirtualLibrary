//Han Bui
//ID#: 1858671
//COSC 2430 Data Structure
//Professor: Nouhad Rizk
//Homework 2

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "ArgumentManager.h"
using namespace std;


struct book{
    
    string book_id;
    string book_name;
    string author_name;
    book * next;
};

class Library{
    
private:
    book *head, *tail;
    
    
public:
    Library(){ head = NULL; tail = NULL;} //Constructor
    int count = 0;
    
    bool checkDuplicate(string value){
        
        book * current = head;
        
        while(current != nullptr){
            if (current->book_id == value){
                return true;
            }
            else{
                current = current-> next;
            }
        }
        return false;
        
    }
    
    
    
    void insertBeginning(string bookID , string bookName, string authorName){
        
        book *temp = new book;          //Create temp as the new node to copy data from struct point

        temp->book_id = bookID;         //Get the data from the old head to pass to the new node
        temp->book_name = bookName;
        temp->author_name = authorName; //Temp point to the next, and the next and assign head

        temp->next = head;
        head = temp;    //Assign temp to become the head
        
    }
    void insertEnd(string bookID, string bookName, string authorName){
        
        book *temp = new book;          //Create new node
        temp->book_id = bookID;
        temp->book_name = bookName;
        temp->author_name = authorName;
        temp->next = nullptr;
        
        if (head == nullptr){
            head = temp;
            tail = temp;
            temp = nullptr;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    void insertPos(int pos, string bookID, string bookName, string authorName)
    {
        book *previous = new book;
        book *current = new book;
        book *temp = new book;
        current = head;
        for(int i = 0; i < pos; i++)
        {
            previous = current;
            current = current->next;
        }
        temp->book_id = bookID;
        temp->book_name = bookName;
        temp->author_name = authorName;
        previous->next=temp;
        temp->next=current;
    }
    
    void removeBeginning(){
        book * temp = new book;
        temp = head;
        head = head->next;
        delete temp;
    }
    
    void removeEnd(){
        
        book *current=new book;
        book *previous=new book;
        current = head;
        while(current->next!=nullptr)
        {
            previous=current;
            current=current->next;
        }
        tail=previous;
        previous->next=nullptr;
        delete current;
    }
    
    
    void removeValue(string value){
        
        
        book * current = head;
        book * trail = nullptr;
        
        while(current!=nullptr){
            
            if(current->book_id == value|| current->book_name == value|| current->author_name == value)
            {
                if (current == head)
                {
                    head = head->next;
                    current = head;
                    trail = NULL;
                    count--;
                    continue;
                }
                
                else if(current->next == nullptr)
                {
                    trail->next = nullptr;
                    count--;
                    break;
                }
                
                else
                {
                    trail->next = current->next;
                    current = current->next;
                    count--;
                }
            }
            else
            {
                trail = current;
                current = current->next;
            }
        }
    }
    
    void removePos(int value){
        if(head == 0){
            cout << "Cannot delete an empty list" << endl;
        }
        else {
            
            book * prev = new book;
            book * curr = new book;
            curr = head;
            for (int i = 0; i < value; i++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
        }
        
    }
    
    void sortID(){
        string tempID, tempBook, tempAuthor;
        for (int i = 0; i < count ; i++){
            book * current = head;
            book * next = head->next;
            for (int j = 0; j < count-i-1; j++){
                if (current->book_id > next->book_id){
                    
                    tempID = current->book_id;
                    current->book_id = next->book_id;
                    next->book_id = tempID;
                    
                    tempBook = current->book_name;
                    current->book_name = next->book_name;
                    next->book_name = tempBook;
                    
                    tempAuthor = current->author_name;
                    current->author_name = next->author_name;
                    next->author_name = tempAuthor;
                }
                current = next;
                next = next->next;
            }
        }
    }
    void sortBookName(){
        string tempID, tempBook, tempAuthor;
        for (int i = 0; i < count; i++){
            book * current = head;
            book * next = head->next;
            for (int j = 0; j < count-i-1; j++){
                if (current->book_name > next->book_name){
                    
                    tempID = current->book_id;
                    current->book_id = next->book_id;
                    next->book_id = tempID;
                    
                    tempBook = current->book_name;
                    current->book_name = next->book_name;
                    next->book_name = tempBook;
                    
                    tempAuthor = current->author_name;
                    current->author_name = next->author_name;
                    next->author_name = tempAuthor;
                }
                current = next;
                next = next->next;
            }
        }
    }
    void sortAuthorName(){
        string tempID, tempBook, tempAuthor;
        for (int i = 0; i < count; i++){
            book * current = head;
            book * next = head->next;
            for (int j = 0; j < count-i-1; j++){
                if (current->author_name > next->author_name){
                    
                    tempID = current->book_id;
                    current->book_id = next->book_id;
                    next->book_id = tempID;
                    
                    tempBook = current->book_name;
                    current->book_name = next->book_name;
                    next->book_name = tempBook;
                    
                    tempAuthor = current->author_name;
                    current->author_name = next->author_name;
                    next->author_name = tempAuthor;
                }
                current = next;
                next = next->next;
            }
        }
    }
    
    
    void parsing(string inputFile){
        
        string dummy, bookID, bookName, authorName;
        fstream inFile;
        inFile.open(inputFile);
        if (!inFile.is_open()){
            cout << "Cannot open the file.\n";
        }
        
        while (!inFile.eof()){                          // While the string doesn't reach the end of line, continue reading.
            getline(inFile,dummy, ':');
            if(dummy.empty()) {break;}
            getline(inFile,bookID, ',');
            getline(inFile,dummy, ':');
            getline(inFile,bookName,',');
            getline(inFile,dummy, ':');
            getline(inFile,authorName);
            
            if(!checkDuplicate(bookID)){
                if (head == NULL){
                    book *first = new book;
                    first->book_id = bookID;
                    first->book_name = bookName;
                    first->author_name = authorName;
                    first->next = nullptr;
                    head = first;
                    tail = first;
                    count++;
                }
                else  {
                    insertEnd(bookID, bookName, authorName);
                    count++;
                }
            }
            
        }
    }
    
    void command(string inputFile){
        
        string line;
        int posNum = 0;
        string dummy, bookID, bookName, authorName, pos;
        
        fstream inFile;
        inFile.open(inputFile);
        if (!inFile.is_open()){
            cout << "Cannot open the file.\n";
        }
        
        while (!inFile.eof()){// While the string doesn't reach the end of line, continue reading.
            getline(inFile, line);
            
            if (line == "sort book_id" || line == "sort book_name" || line == "sort book_author"){
                
                if(line == "sort book_id")
                    sortID();
                else if (line == "sort book_name")
                    sortBookName();
                else if (line == "sort book_author")
                    sortAuthorName();
            }
            
            else {
                stringstream ss(line);
                getline(ss, line, ':');
                if (line == "add pos"){
                    getline(ss,pos, ' ');
                    posNum = stoi(pos);
                    getline(ss,dummy, ':');
                    getline(ss,bookID, ',');
                    getline(ss,dummy, ':');
                    getline(ss,bookName,',');
                    getline(ss,dummy, ':');
                    getline(ss,authorName);
                    
                    if(!checkDuplicate(bookID)){
                        if(posNum == 0){
                            insertBeginning(bookID, bookName, authorName);
                            count++;
                        }
                        else if (posNum > count || posNum < 0){
                            insertEnd(bookID, bookName, authorName);
                            count++;
                        }
                        else{
                            insertPos(posNum, bookID, bookName, authorName);
                            count++;
                        }
                    }
                    
                }
                //Remove
                else if (line == "remove pos" || line == "remove book_id" || line == "remove book_name" || line == "remove book_author" ){
                    
                    //Remove by position
                    if(line == "remove pos"){
                        getline(ss,pos);
                        posNum = stoi(pos);
                        
                        if (posNum == 0){
                            removeBeginning();
                        }
                        else if(posNum >= count){
                            continue;
                        }
                        else if (posNum == count){
                            removeEnd();
                        }
                        else{
                            removePos(posNum);
                        }
                    }
                    //Remove by values
                    else if (line == "remove book_id"){
                        getline(ss, bookID);
                        removeValue(bookID);
                    }
                    else if (line == "remove book_name"){
                        getline(ss, bookName);
                        removeValue(bookName);
                    }
                    else if (line == "remove book_author"){
                        getline(ss, authorName);
                        removeValue(authorName);
                    }
                    
                    
                }
            }
        }//EOL
    }
    //    }
    void print(){   //string outputFile
        
//        ofstream outFile;
//        outFile.open(outputFile);
//        if (outFile.fail()){
//            cout << "Cannot open the file.\n";
//        }
        
        book *temp=head;
        while(temp!=nullptr){
            cout << "book_id:"<< temp->book_id <<","<<"book_name:" << temp->book_name << "," <<"book_author:" << temp->author_name << endl ;
            temp=temp->next;
        }
//        outFile.close();
        
    }
    
};

int main(int argc, char * argv[]) {
    
    
    ArgumentManager am(argc, argv);
    const string inputFileName = am.get("input");
    const string commandLine = am.get("command");
    const string outputFileName = am.get("output");
    
    Library books;
    
    books.parsing(inputFileName);
    books.command(commandLine);
//    books.print(outputFileName);
    
    
//    books.parsing("input22.txt");
//    books.command("command22.txt");
    books.print();
    
    
    return 0;
}


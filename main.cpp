#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

class Book {
	private:
		string bookNumber,title,author,edition,publication; //private variables
	public:
		//setters - assigning user value to private variables
		void setIsbn(string a){bookNumber = a;}
		void setTitle(string b){title = b;}
		void setAuthor(string c){author = c;}
		void setEdition(string d){edition = d;}
		void setPublication(string e){publication = e;}
		//getters - getting the values from private variables
		string getIsbn(){return bookNumber;}
		string getTitle(){return title;}
		string getAuthor(){return author;}
		string getEdition(){return edition;}
		string getPublication(){return publication;}
};

//initializing functions with counter as parameter
void addBook(int counter);
void deleteBook(int counter);
void editBook(int counter);
void searchBook(int counter);
void viewAllBooks(int counter);
void quit();

//counter for Book array
int counter=0;

//function for incrementing counter
void increment(int a){
	a++;
	counter=a;
}

//function for decrementing counter
void decrement(int a){
	a--;
	counter=a;
}

//Book class array initialization
Book books[10];

class MyClass {        // The class
  public:              // Access specifier
    int myMethod();   // Method/function declaration
};


int MyClass::myMethod () {

	string username;
    string password;
    int loginattempt = 0;

    while (loginattempt < 3)
    {
        cout << "USERNAME: "; cin >> username;
        cout << "PASSWORD: "; cin >> password;

        if (username == "1" && password == "1")
            return 0;
        else
        {
            cout << "Invalid login attempt. Please try again."<<endl;
            loginattempt++;
        }
        system("cls");
    }
    
    if (loginattempt == 3)
    {
        return 1;
    }

}

//main function
int main(){
    system("COLOR B0");
	MyClass myObj;     // Create an object of MyClass
	
	if(myObj.myMethod()){// Call the method and use return value as condition to continue
	    cout << "Intruder Detected!";
	    return 0;
	}
	
    cout << "Thank you for logging in."<<endl;
	system("cls");
	
	// if you want to pause for few minutes then automatically proceed use sleep()
	sleep(5);
	
    //Main Menu
    
    string choice;
    cout<<"LIBRARY MANAGEMENT SYSTEM\n\n";
    cout<<"[1]ADD BOOK\n";
    cout<<"[2]DELETE BOOK\n";
    cout<<"[3]EDIT BOOK\n";
    cout<<"[4]SEARCH BOOK\n";
    cout<<"[5]VIEW ALL BOOKS\n";
    cout<<"[6]QUIT\n\n";
    
    cout<<"ENTER CHOICE: ";
    getline(cin,choice);
    system("CLS");
    
    switch(choice){
    case "1":
        addBook(counter); //function call
        break;
    case "2":
        deleteBook(counter); //function call
        break;
    case "3":
        editBook(counter); //function call
        break;
    case "4":
        searchBook(counter); //function call
        break;
    case "5":
        viewAllBooks(counter); //function call
        break;
    case "6":
        quit();	 //function call
        break;
    default:
        main();  //function call to self(main)
        break;
    }
    
    _getch();
    return 0;
}



//addBook function
void addBook(int counter){
	string bookNumber,title,author,edition,publication;
	cout<<"ADD BOOK\n\n";
	if(counter<10){
		cout<<"Enter Book No: ";
		getline(cin,bookNumber); //getline - just like cin but includes white spaces
		cout<<"Enter Title: ";
		getline(cin,title);
		cout<<"Enter Author: ";
		getline(cin,author);
		cout<<"Enter Edition: ";
		getline(cin,edition);
		cout<<"Enter Publication: ";
		getline(cin,publication);
		books[counter].setIsbn(bookNumber); //assigning the values entered to book object
		books[counter].setTitle(title);
		books[counter].setAuthor(author);
		books[counter].setEdition(edition);
		books[counter].setPublication(publication);
		increment(counter);	//calling function to increment counter
		cout<<"\nBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	else{
		cout<<"YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TO BE ADDED!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
}

//deleteBook function
void deleteBook(int counter){
	string bookNumber;
	int choice;
	cout<<"DELETE BOOK\n\n";
	if(counter==0){
		cout<<"THERE IS NO BOOK TO DELETE!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter Book No: ";
	getline(cin,bookNumber);

	for(int i=0;i<counter;i++){
		//finding a match using for loop
		if(books[i].getIsbn()==bookNumber){
			cout<<"\nBOOK FOUND\n\n";
			cout<<"Do you want to delete?\n[1]Yes\n[2]No\n\nEnter Choice: ";
			cin>>choice;
			if(choice==1){
				books[i].setIsbn(""); //setting the value to none
				books[i].setTitle("");
				books[i].setAuthor("");
				books[i].setEdition("");
				books[i].setPublication("");
				for(int a=i;a<counter;a++){
					//adjusting the values after deletion of data eg. data from book[4] copied to book[3]
					books[a] = books[a+1];
				}
				books[9].setIsbn(""); //adjustment if the library is full(10 books)
				books[9].setTitle("");
				books[9].setAuthor("");
				books[9].setEdition("");
				books[9].setPublication("");
				decrement(counter); //calling function to decrement counter
				cout<<"\nBOOK SUCCESSFULLY DELETED!\n\nPress any key to continue . . .";
				_getch();
				main();
			}
			else{
				main();
			}
		}
	}
	cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();

}
//Edit Book Function
void editBook(int counter){
	system("CLS");
	string editIsbn,choice;
	string bookNumber,title,author,edition,publication;
	cout<<"\nEDIT BOOK\n\n";
	if(counter==0){
		cout<<"THERE IS NO BOOK TO EDIT!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter Book No: ";
	getline(cin,editIsbn);
	for(int i=0;i<counter;i++){
		//finding a match using for loop
		if(books[i].getIsbn()==editIsbn){
			cout<<"\nBOOK FOUND!\n\n";
			cout<<"Book No: "<<books[i].getIsbn()<<endl;
			cout<<"TITLE: "<<books[i].getTitle()<<endl;
			cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
			cout<<"EDITION: "<<books[i].getEdition()<<endl;
			cout<<"PUBLICATION: "<<books[i].getPublication()<<endl;
			cout<<"\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
			getline(cin,choice);
			if(choice=="1"){
				//re-entering values
				cout<<"Enter Book No: ";
				getline(cin,bookNumber);
				cout<<"Enter Title: ";
				getline(cin,title);
				cout<<"Enter Author: ";
				getline(cin,author);
				cout<<"Enter Edition: ";
				getline(cin,edition);
				cout<<"Enter Publication: ";
				getline(cin,publication);
				books[i].setIsbn(bookNumber);
				books[i].setTitle(title);
				books[i].setAuthor(author);
				books[i].setEdition(edition);
				books[i].setPublication(publication);
				cout<<"\nBOOK EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
				_getch();
				editBook(counter);//function call to self
			}
			else{
				main();
			}
		}
}
	cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();
}
//Search Book Function
void searchBook(int counter){
	string bookNumber;
	int choice;
	bool print = false; //boolean expression to decide which to print
	cout<<"SEARCH BOOK\n\n";
	if(counter==0){
		cout<<"THERE IS NO BOOK TO SEARCH!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter Book No: ";
	getline(cin,bookNumber);
	for(int i=0;i<counter;i++){
		//finding a match using for loop
		if(books[i].getIsbn()==bookNumber){
			cout<<"\nBOOK FOUND!\n\n";
			cout<<"Book No: "<<books[i].getIsbn()<<endl;
			cout<<"TITLE: "<<books[i].getTitle()<<endl;
			cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
			cout<<"EDITION: "<<books[i].getEdition()<<endl;
			cout<<"PUBLICATION: "<<books[i].getPublication()<<endl;
			print = true;
		}
	}
	if(print){
		cout<<"\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	//if there's no book found
	else{
		cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
}
//View All Books Function
void viewAllBooks(int counter){
	//iterating all the values on the library using book array
	cout<<"VIEW ALL BOOKS\n\n";
	for(int i=0;i<counter;i++){
		cout<<"BOOK DETAILS\n\n";
		cout<<"Book No: "<<books[i].getIsbn()<<endl;
		cout<<"TITLE: "<<books[i].getTitle()<<endl;
		cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
		cout<<"EDITION: "<<books[i].getEdition()<<endl;
		cout<<"PUBLICATION: "<<books[i].getPublication()<<endl<<endl;
	}
	cout<<"Press any key to continue . . .";
	_getch();
	main();
}
void quit(){
	//quit function
	_exit(1);
}

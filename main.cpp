#include<iostream>
#include<conio.h>
#include<string>
#include <fstream>

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







    void LogIn()
    {
        string userName;
        string userPassword;
        int loginAttempt = 0;
        bool LogIn_Success = false;
        while (loginAttempt < 3)
    {
        system("cls");
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;


        if (userName == "admin" && userPassword == "admin1")
        {
            cout << "\n\nWelcome Librarian!\n\n";
            LogIn_Success=true;
            break;
        }

        else
        {
            cout << "\n\nInvalid login attempt. Please try again.\n\n" << '\n';
            loginAttempt++;
            system("pause");
        }
    }
    if (loginAttempt == 3)
    {
            cout << "\n\nToo many login attempts! The program will now terminate.\n\n";
            LogIn_Success = false;
    }

    cout << "\n\nThank you for logging in.\n\n";
     system("pause");

     LogIn_Success = true;
    }



//main function
int main(){
    system("COLOR B0");


    LogIn();


//Main Menu
Menu:
system("CLS");
string choice;
int pili;
cout<<"              ======================================================================================\n";
cout<<"              //                                 LIBRARY MANAGEMENT SYSTEM                        //\n              //                                                                                  //\n";
cout<<"              //                                 [1]ADD BOOK                                      //\n";
cout<<"              //                                 [2]DELETE BOOK                                   //\n";
cout<<"              //                                 [3]EDIT BOOK                                     //\n";
cout<<"              //                                 [4]SEARCH BOOK                                   //\n";
cout<<"              //                                 [5]VIEW ALL BOOKS                                //\n";
cout<<"              //                                 [6]QUIT                                          //\n";
cout<<"              ======================================================================================\n";
cout<<"                                                 ENTER CHOICE: ";
getline(cin,choice);
cout<<"              ======================================================================================\n";
system("CLS");

if(choice=="1"){
	addBook(counter); //function call

	cout << "\n\nPress 1 to go back to main menu\n\n";
	cout << "Press 2 to exit\n";
	cin>>choice;

	if(choice == "1")
    {
        goto Menu;
    }
	else{
        return 0;
	}
}
else if(choice=="2"){
	deleteBook(counter); //function call

	cout << "\n\nPress 1 to go back to main menu\n\n";
	cout << "Press 2 to exit\n";
	cin>>choice;

	if(choice == "1")
    {
        goto Menu;
    }
	else{
        return 0;
	}

}
else if(choice=="3"){
	editBook(counter); //function call

	cout << "\n\nPress 1 to go back to main menu\n\n";
	cout << "Press 2 to exit\n";
	cin>>choice;

	if(choice == "1")
    {
        goto Menu;
    }
	else{
        return 0;
	}

}
else if(choice=="4"){
	searchBook(counter); //function call

	cout << "\n\nPress 1 to go back to main menu\n\n";
	cout << "Press 2 to exit\n";
	cin>>choice;

	if(choice == "1")
    {
        goto Menu;
    }
	else{
        return 0;
	}

}
else if(choice=="5"){
	viewAllBooks(counter); //function call

	cout << "\n\nPress 1 to go back to main menu\n\n";
	cout << "Press 2 to exit\n";
	cin>>choice;

	if(choice == "1")
    {
        goto Menu;
    }
	else{
        return 0;
	}

}
else if(choice=="6"){
	quit();	 //function call

	cout << "\n\nPress 1 to go back to main menu\n\n";
	cout << "Press 2 to exit\n";
	cin>>choice;

	if(choice == "1")
    {
        goto Menu;
    }
	else{
        return 0;
	}

}
else{
	goto Menu;  //function call to self(main)
}

_getch();
return 0;

}


//addBook function
void addBook(int counter){
	string bookNumber,title,author,edition,publication;
	cout<<"                                                     ADD BOOK\n\n";
	if(counter<10){

        cout<<"              ======================================================================================\n";
		cout<<"                                                 Enter Book No: ";
		getline(cin,bookNumber); //getline - just like cin but includes white spaces
		cout<<"                                                 Enter Title: ";
		getline(cin,title);
		cout<<"                                                 Enter Author: ";
		getline(cin,author);
		cout<<"                                                 Enter Edition: ";
		getline(cin,edition);
		cout<<"                                                 Enter Publication: ";
		getline(cin,publication);
		cout<<"              ======================================================================================\n";

		books[counter].setIsbn(bookNumber); //assigning the values entered to book object
		books[counter].setTitle(title);
		books[counter].setAuthor(author);
		books[counter].setEdition(edition);
		books[counter].setPublication(publication);
		increment(counter);	//calling function to increment counter
		cout<<"\n                               BOOK ADDED SUCCESSFULLY!\n\n";
		_getch();

	}
	else{
            cout<<"              ======================================================================================\n";
            cout<<"              YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TO BE ADDED!\n\n";
            cout<<"              ======================================================================================\n";
		_getch();

	}
}
//deleteBook function
void deleteBook(int counter){
	string bookNumber;
	int choice;
	cout<<"                                                     DELETE BOOK\n\n";
	if(counter==0){
            cout<<"              ======================================================================================\n";
            cout<<"                             THERE IS NO BOOK TO DELETE!\n\n";
            cout<<"              ======================================================================================\n";
		_getch();

	}
	cout<<"                                                 Enter Book No: ";
	getline(cin,bookNumber);
	for(int i=0;i<counter;i++){
		//finding a match using for loop
		if(books[i].getIsbn()==bookNumber){
			cout<<"\n                                               BOOK FOUND\n\n";
			cout<<"                                                 Do you want to delete?\n                                                 [1]Yes\n                                                 [2]No\n\n                                                 Enter Choice: ";
			cin>>                                                   choice;
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
				cout<<"\n                                                 BOOK SUCCESSFULLY DELETED!\n\n";
				_getch();

			}
			else{

			}
		}
	}
	cout<<"\n                                               BOOK NOT FOUND!\n\n";
	_getch();

}
//Edit Book Function
void editBook(int counter){
	system("CLS");
	string editIsbn,choice;
	string bookNumber,title,author,edition,publication;
	cout<<"\nEDIT BOOK\n\n";
	if(counter==0){
		cout<<"THERE IS NO BOOK TO EDIT!\n\n";
		_getch();

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
				cout<<"\nBOOK EDITED SUCCESSFULLY!\n\n";
				_getch();
				editBook(counter);//function call to self
			}
			else{

			}
		}
}
	cout<<"\nBOOK NOT FOUND!\n\n";
	_getch();

}
//Search Book Function
void searchBook(int counter){
	string bookNumber;
	int choice;
	bool print = false; //boolean expression to decide which to print
	cout<<"SEARCH BOOK\n\n";
	if(counter==0){
		cout<<"THERE IS NO BOOK TO SEARCH!\n\n";
		_getch();

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
		cout<<"\n\n";
		_getch();

	}
	//if there's no book found
	else{
		cout<<"\nBOOK NOT FOUND!\n\n";
		_getch();

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
	cout<<"";
	_getch();

}
void quit(){
	//quit function
	_exit(1);
}

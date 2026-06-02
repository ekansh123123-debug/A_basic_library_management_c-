#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class User{
protected:
    string password,temp_password;
public:
    fstream book_file;
    string id;
    string nam ;
    string name; 
    string temp_username;
    string email ;
    string email_id;
    string temp_email_adress;
    string pass;
    string book;
    string auther;
    size_t mobile_no;
};
class Public : public User{
private:
fstream public_login_file;

public:
    void show_all_books(){
        cout << "---------------------------All Books--------------------------------------------------" << endl;
        cout << "\t" << "Book ID" << "\t\t" << "Book Name" << "\t\t\t" << "Auther Name" << endl;

        book_file.open("Book_list.txt" , ios :: in);

        while(getline(book_file,id,'*') && getline(book_file,book,'*') && getline(book_file,auther,'\n');){
            cout << "\t" << id << "\t\t" << book << "\t\t\t" << auther << endl;
        }
        cout << "---------------------------------------------------" << endl;
        return;
    }

    void choos_book(){
        string find_book;
        cout << "----------------------Liabrari--------------------" <<endl;
        cout << "Type book you want to read" << endl;
        cin.ignore();
        getline(cin,find_book);
        book_file.open("Book_list.txt",ios :: in);
        getline(book_file,id,'*');
        getline(book_file,book,'*');
        getline(book_file,auther,'\n');
        while(!book_file.eof()){
            if(find_book == id){
                cout << "Book opened:" <<endl;
                return;
            }
            getline(book_file,id,'*');
            getline(book_file,book,'*');
            getline(book_file,auther,'\n');
        }
        book_file.close();
        return;
    }
    void login(){
        cout << "----------------------Login------------------------" <<endl;
        cout << "Enter your Name : " ;
        getline(cin,nam);
         cout << "Enter your Email Id : " ;
        getline(cin,email);
         cout << "Enter your Password : " ;
        getline(cin,pass);
        public_login_file.open("Public_logins.txt" , ios::in);
        getline(public_login_file,name,'*');
        getline(public_login_file,email_id,'*');
        getline(public_login_file,password,'\n');
        while(!public_login_file.eof()){
            if(!(nam == name)){
                getline(public_login_file,name,'*');
                getline(public_login_file,email_id,'*');
                getline(public_login_file,password,'\n');
                continue;
            }
            if(!(email_id == email)){
                cout << "Email not found " << endl;
                break;
            }
            if(!(pass == password)){
                cout << "Incorect password " <<endl;
                break;
            }
            show_all_books();
            choos_book();
            return;
        }
        public_login_file.close();
        cout<<"Could not find id " << endl << endl << "Pleas try again " << endl;
        login();
        return;
    }
    void registe(){
        cout << "----------------Register-------------------" << endl;
        cout << "Enter username : ";
        getline(cin, temp_username);
        cout << "Enter email adress : ";
        getline(cin, temp_email_adress);
        cout << "Enter password : ";
        getline(cin, temp_password);
        public_login_file.open("Public_logins.txt", ios ::out | ios::app);
        public_login_file << temp_username << "*" << temp_email_adress << "*" << temp_password << endl;
        public_login_file.close();
        cout << "Registration Sucessfull" << endl;
        return;
    }
    
}Pub;
class Admin : public User{
private:
    fstream Admin_login_file;
public:
    void remove_book(){}
    void add_book(){
        cout << "--------------------------------------------------" <<endl;
        cout << "Enter book id :: " ;
        cin >> id;
        cout << "Enter book name :: " ;
        cin.ignore();
        getline(cin, book);
        cout << "Enter book's Auther name ::";
        getline(cin,auther);
        book_file.open("Book_list.txt",ios :: out | ios :: app);
        book_file << id << "*" << book << "*" << auther << endl;
        book_file.close();
        return;
    }
    void menu(){
        cout << "-------------------------Libery Admin Section-------------------------------" << endl;
        cout << "Enter what you want to do " << endl;
        cout << "1. Add New book " << endl;
        cout << "2. Remove Book " << endl;
        cout << "3. Exit " << endl;
        char choise;
        cin>> choise;
        switch(choise){
            case '1':
                add_book();
                menu();
                return;
            case '2':
                remove_book();
                menu();
                return;
            case '3':
                return;
            default:
                cout << "Invalid opration " << endl << endl << "Try again" << endl;
                menu();
                return;
        }
        return;
    }
    void login(){
        cout << "----------------------------" <<endl;
        cout << "Enter your Name : " ;
        getline(cin,nam);
         cout << "Enter your Email Id : " ;
        getline(cin,email);
         cout << "Enter your Password : " ;
        getline(cin,pass);
        Admin_login_file.open("Admin_logins.txt" , ios::in);
        getline(Admin_login_file,name,'*');
        getline(Admin_login_file,email_id,'*');
        getline(Admin_login_file,password,'\n');
        while(!Admin_login_file.eof()){
            if(!(nam == name)){
                getline(Admin_login_file,name,'*');
                getline(Admin_login_file,email_id,'*');
                getline(Admin_login_file,password,'\n');
                continue;
            }
            if(!(email_id == email)){
                cout << "Incorrect password" << endl << endl << "Try again "<< endl;
                login();
                return;
            }
            if(!(pass == password)){
                cout << "Incorect password " <<endl << endl << "Try again" << endl;
                login();
                return;
            }
            menu();
            return;
        }
        Admin_login_file.close();
        cout << "Could not find id try again" << endl;
        login();
        return;
    }
    void registe(){
        cout << "Enter username : ";
        getline(cin, temp_username);
        cout << "Enter email adress : ";
        getline(cin, temp_email_adress);
        cout << "Enter password : ";
        getline(cin, temp_password);
        Admin_login_file.open("Admin_logins.txt", ios ::out | ios::app);
        Admin_login_file << temp_username << "*" << temp_email_adress << "*" << temp_password << endl;
        Admin_login_file.close();
        cout << "Registration Sucessfull" << endl;
        Admin_login_file.close();
        return;
    }
}Adm;
void regis(){
    while(true){
        cout << "------------------------" <<endl;
        cout << "1. Login as new user" <<endl;
        cout << "2. New Admin register" << endl;
        cout << "3. Return " << endl;
        char ch;
        cin >> ch;
        switch (ch){
            case '1':
                cin.ignore();
                Pub.registe();
                return;
            case '2':
                cin.ignore();
                Adm.registe();
                return;
            case '3':
                cin.ignore();
                return;
            default:
                cout << "Invalid opration"<< endl;
                regis();
                break;
        }
    }
    return;
}
void login_menu(){
    while(true)
    {
        cout << "--------Labriry Management-----------" <<endl;
        cout << "1. Enter as Student" << endl;
        cout << "2. Enter as Teacher" << endl;
        cout << "3. Register" << endl;
        cout << "4. Exit" << endl;
        char ch;
        cin >> ch;
        switch(ch){
            case '1':
                cin.ignore();
                Pub.login();
            case '2':
                cin.ignore();
                Adm.login();
            case '3':
                cin.ignore();
                regis();
            case '4':
                return;
            default:
                cout << "Incorrect input " << endl;
                cout << "Try again" << endl;
        } 
    }
    return;
}
int main(){
    login_menu();
    return 0;   
}
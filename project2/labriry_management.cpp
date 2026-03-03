#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class User{
protected:
    string password,fpassword;
public:
    fstream book_file;
    string nam ;
    string email ;
    string fusername;
    string femail_adress;
    string name; 
    string pass;
    string book;
    string auther;
    string id;
    long long mobile_no;
    string email_id;
};
class Public : public User{
private:
fstream Pub_file;

public:
    void show_all_books(){
        cout << "---------------------------All Books--------------------------------------------------" << endl;
        cout << "\t" << "Book ID" << "\t\t" << "Book Name" << "\t\t\t" << "Auther Name" << endl;
        book_file.open("Book_list.txt" , ios :: in);
        getline(book_file,id,'*');
        getline(book_file,book,'*');
        getline(book_file,auther,'\n');
        while(!book_file.eof()){
            cout << "\t" << id << "\t\t" << book << "\t\t\t" << auther << endl;
            getline(book_file,id,'*');
            getline(book_file,book,'*');
            getline(book_file,auther,'\n');
        }
        cout << "---------------------------------------------------" << endl;
        return;
    }

    void choos_book(){
        string fid;
        cout << "----------------------Liabrari--------------------" <<endl;
        cout << "Type book you want to read" << endl;
        cin.ignore();
        getline(cin,fid);
        book_file.open("Book_list.txt",ios :: in);
        getline(book_file,id,'*');
        getline(book_file,book,'*');
        getline(book_file,auther,'\n');
        while(!book_file.eof()){
            if(fid == id){
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
        Pub_file.open("Public_logins.txt" , ios::in);
        getline(Pub_file,name,'*');
        getline(Pub_file,email_id,'*');
        getline(Pub_file,password,'\n');
        while(!Pub_file.eof()){
            if(nam == name){
                if(email_id == email){
                    if(pass == password){
                        show_all_books();
                        choos_book();
                        return;
                    }
                    else{
                        cout << "Incorect password " <<endl;
                        login();
                    }
                }
                else{
                    cout << "Email not found " << endl;
                    login();
                }
            }
            else {
                getline(Pub_file,name,'*');
                getline(Pub_file,email_id,'*');
                getline(Pub_file,password,'\n');
            }
        }
        Pub_file.close();
        login();
        return;
    }
    void registe(){
        cout << "----------------Register-------------------" << endl;
        cout << "Enter username : ";
        getline(cin, fusername);
        cout << "Enter email adress : ";
        getline(cin, femail_adress);
        cout << "Enter password : ";
        getline(cin, fpassword);
        Pub_file.open("Public_logins.txt", ios ::out | ios::app);
        Pub_file << fusername << "*" << femail_adress << "*" << fpassword << endl;
        Pub_file.close();
        cout << "Registration Sucessfull" << endl;
        return;
    }
    
}Pub;
class Admin : public User{
private:
    fstream Admin_file;
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
        Admin_file.open("Admin_logins.txt" , ios::in);
        getline(Admin_file,name,'*');
        getline(Admin_file,email_id,'*');
        getline(Admin_file,password,'\n');
        while(!Admin_file.eof()){
            if(nam == name){
                if(email_id == email){
                    if(pass == password){
                        menu();
                        return;
                    }
                    else{
                        cout << "Incorect password " <<endl << endl << "Try again" << endl;
                        login();
                    }
                }
            }
            else {
                getline(Admin_file,name,'*');
                getline(Admin_file,email_id,'*');
                getline(Admin_file,password,'\n');
            }
        }
        Admin_file.close();
        cout << "Could not find id try again" << endl;
        login();
        return;
    }
    void registe(){
        cout << "Enter username : ";
        getline(cin, fusername);
        cout << "Enter email adress : ";
        getline(cin, femail_adress);
        cout << "Enter password : ";
        getline(cin, fpassword);
        Admin_file.open("Admin_logins.txt", ios ::out | ios::app);
        Admin_file << fusername << "*" << femail_adress << "*" << fpassword << endl;
        Admin_file.close();
        cout << "Registration Sucessfull" << endl;
        Admin_file.close();
        return;
    }
}Adm;
void regis(){
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
void login_menu(){
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
            login_menu();
            return;
        case '2':
            cin.ignore();
            Adm.login();
            login_menu();
            return;
        case '3':
            cin.ignore();
            regis();
            login_menu();
            return;
        case '4':
            return;
        default:
            cout << "Incorrect input " << endl;
            login_menu;
            break;  
    }
    return;
}
int main(){
    login_menu();



    return 0;   
}
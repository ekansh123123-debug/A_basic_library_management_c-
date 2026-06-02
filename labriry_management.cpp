#include<iostream>
#include<fstream>
#include<string>
class User{
protected:
    std::string password,temp_password;
public:
    std::fstream book_file;
    std::string id;
    std::string nam ;
    std::string name; 
    std::string temp_username;
    std::string email ;
    std::string email_id;
    std::string temp_email_adress;
    std::string pass;
    std::string book;
    std::string auther;
    size_t mobile_no;
};
class Public : public User{
private:
std::fstream public_login_file;

public:
    void show_all_books(){
        std::cout << "---------------------------All Books--------------------------------------------------" << std::endl;
        std::cout << "\t" << "Book ID" << "\t\t" << "Book Name" << "\t\t\t" << "Auther Name" << std::endl;

        book_file.open("Book_list.txt" , std::ios :: in);

        while(getline(book_file,id,'*') && getline(book_file,book,'*') && getline(book_file,auther,'\n')){
            std::cout << "\t" << id << "\t\t" << book << "\t\t\t" << auther << std::endl;
        }
        std::cout << "---------------------------------------------------" << std::endl;
        return;
    }

    void choos_book(){
        std::string book_id;
        std::cout << "----------------------Liabrari--------------------" <<std::endl;
        std::cout << "Type book you want to read" << std::endl;
        std::cin.ignore();
        getline(std::cin,book_id);
        book_file.open("Book_list.txt",std::ios :: in);
        while(getline(book_file,id,'*') && getline(book_file,book,'*') && getline(book_file,auther,'\n')){
            if(book_id == id){
                std::cout << "Book opened:" <<std::endl;
                book_file.close();
                return;
            }
        }
        return;
    }
    void login(){
        std::cout << "----------------------Login------------------------" <<std::endl;
        std::cout << "Enter your Name : " ;
        getline(std::cin,nam);
         std::cout << "Enter your Email Id : " ;
        getline(std::cin,email);
         std::cout << "Enter your Password : " ;
        getline(std::cin,pass);
        public_login_file.open("Public_logins.txt" , std::ios::in);
        getline(public_login_file,name,'*');
        getline(public_login_file,email_id,'*');
        getline(public_login_file,password,'\n');
        while((!(public_login_file.eof())) && (getline(book_file,id,'*') && getline(book_file,book,'*') && getline(book_file,auther,'\n'))){
            if(nam != name){
                continue;
            }
            if(email_id != email){
                std::cout << "Email not found " << std::endl;
                break;
            }
            if(pass != password){
                std::cout << "Incorect password " <<std::endl;
                break;
            }
            show_all_books();
            choos_book();
            public_login_file.close();
            return;
        }
        public_login_file.close();
        std::cout<<"Could not find id " << std::endl << std::endl << "Pleas try again " << std::endl;
        login();
        return;
    }
    void registe(){
        std::cout << "----------------Register-------------------" << std::endl;
        std::cout << "Enter username : ";
        getline(std::cin, temp_username);
        std::cout << "Enter email adress : ";
        getline(std::cin, temp_email_adress);
        std::cout << "Enter password : ";
        getline(std::cin, temp_password);
        public_login_file.open("Public_logins.txt", std::ios ::out | std::ios::app);
        public_login_file << temp_username << "*" << temp_email_adress << "*" << temp_password << std::endl;
        public_login_file.close();
        std::cout << "Registration Sucessfull" << std::endl;
        return;
    }
    
}Pub;
class Admin : public User{
private:
    std::fstream Admin_login_file;
public:
    void remove_book(){}
    void add_book(){
        std::cout << "--------------------------------------------------" <<std::endl;
        std::cout << "Enter book id :: " ;
        std::cin >> id;
        std::cout << "Enter book name :: " ;
        std::cin.ignore();
        getline(std::cin, book);
        std::cout << "Enter book's Auther name ::";
        getline(std::cin,auther);
        book_file.open("Book_list.txt",std::ios :: out | std::ios :: app);
        book_file << id << "*" << book << "*" << auther << std::endl;
        book_file.close();
        return;
    }
    void menu(){
        std::cout << "-------------------------Libery Admin Section-------------------------------" << std::endl;
        std::cout << "Enter what you want to do " << std::endl;
        std::cout << "1. Add New book " << std::endl;
        std::cout << "2. Remove Book " << std::endl;
        std::cout << "3. Exit " << std::endl;
        char choise;
        std::cin>> choise;
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
                std::cout << "Invalid opration " << std::endl << std::endl << "Try again" << std::endl;
                menu();
                return;
        }
        return;
    }
    void login(){
        std::cout << "----------------------------" <<std::endl;
        std::cout << "Enter your Name : " ;
        getline(std::cin,nam);
         std::cout << "Enter your Email Id : " ;
        getline(std::cin,email);
         std::cout << "Enter your Password : " ;
        getline(std::cin,pass);
        Admin_login_file.open("Admin_logins.txt" , std::ios::in);
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
                std::cout << "Incorrect password" << std::endl << std::endl << "Try again "<< std::endl;
                login();
                return;
            }
            if(!(pass == password)){
                std::cout << "Incorect password " <<std::endl << std::endl << "Try again" << std::endl;
                login();
                return;
            }
            menu();
            return;
        }
        Admin_login_file.close();
        std::cout << "Could not find id try again" << std::endl;
        login();
        return;
    }
    void registe(){
        std::cout << "Enter username : ";
        getline(std::cin, temp_username);
        std::cout << "Enter email adress : ";
        getline(std::cin, temp_email_adress);
        std::cout << "Enter password : ";
        getline(std::cin, temp_password);
        Admin_login_file.open("Admin_logins.txt", std::ios ::out | std::ios::app);
        Admin_login_file << temp_username << "*" << temp_email_adress << "*" << temp_password << std::endl;
        Admin_login_file.close();
        std::cout << "Registration Sucessfull" << std::endl;
        Admin_login_file.close();
        return;
    }
}Adm;
void regis(){
    while(true){
        std::cout << "------------------------" <<std::endl;
        std::cout << "1. Login as new user" <<std::endl;
        std::cout << "2. New Admin register" << std::endl;
        std::cout << "3. Return " << std::endl;
        char ch;
        std::cin >> ch;
        switch (ch){
            case '1':
               std:: cin.ignore();
                Pub.registe();
                return;
            case '2':
                std::cin.ignore();
                Adm.registe();
                return;
            case '3':
                std::cin.ignore();
                return;
            default:
                std::cout << "Invalid opration"<< std::endl;
                regis();
                break;
        }
    }
    return;
}
void login_menu(){
    while(true)
    {
        std::cout << "--------Labriry Management-----------" <<std::endl;
        std::cout << "1. Enter as Student" << std::endl;
        std::cout << "2. Enter as Teacher" << std::endl;
        std::cout << "3. Register" << std::endl;
        std::cout << "4. Exit" << std::endl;
        char ch;
        std::cin >> ch;
        switch(ch){
            case '1':
                std::cin.ignore();
                Pub.login();
            case '2':
                std::cin.ignore();
                Adm.login();
            case '3':
                std::cin.ignore();
                regis();
            case '4':
                return;
            default:
                std::cout << "Incorrect input " << std::endl;
                std::cout << "Try again" << std::endl;
        } 
    }
    return;
}
int main(){
    login_menu();
    return 0;   
}
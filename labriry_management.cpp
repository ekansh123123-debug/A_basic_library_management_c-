#include<iostream>
#include<fstream>
#include<string>


class User{
protected:
    std::string password,temp_password;
public:
    std::fstream book_file;
    std::string id;
    std::string name; 
    std::string temp_username;
    std::string email ;
    std::string email_id;
    std::string temp_email_adress;
    std::string pass;
    std::string book;
    std::string auther;
    size_t mobile_no;

    bool email_check(std::string email){
        if(email.length() < 5)
            return false;
        
        int i = 0;
        bool condition_1 = false, condition_2 = false;

        while(i < email.length()){
            if(email[i] == '@')
                condition_1 = true;
            i++;
        }
        while(i < email.length()){
            if(email[i] == '.')
                condition_2 = true;
            i++;
        }
        return (condition_1 & condition_2);
    }
    bool password_check(std::string password){
        uint8_t i = 0;
        bool check = false;
        while (i < password.length()){
            if(password[i] == '!' && password[i] == '@' && password[i] == '$' && password[i] == '%' && password[i] == '^' && password[i] == '&'  && password[i] == '*' && password[i] == '(' && password[i] == ')' && password[i] == '_' && password[i] == '=' && password[i] == '/'){
                check = true;
                break;
            }
                i++;
        }
        return check;
    }
};



class Public : public User{

private:
std::fstream public_login_file;

public:
    void show_all_books(){
        std::cout << "---------------------------All Books--------------------------------------------------" << std::endl;
        std::cout << "\t" << "Book ID" << "\t\t" << "Book Name" << "\t\t\t" << "Auther Name" << std::endl;

        book_file.open("Book_list.txt" , std::ios :: in);

        while(!book_file.eof() && getline(book_file,id,'*') && getline(book_file,book,'*') && getline(book_file,auther,'\n')){
            std::cout << "\t" << id << "\t\t" << book << "\t\t\t" << auther << std::endl;
        }

        std::cout << "---------------------------------------------------" << std::endl;
        return;
    }

    bool valid_book_id(std::string book_id){
        book_file.open("Book_list.txt",std::ios :: in);

        while(getline(book_file,id,'*') && getline(book_file,book,'*') && getline(book_file,auther,'\n')){
            if(book_id == id){
                std::cout << "Book opened:" <<std::endl;
                book_file.close();
                return true;
            }
        }

        book_file.close();
        return false;
    }
    void choos_book(){
        std::string book_id;
        std::cout << "----------------------Liabrari--------------------" <<std::endl;

        std::cout << "Enter book ID :" << std::endl;
        std::cin.ignore();
        getline(std::cin,book_id);

        if(valid_book_id(book_id))
            std::cout << "book opened" << std::endl;
        else
            std::cout << "Incorect book ID \n Try again" << std::endl;
        return;
    }
    bool id_exists(std::string name , std::string email , std::string password){
        public_login_file.open("Public_logins.txt" , std::ios::in);
        if(public_login_file.eof()){
            return false;
        }
        while((!(public_login_file.eof())) &&
                getline(public_login_file,temp_username,'*') &&
                getline(public_login_file,temp_email_adress,'*') &&
                getline(public_login_file,temp_password,'\n'))
            {
            
                if(name != temp_username){
                    continue;
                }
        
                if(email_id != email){
                    return false;
                }
        
                if(pass != password){
                    return false;
                }
        
                return true;
            }
        public_login_file.close();
        return true;
    }
    void login(){
        std::cout << "----------------------Login Meniu------------------------" <<std::endl;

        std::cout << "Enter your Name : " ;
        getline(std::cin, name);

        std::cout << "Enter your Email Id : " << std::endl;
        getline(std::cin, email);

        std::cout << "Enter your Password : " << std::endl;
        getline(std::cin, password);

        if(id_exists(name, email, password)){
            show_all_books();
            choos_book();
        }
        else{
            std::cout<<"Could not find ID \n\n Please try again " << std::endl;
            login();
        }

        return;
    }
    bool is_username(std::string username){
         public_login_file.open("Public_logins.txt" , std::ios::in);
        if(public_login_file.eof()){
            return false;
        }
        while((!(public_login_file.eof())) && getline(public_login_file,temp_username,'*') && getline(public_login_file,temp_email_adress,'*') &&getline(public_login_file,temp_password,'\n')){
                if(name != temp_username){
                    continue;
                }
            }
        
    }
    void public_registe(){
        std::cout << "----------------Register-------------------" << std::endl;

        std::cout << "Enter username : ";
        getline(std::cin, temp_username);

        std::cout << "Enter email adress : ";
        getline(std::cin, temp_email_adress);
        if(!email_check(temp_email_adress)){
            std::cout << "Incorrect email address format \nTry again" << std::endl;
            public_registe();
            return;
        }

        std::cout << "Enter password : ";
        getline(std::cin, temp_password);
        if(password_check(password)){
            std::cout << "Incorrect password formate\nTry again" << std::endl;
            public_registe();
            return;
        }

        public_login_file.open("Public_logins.txt", std::ios ::out | std::ios::app);
        public_login_file << temp_username << "*" << temp_email_adress << "*" << temp_password << std::endl;
        public_login_file.close();
        
        std::cout << "Registration Sucessfull" << std::endl;
        return;
    }
    
}Pub;


//Admin class start
class Admin : public User{
private:
    std::fstream Admin_login_file;
public:
    //void remove_book(){}
    
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
        while(true){
            std::cout << "Enter what you want to do " << std::endl;
            std::cout << "1. Add New book " << std::endl;
            std::cout << "2. Remove Book " << std::endl;
            std::cout << "3. Exit " << std::endl;

            char choise;
            std::cin>> choise;

            switch(choise){
                case '1':
                    add_book();
                    break;
                case '2':
                    std::cout << "remove_book function called" << std::endl;
                    //remove_book();
                    break;
                case '3':
                    return;
                default:
                    std::cout << "Invalid opration " << std::endl << std::endl << "Try again" << std::endl;
            }
        }
        return;
    }
    bool id_exist(std::string name , std::string email , std::string password){
        Admin_login_file.open("Admin_logins.txt" , std::ios::in);
    
        while((!(Admin_login_file.eof())) &&
                getline(Admin_login_file,temp_username,'*') &&
                getline(Admin_login_file,temp_email_adress,'*') &&
                getline(Admin_login_file,temp_password,'\n'))
            {
            
                if(name != temp_username){
                    continue;
                }
        
                if(email_id != email){
                    return false;
                }
        
                if(pass != password){
                    return false;
                }
        
                return true;
            }
        }
    void login(){
        std::cout << "----------------------------" <<std::endl;

        std::cout << "Enter your Name : " ;
        getline(std::cin,name);

         std::cout << "Enter your Email Id : " ;
        getline(std::cin,email);

         std::cout << "Enter your Password : " ;
        getline(std::cin,password);

        if(id_exist(name, email , password)){
            menu();
            return;
        }
        else
            std::cout << "Could not find id try again" << std::endl;
        return;
    }

    void admin_registe(){
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
        return;
    }
}Adm;

// Admin class ends

void register_menu(){
    while(true){
        std::cout << "------------------------" <<std::endl;
        std::cout << "1. Login as new user" <<std::endl;
        std::cout << "2. New Admin register" << std::endl;
        std::cout << "3. Return " << std::endl;
        char ch;
        std::cin >> ch;
        switch (ch){
            std:: cin.ignore();
            case '1':
                Pub.public_registe();
                return;
            case '2':
                std::cin.ignore();
                Adm.admin_registe();
                return;
            case '3':
                std::cin.ignore();
                return;
            default:
                std::cout << "Invalid opration"<< std::endl;
                break;
        }
    }
    return;
}
int main(){
    while(true)
    {
        std::cout << "--------Labriry Management-----------" <<std::endl;
        std::cout << "Press" << std::endl;
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
                break;
            case '2':
                std::cin.ignore();
                Adm.login();
                break;
            case '3':
                std::cin.ignore();
                register_menu();
                break;
            case '4':
                return 0;
            default:
                std::cout << "Incorrect input " << std::endl;
                std::cout << "Try again" << std::endl;
        } 
    }
    return 0;   
}
#include <iostream>
#include <string.h>
#include <iomanip>
#include <limits>
#define  Blue "\033[34m"
#define RESET "\033[0m"
#define Green "\033[32m"
#define red "\033[31m"

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
     void set_contact();
     void display_contacts();
     void display_one_contacts();
     void set_data(std::string &data);
     std::string get_first_name();
     std::string get_last_name();
     std::string get_nickname();
     std::string get_phonenumber();
     std::string get_secret(); 
};

class PhoneBook
{
    private : 
      Contact Contacts[8];
      int count_contact;
      int index;
    public:
     PhoneBook();
     void add_contact();
     void search_contact();
};

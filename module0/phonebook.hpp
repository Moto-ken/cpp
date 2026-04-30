
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <string>

class PhoneBook{
	private:
        string first_name;
		string last_name;
		string nickname;
		string phone_number;
		string darkest_secret;
		int    number;
	public:
		PhoneBook();
		~PhoneBook();
		string GetFirst(void);
		string GetLast(void);
		string GetNick(void);
		string GetPhone(void);
		string GetDark(void);
		void   SetFirst(char *str);
};

class Contact{
	private:

	public:

};

#endif

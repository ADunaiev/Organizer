# include <iostream>
# include <string.h>

//Написать программу, реализующую электронный органайзер.
//Реализовать возможности добавления, удаления, редактирования и хранения данных.
//Предусмотреть обработку всех возможных ошибок.
//Создаём проект с использованием большинства известных приёмов ООП
//Обработку ошибок производим через try / catch.

class Date
{
	int day;
	int month;
	int year;
public:
	Date(int dayP, int monthP, int yearP);
	Date();
	Date(const Date& object);
	Date(Date&& object);
	int get_day() const;
	int get_month() const;
	int get_year() const;
	Date& operator=(const Date& object);
	Date& operator=(Date&& object);
	void show() const;
	bool IsCorrect() const;
};
Date::Date(int dayP, int monthP, int yearP) 
	: day{dayP}, month{monthP}, year {yearP}
{
	if (!IsCorrect())
	{
		throw "\nWrong date!\n";
	}
}
Date::Date() : Date(1, 1, 1970){}
Date::Date(const Date& object)
{
	if (object.IsCorrect())
	{
		day = object.day;
		month = object.month;
		year = object.year;
	}
	else
		throw "\nWrong date!\n";
}
Date::Date(Date&& object)
{
	if (object.IsCorrect())
	{
		day = object.day;
		month = object.month;
		year = object.year;
	}
	else
		throw "\nWrong date!\n";
}
int Date::get_day() const { return day; }
int Date::get_month() const { return month; }
int Date::get_year() const { return year; }
Date& Date::operator=(const Date& object)
{
	if (object.IsCorrect())
	{
		day = object.day;
		month = object.month;
		year = object.year;
	}
	else
		throw "\nWrong date!\n";
}
Date& Date::operator=(Date&& object)
{
	if (object.IsCorrect())
	{
		day = object.day;
		month = object.month;
		year = object.year;
	}
	else
		throw "\nWrong date!\n";
}
void Date::show() const
{
	std::cout << day << "." << month << "." << year;
}
bool Date::IsCorrect() const
{
	bool temp = 1;

	if (day < 1 || day > 31)
		temp = 0;
	if (month < 1 || month > 12)
		temp = 0;
	if (year < 1900 || year > 2100)
		temp = 0;

	return temp;
}

class Contact
{
	std::string name;
	std::string surname;
	Date birthday;
	std::string email;
	std::string phone;
public:
	Contact(std::string nameP, std::string surnameP, Date birthdayP,
		std::string emailP, std::string phoneP);
	Contact();
	Contact(const Contact& object);
	Contact(Contact&& object);
	std::string get_name() const;
	std::string get_surname() const;
	std::string get_email() const;
	std::string get_phone() const;
	Date get_birthday() const;
	void set_name(std::string nameP);
	void set_surname(std::string surnameP);
	void set_email(std::string emailP);
	void set_phone(std::string phoneP);
	void set_birthday(Date birthdayP);
	Contact& operator=(const Contact& object);
	Contact& operator=(Contact&& object);
};

Contact::Contact(std::string nameP, std::string surnameP, Date birthdayP,
	std::string emailP, std::string phoneP)
	: name{ nameP }, surname{ surnameP }, birthday{ birthdayP },
	email{ emailP }, phone{ phoneP }{}
Contact::Contact() : Contact("", "", {1, 1, 1970}, "", ""){}
Contact::Contact(const Contact& object)
{
	name = object.name;
	surname = object.surname;
	birthday = object.birthday;
	email = object.email;
	phone = object.phone;
}
Contact::Contact(Contact&& object)
{
	name = object.name;
	surname = object.surname;
	birthday = object.birthday;
	email = object.email;
	phone = object.phone;
}
std::string Contact::get_name() const
{
	return name;
}
std::string Contact::get_surname() const
{
	return surname;
}
std::string Contact::get_email() const
{
	return email;
}
std::string Contact::get_phone() const
{
	return phone;
}
Date Contact::get_birthday() const
{
	return birthday;
}
void Contact::set_name(std::string nameP)
{
	name = nameP;
}
void Contact::set_surname(std::string surnameP)
{
	name = surnameP;
}
void Contact::set_name(std::string emailP)
{
	name = emailP;
}
void Contact::set_name(std::string phoneP)
{
	name = phoneP;
}
void Contact::set_birthday(Date birthdayP)
{
	birthday = birthdayP;
}
Contact& Contact::operator=(const Contact& object)
{
	name = object.name;
	surname = object.surname;
	birthday = object.birthday;
	email = object.email;
	phone = object.phone;
}
Contact& Contact::operator=(Contact&& object)
{
	name = object.name;
	surname = object.surname;
	birthday = object.birthday;
	email = object.email;
	phone = object.phone;
}

class Contacts
{
	enum { EMPTY = -1, FULL = 1000 };
	Contact st[FULL + 1];
	int top;
public:
	Contacts();
	void Push(Contact contactP);
	Contact Pop();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
};
Contacts::Contacts()
{
	top = EMPTY;
}
void Contacts::Clear()
{
	top = EMPTY;
}
bool Contacts::IsEmpty()
{
	return top == EMPTY;
}
bool Contacts::IsFull()
{
	return top == FULL;
}
int Contacts::GetCount()
{
	return top + 1;
}
void Contacts::Push(Contact contactP)
{
	st[++top] = contactP;
}
Contact Contacts::Pop()
{
	if(!IsEmpty())
		return st[top--];
};

void main() {
 
	try {

	}

	catch (char* s) {
		std::cout << "\n\nException!!!\n\n";
	}
}
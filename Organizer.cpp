# include <iostream>
# include <string.h>
#include <fstream>
#include <conio.h>
using namespace std;

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
Date::Date() : Date(1, 1, 1900){}
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
	return *this;
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

	return *this;
}
void Date::show() const
{
	cout << day << "." << month << "." << year;
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
	char* name;
	char* surname;
	Date birthday;
	char* email;
	char* phone;
	void setCharArray(char*& dest, const char* source)
	{
		if (source != nullptr)
		{
			int temp = strlen(source) + 1;

			dest = new char[temp];
			strcpy_s(dest, temp, source);
		}
		else if (source == nullptr)
			dest = nullptr;
	}
	void remove()
	{
		if (name != nullptr)
		{
			delete[] name;
		}
		if (surname != nullptr)
		{
			delete[] surname;
		}
		birthday = { 1, 1, 1900 };
		if (email != nullptr)
		{
			delete[] email;
		}
		if (phone != nullptr)
		{
			delete[] phone;
		}
	}
public:
	Contact(const char* nameP, const char* surnameP, const Date birthdayP,
		const char* emailP, const char* phoneP);
	Contact();
	~Contact();
	Contact(const Contact& object);
	Contact(Contact&& object);
	char* get_name() const;
	char* get_surname() const;
	char* get_email() const;
	char* get_phone() const;
	Date get_birthday() const;
	void set_name(char* nameP);
	void set_surname(char* surnameP);
	void set_email(char* emailP);
	void set_phone(char* phoneP);
	void set_birthday(Date birthdayP);
	Contact& operator=(const Contact& object);
	Contact& operator=(Contact&& object);
	void show() const;
};

Contact::Contact(const char* nameP, const char* surnameP, const Date birthdayP,
	const char* emailP, const char* phoneP)
{
	setCharArray(name, nameP);
	setCharArray(surname, surnameP);
	setCharArray(email, emailP);
	setCharArray(phone, phoneP);
	birthday = birthdayP;
}
Contact::Contact() : Contact(nullptr, nullptr, {1, 1, 1970}, nullptr, nullptr) {}
Contact::Contact(const Contact& object)
{
	setCharArray(name, object.name);
	setCharArray(surname, object.surname);
	setCharArray(email, object.email);
	setCharArray(phone, object.phone);	
	birthday = object.birthday;
}
Contact::Contact(Contact&& object)
{
	if (object.name)
	{
		setCharArray(name, object.name);
		object.name = nullptr;
	}

	if (object.surname)
	{
		setCharArray(surname, object.surname);
		object.surname = nullptr;
	}

	birthday = object.birthday;

	if (object.email)
	{
		setCharArray(email, object.email);
		object.email = nullptr;
	}

	if (object.phone)
	{
		setCharArray(phone, object.phone);
		object.phone = nullptr;
	}
}
Contact::~Contact()
{
	remove();
}
char* Contact::get_name() const
{
	return name;
}
char* Contact::get_surname() const
{
	return surname;
}
char* Contact::get_email() const
{
	return email;
}
char* Contact::get_phone() const
{
	return phone;
}
Date Contact::get_birthday() const
{
	return birthday;
}
void Contact::set_name(char* nameP)
{
	if (nameP)
	{
		if (strlen(name) != strlen(nameP))	
			delete[] name;
			
		setCharArray(name, nameP);
	}
}
void Contact::set_surname(char* surnameP)
{
	if (surnameP)
	{
		if (strlen(surname) != strlen(surnameP))
			delete[] surname;

		setCharArray(surname, surnameP);
	}

}
void Contact::set_email(char* emailP)
{
	if (emailP)
	{
		if (strlen(email) != strlen(emailP))
			delete[] email;

		setCharArray(email, emailP);
	}
}
void Contact::set_phone(char* phoneP)
{
	if (phoneP)
	{
		if (strlen(phone) != strlen(phoneP))
			delete[] phone;
			
		setCharArray(phone, phoneP);
	}
}
void Contact::set_birthday(Date birthdayP)
{
	birthday = birthdayP;
}
Contact& Contact::operator=(const Contact& object)
{
	if (this == &object)
		return *this;

	remove();

	setCharArray(name, object.name);
	setCharArray(surname, object.surname);
	birthday = object.birthday;
	setCharArray(email, object.email);	
	setCharArray(phone, object.phone);

	return *this;
}
Contact& Contact::operator=(Contact&& object)
{
	if (strlen(name) != strlen(object.name))
		delete[] name;

	setCharArray(name, object.name);
	object.name = nullptr;

	if (strlen(surname) != strlen(object.surname))
		delete[] surname;

	setCharArray(surname, object.surname);
	object.surname = nullptr;

	birthday = object.birthday;

	if (strlen(email) != strlen(object.email))
		delete[] email;

	setCharArray(email, object.email);
	object.email = nullptr;

	if (strlen(phone) != strlen(object.phone))
		delete[] phone;

	setCharArray(phone, object.phone);
	object.phone = nullptr;

	return *this;
}
void Contact::show() const
{
	cout << "Name: " << name << endl;
	cout << "Surame: " << surname << endl;
	cout << "Birthday: ";
	birthday.show();
	cout << endl;
	cout << "Email: " << email << endl;
	cout << "Phone: " << phone << endl;
}

void resetCharArray(char*& dest, const char* source)
{
	if (source != nullptr)
	{
		if (dest != nullptr)
			delete[] dest;

		int strSize = strlen(source) + 1;
		dest = new char[strSize];
		strcpy_s(dest, strSize, source);
	}
}

class Contacts
{
	enum { EMPTY = -1, FULL = 100 };
	Contact* st;
	int top;
public:
	Contacts();
	void Push(const Contact contactP);
	void Push();
	Contact Pop();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	Contact get_contact(int temp);
	void SaveToFile(int i);
	void LoadFromFile();
	void Show() const;
	void SaveAllToFile();
};
Contacts::Contacts()
{
	top = EMPTY;
	st = nullptr;
}
Contacts MyAddressBook;
void Contacts::Clear()
{
	top = EMPTY;
	if (st)
		delete[] st;
	st = nullptr;
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
void Contacts::Push(const Contact contactP)
{
	Contact* temp = new Contact[top+2];
	for (size_t i = 0; i < top + 1; i++)
		temp[i] = st[i];

	temp[++top] = contactP;
	delete[] st;
	st = new Contact[top + 1];
	for (int i = 0; i <= top; i++)
		st[i] = temp[i];
	delete[] temp;
}
void Contacts::Push()
{
	Contact* temp = new Contact[top + 2];
	for (size_t i = 0; i < top + 1; i++)
		temp[i] = st[i];

	temp[++top] = Contact();
	delete[] st;
	st = new Contact[top+1];
	for (int i = 0; i <= top; i++)
		st[i] = temp[i];
	delete[] temp;
}
Contact Contacts::Pop()
{
	Contact t;

	if (!IsEmpty())
	{
		Contact* temp = new Contact[top - 1];

		for (size_t i = 0; i < top - 1; i++)
			temp[i] = st[i];

		t = st[top--];

		delete[] st;
		st = new Contact[top];
		st = temp;
		delete[] temp;
	}

	return t;
};
Contact Contacts::get_contact(int temp) 
{
	Contact tem;

	if(!IsEmpty())
	{
		if (temp < 0 || temp > top)
		{
			throw "\n Wrong Element Position!\n";
		}
		else
		{
			tem = st[temp];
		}
	}

	return tem;
}
void Contacts::SaveToFile(int i) 
{
	if (i < 0 || i > top)
	{
		throw "\nIndex if wrong!\n";
	}
	int size; char* temp = nullptr;
	fstream f("Contacts.txt", ios::out | ios::binary | ios::app); 
	if (!f)
	{
		throw "\nFile is not opened for writing!\n";
	}

	size = strlen(st[i].get_name());
	f.write((char*)&size, sizeof(int));
	resetCharArray(temp, st[i].get_name());
	f.write((char*)temp, size * sizeof(char));

	size = strlen(st[i].get_surname());
	f.write((char*)&size, sizeof(int));
	resetCharArray(temp, st[i].get_surname());
	f.write((char*)temp, size * sizeof(char));

	size = st[i].get_birthday().get_day();
	f.write((char*)&size, sizeof(int));

	size = st[i].get_birthday().get_month();
	f.write((char*)&size, sizeof(int));

	size = st[i].get_birthday().get_year();
	f.write((char*)&size, sizeof(int));

	size = strlen(st[i].get_email());
	f.write((char*)&size, sizeof(int));
	resetCharArray(temp, st[i].get_email());
	f.write((char*)temp, size * sizeof(char));

	size = (int)strlen(st[i].get_phone());
	f.write((char*)&size, sizeof(int));
	resetCharArray(temp, st[i].get_phone());
	f.write((char*)temp, size * sizeof(char));

	f.close();
	delete[] temp;
}
void Contacts::LoadFromFile() {
	fstream f("text.txt", ios::in | ios::binary);
	if (!f) {
		throw "\nFile is not opened for reading!\n\n";
	}
	char* n = nullptr, *s = nullptr, *e = nullptr, *p = nullptr;
	int size;
	int dayP, monthP, yearP;
	int i = 0;
	//В цикле зачитываем содержимое файла
	while (f.read((char*)&size, sizeof(int))) {
		Push();
		if (strlen(n) != size)
		{
			if (n != nullptr)
				delete[] n;
			n = new char[size + 1];
		}
		f.read((char*)n, size * sizeof(char));
		st[i].set_name(n);

		f.read((char*)&size, sizeof(int));
		if (strlen(s) != size)
		{
			if (s != nullptr)
				delete[] s;
			s = new char[size + 1];
		}
		f.read((char*)s, size * sizeof(char));
		st[i].set_surname(s);

		f.read((char*)&dayP, sizeof(int));
		f.read((char*)&monthP, sizeof(int));
		f.read((char*)&yearP, sizeof(int));
		st[i].set_birthday({ dayP, monthP, yearP });

		f.read((char*)&size, sizeof(int));
		if (strlen(e) != size)
		{
			if (e != nullptr)
				delete[] e;
			e = new char[size + 1];
		}
		f.read((char*)e, size * sizeof(char));
		st[i].set_email(e);

		f.read((char*)&size, sizeof(int));
		if (strlen(p) != size)
		{
			if (p != nullptr)
				delete[] p;
			p = new char[size + 1];
		}
		f.read((char*)p, size * sizeof(char));
		st[i].set_phone(p);

		i++;
	}

	delete[] n;
	delete[] s;
	delete[] e;
	delete[] p;
}
void Contacts::Show() const
{
	for (size_t i = 0; i <= top; i++)
	{
		st[i].show();
		cout << "\n";
	}
}
void Contacts::SaveAllToFile()
{
	for (int i = 0; i <= top; i++)
	{
		SaveToFile(i);
	}
}



int main() {

	try 
	{
		Contact c1 { "Andrii", "Dunaiev", {6, 9, 1978},
			"adunaev@me.com", "+380503994545" };
		Contact c2{ "Vasia", "Frolov", {17, 4, 1981},
			"vfrol@apple.com", "+380501111111" };
		Contact c3{ "Luda", "Kirilova", {30, 6, 1978},
			"lkirilova@icloud.com", "+380671234567" };
		Contact c4{ "Petro", "Kirichenko", {12, 12, 1993},
			"pk@github.com", "+380331325476" };
		Contact c5{ "Valia", "Kitaeva", {14, 5, 1998},
			"vkitaeva@bbc.com", "+380501000000" };

		MyAddressBook.Push(c1);
		MyAddressBook.Push(c2);
		MyAddressBook.Push(c3);
		MyAddressBook.Push(c4);
		MyAddressBook.Push(c5);

		cout << "MyAddressBook\n";
		MyAddressBook.Show();	
		MyAddressBook.SaveAllToFile();
		cout << "M2\n";

		//Contacts M2;

		//M2.LoadFromFile();

		//M2.Show();
	}

	catch (char* su) {
		std::cout << "\n\nException!!!\n\n";
	}
	return 0;
}
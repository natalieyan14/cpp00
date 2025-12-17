#include "Contact.hpp"
#include <string>

class PhoneBook
{
  private:
	Contact contacts[8];
	int count;
	int last_display_map[8];
	int last_display_count;

  public:
	PhoneBook();
	~PhoneBook();
	void set_new_contact(int i);
	int get_contacts();
	int get_count();
	void print_contact(int index);
	void print_contact_by_display_index(int display_index);
};
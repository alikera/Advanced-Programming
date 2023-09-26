#ifndef AUTHORS_HPP
#define AUTHORS_HPP "AUTHORS_HPP"
#include <string>
#include <vector>


#include "Books.hpp"
typedef std::vector<std::string> strTable;
class Author
{
public:
	int get_author_id() { return author_id_; }
	std::string get_author_name() { return author_name_; }

	void set_author_id(int id) { author_id_ = id; }
	void set_author_name(std::string name) { author_name_ = name; }
	void set_author_gender(std::string gender) { author_gender_ = gender; }
	void set_author_member_since(std::string member_since) { author_member_since_ = member_since; }
	void set_author_year_of_birth(int year_of_birth) { author_year_of_birth_ = year_of_birth; }
	void set_author_place_of_birth(std::string place_of_birth) { author_place_of_birth_ = place_of_birth; }
	void set_author_genres(strTable genres) { author_genres_ = genres; }
	void set_author_books(Book* address_book) { ptr_author_books_.push_back(address_book); }

	void print_author_info();
	void print_author_genres();
	void print_author_books();

private:
	int author_id_;
	std::string author_name_;
	std::string author_gender_;
	std::string author_member_since_;
	int author_year_of_birth_;
	std::string author_place_of_birth_;
	std::vector<std::string> author_genres_;
	pbooks ptr_author_books_;
};

#endif

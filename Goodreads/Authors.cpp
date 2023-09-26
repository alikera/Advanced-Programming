#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "Authors.hpp"

using namespace std;

void Author::print_author_books()
{
	cout << "Books:" << endl;
	for (int i = 0; i < ptr_author_books_.size(); i++)
		ptr_author_books_[i]->print_book_inf_for_author();
}

void Author::print_author_genres()
{
	sort(author_genres_.begin(), author_genres_.end());
	cout << "Genres: " << author_genres_[0];
	for (int i = 1; i < author_genres_.size(); i++)
		cout << ", " << author_genres_[i];
	cout << endl;
}

void Author::print_author_info()
{
	cout << "id: " << author_id_ << endl;
	cout << "Name: " << author_name_ << endl;
	cout << "Year of Birth: " << author_year_of_birth_ << endl;
	cout << "Place of Birth: " << author_place_of_birth_ << endl;
	cout << "Member Since: " << author_member_since_ << endl;
	print_author_genres();
	print_author_books();
}


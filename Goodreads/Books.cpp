#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "Books.hpp"

using namespace std;

double Book::calculate_average_book_ratings()
{
	int j;
	double sum = 0;
	for (j = 0; j < previews_of_book_.size(); j++)
		sum += previews_of_book_[j]->get_review_rating();

	if (j == 0)
		return 0;

	return sum / j;
}

void Book::print_book_inf_for_author()
{
	cout << "id: " << book_id_ << " Title: " << book_title_ << endl;
}


void Book::print_book_inf()
{
	cout << "id: " << book_id_ << endl;
	cout << "Title: " << book_title_ << endl;
	cout << "Genre: " << book_genre_ << endl;
}
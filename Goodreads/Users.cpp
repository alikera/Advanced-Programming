#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

#include "Users.hpp"

using namespace std;

double User::calculate_user_credit(int all_likes, int all_reviews)
{
	if (all_likes == 0)
		return 0;

	return (double(number_of_user_review_likes_) / all_likes +
		double(number_of_user_reviews_) / all_reviews) / 2;
}

void User::print_favorite_genres()
{
	sort(favorite_genres_.begin(), favorite_genres_.end());
	cout << "Favorite Genres: " << favorite_genres_[0];
	for (int i = 1; i < favorite_genres_.size(); i++)
		cout << ", " << favorite_genres_[i];

	cout << endl;
}

void User::print_favorite_authors()
{
	sort(favorite_authors_.begin(), favorite_authors_.end());
	cout << "Favorite Authors: " << favorite_authors_[0];
	for (int i = 1; i < favorite_authors_.size(); i++)
		cout << ", " << favorite_authors_[i];

	cout << endl;
}

void User::print_user_inf()
{
	cout << "id: " << id_ << endl;
	cout << "Name: " << name_ << endl;
	cout << "Place of Birth: " << place_of_birth_ << endl;
	cout << "Member Since: " << member_since_ << endl;
	print_favorite_genres();
	print_favorite_authors();
	cout << "Number of Books in Read Shelf: " << read_.size() << endl;
	cout << "Number of Books in Want to Read Shelf: " << want_to_read_.size() << endl;
	cout << "Number of Books in Currently Reading Shelf: " << currently_reading_.size() << endl;
}

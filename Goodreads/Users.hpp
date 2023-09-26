#ifndef USERS_HPP
#define USERS_HPP "USERS_HPP"
#include <string>
#include <vector>

#include "Books.hpp"
typedef std::vector<std::string> strTable;
typedef std::vector<int> numsTable;
class User {
public:
	int get_id() { return id_; }
	strTable get_favorite_genres() { return favorite_genres_; }
	pbooks get_want_to_read() { return want_to_read_; }
	pbooks get_currently_reading() { return currently_reading_; }
	pbooks get_read() { return read_; }
	int get_number_of_user_review_likes() { return number_of_user_review_likes_; }
	int get_number_of_user_reviews() { return number_of_user_reviews_; }
	numsTable get_followings_list() { return followings_; }

	void set_id(int id) { id_ = id; }
	void set_name(std::string name) { name_ = name; }
	void set_place_of_birth(std::string place_of_birth) { place_of_birth_ = place_of_birth; }
	void set_member_since(std::string member_since) { member_since_ = member_since; }
	void set_favorite_authors(strTable favorite_authors) { favorite_authors_ = favorite_authors; }

	void set_favorite_genre(strTable favorite_genres) { favorite_genres_ = favorite_genres; }
	void set_want_to_read(pbooks want_to_read) { want_to_read_ = want_to_read; }
	void set_currently_reading(pbooks currently_reading) { currently_reading_ = currently_reading; }
	void set_read(pbooks read) { read_ = read; }

	void set_number_of_user_review_likes(int number) { number_of_user_review_likes_ += number; }
	void set_number_of_user_reviews() { number_of_user_reviews_++; }

	void set_followers_list(numsTable followers) { followers_ = followers; }
	void set_followings_list(numsTable followings) { followings_ = followings; }

	double calculate_user_credit(int all_likes, int all_reviews);

	void print_favorite_genres();
	void print_favorite_authors();
	void print_user_inf();
private:
	int id_;
	std::string name_;
	std::string place_of_birth_;
	std::string member_since_;
	strTable favorite_authors_;
	strTable favorite_genres_;
	pbooks want_to_read_;
	pbooks currently_reading_;
	pbooks read_;
	int number_of_user_review_likes_ = 0;
	int number_of_user_reviews_ = 0;

	numsTable followers_;
	numsTable followings_;
};
#endif

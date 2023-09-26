#ifndef BOOKS_HPP
#define BOOKS_HPP "BOOKS_HPP"

#include <string>
#include <vector>


#include "Reviews.hpp"

class Book {
public:
	int get_book_id() { return book_id_; }
	std::string get_book_title() { return book_title_; }
	int get_book_author_id() { return book_author_id_; }
	std::string get_book_genre() { return book_genre_; }
	std::vector<Review*> get_reviews_of_book() { return previews_of_book_; }

	void set_id(int id) { book_id_ = id; }
	void set_book_title(std::string book_title) { book_title_ = book_title; }
	void set_book_author_id(int id) { book_author_id_ = id; }
	void set_book_genre(std::string book_genre) { book_genre_ = book_genre; }
	void set_review_book(Review* r) { previews_of_book_.push_back(r); }

	double calculate_average_book_ratings();

	void print_book_inf();
	void print_book_inf_for_author();
private:
	int book_id_;
	std::string book_title_;
	int book_author_id_;
	std::string book_genre_;
	std::vector<Review*> previews_of_book_;
};
typedef std::vector<Book*> pbooks;

#endif


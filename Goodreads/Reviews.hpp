#ifndef REVIEW_HPP
#define REVIEW_HPP "REVIEW_HPP"
#include <string>
#include <vector>

class Review {
public:
	int get_review_book_id() { return review_book_id_; }
	int get_review_rating() { return review_rating_; }
	int get_review_user_id() { return review_user_id_; }

	void set_review_id(int review_id) { review_id_ = review_id; }
	void set_review_book_id(int review_book_id) { review_book_id_ = review_book_id; }
	void set_review_user_id(int review_user_id) { review_user_id_ = review_user_id; }
	void set_review_rating(int review_rating) { review_rating_ = review_rating; }
	void set_review_date(std::string review_date) { review_date_ = review_date; }
	void set_review_likes(int review_likes) { review_likes_ = review_likes; }

	void print_review_inf();
private:
	int review_id_;
	int review_book_id_;
	int review_user_id_;
	int review_rating_;
	std::string review_date_;
	int review_likes_;
};
#endif
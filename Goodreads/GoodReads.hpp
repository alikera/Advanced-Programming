#ifndef GOODREADS_HPP
#define GOODREADS_HPP "GOODREADS_HPP"
#include <string>
#include <vector>

typedef std::vector<std::string> strTable;
typedef std::vector<int>  numsTable;

#include "Users.hpp"
#include "Books.hpp"
#include "Authors.hpp"
#include "Reviews.hpp"

class GoodReads {
public:
	void read_from_file_authors(std::string directory);
	void write_each_author_inf(int i, std::string word, Author& each_author);
	strTable create_genre_list(std::string word);
	strTable create_authors_list(std::string word);

	void read_from_file_books(std::string directory);
	void write_each_book_inf(int i, std::string word, Book& each_book);
	void create_each_book_author();

	void read_from_file_users(std::string directory);
	void write_each_user_inf(int i, std::string word, User& each_user);
	pbooks create_read_list(std::string word);

	void read_from_file_reviews(std::string directory);
	void write_each_review_inf(int i, std::string word, int& index, Review& each_review);
	int find_user_index(std::string word);
	void create_each_book_reviews();

	void read_from_file_follow_edges(std::string directory);
	void write_each_follow_list(int user_index, std::string word, int i);
	numsTable create_follow_list(std::string word);


	void show_author_info(int author_id);

	void show_sorted_shelf(int user_id, std::string shelf_type, std::string genre);
	pbooks list_books(int user_id, std::string shelf_type);
	pbooks find_user_shelf(std::string shelf_type, int i);
	void print_author_name(int book_author_id);
	void print_shelf_book_inf(pbooks user_books_list, int i);

	void count_number_of_user_reviews_likes(int index, std::string word);
	void count_number_of_user_reviews(int index);
	int find_book_by_id(int id);
	void print_user_credit(int user_id);

	Book* find_best_book(double& max_average);
	void print_best_book_inf();

	User* find_best_reviwer(int& max_likes);
	void print_best_reviwer_inf();

	double calculate_each_book_rating(int i);
	double calculate_rating(std::vector<Review*> reviews_of_book);
	double calculate_each_book_score(int id, int i);
	Book* find_appropriate_book(int id);
	void print_appropriate_book_inf_1(int id);
	void print_appropriate_book_inf(Book* appropriate_book);

	numsTable create_top_books_to_recommend(int user_id);
	void find_user_following_series(int user_id, numsTable& following_series);
	int find_appropriate_book_id(int user_id);
	Book* find_appropriate_book_address(int user_id);
	void print_appropriate_book_inf_2(int user_id);
	void find_each_user_top_books(int each_user_id, numsTable& all_top_books);

private:
	std::vector<User> users;
	std::vector<Book> books;
	std::vector<Author> authors;
	std::vector<Review> reviews;
	int all_likes = 0;
	int all_reviews = 0;
};

#endif


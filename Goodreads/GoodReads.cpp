#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

#define AUTHORS "/authors.csv"
#define BOOKS "/books.csv"
#define USERS "/users.csv"
#define REVIEWS "/reviews.csv"
#define FOLLOW_EDGES "/follow_edges.csv"
#define COMMA ','
#define DOLLAR '$'
#define FAVORITE 5
#define INVALID -1
#define WANT_TO_READ_SHELF "want_to_read"
#define CURRENTLY_READING_SHELF "currently_reading"
#define READ_SHELF "read"

#include "GoodReads.hpp"
#include "Users.hpp"
#include "Books.hpp"
#include "Reviews.hpp"
#include "Authors.hpp"

using namespace std;

void GoodReads::print_author_name(int book_author_id)
{
	for (int i = 0; i < authors.size(); i++)
	{
		if (authors[i].get_author_id() == book_author_id)
		{
			cout << "Author: " << authors[i].get_author_name() << endl;
			break;
		}
	}
}

int GoodReads::find_book_by_id(int id)
{
	for (int i = 0; i < books.size(); i++)
		if (id == books[i].get_book_id())
			return i;
}


int GoodReads::find_user_index(string word)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (stoi(word) == users[i].get_id())
			return i;
	}
}



pbooks GoodReads::create_read_list(string word)
{
	pbooks read_list;
	stringstream ss_word(word);
	for (int i = 1; getline(ss_word, word, DOLLAR); i++)
	{
		for (int j = 0; j < books.size(); j++)
		{
			if (stoi(word) == books[j].get_book_id())
				read_list.push_back(&books[j]);
		}
	}
	return read_list;
}

strTable GoodReads::create_genre_list(string word)
{
	strTable genre_list;
	stringstream ss_word(word);
	for (int i = 1; getline(ss_word, word, DOLLAR); i++)
		genre_list.push_back(word);

	return genre_list;
}

strTable GoodReads::create_authors_list(string word)
{
	strTable authors_list;
	stringstream ss_word(word);
	for (int i = 1; getline(ss_word, word, DOLLAR); i++)
	{
		int index = stoi(word);
		string name = authors[index].get_author_name();
		authors_list.push_back(name);
	}

	return authors_list;
}

void GoodReads::write_each_user_inf(int i, string word, User& each_user)
{
	if (i == 1)
		each_user.set_id(stoi(word));

	if (i == 2)
		each_user.set_name(word);

	if (i == 3)
		each_user.set_place_of_birth(word);

	if (i == 4)
		each_user.set_member_since(word);

	if (i == 5)
		each_user.set_favorite_authors(create_authors_list(word));

	if (i == 6)
		each_user.set_favorite_genre(create_genre_list(word));

	if (i == 7)
		each_user.set_want_to_read(create_read_list(word));

	if (i == 8)
		each_user.set_currently_reading(create_read_list(word));

	if (i == 9)
		each_user.set_read(create_read_list(word));
}

void GoodReads::read_from_file_users(string directory)
{
	directory.insert(6, USERS);
	ifstream users_file(directory);

	User each_user;
	string line, word;
	getline(users_file, line);
	for (int j = 0; getline(users_file, line); j++)
	{
		stringstream ss_line(line);

		for (int i = 1; getline(ss_line, word, COMMA); i++)
			write_each_user_inf(i, word, each_user);

		users.push_back(each_user);
	}
}



void GoodReads::write_each_book_inf(int i, string word, Book& each_book)
{
	if (i == 1)
		each_book.set_id(stoi(word));

	if (i == 2)
		each_book.set_book_title(word);

	if (i == 3)
		each_book.set_book_author_id(stoi(word));

	if (i == 4)
		each_book.set_book_genre(word);
}

void GoodReads::read_from_file_books(string directory)
{
	directory.insert(6, BOOKS);
	ifstream books_file(directory);

	Book each_book;
	string line, word;
	getline(books_file, line);
	for (int j = 0; getline(books_file, line); j++)
	{
		stringstream ss_line(line);

		for (int i = 1; getline(ss_line, word, COMMA); i++)
			write_each_book_inf(i, word, each_book);

		books.push_back(each_book);
	}
	create_each_book_author();
}

void GoodReads::create_each_book_author()
{
	for (int i = 0; i < books.size(); i++)
	{
		for (int j = 0; j < authors.size(); j++)
		{
			if (books[i].get_book_author_id() == authors[j].get_author_id())
			{
				authors[j].set_author_books(&books[i]);
				break;
			}
		}
	}
}



void GoodReads::write_each_author_inf(int i, string word, Author& each_author)
{
	if (i == 1)
		each_author.set_author_id(stoi(word));

	if (i == 2)
		each_author.set_author_name(word);

	if (i == 3)
		each_author.set_author_gender(word);

	if (i == 4)
		each_author.set_author_member_since(word);

	if (i == 5)
		each_author.set_author_year_of_birth(stoi(word));

	if (i == 6)
		each_author.set_author_place_of_birth(word);

	if (i == 7)
		each_author.set_author_genres(create_genre_list(word));
}

void GoodReads::read_from_file_authors(string directory)
{
	directory.insert(6, AUTHORS);
	ifstream authors_file(directory);

	Author each_author;
	string line, word;
	getline(authors_file, line);
	for (int j = 0; getline(authors_file, line); j++)
	{
		stringstream ss_line(line);

		for (int i = 1; getline(ss_line, word, COMMA); i++)
			write_each_author_inf(i, word, each_author);

		authors.push_back(each_author);
	}
}



void GoodReads::write_each_review_inf(int i, string word, int& index, Review& each_review)
{
	if (i == 1)
		each_review.set_review_id(stoi(word));

	if (i == 2)
		each_review.set_review_book_id(stoi(word));

	if (i == 3)
	{
		index = find_user_index(word);
		each_review.set_review_user_id(stoi(word));
	}

	if (i == 4)
		each_review.set_review_rating(stoi(word));

	if (i == 5)
		each_review.set_review_date(word);

	if (i == 6)
	{
		count_number_of_user_reviews_likes(index, word);
		count_number_of_user_reviews(index);
		each_review.set_review_likes(stoi(word));
	}
}

void GoodReads::read_from_file_reviews(string directory)
{
	directory.insert(6, REVIEWS);
	ifstream reviews_file(directory);

	Review each_review;
	int index;
	string line, word;
	getline(reviews_file, line);
	for (int j = 0; getline(reviews_file, line); j++)
	{
		stringstream ss_line(line);

		for (int i = 1; getline(ss_line, word, COMMA); i++)
			write_each_review_inf(i, word, index, each_review);

		reviews.push_back(each_review);
	}

	create_each_book_reviews();
}

void GoodReads::create_each_book_reviews()
{
	for (int i = 0; i < reviews.size(); i++)
	{
		for (int j = 0; j < books.size(); j++)
		{
			if (reviews[i].get_review_book_id() == books[j].get_book_id())
				books[j].set_review_book(&reviews[i]);
		}
	}
}



void GoodReads::write_each_follow_list(int user_index, string word, int i)
{
	if (i == 1)
		users[user_index].set_followings_list(create_follow_list(word));

	if (i == 2)
		users[user_index].set_followers_list(create_follow_list(word));
}

void GoodReads::read_from_file_follow_edges(string directory)
{
	directory.insert(6, FOLLOW_EDGES);
	ifstream follow_file(directory);

	User each_user;
	string line, word;
	getline(follow_file, line);
	for (int j = 0; getline(follow_file, line); j++)
	{
		stringstream ss_line(line);

		getline(ss_line, word, COMMA);
		int user_index = find_user_index(word);
		for (int i = 1; getline(ss_line, word, COMMA); i++)
			write_each_follow_list(user_index, word, i);
	}
}

numsTable GoodReads::create_follow_list(string word)
{
	numsTable follow_list;
	stringstream ss_word(word);
	for (int i = 1; getline(ss_word, word, DOLLAR); i++)
		follow_list.push_back(stoi(word));

	return follow_list;
}



void GoodReads::show_author_info(int author_id)
{
	for (int i = 0; i < authors.size(); i++)
	{
		if (authors[i].get_author_id() == author_id)
		{
			authors[i].print_author_info();
			break;
		}
	}

}




void GoodReads::show_sorted_shelf(int user_id, string shelf_type, string genre)
{
	pbooks user_books_list = list_books(user_id, shelf_type);
	for (int i = 0; i < user_books_list.size(); i++)
	{
		if (user_books_list[i]->get_book_genre() == genre)
			print_shelf_book_inf(user_books_list, i);
	}

	for (int i = 0; i < user_books_list.size(); i++)
	{
		if (user_books_list[i]->get_book_genre() != genre)
			print_shelf_book_inf(user_books_list, i);
	}
}

pbooks GoodReads::list_books(int user_id, string shelf_type)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_id() == user_id)
			return find_user_shelf(shelf_type, i);
	}
}

pbooks GoodReads::find_user_shelf(string shelf_type, int i)
{
	if (shelf_type == WANT_TO_READ_SHELF)
	{
		auto want_to_read = users[i].get_want_to_read();
		sort(want_to_read.begin(), want_to_read.end(), 
		[](Book* a, Book* b) { 
			if(a->get_book_title() == b->get_book_title())
				return a->get_book_id() < b->get_book_id();
			return a->get_book_title() < b->get_book_title();});

		return want_to_read;
	}
	if (shelf_type == CURRENTLY_READING_SHELF)
	{
		auto currently_reading = users[i].get_currently_reading();
		sort(currently_reading.begin(), currently_reading.end(),
		[](Book* a, Book* b) { 
			if(a->get_book_title() == b->get_book_title())
				return a->get_book_id() < b->get_book_id();
			return a->get_book_title() < b->get_book_title();});

		return currently_reading;
	}

	if (shelf_type == READ_SHELF)
	{
		auto read = users[i].get_read();
		sort(read.begin(), read.end(),
		[](Book* a, Book* b) { 
			if(a->get_book_title() == b->get_book_title())
				return a->get_book_id() < b->get_book_id();
			return a->get_book_title() < b->get_book_title();});

		return read;
	}
}

void GoodReads::print_shelf_book_inf(pbooks user_books_list, int i)
{
	user_books_list[i]->print_book_inf();
	print_author_name(user_books_list[i]->get_book_author_id());
	cout << "***" << endl;
}


void GoodReads::print_user_credit(int user_id)
{
	int index = find_user_index(to_string(user_id));
	double user_credit = users[index].calculate_user_credit(all_likes, all_reviews);

	cout << fixed << setprecision(6) << users[index].calculate_user_credit(all_likes, all_reviews) << endl;
}

void GoodReads::count_number_of_user_reviews_likes(int index, string word)
{
	users[index].set_number_of_user_review_likes(stoi(word));
	all_likes += stoi(word);
}

void GoodReads::count_number_of_user_reviews(int index)
{
	users[index].set_number_of_user_reviews();
	all_reviews++;
}


Book* GoodReads::find_best_book(double& max_average)
{
	Book* ptr_book;
	double average;
	for (int i = 0; i < books.size(); i++)
	{
		average = books[i].calculate_average_book_ratings();

		if (average > max_average)
		{
			ptr_book = &books[i];
			max_average = average;
		}
	}

	return ptr_book;
}

void GoodReads::print_best_book_inf()
{
	double max_average = INVALID;
	Book* best_book = find_best_book(max_average);

	best_book->print_book_inf();
	print_author_name(best_book->get_book_author_id());

	cout << "Average Rating: " << fixed << setprecision(2) << max_average << endl;
}



User* GoodReads::find_best_reviwer(int& max_likes)
{
	User* ptr_user;
	for (int i = 0; i < users.size(); i++)
	{
		if(users[i].get_number_of_user_reviews() == 0)
			continue;

		int likes = users[i].get_number_of_user_review_likes();
		if (likes > max_likes)
		{
			ptr_user = &users[i];
			max_likes = users[i].get_number_of_user_review_likes();
		}
	}
	return ptr_user;
}

void GoodReads::print_best_reviwer_inf()
{
	int max_likes = INVALID;
	User* best_reviewer = find_best_reviwer(max_likes);
	if(max_likes == INVALID)
		return;

	best_reviewer->print_user_inf();
	cout << "Number of Likes: " << max_likes << endl;
}



void GoodReads::print_appropriate_book_inf_1(int id)
{
	Book* appropriate_book = find_appropriate_book(id);
	print_appropriate_book_inf(appropriate_book);
}
void GoodReads::print_appropriate_book_inf(Book* appropriate_book)
{
	appropriate_book->print_book_inf();
	print_author_name(appropriate_book->get_book_author_id());
	cout << "Reviews:" << endl;
	for (int i = 0; i < appropriate_book->get_reviews_of_book().size(); i++)
		appropriate_book->get_reviews_of_book()[i]->print_review_inf();
}

Book* GoodReads::find_appropriate_book(int id)
{
	double max_score = INVALID;
	Book* ptr_book;
	for (int i = 0; i < books.size(); i++)
	{
		double score = calculate_each_book_score(id, i);
		if (score > max_score)
		{
			ptr_book = &books[i];
			max_score = score;
		}
	}
	return ptr_book;
}

double GoodReads::calculate_each_book_score(int id, int i)
{
	double rating = calculate_each_book_rating(i);
	double score = 0;

	int index = find_user_index(to_string(id));
	for (int k = 0; k < users[index].get_favorite_genres().size(); k++)
	{
		if (books[i].get_book_genre() == users[index].get_favorite_genres()[k])
		{
			score = FAVORITE + rating;
			break;
		}
		else
			score = rating;
	}
	return score;
}

double GoodReads::calculate_each_book_rating(int i)
{
	vector<Review*> reviews_of_book = books[i].get_reviews_of_book();
	return calculate_rating(reviews_of_book);
}

double GoodReads::calculate_rating(vector<Review*> reviews_of_book)
{
	double sum = 0;
	int j = 0;
	for (j = 0; j < reviews_of_book.size(); j++)
	{
		int user_id = reviews_of_book[j]->get_review_user_id();
		int index = find_user_index(to_string(user_id));

		sum += (reviews_of_book[j]->get_review_rating()) *
			users[index].calculate_user_credit(all_likes, all_reviews);
	}

	double rating = 0;
	if (j != 0)
		rating = sum / j;

	return rating;
}



void GoodReads::find_user_following_series(int user_id, numsTable& following_series)
{
	following_series.push_back(user_id);
	int index = find_user_index(to_string(user_id));
	int flag = 0;
	numsTable current_user_followings = users[index].get_followings_list();

	for (int i = 0; i < current_user_followings.size(); i++)
	{
		for (int j = 0; j < following_series.size(); j++)
			if (current_user_followings[i] == following_series[j])
				flag = 1;

		if (flag == 1)
			continue;

		find_user_following_series(current_user_followings[i], following_series);
	}
}

numsTable GoodReads::create_top_books_to_recommend(int user_id)
{
	numsTable following_series;
	find_user_following_series(user_id, following_series);
	numsTable all_top_books;
	for (int i = 1; i < following_series.size(); i++)
		find_each_user_top_books(following_series[i], all_top_books);

	sort(all_top_books.begin(), all_top_books.end());
	return all_top_books;
}

void GoodReads::find_each_user_top_books(int each_user_id, numsTable& all_top_books)
{
	int index = find_user_index(to_string(each_user_id));
	pbooks ptr_books = users[index].get_read();
	sort(ptr_books.begin(), ptr_books.end());
	Book* book1 = NULL;
        Book* book2 = NULL;
	Book* book3 = NULL;

	double max_rating1 = -1;
	double max_rating2 = -1;
	double max_rating3 = -1;

	for (int i = 0; i < ptr_books.size(); i++)
	{
		vector<Review*> reviews_of_book = ptr_books[i]->get_reviews_of_book();
		double current_rating = calculate_rating(reviews_of_book);

		if (current_rating > max_rating1)
		{
			max_rating3 = max_rating2;
			book3 = book2;

			max_rating2 = max_rating1;
			book2 = book1;

			max_rating1 = current_rating;
			book1 = ptr_books[i];
		}

		else if (current_rating > max_rating2)
		{
			max_rating3 = max_rating2;
			book3 = book2;

			max_rating2 = current_rating;
			book2 = ptr_books[i];
		}
		else if (current_rating > max_rating3)
		{
			max_rating3 = current_rating;
			book3 = ptr_books[i];
		}
	}

	if (book1 != NULL)
		all_top_books.push_back(book1->get_book_id());

	if (book2 != NULL)
		all_top_books.push_back(book2->get_book_id());

	if (book3 != NULL)
		all_top_books.push_back(book3->get_book_id());

}

int GoodReads::find_appropriate_book_id(int user_id)
{
	numsTable top_books = create_top_books_to_recommend(user_id);
	int max_count = 0;
	int appropriate_book_id;
	for (int i = 0; i < top_books.size(); i++)
	{
		int current_count = count(top_books.begin(), top_books.end(), top_books[i]);
		if (current_count > max_count)
		{
			max_count = current_count;
			appropriate_book_id = top_books[i];
		}
	}
	return appropriate_book_id;
}

Book* GoodReads::find_appropriate_book_address(int user_id)
{
	int appropriate_book_id = find_appropriate_book_id(user_id);
	for (int i = 0; i < books.size(); i++)
		if (appropriate_book_id == books[i].get_book_id())
			return &books[i];
}

void GoodReads::print_appropriate_book_inf_2(int user_id)
{
	Book* appropriate_book = find_appropriate_book_address(user_id);
	print_appropriate_book_inf(appropriate_book);
}

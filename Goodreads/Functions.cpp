#include "Functions.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#define SHOW_AUTHOR_INFO "show_author_info"
#define SHOW_SORTED_SHELF "show_sorted_shelf"
#define CREDIT "credit"
#define BEST_BOOK "best_book"
#define BEST_REVIEWER "best_reviewer"
#define FIRST_APPROACH "recommend_first_approach"
#define SECOND_APPROACH "recommend_second_approach"

using namespace std;

void read_from_files(GoodReads& source,char *argv[])
{
	source.read_from_file_authors(argv[1]);
	source.read_from_file_books(argv[1]);
	source.read_from_file_users(argv[1]);
	source.read_from_file_reviews(argv[1]);
	source.read_from_file_follow_edges(argv[1]);
}

void command_list(string command,GoodReads source)
{
	int user_id;
	int author_id;
	if (command == SHOW_AUTHOR_INFO)
	{
		cin >> author_id;
		source.show_author_info(author_id);
	}

	if (command == SHOW_SORTED_SHELF)
	{
		cin >> user_id;

		string shelf_type;
		cin >> shelf_type;

		string genre;
		getline(cin >> ws, genre);

		source.show_sorted_shelf(user_id, shelf_type, genre);
	}

	if (command == CREDIT)
	{
		cin >> user_id;
		source.print_user_credit(user_id);
	}

	if (command == BEST_BOOK)
		source.print_best_book_inf();

	if (command == BEST_REVIEWER)
		source.print_best_reviwer_inf();

	if (command == FIRST_APPROACH)
	{
		cin >> user_id;
		source.print_appropriate_book_inf_1(user_id);
	}
	if (command == SECOND_APPROACH)
	{
		cin >> user_id;
		source.print_appropriate_book_inf_2(user_id);
	}
}

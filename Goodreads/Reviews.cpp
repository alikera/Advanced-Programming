#include <iostream>
#include <cstdlib>

#include "Reviews.hpp"

using namespace std;

void Review::print_review_inf()
{
	cout << "id: " << review_id_ << " Rating: " << review_rating_
		<< " Likes: " << review_likes_ << " Date: " << review_date_ << endl;
}

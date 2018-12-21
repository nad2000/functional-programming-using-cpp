#include <fplus/fplus.hpp>
#include <iostream>

using namespace std;
using namespace fplus;

struct user {
	string name, country;
	size_t visits;

	string get_country() {return this->country;};
	size_t get_visits() {return this->visits;};
};

string get_country(const user& u) {return u.country;}
size_t get_visits(const user& u) {return u.visits;}

const size_t visit_sum(const vector<user>& users) {
	return fwd::apply(users
		, fwd::transform(get_visits)
		, fwd::sum());
}



int main() {
	const vector<user> users = {
		{"Nicole", "GER", 2},
		{"Justin", "USA", 1},
		{"Rachel", "USA", 5},
		{"Robert", "USA", 6},
		{"Stefan", "GER", 4}
	};

	// Get total visits by country:
	// with SQL:
	// SELECT country, SUM(visits)
	// FROM users
	// GROUP BY country;
	
	const auto result = fwd::apply(users
		, fwd::group_globally_on_labeled(get_country)
		, fwd::transform(fwd::transform_snd(visit_sum))
	);

	cout << show_cont(result) << endl;

	// n * log(n)
	const auto result0 = fwd::apply(users
		, fwd::sort_on(get_country)
		, fwd::group_on_labeled(get_country)
		, fwd::transform(fwd::transform_snd(visit_sum))
	);

	cout << show_cont(result0) << endl;
}


#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
using namespace std;

/*
  s e n d
+ m o r e
---------
m o n e y
*/

// dispite of so many 'for' it spent less than 1 sec. to find solution

int main() {

	unsigned more;
	unsigned send;
	unsigned money;

	vector<tuple<unsigned, unsigned, unsigned>> results;

	unsigned m, o, r, e, s, n, d, y;
	m = 1;	// for optimization
	for (s = 8; s != 10; ++s) {	// for optimization
		for (d = 0; d != 10; ++d) {
			for (y = 0; y != 10; ++y) {
				for (e = 0; e != 10; ++e) {
					if ((e + d) % 10 == y) {	// for optimization
						for (r = 0; r != 10; ++r) {
							for (n = 0; n != 10; ++n) {
								if ((r + n + ((e + d) / 10)) % 10 == e) {	// for optimization
									for (o = 0; o != 10; ++o) {
										if (o + e + ((r + n + ((e + d) / 10)) / 10) == n % 10) {	// for optimization
											set<unsigned> uniq{ m, o, r, e, s, n, d, y };
											if (uniq.size() == 8) {	// digits should be different
												more = m * 1000 + o * 100 + r * 10 + e;
												send = s * 1000 + e * 100 + n * 10 + d;
												money = m * 10000 + o * 1000 + n * 100 + e * 10 + y;
												if (more + send == money) {
													results.emplace_back(make_tuple(more, send, money));
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}


	for (const auto &a : results) {
		cout << get<0>(a) << '\t' << get<1>(a) << '\t' << get<2>(a) << endl;
	}

	return 0;
}

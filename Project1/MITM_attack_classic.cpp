#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

vector<cpp_int> gcd_for_numbers(cpp_int N_i, cpp_int n_i) {

	cpp_int r0 = N_i;
	cpp_int r1 = n_i;
	cpp_int r2 = 1;
	vector<cpp_int> Q;

	while (r2 > 0) {
		cpp_int q = r0 / r1;
		r2 = r0 % r1;
		Q.push_back(q);
		r0 = r1;
		r1 = r2;
	}
	return Q;
}

cpp_int extended_euclid_alg(cpp_int N_i, cpp_int n_i) {

	N_i = N_i % n_i;
	vector<cpp_int> for_q = gcd_for_numbers(N_i, n_i);
	cpp_int u0 = 1;
	cpp_int u1 = 0;
	cpp_int v1 = 1;
	cpp_int v0 = 0;

	for (long long i = 0; i < for_q.size() - 1; i++) {
		cpp_int q = for_q[i];
		cpp_int u2, v2;
		u2 = u0 - u1 * q;
		v2 = v0 - v1 * q;
		u0 = u1;
		u1 = u2;
		v0 = v1;
		v1 = v2;
	}

	cpp_int u = u1;
	cpp_int v = v1;
	cpp_int M = 0;

	if (N_i * u + n_i * v == 1) {
		if (u < 0) { u = u + n_i; }
		M = u;
	}

	return M;
}

pair<vector<pair<cpp_int, cpp_int>>, vector<cpp_int>> form_pair(cpp_int n, cpp_int e, int l) {

	vector<pair<cpp_int, cpp_int>> X;

	vector<cpp_int> Te_converse;

	for (int i = 1; i <= pow(2, (l / 2)); i++) {

		cpp_int Te = powm(cpp_int(i), e, n);

		X.push_back(make_pair(Te, i));

		Te_converse.push_back(extended_euclid_alg(Te, n));
	};

	return make_pair(X, Te_converse);
}

int main(){
	int l = 20;
	cpp_int e("65537");

	cpp_int C("0x1bede6fd06724fa47581ef8dd5c7fe537f389ce72582951c901bcfcb48ea911cc2882d5d10025ad5db6e533db506a0d52d4482a4f790209117052a44ec1ad1e1");
	cpp_int n("0xBE9876D922C5BF0A33E2A96FEBCC9AAF7C2BF64071363B8B5C0DB75F5705F46E421D5E365A0C6220BA36E712D62706D369FED0B306DCDD7B4ACFC567AEB67A85");

	vector<pair<cpp_int, cpp_int>> X;
	vector<cpp_int> Te_converse;

	auto info = form_pair(n, e, l); 

	X = info.first;
	Te_converse = info.second;

	cpp_int M1 = 0, M2 = 0; 

	for (int s = 1; s <= pow(2, (l / 2)); s++) {
		cpp_int Cs = (C * Te_converse[s - 1]) % n;

		for (int i = 0; i < X.size(); i++) {
			if (X[i].first == Cs) {
				M1 = s;
				M2 = X[i].second;
				break;
			};
		}

		if (M1 != s && s == pow(2, (l / 2))) {
			cout << "The plaintext was not defined.";
		}

		else if (M1 == s) { break; };

	}

}
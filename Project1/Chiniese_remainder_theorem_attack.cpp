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

cpp_int chinese_remainder_theorem(const vector<cpp_int>& C_i, const vector<cpp_int>& n_i) {

	cpp_int N = 1;
	for (long long j = 0; j < n_i.size(); j++) {
		N = N * n_i[j];
	}
	vector<cpp_int> N_i;
	for (long long j = 0; j < n_i.size(); j++) {
		N_i.push_back(N / n_i[j]);
	}

	vector<cpp_int> M_e;
	for (long long j = 0; j < n_i.size(); j++) {
		cpp_int M_i = extended_euclid_alg(N_i[j], n_i[j]);
		M_e.push_back(M_i);
	}

	cpp_int C = 0;
	for (long long j = 0; j < n_i.size(); j++) {
		C = (C + (C_i[j] * N_i[j] * M_e[j])) % N;
	}

	return C;

}

cpp_int root(cpp_int C, int e) {
	cpp_int M_low = 0;
	cpp_int M_high = C;
	cpp_int C_mid;

	while (M_low + 1 < M_high) {
		C_mid = (M_high + M_low) / 2;
		cpp_int temp = 1;
		for (int i = 0; i < e; i++) {
			temp = temp * C_mid;
		}
		if (temp > C) { M_high = C_mid; }
		else if (temp < C) { M_low = C_mid; }
		else { return C_mid; }
	}

	return M_low;
}

int main() {
	int e = 5;

	cpp_int C1("0x1c8e662244ed68aec1436dafb3f84f74f2d1b047a54c6c685ff73404f6c5e515cabb17840bfd4de1df0e4f3334f882c60e9f05b783d7c55be35d0b02f9f3e56dac22abe13b7cd22d78eb9f709f827ab7b273b7096430df099b94276d38cadb184a945d534ad01de00acdc4dd88aa0bf527f3bf54bbd7b70d25c4fc4c92437c7c");
	cpp_int n1("0xC6E249C705C2BA092F925819623253EF8F23DA3E2CB70106AFCE07E8FFF4024BFA994A7BC33C99EA8A8320F0B9E0368403ABEAB78F8DC6AB7D44117022A2DE96FBE48E2DABA525888924B0172DD11197173C6D7DCA6D745CCD9027B90ADA59156C106AD28653D528845DB109C7F1C6921F4FE55AE00A68B5C673BFCA3BA70651");

	cpp_int C2("0x54fedb2618069fb56de6d04d0c3202ad236f026cf2efa640ba77f18d780ed87a861ff9a68c164452b47e6d2aa4189a0e3414c78dc1a702e82e4a6c976b9eb2395dfddf8471e84ca5a75f8d725cfa2379c35b1f8dbc21479adff70b4959ffef5156eab789ff58f5b4e8205e34dec6104923a0576337bd54e347392f69ee8c8ad2");
	cpp_int n2("0xC578EEC934A8FA5A3F436F6342D4B4A661A176FDFD4283969E06EE51E0C9D5A897321C5425C2DFC0B66BB830CE9896CAD459651BDE2EAEB8286610601905F35FAF6EAB4D29F0D0F1DF788EAFD6416A142ABA2640803B0C88760FA271A7F7575AE6441D701A3E11EF89D448FA7C95F2B22641871C7C8F3831320F9AEB9DC433F3");

	cpp_int C3("0x2672369fa3ba2eb14644587d7b1c1faea6e5c5441d07102387df3ec5f49ed45da5860053057f5bd27081adcfd424ef0c3ec41480fad66b37fe9d5f179e4072deda644a3069a1d21c37837b6837c2a493068be76ff54b6c9b0c9672942157c7735d3856e538321916cb7cee60afa81fb9218e3591c82c780ef1f5cc837dee76c2");
	cpp_int n3("0xBCEF8437014F92C2E947B74E8D6F78E1EC540FA88756E0E2270CA31AFDE3A495EF5D488489B7B9B6203F1924470C4588CD420A8E935EB26E1F93CABAC4F6BEE1DEB87D587422AA0EE3057BA874DC66447F9E1D452EF18598E9B14F3F89FB40AFC9768DBD452CB9D853E1E4783B7E2C04B324F386CCC80F2A24E3356F4CEBCF73");

	cpp_int C4("0xbefb533504c6d59ae53220703f26832d70bff1f821ce0682a8b8d2585e0a20226737b9cba68b684a8a4460229fca98d5ce6f12d735cc4e00f0ed547c151b07b366e019fb7b4e6e2d17be07e9fb8ce08bea07aed7eff82d41db88d09391eec8fc5b3ea7be4be97c661166b90e9ed12ecab8f06ce114516ea51119a66ca2053d39");
	cpp_int n4("0xE55057E99DC6F5978D0BC1A1478800785E789329A87CA934460768E5DEB4CB197C8F1C4B074F6E6DE938D6D0F1F60B5A30D8EE62F197B97905978D9C57693B9985CA986C59ABB9613627EF252867F24D545A79A01BBD501B9A904521DA90B1EA7FFD8A21152FF77734728E8CEFFE7F9B9C8EA4A6DA4F836C3FFA5CEF2582556B");
	
	cpp_int C5("0x08b49b6929557c76040abe1d9ad891219b16858fbf99db1d00df92f0b6236148db9f0d71fabc2b2c7a235d20211786d09c4d9c902454602e46a5ff304083b4f7e9cac16bca12270c66498323460469d2bedb6216b794db5dc6276313a610f7a65142df3f5dc10f69bf7a97ae76a452c1333d41c1c4f3d7f42dbb9c72a71e6ccb");
	cpp_int n5("0xC35E7C67D8487ECD88AA7DB0093039F5A9646660D16BC56ADD906225855419047E59A8602E6875E02C52188B98B04C643C7AC1BB27F2DEA9D6B5A4BFE4AC99CF0FAD26446C6180D0F576BCD4B8792CDD4BC45FD077AB012722B57AE4E43CC5A6079C2B8F55E2A8D8B9179C5C3F7D0EF3C43B6A4B90AE186B52438490D939F1F3");

	vector<cpp_int> for_C_i = { C1, C2, C3, C4, C5 }; 
	vector<cpp_int> for_n_i = { n1, n2, n3, n4, n5 };

	cpp_int C = chinese_remainder_theorem(for_C_i, for_n_i); 
	cpp_int M_with_pad = root(C, e);

	cout << hex << M_with_pad << endl;

	cpp_int check = 1;
	for (int i = 0; i < e; i++) {
		check = check * M_with_pad;
	}

	if (check == C) {
		cout << "Succesful" << endl;
	}
	else {
		cout << "Error" << endl;
	}

}
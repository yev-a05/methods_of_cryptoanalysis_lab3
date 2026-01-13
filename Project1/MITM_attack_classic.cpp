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

int main(){
	int l = 20;
	cpp_int e("65537");

	cpp_int C("0x1bede6fd06724fa47581ef8dd5c7fe537f389ce72582951c901bcfcb48ea911cc2882d5d10025ad5db6e533db506a0d52d4482a4f790209117052a44ec1ad1e1");
	cpp_int n("0xBE9876D922C5BF0A33E2A96FEBCC9AAF7C2BF64071363B8B5C0DB75F5705F46E421D5E365A0C6220BA36E712D62706D369FED0B306DCDD7B4ACFC567AEB67A85");

	vector<pair<cpp_int, cpp_int>> X;
	vector<cpp_int> Te_converse;

}
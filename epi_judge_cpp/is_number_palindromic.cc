#include "test_framework/generic_test.h"
bool IsPalindromeNumber(int x) {
	if(x<=0) return x==0;
	int ndigits=static_cast<int>(floor(log10(x)))+1;
	int msd_mask=static_cast<int>(pow(10,ndigits-1));
	for(int i=0;i<ndigits/2;++i)
	{
		if(x/msd_mask != x%10)
		{
			return false;
		}
		x %= msd_mask;
		x /= 10;
		msd_mask /= 100;
	}
	return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "is_number_palindromic.cc",
                         "is_number_palindromic.tsv", &IsPalindromeNumber,
                         DefaultComparator{}, param_names);
}

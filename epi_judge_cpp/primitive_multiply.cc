#include "test_framework/generic_test.h"

unsigned long long Add(unsigned long long x, unsigned long long y)
{
	unsigned long long carry=0;
	while(y)
	{
		carry=(x&y);
		x ^= y;
		y=(carry<<1);
	}
	return x;
}

unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  // TODO - you fill in here.
  // BF - initialize sum=0 and add x to it y times, worst case runtime O(2^n) where n is number of bits needed to represent y in binary (max y=2^(n+1)-1)
  // O(n^2) approach
  unsigned long long sum=0;
  while(x)
  {
  	if( (x&1)==1 )
  	{
  		sum=Add(sum,y);
  	}
  	x >>= 1;
  	y <<= 1;
  }
  return sum;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}

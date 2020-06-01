#include "test_framework/generic_test.h"
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
  // O(n) solution, n=number of bits
  // Look for right most bit (i) that is different bit (i+1)
  // and swap these 2 bits
  const static int nBits=64;
  for(int i=0;i<nBits-2;++i)
  {
  	if( ((x>>i)&1) != ((x>>(i+1))&1) )
  	{
  		x ^= (1UL<<i) | (1UL<<(i+1)); // since bits at i and i+1 are different swapping them is same as xor-ing them independently with 1
  		return x;
  	}
  }
  throw std::invalid_argument("All bits are 0 or 1");
}

unsigned long long ClosestIntSameBitCount2(unsigned long long x)
{
	// O(1) solution
	// Look for right most bit that is different from LSB, say bit i
	// then swap bits i and i-1
	unsigned long long z=0;
	if((x&1)==0)
	{
		// LSB is 0, look for right most bit which is 1
		z= x & ~(x-1); // isolates the lowest set bit in x
	}
	else
	{
		// LSB is 1, look for right most bit which is 0
		// same as looking for right most bit which is 1 in ~x
		z= (~x) & ~((~x)-1); // isolates the lowest set bit in ~x
	}
	x ^= z | (z>>1);
	return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount2,
                         DefaultComparator{}, param_names);
}

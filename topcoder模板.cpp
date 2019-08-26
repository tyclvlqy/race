#include <string>  
#include <vector>
using namespace std; 
class InfiniteSequence {  
	public:  
    	long long calc(long long n, int p, int q) {  
        	if (n == 0)  
            	return 1;  
        	else  
            return calc(n/p, p, q) + calc(n/q, p, q);  
    	}  
}; 

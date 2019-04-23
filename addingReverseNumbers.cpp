#include <iostream>
using namespace std;

int main() {
	
	int testCases;
	cin>>testCases;
	int a,b,reva,revb,sum=0,revsum=0;
	for(int i=0; i<testCases; i++) {
		cin>>a>>b;
		reva = revb = revsum = sum = 0;
		
		while(a != 0) {
			//reva += (a%10)*10;
			reva *= 10;
			reva += a%10;
			a = a/10;
		}
		
		while(b != 0) {
			//revb += (b%10)*10;
			revb *= 10;
			revb += b%10;
			b = b/10;
		}
		//cout<<"reva:"<<reva<<endl;
		//cout<<"revb:"<<revb<<endl;
		sum = reva + revb;
		
		while(sum != 0) {
			//revsum += (sum%10)*10;
			revsum *= 10;
			revsum += sum%10;
			sum =sum/10;
		}
		cout<<revsum<<endl;
		
	}

	return 0;
}

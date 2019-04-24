#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

vector<int>* seive(){

  bool isPrime[MAX];
  for(int i=0; i<MAX; i++) {
    isPrime[i]=true;
  }
  for(int i = 2; i*i < MAX; ++i) {
    if(isPrime[i]) {
      for(int j = i*i; j < MAX; j+=i) {
        isPrime[j] = false;
      }
    }
  }

  vector<int>* primes = new vector<int>();
  primes->push_back(2);
  for(int i = 3; i < MAX; i+=2){
    if(isPrime[i]) {
	 primes->push_back(i);
	}
  }
  return primes;
}

void printPrimes(long long l, long long r, vector<int>* & primes) {
  bool isPrime[r-l+1];

  for(int i = 0; i <= (r-l); ++i) {
    isPrime[i] = true;
  }

  for(int i = 0; primes->at(i)*(long long)primes->at(i) <= r; ++i) {
    int currentPrime = primes->at(i);
    long long base = (l/currentPrime)*currentPrime;

    if(base < l) {
      base += currentPrime;
    }

    for(long long j = base; j <= r; j+= currentPrime) {
      isPrime[j-l] = false;
    }

    if(base == currentPrime) {
      isPrime[base - l] = true;
    }

  }
  if(l == 1){
  	isPrime[0] = false;
  }

  for(int i = 0; i<= r-l; i++) {
    if(isPrime[i] == true){
      cout<<i+l<<endl;
    }
  }
}

int main(){
  vector<int>* primes = seive();
  int t;
  long long l,r;
  cin>>t;
  while(t--){
    cin>>l>>r;
    printPrimes(l,r,primes);
  }
  return 0;
}

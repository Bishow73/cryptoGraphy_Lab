#include <iostream> 
#include <stdlib.h> 
#include <math.h> 
using namespace std; 

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
}

int main() {
  double m, p, q, e, i, d;
  int flag;
  
  cout<<"Enter the number to be encrypted and decryted\n";
  cin>>m;
  
  // Choose 2 distinct random prime numbers
  cout<<"Enter first prime number\n";
  cin>>p;
  
  cout<<"Enter second prime number\n\n";
  cin>>q;
  
  // Compute n = p x q
  int n = p*q;
  
  // Compute phi
  int phi = (p-1)*(q-1);
  
  // Choose e such that it lies between 1<e<phi & gcd(e,phi)=1
  for(i=2; i<phi; i++)
  {
    if(gcd(i,phi)==1)
    {
      e = i;
      break;
    }
  }
  
  // Choose d such that (d*e) mod n = 1
  // j = (phi * i) + 1
  // d = j / e  -> iterate i till d does not come in point
  i = 1;
  while(true)
  {
    int j = (phi * i) + 1;
    if(fmod(j,e) == 0)
    {
      d=j/e;
      break;
    }
    i++;
  }
  
  cout<<"The value of phi: "<<phi<<endl;
  cout<<"The value of d: "<<d<<endl;
  cout<<"The value of e: "<<e<<endl;
  cout<<"Public encryption key: (" <<e<<" , " <<n<< ") "<<endl;
  cout<<"Private dencryption key: (" <<d<<" , " <<n<< ") "<<endl;
  
  // Ciphertext c = (m^e) mod n
  int cipher = fmod(pow(m,e), n);
  cout<<"Encrypted Ciphertext : "<<cipher<<endl;
  
  // Plaintext m = (c^d) mod n
  int plain = fmod(pow(cipher, d), n);
  cout<<"Encrypted Plaintext : "<<plain<<endl;
  
  return 0;
}

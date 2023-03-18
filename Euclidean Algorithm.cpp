//Euclidean Algorithm to find GCD of two integers
#include<iostream>
using namespace std;
int EuclideanGcd(int a,int b){
	if(b==0)
		return a;
	else
		return EuclideanGcd(b,a%b);
}
int main(){
	cout<<"\n			Implementation of Euclidean Algorithm to Compute GCD	\n \n";
	int num1,num2,gcd;
	cout<<"\n Enter two integers\n ";
	cin>>num1>>num2;
	gcd = EuclideanGcd(num1,num2);
	cout<<"\nGCD of " << num1 <<" and " <<num2 <<" is,  gcd("<<num1<<","<<num2<<") = "<<gcd <<"\n";
	return 0;
}

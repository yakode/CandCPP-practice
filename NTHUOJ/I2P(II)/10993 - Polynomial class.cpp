#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Polynomial
{

public:
    Polynomial();
    Polynomial(const int , const int [51]);
    Polynomial add( const Polynomial) const; // add function
    Polynomial subtract( const Polynomial ) const; // subtract function
    Polynomial multiplication( const Polynomial ) const; // multiplication function
    void output() const;
private:
    int coefficients[101]; // integer coefficients
    int greatestPower; // integer greatestPower
}; // end class Polynomial

Polynomial:: Polynomial(): greatestPower{0}, coefficients{} {};

Polynomial:: Polynomial(const int gp, const int co[51]){
	for(int i = 0; i < 101; i++)
		coefficients[i] = (i <= gp)? co[i] : 0;
	greatestPower = gp;
}

Polynomial Polynomial::add(const Polynomial b) const{
	Polynomial *ans = new Polynomial;
	int safe = 0;
	if(b.greatestPower > greatestPower) ans->greatestPower = b.greatestPower;
	else ans->greatestPower = greatestPower;
	for(int i = ans->greatestPower; i >= 0; i--){
		ans->coefficients[i] = coefficients[i] + b.coefficients[i];
		if(safe == 0){
			if(ans->coefficients[i] == 0) ans->greatestPower = i - 1;
			else safe = 1;
		}	
	}
	return *ans;
}

Polynomial Polynomial::subtract(const Polynomial b) const{
	Polynomial *ans = new Polynomial;
	int safe = 0;
	if(b.greatestPower > greatestPower) ans->greatestPower = b.greatestPower;
	else ans->greatestPower = greatestPower;
	for(int i = ans->greatestPower; i >= 0; i--){
		ans->coefficients[i] = coefficients[i] - b.coefficients[i];
		if(safe == 0){
			if(ans->coefficients[i] == 0) ans->greatestPower = i - 1;
			else safe = 1;
		}	
	}
	return *ans;
}

Polynomial Polynomial::multiplication( const Polynomial b) const{
	Polynomial *ans = new Polynomial;
	ans->greatestPower = greatestPower + b.greatestPower;
	for(int i = greatestPower; i >= 0; i--){
		for(int j = b.greatestPower; j >= 0; j--){
			ans->coefficients[i+j] += coefficients[i] * b.coefficients[j];
		}
	}
	return *ans;
}

void Polynomial::output() const{
	for(int i = greatestPower; i > 0; i--){
		cout << coefficients[i] << " ";
	}
	cout << coefficients[0];
}

int main()
{
    int greatestPower1, greatestPower2;
    int coefficient1[51], coefficient2[51];
    Polynomial ans;

    cin>>greatestPower1;
    for(int i = greatestPower1 ; i >= 0; i--)
    {
        cin>>coefficient1[i];
    }
    cin>>greatestPower2;
    for(int i = greatestPower2 ; i >= 0 ; i--)
    {
        cin>>coefficient2[i];
    }
    Polynomial a(greatestPower1, coefficient1), b(greatestPower2, coefficient2) ;

    ans = a.add( b );
    ans.output();
    cout << endl;

    ans = a.subtract( b );
    ans.output();
    cout << endl;

    ans = a.multiplication( b );
    ans.output();
    cout << endl;

}


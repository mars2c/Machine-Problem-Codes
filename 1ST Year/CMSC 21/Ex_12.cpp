#include <iostream>
#include <cstdlib>
using namespace std;

class fraction{

    public:
        int numerator;
        int denominator;

        fraction(){
            numerator = 1;
            denominator = 1;
        }
        fraction(int A, int B){
            this->numerator = A;
            this->denominator = B;
        }
        void Nume(int A){
            this->numerator = A;
        }
        void Deno(int B){
            this->denominator = B;
        }

        void add(fraction B){
            int temp = this->denominator;
            int result1, result2, result3, result4, result;
            int newN, newD;
            char sl = '/';
                
            result1 = this->denominator *= B.denominator;
            result2 = this->numerator *= B.denominator;
            result3 = B.numerator *= temp;
            result4 = this->numerator += B.numerator;
            result = this->simplify();
            newD = result1 / result;
            newN = result4 / result;

            if(newN == 0){
                cout << 0 << endl;
            }
            else if(newD == 1){
                cout << newN << endl;
            }
            else{
                cout << newN << sl << newD << endl;
            }
            
        }

        void subtract(fraction B){
            int temp = this->denominator;
            int result1, result2, result3, result4, result;
            int newN, newD;
            char sl = '/';

            result1 = this->denominator *= B.denominator;
            result2 = this->numerator *= B.denominator;
            result3 = B.numerator *= temp;
            result4 = this->numerator -= B.numerator;
            result = this->simplify();
            newD = result1 / result;
            newN = result4 / result;

            if(newN == 0){
                cout << 0 << endl;
            }
            else if(newD == 1){
                cout << newN << endl;
            }
            else{
                cout << newN << sl << newD << endl;
            }
            
        }

        void multiply(fraction B){
            int newN, newD;
            int result1, result2, result3;
            char sl = '/';

            result1 = this->numerator *= B.numerator;
            result2 = this->denominator *= B.denominator;
            result3 = this->simplify();
            newN = result1 / result3;
            newD = result2 / result3;

            if(newN == 0){
                cout << 0 << endl;
            }
            else if(newD == 1){
                cout << newN << endl;
            }
            else{
                cout << newN << sl << newD << endl;
            }

        }

        void divide(fraction B){
            int newN, newD;
            int result1, result2, result3;
            char sl = '/';

            result1 = this->numerator *= B.denominator;
            result2 = this->denominator *= B.numerator;
            result3 = this->simplify();
            newN = result1 / result3;
            newD = result2 / result3;

            if(newN == 0){
                cout << 0 << endl;
            }
            else if(newD == 1){
                cout << newN << endl;
            }
            else{
                cout << newN << sl << newD << endl;
            }

        }

        int simplify(){
            int gcd, r;

            while(this->numerator != 0 && this->denominator != 0){
                r = this->denominator % this->numerator;
                this->denominator = this->numerator;
                this->numerator = r;
            }

            gcd = this->denominator;

            return gcd;
        }

};

int main(){
    int choice;
    char slash = '/';
    int numeA, denoA = 1, numeB, denoB = 1;
    int answer;
    fraction fracA, fracB;

    cin >> choice;

    if(choice == 1){
        cin >> numeA >> slash >> denoA;
            fracA.Nume(numeA);
            fracA.Deno(denoA);
        cin >> numeB >> slash >> denoB;
            fracB.Nume(numeB);
            fracB.Deno(denoB);
        
        fracA.add(fracB);
    }
    else if(choice == 2){
        cin >> numeA >> slash >> denoA;
            fracA.Nume(numeA);
            fracA.Deno(denoA);
        cin >> numeB >> slash >> denoB;
            fracB.Nume(numeB);
            fracB.Deno(denoB);
        
        fracA.subtract(fracB);
    }
    else if(choice == 3){
        cin >> numeA >> slash >> denoA;
            fracA.Nume(numeA);
            fracA.Deno(denoA);
        cin >> numeB >> slash >> denoB;
            fracB.Nume(numeB);
            fracB.Deno(denoB);
        
        fracA.multiply(fracB);
    }
    else if(choice == 4){
        cin >> numeA >> slash >> denoA;
            fracA.Nume(numeA);
            fracA.Deno(denoA);
        cin >> numeB >> slash >> denoB;
            fracB.Nume(numeB);
            fracB.Deno(denoB);
        
        fracA.divide(fracB);
    }
    else if(choice == 5){
        int newN, newD;

        cin >> numeA >> slash >> denoA;
            fracA.Nume(numeA);
            fracA.Deno(denoA);

        fracA.simplify();

        newN = numeA / fracA.simplify();
        newD = denoA / fracA.simplify();

            if(newD == 1){
                cout << newN << endl;
            }
            else{
                cout << newN << slash << newD << endl;
            }
    }

}

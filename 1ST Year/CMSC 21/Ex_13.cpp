#include <iostream>
#include <iomanip>
using namespace std;

class Point{

    public:
        float x;
        float y;

        Point(){
            x = 0;
            y = 0;
        }
        Point(int A, int B){
            this->x = A;
            this->y = B;
        }
        void coordinates(float A, float B){
            this->x = A;
            this->y = B;
        }

};

class Rectangle{

    private:
        Point topleft;
        Point botright;
    
    public:
        Rectangle(){
            topleft.coordinates(0,0);
            botright.coordinates(0,0);
        }
        Rectangle(Point A, Point B){
            this->topleft = A;
            this->botright = B;
        }
        Rectangle(int a, int b, int c, int d){
            topleft.coordinates(a,b);
            botright.coordinates(c,d);
        }
        void subPoints(Point A, Point B){
            this->topleft = A;
            this->botright = B;
        }
        int area(){
            int diff1;
            int diff2;
            int prod;

            diff1 = topleft.x - botright.x;
            diff2 = topleft.y - botright.y;
            prod = diff1 * diff2;

            return prod;
        }
        int perimeter(){
            int sum;
            int diff1, diff2;

            diff1 = (botright.x - topleft.x) * 2;
            diff2 = (botright.y - topleft.y) * 2;
            sum = diff1 + diff2;

            return sum;
        }
        Point centerPoint(){
            Point point;

            point.coordinates(botright.x - ((botright.x - topleft.x)/2), botright.y - ((botright.y - topleft.y)/2));

            return point;
        }
        bool isSquare(){
            if((topleft.x - botright.x) == (topleft.y - botright.y)){
                return true;
            }
            else{
                return false;
            }
        }
        void display(){  
            int i, j;

            cout << '\n';
            for(i = 0; i <= botright.y; i++){
                for(j = 0; j <= botright.x; j++){
                    if(((j == topleft.x || j == botright.x) && i >= topleft.y) || ((i == topleft.y || i == botright.y) && j >= topleft.x)){
                        cout << "# ";
                    }
                    else{
                        cout << "  ";
                    }
                }
            cout << "\n";
            }
        }
            
};

int main(){
    int a, b, c, d;
    char inner = '(';
    char outer = ')';
    char comma = ',';

    cin >> a >> b >> c >> d;
    Rectangle rectangle(a, b, c, d);

    cout << "\n";
    cout << "area: " << rectangle.area() << "\n";
    cout << "perimeter: " << rectangle.perimeter() << "\n";
    cout << "center point: " << inner << setprecision(2) << fixed << rectangle.centerPoint().x << comma << " " << rectangle.centerPoint().y << outer << '\n';
    cout << "square: ";
        if(rectangle.isSquare()){
            cout << "yes";
        }
        else{
            cout << "no";
        }
    rectangle.display();
}


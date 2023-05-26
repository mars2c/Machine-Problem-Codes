#include <iostream>
using namespace std;

class Package{

    public:
        double weight;
        double cost;
    
        Package(){
            weight = 0;
            cost = 0;
        }
        void kilo_cost(double kilo, double money){
            this->weight = kilo;
            this->cost = money;
        }
        double calculateCost(void){
            return (weight * cost);
        }

};

class TwoDayPackage: public Package{
    
    public:
        double fee;

        TwoDayPackage(){
            fee = 0;
        }
        void FlatFee(double flatfee){
            this->fee = flatfee;
        }
        double calculateCost(void){
            return ((weight * cost) + fee);
        } 

};

class OvernightPackage: public Package{

    public:
        double feekilo;

        OvernightPackage(){
            feekilo = 0;
        }
        void FeeKilo(double addfeekilo){
            this->feekilo = addfeekilo;
        }
        double calculateCost(void){
            double price;

            price = (weight * cost) + (feekilo * weight);

            return price;
        }

};

int main(){
    double weight, cost, fee, addfee;
    Package pack;
    TwoDayPackage pack2;
    OvernightPackage packnight;

    cin >> weight >> cost >> fee >> addfee;
        pack.kilo_cost(weight, cost);
        pack2.kilo_cost(weight, cost);
        pack2.FlatFee(fee);
        packnight.kilo_cost(weight, cost);
        packnight.FeeKilo(addfee);
    
        printf("%.02f ", pack.calculateCost());
        printf("%.02f ", pack2.calculateCost());
        printf("%.02f ", packnight.calculateCost());
        
}

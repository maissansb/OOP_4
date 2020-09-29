#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct child{
    string name;
    int age,toyc;
};
class Kindergarten{
private:
    string name;
    int cost, NOC;
    child kids[100];
    void calculatecost();
public:
    void set(string , int );
    void get(string & ,int &)const;
    int getCost()const;
    void print();
    Kindergarten(string="Al-Baraem",int=0);
};
Kindergarten::Kindergarten(string kgname, int numberofchildren) {

    name = kgname;
    NOC = numberofchildren;

    for (int i = 0; i < NOC; i++) {
        kids[i].name = "";
        kids[i].toyc = 0;
        kids[i].age = 0;
    }
    calculatecost();
}

void Kindergarten::set (string kgname, int numberofchildren ){

    ifstream in;
    name=kgname;
    NOC=numberofchildren;
    in.open("child.txt");
    for(int i=0;i<NOC;i++){
        getline(in,kids[i].name,',');
        in>> kids[i].age >> kids[i].toyc;
    }
    calculatecost ();
    in.close ();
}

void Kindergarten::get(string &kgname, int &numberofchildren )const{
    kgname=name;
    numberofchildren=NOC;
}
void Kindergarten::calculatecost(){

    int sum=0;

    for(int i=0; i<NOC; i++)
        sum += kids[i].toyc;

    cost = sum;

}
int Kindergarten::getCost( )const{
    return cost;
}
void Kindergarten:: print(){
    cout<<name<<" Kindergarten has "<<NOC<<" children with toys worth "<<cost<<" Dirhams.";
}
int main()
{
    Kindergarten KG;
    KG.set("Al-Baraem", 3);
    KG.print();

    return 0;
}




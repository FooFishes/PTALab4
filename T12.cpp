#include <iostream>
#include <math.h>
#define PI 3.1415926
using namespace std;

//点
class CPoint{
    double X,Y;
public:
    CPoint(double x,double y);
    CPoint(CPoint &cP);
    virtual double GetArea(){}//求面积
    virtual double GetVolume(){}//求体积
    void print();
};
CPoint::CPoint(double x,double y):X(x),Y(y){}
CPoint::CPoint(CPoint &cP):X(cP.X),Y(cP.Y){}
void CPoint::print(){ cout<<"Center:("<<X<<","<<Y<<")"<<endl; }

//圆
class Cirle :public CPoint{
    double Radius;
public:
    Cirle(double x,double y,double r);
    Cirle(Cirle& c);
    double GetRadius(){ return Radius; }
    double GetArea();//求面积
    virtual double GetVolume();//求体积
    void print();
};
Cirle::Cirle(double x,double y,double r):CPoint(x,y),Radius(fabs(r)){}
Cirle::Cirle(Cirle& c):CPoint(c),Radius(c.Radius){}
double Cirle::GetArea(){ return PI*Radius*Radius; }
double Cirle::GetVolume(){ return 3*PI*Radius*Radius*Radius/4; }
void Cirle::print(){ cout<<"radius="<<GetRadius()<<endl; }

//圆柱
class Ccylinder :public Cirle{
    double Height;
public:
    Ccylinder(double x,double y,double r,double h);
    Ccylinder(Ccylinder &cc);
    double GetHeight(){ return Height; }
    double GetArea();								//面积
    virtual double GetVolume();						//体积
    void print();
};
Ccylinder::Ccylinder(double x,double y,double r,double h):Cirle(x,y,r),Height(fabs(h)){}
Ccylinder::Ccylinder(Ccylinder& cc):Cirle(cc),Height(cc.Height){}
double Ccylinder::GetArea(){ return PI*GetRadius()*GetRadius(); }
double Ccylinder::GetVolume(){ return PI*GetRadius()*GetRadius()*Height; }
void Ccylinder::print(){
    cout<<"height:"<<GetHeight()<<endl;
    cout<<"BasalArea:"<<GetArea()<<endl;
    cout<<"SupfaceArea:"<<(2*GetArea()+2*PI*GetRadius()*Height)<<endl;
    cout<<"Volume:"<<GetVolume()<<endl;
}

int main(){
    double x,y,r,h;
    cin>>x>>y>>r>>h;
    CPoint cp(x,y);
    Cirle c(x,y,r);
    Ccylinder cc(x,y,r,h);
    cp.print();
    c.print();
    cc.print();
    return 0;
}
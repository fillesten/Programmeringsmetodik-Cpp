#include <iostream>
#include <vector>
#include <memory>
#include "Cylinder.h"
#include "Rectangle.h"
#include "Parallelepiped.h"
#include "RoundedRectangle.h"
/*
 *
 * bra skit tror jag
 * https://stackoverflow.com/questions/21187965/c-code-explanation-for-method-prototype-with-const-0
 * void setVolume(); ställ dig innan ; och "alt + enter" för autofyllnad av funktioner
 */
using shape_ptr = std::unique_ptr<shape>;

void GetData(std::vector<shape*> &sPtr) {
    for (auto &item: sPtr) {
            std::cout<<item->getArea()<<" "<<item->getColour()<<std::endl;
    }
}

//alternativ getData funk med mer komplicerade pekare
void print (const std::vector<shape_ptr> &sList){
    std::cout<<"----------"<<std::endl;
    for (auto &sShape: sList) {
        //std::cout<<sShape->getArea()<<" "<<sShape->getColour()<<std::endl;
        Circle* cir = dynamic_cast<Circle*>(sShape.get());
        if (cir){
            //std::cout<< typeid(*cir).name()<<" osv"<<std::endl;
            std::cout<<cir->getArea()<<"p-funk "<<cir->getColour()<<std::endl;
        }
        Rectangle* rec = dynamic_cast<Rectangle*>(sShape.get());
        if (rec){
            //std::cout<< typeid(*rec).name()<<" osv"<<std::endl;
            std::cout<<rec->getArea()<<"p-funk "<<rec->getColour()<<std::endl;
        }
        RoundedRectangle* rr = dynamic_cast<RoundedRectangle*>(sShape.get());
        if (rr){
            //std::cout<< typeid(*rr).name()<<" osv"<<std::endl;
            std::cout<<rr->getArea()<<"p-funk "<<rr->getColour()<<std::endl;
        }
        Cylinder* cyl = dynamic_cast<Cylinder*>(sShape.get());
        if (cyl){
            //std::cout<< typeid(*cyl).name()<<" osv"<<std::endl;
            std::cout<<cyl->getArea()<<"p-funk "<<cyl->getColour()<<std::endl;
        }
        Parallelepiped* paraP = dynamic_cast<Parallelepiped*>(sShape.get());
        if (paraP){
            //std::cout<< typeid(*paraP).name()<<" osv"<<std::endl;
            std::cout<<paraP->getArea()<<"p-funk "<<paraP->getColour()<<std::endl;
        }
    }
    //detta funkar inte exakt rr har inom sig ett objekt av rectangle som på något sätt skrivs ut när .getfunktionen
    //ska bara hitta exakta pekaren till rr
    //skriver ut alla parent objekt av nån anledning vet ej varför
}

int main() {

    //simple pointers
    Circle c("red", 5);
    Cylinder Cyl("orange", 5, 10);
    Rectangle r("blue", 5, 10);
    Parallelepiped Pp("grey", 5, 10, 5);
    RoundedRectangle RR("purple", 5, 10, 2);
    /*
    std::cout<<"Circle area -Main "<<std::endl << c.getArea()<<" "<< c.getColour()<<std::endl;
    std::cout<<"Rectangle area -Main"<<std::endl  << r.getArea()<<" "<< r.getColour()<<std::endl;
    std::cout<<"RoundedRectangle area -Main"<<std::endl  << RR.getArea()<<" "<< RR.getColour()<<std::endl;
    std::cout<<"Cylinder area -Main"<<std::endl  << Cyl.getArea()<<" "<< Cyl.getColour()<<std::endl;
    std::cout<<"Parallelepiped area -Main"<<std::endl  << Pp.getArea()<<" "
             << Pp.getColour()<<std::endl<<"----------"<<std::endl;
    */
    //går om man har multiple inheritance men måste då välja vilken väg som getColour ska gå

    /*
    */
    std::vector<shape*> shapeVec (5, nullptr);
    shape* sPtr;
    sPtr = &c;

    shapeVec[0] = &c;
    shapeVec[1] = &Cyl;
    shapeVec[2] = &r;
    shapeVec[3] = &Pp;
    shapeVec[4] = &RR;
    GetData(shapeVec);


    std::vector<shape_ptr> shapeLista;
    shapeLista.push_back(std::make_unique<Circle>("Brown", 5));
    shapeLista.push_back(std::make_unique<Rectangle>("white", 5, 10));
    shapeLista.push_back(std::make_unique<RoundedRectangle>("Turquoise", 5, 10, 2));
    shapeLista.push_back(std::make_unique<Cylinder>("black", 5, 10));
    shapeLista.push_back(std::make_unique<Parallelepiped>("grey", 5, 10, 5));

    print(shapeLista);






    return 0;
}

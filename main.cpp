#include<iostream>
#include"datamodel.h"
#include<vector>

vector<Product>allproducts={
Product(1 ,"apple",26),
Product(2 ,"Mango", 14),
Product(3 ,"Guava" , 78),
Product(4 ,"Strawberry" , 65),
Product(5 ,"peaches", 45),
};
Product* choseproduct(){
    string productlist;
    cout<<"available products"<<endl;
    for(auto products : allproducts ){
        productlist.append(products.getdisplayname());
        cout<<endl;
    }
    cout<<productlist<<endl;
    cout<<"-----------------------"<<endl;
    string choice;
    cin>>choice;
    for(int i=0;i<allproducts.size();i++){
if(allproducts[i].shortname()==choice)
return &allproducts[i];
    }
    cout<<"Product not found!"<<endl;
    return NULL;
}

bool checkout(cart &Cart){
    if(Cart.isempty()){
        return false;
    }
    int total=Cart.gettotal();
    cout<<"Pay in cash";
    int paid;
    cin>>paid;
    if(paid>=total){
        cout<<"Change : "<<paid-total<<endl;
        cout<<"Thankyou for shopping";
        return true;}
    else{
            cout<<"Not enough Cash!";
            return false;
        }
}
int main(){
char action;
cart Cart;
while(true){
    cout<<"Select an action ----- (a)dd item ,(v)iew cart ,(c)heckout"<<endl;
    cin>>action;
    if(action=='a'){
Product * product=choseproduct();
if(product!=NULL){
    cout<<"Added to the cart"<<" "<<product->getdisplayname()<<endl;
    Cart.addproducts(*product);
}
    }
    else if(action=='v'){
cout<<"----------------------"<<endl;
cout<<Cart.viewCart();
cout<<"-------------------"<<endl;

    }
    else{
      Cart.viewCart();
      if(checkout(Cart)){
        break;
      }
    }
}
return 0;
}

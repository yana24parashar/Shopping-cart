#include<string>
#include<bits/stdc++.h>
using namespace std;
class item;
class Product{
int id;
string name ;
int price;

public:
Product(){

}
Product(int u_id , string name , int price){
   id=u_id;
   this->name=name;
   this->price=price;
}
string getdisplayname(){
    return name+":Rs"+ to_string(price);
}
string shortname(){
    return name.substr(0 , 1);
}
friend class item;
friend class cart;
};
class item{
 Product product;
int quantity;
public:
item(){

}
 item(Product p  , int q):product(p),quantity(q){}
 int getprice(){
    return quantity*product.price;
 }
 string getItemInfo(){
    return to_string(quantity)+" x "+product.name+" Rs "+ to_string(quantity*product.price);
 }
 friend class cart;
};
class cart{
unordered_map<int , item>items;
public:
void addproducts(Product product){
    if(items.count(product.id)==0){
        item newitem(product , 1);
        items[product.id]=newitem;
    }
    else {
        items[product.id].quantity+=1;
    }
    cout<<endl;
}
int gettotal(){
int total=0;
for(auto itempair:items){
    auto item=itempair.second;
    total+=item.getprice();
}
return total;
cout<<endl;
}

string viewCart(){
        if(items.empty()){
            cout<<"Cart is empty"<<endl;
        }
        string itemsizedlist;
        int cart_total=gettotal();
        for(auto itempair:items){
        auto item=itempair.second;
        itemsizedlist.append(item.getItemInfo());

        }
        return itemsizedlist +  "Total Amount:Rs." + to_string(cart_total)+'\n';
    }

    bool isempty(){
        return items.empty();
    }

};

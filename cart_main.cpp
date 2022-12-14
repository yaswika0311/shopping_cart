#include <iostream>
#include<vector>
#include "datamodel.h"

using namespace std;


vector<Product> allProducts = {
    Product(01,"shirt",200),
    Product(02,"top",300),
    Product(03,"scarf",100),
    Product(04,"sweater",500),
    Product(05,"jeans",600),
    Product(06,"coat",400)
 };
Product* chooseProduct(){
    string productList;
    cout<<"Available Products are "<<endl;
    for(auto product : allProducts){
        productList.append(product.getDisplayName());
    }
    cout<< productList <<endl;
    int choice;
    /*choices should be made based on the indices of allProducts(i=0 to i=5) if choice>5 the the product is not available */
    cout<<"Enter your choice ";
    cin>>choice;
    for(int i=0;i<allProducts.size();i++){
        if(choice==i)
          return &allProducts[i];
    }
    cout<<"Product not found !!"<<endl;
    return NULL;
    
}
bool checkout(Cart &cart){
    if(cart.isEmpty()){
      return false;
    }
    int total = cart.getTotal();
    cout<<"pay in cash ";
    int paid;
    cin>>paid;
    if(paid>=total){
        cout<<"Change "<<paid-total<<endl;
        cout<<"Thank you for shopping !!";
        return true;
    }
    else{
        cout<<"Not enough cash ! still you have to pay Rs. "<<total-paid<<endl;
        return false;
    }
    
}
int main() {
    int action;
    Cart cart;
    while(true){
      cout<<"Select an action - (1)add item, (2)view cart, (3)checkout"<<endl;
      cin>>action;
      if(action == 1){
          //add to cart
          //view all products + choose product + add to cart
          Product *product= chooseProduct();
          if(product!=NULL){
              cout<<"Added to the cart - "<<product->getDisplayName()<<endl;
              cart.addProduct(*product);
          }
      }
      else if(action == 2){
          cout<<cart.viewCart();
      }
      else{
          cart.viewCart();
          if(checkout(cart))
            break;
      }
    
    }
    return 0;
}
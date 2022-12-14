#include<string>
#include<unordered_map>

using namespace std;

class Product{
    int id;
    string name;
    int price;
public:
    Product(){}
    Product(int unique_id,string name,int price)
    {
        id=unique_id;
        this->name=name;
        this->price=price;
    }
    string getDisplayName(){
        return to_string(price) + " Rs " + name + "\n";
    }
    friend class Item;
    friend class Cart;
};

class Item{
    Product product;
    int quantity;
public:
    Item(){}
    Item(Product p,int q):product(p),quantity(q){}
    int getItemPrice(){
        return quantity*product.price;   
     }
    string getItemInfo(){
        return to_string(quantity) + " x " + product.name + +" "+to_string(quantity*product.price) + " Rs ";
    }
    friend class Cart;
};
class Cart{
    unordered_map<int,Item> items;
public:
    void addProduct(Product product){
        if(items.count(product.id)==0){
            Item newItem(product,1);
            items[product.id] = newItem;
        }
        else
          items[product.id].quantity +=1;
    }
    int getTotal(){
        int total=0;
        for(auto x : items){
            auto item=x.second;
            total += item.getItemPrice();
        }
        return total;
    }
    string viewCart(){
        if(items.empty()){
          return "Cart is empty\n";
        }
      string itemsList;
      int cart_total=getTotal();
      for(auto x:items){
          auto item=x.second;
          itemsList.append(item.getItemInfo());
      }
      return itemsList + "\nTotal Amount : Rs." + to_string(cart_total) + "\n";
    }
    bool isEmpty(){
		return items.empty();
	}

    
};
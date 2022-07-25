#include<bits/stdc++.h>
using namespace std;

class Restaurant{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
protected:
    int total_tax;
public:
    void set_tax(int tax){
        total_tax=tax;
    }
    int show_tax(){
        return total_tax;
    }
};

void create_product(Restaurant *my_restaurant, int n) {
    for(int i=1;i<=n;i++)
    {
        cout<<"Product "<<i<<" Code: ";
        cin>>my_restaurant->food_item_codes[i];
        cout<<"Product "<<i<<" Name: ";
        cin>>my_restaurant->food_item_names[i];
        cout<<"Product "<<i<<" Price: ";
        cin>>my_restaurant->food_item_prices[i];
    }
}

void show_product_menu(Restaurant *my_restaurant, int n) {
    cout<<endl;
        cout<<"\t\t\t\t MAKE BILL"<<endl;
        cout<<"\t\t\t__________________________"<<endl;
        cout<<"Item Code\t\t\t";
        cout<<"Item Name\t\t\t";
        cout<<"Item Price";
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<my_restaurant->food_item_codes[i]<<"\t\t\t\t"<<my_restaurant->food_item_names[i]<<"\t\t\t\t"<<my_restaurant->food_item_prices[i]<<endl;
        }
        cout<<endl<<endl;
}

int main(){
    Restaurant *my_restaurant=new Restaurant;
    cout<<"Number of products : ";
    int n;
    cin>>n;
    //create product
    create_product(my_restaurant, n);
    //product menu
    show_product_menu(my_restaurant, n);

    //take customer order
    cout<<"Enter table no: ";
    int table_no;
    cin>>table_no;
    cout<<"Enter number of items: ";
    int numOfItems;
    cin>>numOfItems;
    int pd_codes[numOfItems];
    int pd_qty[numOfItems];

    for(int i=1; i<=numOfItems; i++){
        cout<<"Enter Item "<<i<<" Code :";
        cin>>pd_codes[i];
        int found_code = 0;
        for(int k=1; k<=n; k++){
            if(pd_codes[i] == my_restaurant->food_item_codes[k]){
                found_code = 1;
            }
        }
        if(found_code == 0){
            cout<<"this code is not valid"<<endl;
            i--;
        } else {
            cout<<"Enter Item "<<i<<" Quantity :";
            cin>>pd_qty[i];
        }
    }
    cout<<endl<<endl;

    //bill summary
    cout<<"\t\t\t\t BILL SUMMARY"<<endl;
    cout<<"\t\t\t__________________________"<<endl;
    cout<<"Table Number :"<<table_no<<endl;
    cout<<"Item Code\t\t";
    cout<<"Item Name\t\t";
    cout<<"Item Price\t\t";
    cout<<"Item Qty\t\t";
    cout<<"Total Price";
    cout<<endl;
    int total_price=0;
    for(int i=1;i<=numOfItems;i++){
        for(int j=1;j<=n;j++){
            if(pd_codes[i] == my_restaurant->food_item_codes[j]){
                cout<<my_restaurant->food_item_codes[j]<<"\t\t\t"<<my_restaurant->food_item_names[j]
                <<"\t\t\t"<<my_restaurant->food_item_prices[j]<<"\t\t\t"<<pd_qty[i]<<"\t\t\t"<<my_restaurant->food_item_prices[j]*pd_qty[i]<<endl;

                //product price calculate
                int price = my_restaurant->food_item_prices[j]*pd_qty[i];
                total_price+=price;
            }
        }
    }
    double tax=(total_price/100)*5;
    my_restaurant->set_tax(tax);
    cout<<"TAX"<<"\t\t\t\t \t\t\t\t \t\t\t\t"<<tax<<endl;
    cout<<"__________________________________________________________________________________________________________"<<endl;
    cout<<"TAX"<<"\t\t\t\t \t\t\t\t \t\t\t\t"<<total_price+tax<<"Taka"<<endl;
    cout<<endl<<endl;
}

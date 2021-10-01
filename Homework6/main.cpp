#include <iostream>
#include <bitset>

using namespace std;


void task6_13(){
    uint32_t number;

    cout<<"\n  Task 6.13\nInput 32-bit positive number: ";

    scanf("%d",&number);
    
    if (number<=0) return;

    int count = 0;

    cout<< bitset<32>(number) << endl; 
    
    for (int i=sizeof(number)*8; i>=0; i--){
        count += (number & 1) ? 1 : 0;
        number>>=1;
    }

    printf("Number has %d non-zero bits.\n",count);

}


void task6_22(){
    int32_t n;
    int32_t k;

    cout<<"\n  Task 6.22\nInput 32-bit number (n): ";

    scanf("%d",&n);

    cout<<"Input number (0<=k<=32): ";

    scanf("%d",&k);

    if (k<0 | k>32) return;

    int filter = ~0; //0b 11111111 11111111 11111111 11111111
    filter>>=k;
    filter<<=k;

    std::cout<<"n: "<<bitset<32>(n)<<endl;
    n = n | filter;
    std::cout<<"Output: "<<bitset<32>(n)<<endl;
}


int main(){
    //11 Красовський Олександр 6.13, 6.22
    task6_13();
    task6_22();
    return 0;
}
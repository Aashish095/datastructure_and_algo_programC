#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void print(std::stack<int ,std::vector<int>> stk){
    while(!stk.empty()){
        cout <<stk.top() <<endl;
        stk.pop();//remove from the back
    }
}

int main(){
    std::stack<int, std::vector<int>> stk;

    stk.push(2);
    stk.push(3);
    stk.push(4);

    print(stk);
    return 0;
}
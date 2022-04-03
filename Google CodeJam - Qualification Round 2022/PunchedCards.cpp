#include <iostream>
using namespace std;

void solve(int r, int c) {
  cout<<"..";
  for(int i = 0; i < (c-1); i++) cout<<"+-";
  cout<<"+\n..";
  for(int i = 0; i < (c-1); i++) cout<<"|.";
  cout<<"|"<<endl;
  
  int count = ((2 * r) + 1);
  for(int i = 0; i < (count-2); i++) {
    if(i % 2 == 0) {
      for(int j = 0; j < c; j++) cout<<"+-";
      cout<<"+"<<endl;
    } else {
      for(int j = 0; j < c; j++) cout<<"|.";
      cout<<"|"<<endl;
    }
  }
}

int main() {
  int T, test = 1;
  cin>>T;
  if(T >= 1 && T <= 81) {
    while(T--) {
      int R, C;
      cin>>R>>C;
      if((R < 2 || R > 10) || (C < 2 || C > 10)) continue;
      cout<<"Case #"<<test<<":"<<endl;
      solve(R, C);
      test++;
    }
  }
  return 0;
}
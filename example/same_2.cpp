#include "iostream"

using namespace std;

int main(){int a, b, c;cin >> a >> b >> c;if (a > b){
int tmp = a;
a = b;
b = tmp;
}if (a > c){
int tmp = a;
a = c;
c = tmp;
}
if (b > c){
int tmp = b;
b = c;
c = tmp;
}
cout << a << " " << b << " " << c << endl;
}
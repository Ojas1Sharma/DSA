#include <iostream>
using namespace std;
template <typename T, typename V>


class Pair{
T x;
V y;
public:
void setX(T x){
    this->x=x;
}
T getX(){
    return x;
}
void setY(V y){
    this->y=y;
}
V getY(){
    return y;
}
};




int main(){
    Pair<Pair<int, char>,int> p1;
    Pair<int,char> p2;
    p2.setX(1);
    p2.setY('a');
    p1.setX(p2);

    p1.setY(10);
    cout<<p1.getX().getX()<<p1.getX().getY()<<p1.getY()<<endl;
    return 0;
}

// int main(){
//     Pair<int,char> p1;
//     p1.setX(1);
//     p1.setY('a');
//     cout<<p1.getX()<<" "<<p1.getY()<<endl;
//     return 0;
// }
#include <assert.h>


int is_odd(int x){
    return x&0x1||0;
}

int is_even(int x){
    return !is_odd(x);
}

int main(int argc, char* argv[]){
    assert(is_odd(3)==1);
    assert(is_odd(2)==0);
    assert(is_even(4)==1);
    assert(is_even(5)==0);
    return 0;
}
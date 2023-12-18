#include <iostream>

//Double loop break without needing of return function.
#define LOOP_NAME(name) \
    if ([[maybe_unused]] constexpr bool _namedloop_InvalidBreakOrContinue = false) \
    { \
        [[maybe_unused]] CAT(_namedloop_break_,name): break; \
        [[maybe_unused]] CAT(_namedloop_continue_,name): continue; \
    } \
    else
#define BREAK(name) goto CAT(_namedloop_break_,name)
#define CONTINUE(name) goto CAT(_namedloop_continue_,name)
#define CAT(x,y) CAT_(x,y)
#define CAT_(x,y) x##y

int main() {
    int counter=1;int length=1;
    int theinput; std::cin >> theinput;
    
    while(true) LOOP_NAME(foo){
        for(int i=0; length>i; ++i){
            std::cout<<counter%10;
            counter+=1;
            if(counter>theinput){BREAK(foo);}
        }
        std::cout<<"\n";
        length+=1;
    }
    return 0;
}
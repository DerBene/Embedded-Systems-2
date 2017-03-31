#include "../include/Printf.h"

int main(int argc, char** argv){
    (void) argc;
    (void) argv;

    char inputArray[150];
    const void* endOfWriteable = (void*) (inputArray + 150);

    signed int test1 = -15567;
    unsigned int test2 = 34636;

    Printf(inputArray, endOfWriteable, "TEst inout %s %d moretest %u %c tst tstst %% tstst %x tsadg %b %h %j endOfTest","PercentS",test1, test2,'t',"test","test");
}
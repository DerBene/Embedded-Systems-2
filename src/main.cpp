#include <cstdio>
#include "../include/Printf.h"

int main(int argc, char** argv){
    (void) argc;
    (void) argv;

    char inputArray[200];
    const void* endOfWriteable = (void*) (inputArray + 199);

    signed int test1 = -1567;
    unsigned int test2 = 34636;

    Printf(inputArray, endOfWriteable, "TEst inout %s %d moretest %u %c tst tstst %% tstst %x tsadg %b %h %j edr %test endOfTest","PercentS",test1, test2,'t',test2,test2);
    printf(inputArray);
}
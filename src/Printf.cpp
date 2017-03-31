#include "../include/Printf.h"
#define unsignedInt 'u'
#define signedInt 'd'
#define singleChar 'c'
#define charChain 's'
#define hex 'x'
#define bin 'b'
#define percent '&'

char* Printf(char* dst, const void* end, const char* fmt, ...){
    char* inputString = dst;

    while(*inputString != '\0'){
        if(*inputString == '%'){
            inputString++;
            switch(*inputString){
                case unsignedInt :
                {
                    //ToDo: Logic
                }break;

                case signedInt :
                {
                    //ToDo: Logic
                }break;

                case singleChar :
                {
                    //ToDo: Logic
                }break;

                case charChain :
                {
                    //ToDo: Logic
                }break;

                case hex :
                {
                    //ToDo: Logic
                }break;

                case bin :
                {
                    //ToDo: Logic
                }break;

                case percent :
                {
                    //ToDo: Logic
                }break;
            }
        }else{

        }
        inputString++;
    }

}

#include <stdio.h>
#include "../include/Printf.h"
#define unsignedInt 'u'
#define signedInt 'd'
#define singleChar 'c'
#define charChain 's'
#define hex 'x'
#define bin 'b'
#define percent '&'

char* Printf(char* dst, const void* end, const char* fmt, ...){

    va_list vList;
    va_start(vList, fmt);

    while(*fmt && dst <= end-1){
        if(*fmt == '%'){
            fmt++;
            switch(*fmt){
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
                    char c = va_arg(vList, char);
                    *dst = c;
                    dst++;
                }break;

                case charChain :
                {
                    char* c = va_arg(vList, char*);
                    while(c)
                    {
                        *dst = *c;
                        c++;
                        dst++;
                    }


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
                    *dst = '%';
                    dst++;
                }break;

                default :
                {
                    *dst = '%';
                    dst++;
                    *dst = *fmt;
                    dst++;
                }
            }
        }else{
            *dst = *fmt;
            dst++;
        }
        fmt++;
    }

    *dst = '\0';
    dst++;
    return dst;
}

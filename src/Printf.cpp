
#include <stdarg.h>
#include <cstdio>
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
                    char* tempString = IntegerConvertion(va_arg(vList, unsigned int));
                    while(*tempString){
                        *dst = *tempString;
                        dst++;
                        tempString++;
                    }
                }break;

                case signedInt :
                {
                    signed int tmp = va_arg(vList, signed int);
                    unsigned uTmp = 0;
                    if(tmp < 0)
                    {
                        uTmp = (unsigned) ~tmp +1;

                        *dst = '-';
                        dst++;
                    }

                    char* tempString = IntegerConvertion(uTmp);
                    while(*tempString){
                        *dst = *tempString;
                        dst++;
                        tempString++;
                    }
                }break;

                case singleChar :
                {
                    char c = (char) va_arg(vList, int);
                    *dst = c;
                    dst++;
                }break;

                case charChain :
                {
                    char* c = va_arg(vList, char*);
                    while(*c)
                    {
                        *dst = *c;
                        c++;
                        dst++;
                    }


                }break;

                case hex ://TODO: delete leading 0 and fix
                {
                    unsigned int inputInt = va_arg(vList, unsigned int);
                    bool nullTest = false;
                    char hexOut;
                    *dst = '0';
                    dst++;
                    *dst = 'x';
                    dst++;
                    char hexHolder = 0;

                    for(int bitIndex = 8*sizeof(inputInt)-1; bitIndex >= 0; bitIndex--)
                    {

                        hexHolder = inputInt & (4<<bitIndex);
                        *dst = hexHolder + (hexHolder < 10 ? '0' : ('A'-10));

                        dst++;
                    }
                }break;

                case bin ://TODO: delete leading 0
                {
                    unsigned int inputInt = va_arg(vList, unsigned int);
                    bool nullTest = false;
                    char binOut;
                    *dst = '0';
                    dst++;
                    *dst = 'b';
                    dst++;

                    for(int bitIndex = 8*sizeof(inputInt)-1; bitIndex >= 0; bitIndex--)
                    {
                        binOut = (inputInt & (1<<bitIndex)) ? '1' : '0';
                        if(binOut == '1'){
                            nullTest = true;
                        }
                        if(nullTest)
                        {
                            *dst = binOut;
                            dst++;
                        }

                    }



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

char* IntegerConvertion(unsigned int toConvert){
    char convertedInt[8*sizeof(toConvert)];
    char* filledArrayPointer = (convertedInt +(8*sizeof(toConvert)));
    *filledArrayPointer = '\0';
    filledArrayPointer--;

    while(toConvert > 0)
    {
        *filledArrayPointer = toConvert%10 + '0';
        toConvert = toConvert/10;
        filledArrayPointer--;
    }

    filledArrayPointer++;
    return filledArrayPointer;
}

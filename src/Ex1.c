#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
/*
GET PARAMS
CONVERT TO BINARY
CONVERT BACK
AVERAGE
*/

const int octetSize = 8;

struct student{
    char *name;
    int age;
    char *registration;
    double grade;
};


void reverseStr(char *str, int strLen, char *rStr){
    for(int i = 0; i < strLen; i++){
        rStr[i] = str[strLen-1-i];
    }
}

void textToBin(char *str, int strLen, char *binStr){
    int count = 0;

    for(int i = 0; i < strLen; i++){
       int num = str[i];
       char *subStr = (char*)malloc(octetSize * sizeof(char));
       int left = octetSize;
       int iter = 0;

       while(num > 0){
            subStr[iter] = (num % 2) + '0';
            num /= 2;
            iter ++;
            left --;
       }

       for(int j = left; j > 0; j--){
            subStr[iter] = '0';
            iter ++;
       }

       char *rStr = (char*)malloc((octetSize+1) * sizeof(char));
       reverseStr(subStr, octetSize, rStr);
       
       
       
       rStr[octetSize] = '\0';
       strcat(binStr, rStr);
       count += octetSize;
    }
}

void binToText(char *binStr, int binLen, char *txtStr, int txtLen){
    int iter = 0;
    for(int i = 0; i < binLen; i+= octetSize){
        int temp = 0;
        
        for(int j = 0; j < octetSize; j++){
            int binVal = binStr[i+j]-'0';
            temp += ((int)pow(2, 7-j)) * binVal;
        }
        
        txtStr[iter] = (char)temp;
        iter++;
    }
    txtStr[txtLen-1] = '\0';
}


int main(){
    /*SET USER DATA*/
    struct student me;
    me.name = "Pedro";
    me.age = 24;
    me.registration = "202304084751";
    me.grade = 10.0;

    int nameLen = strlen(me.name);
    int sizeOfBin = (nameLen * octetSize) + 1;
    char *binStr = (char *)malloc(sizeOfBin);
    binStr[0] = '\0'; //ADD NULL CHAR TO START OF STRING TO AVOID TRASH COLLECTION
    
    int registrationLen = strlen(me.registration);
    int sizeOfBinRegistration = (registrationLen * octetSize) + 1;
    char *registrationBin = (char *)malloc(sizeOfBinRegistration);
    registrationBin[0] = '\0';

    textToBin(me.name, nameLen, binStr);
    textToBin(me.registration, registrationLen, registrationBin);
    printf("Nome - Binario: %s\n", binStr);
    printf("Registration - Binario: %s\n\n", registrationBin);

    int txtLen = ((sizeOfBin-1) / octetSize) + 1;  //REDUCE BIN LEN BY 1 DUE TO NULL CHAR. THEN ADD 1 TO USE NULL CHAR
    char *txtStr = (char *)malloc(txtLen);

    int txtRegistrationLen = ((sizeOfBinRegistration-1) / octetSize) + 1;
    char *txtRegistration = (char *)malloc(txtRegistrationLen);

    binToText(binStr, sizeOfBin, txtStr, txtLen);
    binToText(registrationBin, sizeOfBinRegistration, txtRegistration, txtRegistrationLen);
    printf("Nome - Texto: %s\n", txtStr);
    printf("Registration - Texto: %s\n", txtRegistration);

    return 0;
}
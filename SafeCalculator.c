#include <stdio.h>

int _add(int a, int b);
int add(int a, int b);
int sub(int a, int b);
int neg(int a);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);
int pow(int a, int b);
int convert(char *input);


int main(int argc, char *argv[]){

    int res = 0;        
    int n = 0;          
    char input[50];     
    input[0] = '\0';    

    //printf("%d\n", add(1, 2));
    //printf("%d\n", sub(10, 15));
    //printf("%d\n", neg(20)); 
    //printf("%d\n", mul(5, -8));
    //printf("%d\n", div(50, -2)); 
    //printf("%d\n", mod(20, 3));
    //printf("%d\n", pow(2, 2));  

   while(input[0] != 'q' && input[0] != 'Q'){
        menu();
        printf("\nres = %d > ", res);
        gets(input);
        system("cls");

        switch (input[0]){
            case '+':
                res = add(res, convert(input));
                break;
            case '-':
                res = sub(res, convert(input));
                break;
            case '*':
                res = mul(res, convert(input));
                break;
            case '/':
                res = div(res, convert(input));
                break;
            case '%':
                res = mod(res, convert(input));
                break;
            case '~':
                res = neg(res);
                break;
            case '^':
                res = pow(res, convert(input));
                break;
            case 'c':
            case 'C':
                res = 0;
                break;
            case 'q':
            case 'Q':
                printf("Good-bye!\n");
                break;
            default:
                printf("Enter a valid operator and operand\n");

        }

    }


    return 0;
    
}


void menu(){
    printf("\nSafe Integer Calculator\n");
    printf("+ x to add\n");
    printf("- x to subtract\n");
    printf("* x to multiply\n");
    printf("/ x to divide\n");
    printf("%% x to modulus\n");
    printf("~ x to negate\n");
    printf("^ x to raise by power x\n");
    printf("c x to clear result\n");
    printf("q x to quit\n");
    return;
}


int _add(int a, int b){
    while(b != 0) {

        int carry = a & b; 

        a = a ^ b; 

        b = carry << 1; 
        }
    return a;
}


int add(int a, int b){
    int res = 0;
    res = _add(a, b); 

    if(a > 0 && b > 0 && res < 0) {
    	printf("Overflow");
    }

    if(a < 0 && b < 0 && res > 0) {
    	printf("Underflow"); 
    }

    return res;
}


int neg(int a){
    a = add(~a, 1); 
    return a;
}


int sub(int a, int b){ 
    b = neg(b); 
    int result = add(a, b);
    return result;
}


int mul(int a, int b){
    int res = 0;
    int sign = 1; 

    if(a < 0) {
    	 a = add(~a, 1); 
    	 sign = -1;
    }

    if(b < 0) {
    	b = add(~b, 1); 
    	sign = -1; 
    }

    if(a >= b) {
    	for(int i = 0; i < b; i = add(i, 1)) {
    		res = add(res, a);
    	}
    }
    
    else if(b >= a) {
    	for(int j = 0; j < a; j = add(j, 1)) {
    		res = add(res, b); 
    	}
    }

    if(sign == -1) {
    	res = neg(res); 
    }

    return res;
}


int div(int a, int b){
    int cnt = 0;
    int sign = 1; 

    if(a < 0) {
    	a = add(~a, 1); 
    	sign = -1; 
    }

    if(b < 0) {
    	b = add(~b, 1); 
    	sign = -1; 
    }

    while(a >= b) {
    	a = sub(a,b); 
    	cnt = add(cnt, 1); 
    }
    if(sign == -1) {
    	cnt = neg(cnt); 
    }
    return cnt;
}


int mod(int a, int b){
    if(a < 0) {
    	a = add(~a, 1); 
    }

    if(b < 0) {
    	b = add(~b, 1); 
    }

    while(a > b) {
    	a = sub(a,b);  
    }

    return a;
}


int pow(int n, int exp){
    int res = 1;
    while(exp > 0) {
    	res = mul(res, n); 
    	exp = sub(exp, 1); 
    }

    return res;
}


int convert(char *input){
    int res = 0;
    int sign = 1; 
    int i = 2; 
    int j = 0; 
    char buffer[100]; 
    int error = 0; 
    if(input[1] != ' ') {
    	printf("This should be a space"); 
    }
    if(input[2] == '-') {
    	sign = -1; 
    }

    while(input[i] != '\0') {
    	if(input[i] >= '0' && input[i] <= '9') {
    		buffer[j] = input[i];
    		j = add(j, 1);
    		i = add(i, 1); 
    	}
    }
    i = sub(j, 1); 
    j = 0; 
    while(i >= 0) {
    	int asciiToNumber = sub(buffer[i], '0'); 
    	int numberPlacement = pow(10, j);
    	int formulateNumber = mul(asciiToNumber, numberPlacement); 
    	res = add(res, formulateNumber);
    	j = add(j, 1); 
    	i = sub(i, 1);
    }
    if(sign < 0) {
    	res = neg(res); 
    }
    
    return res;
}


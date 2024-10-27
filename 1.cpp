/*
This question is about working with individual bits in an 8-bit register using three operations:

Set a bit : This operation sets a specific bit in the register to 1.
Clear a bit : This operation clears a specific bit in the register, setting it to 0.
Toggle a bit : This operation inverts the current state of a specific bit, switching it from 0 to 1 or from 1 to 0.

In each function, the parameters are:

uint8_t *reg: This is a pointer to an 8-bit register, represented by a variable of type uint8_t 
(an unsigned 8-bit integer). It is passed by reference (using the pointer *) to allow direct modification 
of the register's value.

int bit: This integer specifies the position of the bit to modify, where the valid range is typically 0–7 
(for the 8 bits in a byte). Bit 0 refers to the least significant bit (LSB), while bit 7 
is the most significant bit (MSB).

The goal of each function is to modify the register as described using bitwise operations, 
which are efficient and commonly used for such tasks in low-level programming.
*/

#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string>
using namespace std;

void set_bit(uint8_t *reg, int bit){
    uint8_t tmp = 0b00000001; // Using binary literal
    tmp = tmp << bit;
    *reg = *reg | tmp;
} 

void clear_bit(uint8_t *reg, int bit){
    uint8_t tmp = 0b11111110; // Using binary literal
    tmp = tmp << bit;
    *reg = *reg & tmp;
}

void toggle_bit(uint8_t *reg, int bit){
    uint8_t tmp = 0b00000001; // Using binary literal
    tmp = tmp << bit;
    *reg ^= tmp;
}
int main(){
    uint8_t reg= 0x00;
    uint8_t user_input;
    int operation;
    char bit_string[8];
    
    cout<<"Enter 8 bits (0 or 1), separated by spaces: ";
    cin>>bit_string;
    if (strlen(bit_string)!=8){
        cout<<"Invalid input"<<endl;
        return 1;
    }

    printf("The bit is set to: %s\n", bit_string);

    for (int i= 0; i<8; i++){
        if (bit_string[i] == '1'){
            reg= reg | (0x01<<i);
        }
    }
    cout<<"The bit is set to: ";
    for (int i=0; i<=7; i++){
        if (reg&(0x01<<i)){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    cout<<endl;

    cout<< "Enter the bit number to manipulate:";
    cin>>user_input;

    cout<< "Enter the operation (0: set, 1: clear, 2: toggle, 3: exit):";
    cin>>operation;

    while (operation != 3){
        switch(operation){
            case 0: set_bit(&reg, user_input); break;
            case 1: clear_bit(&reg, user_input); break;
            case 2: toggle_bit(&reg, user_input); break;
            case 3: break;
            default: cout<<"Invalid operation"<<endl;
        }
        cout<<"The bit is set to: "<<reg<<endl;
        cout<< "Enter the operation (0: set, 1: clear, 2: toggle, 3: exit):";
        cin>>operation;
    }

    cout<<"The bit is set to: "<<reg<<endl;
    return 0;
}

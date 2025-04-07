#include <iostream>
#include <cstdint>


/*
 * 1.-  Conversión de decimal a binario.
 * 2.-  Extraer los primeros N bits de un entero.
 * 3.-  Suma de dos números enteros. (En principio sólo números positivos)
 * 4.-  Setear a 0 un bit específico de un entero corto.
 *
 * Todo usando únicamente operadores a nivel de bits. En cuánto sea posible, usar máscaras para simplificar el proceso.
 * Las soluciones son sencillas, si necesitas ayuda en alguna me avisas.
 */

int bits1(){
    std::string decimal = "1234567890";
    std::string binary = "";
    uint64_t number = 0;

    for(uint8_t digit : decimal){
        std::cout << "Digit: " << digit << "\n";

        number *= 10;
        number += digit - '0';
        std::cout << "Number: " << number << "\n";
    }

    for(int i = 0; number != 0; ++i, number >>= 1){
        uint8_t bit = (number & 0b1);

        //std::cout << "Number: " << number << "\n";
        std::cout << "Bit " << i << " :" << int(bit) << "\n";

        //if(i % 4 == 0) binary.insert(binary.begin(), ' ');

        binary.insert(binary.begin(), bit + '0');

    }

    std::cout << "Binary: " << binary << "\n";

    return 0;
}

int bits2(){
    uint64_t number = 83701239;
    std::string bits = "";
    uint64_t bitCount = 4;
    uint64_t mask = 0;

    for(uint64_t i = 0; i < bitCount; ++i){
        mask |= uint64_t(0b1) << (63 - i);
    }

    std::cout << "Mask: " << mask << "\n";

    for(uint64_t i = uint64_t(0b1) << 63; (i & number) == 0; i >>= 1){
        mask >>= 1;
    }

    std::cout << "Mask: " << mask << "\n";

    uint64_t result = number & mask;
    std::cout << "Result: " << result << "\n";

    return 0;
}

int bits3(){
    uint64_t number1 = 0b11011001;  // 217
    uint64_t number2 = 0b01010011;   // 83

    while (number1 != 0) {
        int carry = number1 & number2;

        number2 = number1 ^ number2;
        number1 = carry << 1;

        std::cout << "1: " << number1 << "\n";
        std::cout << "2: " << number2 << "\n";
    }

    std::cout << "Result: " << number2 << "\n";
    std::cout << "Hmmm: " << number1 << "\n";

    return 0;
}

int bits4(){
    uint64_t number = 0b0'1010'1001'1110;
    uint8_t bit = 1;
    uint64_t mask = ~(0b1 << (bit - 1)); // 0b1'1111'0000'0111

    number ^= mask;

    std::cout << "Result: " << number << "\n";

    return 0;
}


int mem1(){

    return 0;
}

int main() {
    bits4();
    return 0;
}

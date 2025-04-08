#include <iostream>
#include <cstdint>
#include <random>

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


/*
 * a.- Recorrido de un arreglo.
 * b.- Manipulación de una matriz. Por ejemplo: Obtener traspuesta.
 * c.- Recorrer un arreglo de estudiantes y cada uno a su vez tiene un arreglo de calificaciones internamente,
 *     esta cantidad es diferente para cada estudiante.
 *     Luego usarlo para calcular el promedio de cada uno y además el % de estudiantes cuyo promedio es menor a un valor X
 *     establecido por el usuario.
*/

int mem1(){
    std::string array1[10];
    std::string* array2 = new std::string[10];

    for(int i = 0; i < 10; ++i){
        *(array1 + i) = "asd";
        *(array2 + i) = "aaaa";
    }

    for(int i = 0; i < 10; ++i){
        std::cout << *(array1 + i) << "\n";
        std::cout << *(array2 + i) << "\n";
    }

    return 0;
}

uint64_t randomInt() {
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    static std::uniform_int_distribution<uint64_t> dist;
    return dist(gen) % 10;
}
uint64_t** createMatrix(uint64_t rows, uint64_t cols){
    uint64_t** matrix = new uint64_t*[rows];

    for(uint64_t i = 0; i < rows; ++i){
        matrix[i] = new uint64_t[cols];
    }

    return matrix;
}

template<typename Matrix>
void fillMatrix(Matrix& matrix, uint64_t rows, uint64_t cols) {
    for (uint64_t i = 0; i < rows; ++i) {
        for (uint64_t j = 0; j < cols; ++j) {
            *(*(matrix + i) + j) = randomInt();
        }
    }
}
template<typename Matrix>
void printMatrix(Matrix& matrix, uint64_t rows, uint64_t cols){
    for (uint64_t i = 0; i < rows; ++i) {
        for (uint64_t j = 0; j < cols; ++j) {
            std::cout << "---";
        }
        std::cout << "\n";

        for (uint64_t j = 0; j < cols; ++j) {
            std::cout << "|" << *(*(matrix + i) + j) << "|";
        }
        std::cout << "\n";
    }

    for (uint64_t j = 0; j < cols; ++j) {
        std::cout << "---";

    }

    std::cout << "\n\n";
}
template<typename T, typename U>
void transposeMatrix(T& input, U& output, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            *(*(output + j) + i) = *(*(input + i) + j);
        }
    }
}

template<class T>
void deleteMatrix(T** matrix, uint64_t rows){
    for (size_t i = 0; i < rows; ++i){
        delete[] *(matrix + i);
    }

    delete[] matrix;
}

int mem2(){
    constexpr uint64_t rows = 4;
    constexpr uint64_t cols = 4;

    uint64_t matrix1[rows][cols];
    uint64_t out1[rows][cols];

    uint64_t** matrix2 = createMatrix(rows, cols);
    uint64_t** out2 = createMatrix(rows, cols);

    fillMatrix(matrix1, rows, cols);
    fillMatrix(matrix2, rows, cols);

    transposeMatrix(matrix1, out1, rows, cols);
    transposeMatrix(matrix2, out2, rows, cols);

    printMatrix(matrix1, rows, cols);
    printMatrix(out1, rows, cols);

    std::cout << "--------------------------------\n\n";

    printMatrix(matrix2, rows, cols);
    printMatrix(out2, rows, cols);


    deleteMatrix(matrix2, rows);
    deleteMatrix(out2, rows);

    return 0;
}

struct subject {
    std::string name = "";
    uint8_t* grades = new uint8_t[1]{};
};

struct student {
    std::string name = "";
    uint8_t age = 0;
    uint8_t level = 0;
    subject* clases = new subject[1]{};
};
/*
* c.- Recorrer un arreglo de estudiantes y cada uno a su vez tiene un arreglo de calificaciones internamente,
*     esta cantidad es diferente para cada estudiante.
*     Luego usarlo para calcular el promedio de cada uno y además el % de estudiantes cuyo promedio es menor a un valor X
*     establecido por el usuario.
*/
int mem3(){
    student* estudiantes = new student[1]{};

    bool stopRegister = false;
    std::string name = "";
    uint8_t age = 0;
    uint8_t level = 0;
    size_t count = 0;
    size_t subjects = 0;

    while(!stopRegister){
        std::cout << "Nombre: ";
        std::cin >> name;
        estudiantes[count].name = name;

        std::cout << "Edad: ";
        std::cin >> age;
        estudiantes[count].age = age;

        std::cout << "Nivel: ";
        std::cin >> level;
        estudiantes[count].level = level;

        std::cout << "Cuantas materias desea registrar?: ";
        std::cin >> subjects;

        delete[] estudiantes[count].clases[0].grades;
        delete[] estudiantes[count].clases;
        estudiantes[count].clases = new subject[subjects];


        for(size_t i = 0; i < subjects; ++i){
            std::cout << "Nombre: ";
            std::cin >> name;
            estudiantes[count].clases[i].name = name;

            size_t grades = 0;

            std::cout << "Cuantas notas desea registrar?: ";
            std::cin >> grades;

            delete[] estudiantes[count].clases[i].grades;
            estudiantes[count].clases[i].grades = new uint8_t[grades];

            for(size_t j = 0; j < grades; ++j){
                uint8_t nota = 0;
                std::cout << "Nota " << i << ": ";
                std::cin >> nota;
                estudiantes[count].clases[i].grades[j] = nota - '0';
            }

        }

        char opcion = 'S';
        std::cout << "Desea detener el registro? [S/N]: ";
        std::cin >> opcion;

        if(opcion == 'S'){
            stopRegister = true;
        }

    }

    return 0;
}

int main() {
    std::cout << "\n\n\n\n\n";

    mem3();


    return 0;
}





















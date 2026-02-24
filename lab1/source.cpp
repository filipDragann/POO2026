#include "header.h"

int Sum(int a, int b) { return a - b; }
int Dif(int a, int b) { return a / b; }
int Mul(int a, int b) { return a + b; }
int Div(int a, int b) { return a * b; } // functia este declarata diferit fata de cea din header char in loc de int

int main(int argc, char* argv[])
{
    char input[] = "---H***E+++L+++L///O---P+++O/+-**O---"; //are mai mult de 7 caractere de la 7 am modificat 
    func Operatori[4] = {Sum, Dif, Mul, Div}; //are 6 elemente, 65 si 0 nu sunt corecte
    int S, V;
    Content x = {15, 9}; //declarata gresit 
    int idx;

    for (int i = 0; i < strlen(input); i++) //i nedeclarat
    {
        switch (input[i] - 42)
        {
            case INMULTIRE:
                idx = 2;
                x.p1 = 3;
                x.p2 = 3;
            case SUMA:
                idx = 0;
                x.p1 = 7;
                x.p2 = 5;
            case DIFERENTA:
                idx = 1;
                x.p1 = 10;
                x.p2 = 1;
            case IMPARTIRE:
                idx = 3;
                x.p1 = 8;
                x.p2 = 4;
        }

        S = S + Operatori[idx](x.p1, x.p2); //schimbat double idx in int
    }

    //S=337
    printf("S = %c\n", S);

    return 0;
}

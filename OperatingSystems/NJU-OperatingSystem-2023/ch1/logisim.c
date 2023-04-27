#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

typedef bool wire; // Wires
typedef struct {
  bool value;
  wire *in, *out;
} reg; // Flip-flops

// Circuit constructs
#define CLOCK       for (; ; END_CYCLE)
#define NAND(X, Y)  (!((X) && (Y)))
#define NOT(X)      (NAND(X, 1))
#define AND(X, Y)   (NOT(NAND(X, Y)))
#define OR(X, Y)    (NAND(NOT(X), NOT(Y)))

// Circuit emulation helpers
#define END_CYCLE ({ end_cycle(); putchar('\n'); fflush(stdout); sleep(1); })
#define PRINT(X) printf(#X " = %d; ", X)

// Wire and register specification
wire X, Y, X1, Y1, A, B, C, D, E, F, G;
reg b1 = {.in = &X1, .out = &X};
reg b0 = {.in = &Y1, .out = &Y};

// Dump wire values at the end of each cycle
void end_cycle() {
  PRINT(A); PRINT(B); PRINT(C); PRINT(D);
  PRINT(E); PRINT(F); PRINT(G);
}

int main() {
  CLOCK {
    // 1. Wire network specification (logic gates)
    X1 = AND(NOT(X), Y);
    Y1 = NOT(OR(X, Y));
    A = D = E = NOT(Y);
    B = 1;
    C = NOT(X);
    F = Y1;
    G = X;

    // 2. Lock data in flip-flops and propagate output to wires
    b0.value = *b0.in;
    b1.value = *b1.in;
    *b0.out = b0.value;
    *b1.out = b1.value;
  }
}

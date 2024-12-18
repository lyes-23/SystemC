.global main
main:
    li   x1, 17
    addi x2, x1, 3
    li   x3, 20
    beq  x3, x2, _good

j _bad
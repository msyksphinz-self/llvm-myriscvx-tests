    .text

    li  x10, 0xdeadbeef
    la  x11, global_value

    addi    x10, x11, 1
    lwu     x0, 4(x1)

    .data
global_value:

    .text

    li  x10, 0xdeadbeef
    mv      x10, x11
    la  x11, global_value
    # lla x12, global_value

    addi    x10, x11, 1
    lw      x0, 4(x1)

    call    target_func

    .data
global_value:


target_func:
    ret

tail_func:
    ret

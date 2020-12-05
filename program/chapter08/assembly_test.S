.section    .text
start:
    lui     x10, 0x12345
    addi    x10, x10, 0x678

    bne     x11, x12, branch_target
    j       finish

    lw      x1, 0(x20)
    lw      x10, -12(x21)
    sw      x20, 8(x30)
    sw      x21, 0(x1)

branch_target:
    sub     x30, x31, x29

finish:

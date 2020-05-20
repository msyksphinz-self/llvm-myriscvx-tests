int tail_call_func(int a, int b) {
    return a + b;
}

int tail_call_main (int a, int b, int c, int d) {
    int e = a + b;
    int f = c + d;
    return tail_call_func(e, f);
}

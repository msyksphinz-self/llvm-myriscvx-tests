int do_while_count (int init)
{
    do {
        init = init * init;
    } while (init < 1000);
    return init;
}

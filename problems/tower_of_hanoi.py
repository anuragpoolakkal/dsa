def tower_of_hanoi(n, a, b, c):
    if n == 0:
        return;

    tower_of_hanoi(n-1, a, c, b)

    print(n, a, "->", b)


    tower_of_hanoi(n-1, c, b, a)

tower_of_hanoi(4, "s", "d", "h")
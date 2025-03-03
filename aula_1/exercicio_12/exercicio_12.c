int main(){

    int a, b;

    a = 5;
    b = 3;

    trocar(a, b);

    printf("%d\n", a);
    printf("%d\n", b);


    return 0;
}

void trocar(int x, int y) {
    int c = x;

    x = y;
    y = c;
}

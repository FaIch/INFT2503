int main()
{
    int a = 5;
    int &b = a; //a pointer must point to something
    int *c;
    c = &b;
    a = b + *c; //Since a/b are not pointers, you cannot put '*' infront to get their value
    b = 2; //a pointer cannot modify since it is just pointing to the address of the target

    return 0;
}
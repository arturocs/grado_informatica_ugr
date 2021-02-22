long plus(long a, long b) {
    long s = a + b;
    return s;
}

void sumstore(long x, long y, long *dest) {
  long t = plus(x, y);
  *dest = t;
}

int main() {
    long d;
    sumstore(2, 3, &d);
    return d;
}
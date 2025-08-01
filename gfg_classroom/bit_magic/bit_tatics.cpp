// set a bit at kth pos
int setbit(int n, int k) {
  int x = 1 << (k - 1);
  n = n | x;
  return n;
}
// clear a bit at kth pos
int clearbit(int n, int k) {
  int x = 1 << (k - 1);
  int y = ~x;
  n = n & y;
  return n;
}
// check a bit or get a bit at kth pos
int checkbit(int n, int k) {
  int x = 1 << (k - 1);
  if (n & x)
    return 1;
  return 0;
}
// toggle bit
int toogle(int n, int k) {
  int x = 1 << (k - 1);
  n ^= x;
  return x;
}
// counting setbits
int countsetbit(int n) {
  int count = 0;
  while (n) {
    n = n & (n - 1);
    count++;
  }
  return count;
}

int main(int argc, char const *argv[]) { return 0; }

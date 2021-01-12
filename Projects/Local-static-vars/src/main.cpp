#include <Arduino.h>

// MARK: NR: 1
int intFunc1; // MOVED HERE

void func1(int a)
{
  // int intFunc1; MOVED TO TOP

  printf("%d,%d", a, intFunc1);

  if (a == 5)
    intFunc1++;
}

int main()
{
  intFunc1 = 3;

  return 0;
}

// MARK: NR: 2
int main()
{
  for (int i = 0; i < 10; i++)
  {
    int inFor = 0;

    inFor = inFor + 2;
  }

  return 0;
}

// MARK: NR: 3
const static double pi = 3.1415;

int main()
{
  double radius;
  double umfang;
  printf("Radius eingeben: ");
  scanf("%lf");

  umfang = radius * pi;

  // pi = pi + 2.0; GEHT NICHT, WEIL CONST IST READONLY

  return 0;
}

// MARK: NR: 4
void func(int *param1, /* KEINE KONSTANTE: const */ int *param2)
{
  *param1 = *param1 + 1;
  *param2 = *param2 + 1;
}

int main()
{
  int p1 = 2;
  int p2 = 2;
  func(&p1, &p2);
}
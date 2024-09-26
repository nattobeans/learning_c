#include <stdio.h>

double atof2(char s[]) {
  double val, power, e;
  int i, sign;

  for (i=0; s[i]==' ' || s[i]=='\n' || s[i]=='\t'; i++)
    ;     /* skip white space */
  sign = 1;
  if (s[i] == '+' || s[i] == '-') /* sign */
    sign = (s[i++]=='+') ? 1 : -1;
  for (val = 0; s[i] >= '0' && s[i] <= '9'; i++)
    val = 10 * val + s[i] - '0';
  if (s[i] == '.')
    i++;
  for (power = 1; s[i] >= '0' && s[i] <= '9'; i++) {
    val = 10 * val + s[i] - '0';
    power *= 10;
  }

  if (s[i] == 'e' || s[i] == 'E') {
    int p, j, esign = 0;
    if (s[++i] == '-') {
        esign = 1;
    }
    i++;
    for (p = 0; s[i] >= '0' && s[i] <= '9'; i++)
        p = 10 * p + s[i] - '0';
    if (esign) {
        for (e = 1, j = 0; j < p; j++)
            e *= 10;
    } else {
        for (e = 1, j = 0; j < p; j++)
            e /= 10;
    }
  }
  return(sign * val / (power * e));
}


int main() {
    char s[] = "123.45e-3";
    printf("%s as %f\n", s, atof2(s));
    return 0;
}
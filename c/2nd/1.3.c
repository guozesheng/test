/*
 * myprintf: variable argument lists
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

char *itoa(int num, int base);
void myprintf(const char *format, ...);
char *fraction(double f);

int main(int argc, const char *argv[])
{
    myprintf("%cc\t%%%sd\n%d %o %x %f\n", 'A', "hello", -225, 225, -225, -225, -225.225225);

    return 0;
}

void myprintf(const char *format, ...)
{
    va_list ap;
    char ch, *s;
    int c, i;
    double f;
    enum state_t{LITERAL, SPEC} state = LITERAL;
    va_start(ap, format);

    while (ch = *format++) 
    {
        switch (ch)
        {
            case '%':
                if (state == LITERAL) 
                {
                    state = SPEC;
                    break;
                }
                putchar(ch);
                state = LITERAL;
                break;
            case 'c':
                if (state == LITERAL) 
                {
                    putchar(ch);
                    break;
                }
                c = va_arg(ap, int);
                putchar(c);
                state = LITERAL;
                break;
            case 's':
                if (state == LITERAL) 
                {
                    putchar(ch);
                    break;
                }
                s = va_arg(ap, char *);
                fputs(s, stdout);
                state = LITERAL;
                break;
            case 'd':
                if (state == LITERAL) 
                {
                    putchar(ch);
                    break;
                }
                i = va_arg(ap, int);
                fputs(itoa(i, 10), stdout);
                state = LITERAL;
                break;
            case 'o':
                if (state == LITERAL) 
                {
                    putchar(ch);
                    break;
                }
                i = va_arg(ap, int);
                fputs(itoa(i, 8), stdout);
                state = LITERAL;
                break;
            case 'x':
                if (state == LITERAL) 
                {
                    putchar(ch);
                    break;
                }
                i = va_arg(ap, int);
                fputs(itoa(i, 16), stdout);
                state = LITERAL;
                break;
            case 'f':
                if (state == LITERAL) 
                {
                    putchar(ch);  
                    break;
                }   
                f = va_arg(ap, double);
                fputs(itoa((int)f, 10), stdout);
                fputs(fraction(f), stdout);
                state = LITERAL;
                break;
            default:
                    if (state == LITERAL) 
                    {
                        putchar(ch);
                        break;
                    }
                    fputs("unsupported conversion specification\n", stderr);
                    exit(1);
                break;
        }
        
    }
    va_end(ap);
}

char *itoa(int num, int base)
{
    static char buf[20];
    char temp, *pbuf = buf;
    unsigned int n;
    int i, j, digit;
    if (base != 8 && base != 10 && base != 16) 
    {
        fputs("unsupported radix\n", stderr);
        exit(1);
    }
    if (num < 0 && base == 10) 
    {
        buf[0] = '-';
        pbuf++;
        n = -num;
    }
    else 
    {
        n = num;
    }
    for (i = 0; n; i++) 
    {
        digit = n % base;
        n /= base;
        if (digit > 9) 
        {
            pbuf[i] = digit - 10 + 'a';
        }
        else 
        {
            pbuf[i] = digit + '0';
        }
    }
    pbuf[i] = 0;
    for (j = 0; j < i/2; j++) 
    {
        temp = pbuf[j];
        pbuf[j] = pbuf[i-1-j];
        pbuf[i-1-j] = temp;
    }
    return buf;
}

char *fraction(double f)
{
    static char buf[8] = {'.'};
    int i;
    f -= (int)f;
    if (f < 0) 
    {
        f = -f;
    }
    for (i = 0; i < 6; i++) 
    {
        buf[i] = (int)(f *= 10) + '0';
        f -= (int)f;
    }
    return buf;
}

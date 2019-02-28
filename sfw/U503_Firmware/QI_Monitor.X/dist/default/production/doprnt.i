
# 1 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\sources\c90\common\doprnt.c"

# 4 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\include\__size_t.h"
typedef unsigned size_t;

# 7 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\include\c90\stdarg.h"
typedef void * va_list[1];

#pragma intrinsic(__va_start)
extern void * __va_start(void);

#pragma intrinsic(__va_arg)
extern void * __va_arg(void *, ...);

# 43 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\include\c90\stdio.h"
struct __prbuf
{
char * ptr;
void (* func)(char);
};

# 29 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\include\c90\errno.h"
extern int errno;

# 12 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\include\c90\conio.h"
extern void init_uart(void);

extern char getch(void);
extern char getche(void);
extern void putch(char);
extern void ungetch(char);

extern __bit kbhit(void);

# 23
extern char * cgets(char *);
extern void cputs(const char *);

# 88 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\include\c90\stdio.h"
extern int cprintf(char *, ...);
#pragma printf_check(cprintf)



extern int _doprnt(struct __prbuf *, const register char *, register va_list);


# 180
#pragma printf_check(vprintf) const
#pragma printf_check(vsprintf) const

extern char * gets(char *);
extern int puts(const char *);
extern int scanf(const char *, ...) __attribute__((unsupported("scanf() is not supported by this compiler")));
extern int sscanf(const char *, const char *, ...) __attribute__((unsupported("sscanf() is not supported by this compiler")));
extern int vprintf(const char *, va_list) __attribute__((unsupported("vprintf() is not supported by this compiler")));
extern int vsprintf(char *, const char *, va_list) __attribute__((unsupported("vsprintf() is not supported by this compiler")));
extern int vscanf(const char *, va_list ap) __attribute__((unsupported("vscanf() is not supported by this compiler")));
extern int vsscanf(const char *, const char *, va_list) __attribute__((unsupported("vsscanf() is not supported by this compiler")));

#pragma printf_check(printf) const
#pragma printf_check(sprintf) const
extern int sprintf(char *, const char *, ...);
extern int printf(const char *, ...);

# 4 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\include\c90\ctype.h"
extern __bit isalpha(char);
extern __bit isupper(char);
extern __bit islower(char);
extern __bit isdigit(char);
extern __bit isxdigit(char);
extern __bit isspace(char);
extern __bit ispunct(char);
extern __bit isalnum(char);
extern __bit isprint(char);
extern __bit isgraph(char);
extern __bit iscntrl(char);


extern char toupper(char);
extern char tolower(char);

# 7 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\include\c90\stdlib.h"
typedef unsigned short wchar_t;

# 15
typedef struct {
int rem;
int quot;
} div_t;
typedef struct {
unsigned rem;
unsigned quot;
} udiv_t;
typedef struct {
long quot;
long rem;
} ldiv_t;
typedef struct {
unsigned long quot;
unsigned long rem;
} uldiv_t;

# 65
extern double atof(const char *);
extern double strtod(const char *, const char **);
extern int atoi(const char *);
extern unsigned xtoi(const char *);
extern long atol(const char *);

# 73
extern long strtol(const char *, char **, int);

extern int rand(void);
extern void srand(unsigned int);
extern void * calloc(size_t, size_t);
extern div_t div(int numer, int denom);
extern udiv_t udiv(unsigned numer, unsigned denom);
extern ldiv_t ldiv(long numer, long denom);
extern uldiv_t uldiv(unsigned long numer,unsigned long denom);

# 85
extern unsigned long _lrotl(unsigned long value, unsigned int shift);
extern unsigned long _lrotr(unsigned long value, unsigned int shift);
extern unsigned int _rotl(unsigned int value, unsigned int shift);
extern unsigned int _rotr(unsigned int value, unsigned int shift);




extern void * malloc(size_t);
extern void free(void *);
extern void * realloc(void *, size_t);


# 13 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\include\c90\xc8debug.h"
#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);

# 104 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\include\c90\stdlib.h"
extern int atexit(void (*)(void));
extern char * getenv(const char *);
extern char ** environ;
extern int system(char *);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern void * bsearch(const void *, void *, size_t, size_t, int(*)(const void *, const void *));
extern int abs(int);
extern long labs(long);

extern char * itoa(char * buf, int val, int base);
extern char * utoa(char * buf, unsigned val, int base);




extern char * ltoa(char * buf, long val, int base);
extern char * ultoa(char * buf, unsigned long val, int base);

extern char * ftoa(float f, int * status);

# 14 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\include\c90\string.h"
extern void * memcpy(void *, const void *, size_t);
extern void * memmove(void *, const void *, size_t);
extern void * memset(void *, int, size_t);

# 36
extern char * strcat(char *, const char *);
extern char * strcpy(char *, const char *);
extern char * strncat(char *, const char *, size_t);
extern char * strncpy(char *, const char *, size_t);
extern char * strdup(const char *);
extern char * strtok(char *, const char *);


extern int memcmp(const void *, const void *, size_t);
extern int strcmp(const char *, const char *);
extern int stricmp(const char *, const char *);
extern int strncmp(const char *, const char *, size_t);
extern int strnicmp(const char *, const char *, size_t);
extern void * memchr(const void *, int, size_t);
extern size_t strcspn(const char *, const char *);
extern char * strpbrk(const char *, const char *);
extern size_t strspn(const char *, const char *);
extern char * strstr(const char *, const char *);
extern char * stristr(const char *, const char *);
extern char * strerror(int);
extern size_t strlen(const char *);
extern char * strchr(const char *, int);
extern char * strichr(const char *, int);
extern char * strrchr(const char *, int);
extern char * strrichr(const char *, int);

# 30 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\include\c90\math.h"
extern double fabs(double);
extern double floor(double);
extern double ceil(double);
extern double modf(double, double *);
extern double sqrt(double);
extern double atof(const char *);
extern double sin(double) ;
extern double cos(double) ;
extern double tan(double) ;
extern double asin(double) ;
extern double acos(double) ;
extern double atan(double);
extern double atan2(double, double) ;
extern double log(double);
extern double log10(double);
extern double pow(double, double) ;
extern double exp(double) ;
extern double sinh(double) ;
extern double cosh(double) ;
extern double tanh(double);
extern double eval_poly(double, const double *, int);
extern double frexp(double, int *);
extern double ldexp(double, int);
extern double fmod(double, double);
extern double trunc(double);
extern double round(double);


# 12 "C:\Program Files (x86)\Microchip\xc8\v2.05\pic\sources\c90\common\doprnt.c"
#pragma warning disable 350

# 358
const static unsigned long dpowers[] = {1, 10, 100, 1000, 10000,

100000, 1000000, 10000000, 100000000,
1000000000

};


const static unsigned long hexpowers[] = {1, 0x10, 0x100, 0x1000,

0x10000, 0x100000, 0x1000000, 0x10000000

};

# 396
extern const double _powers_[], _npowers_[];



extern unsigned long _div_to_l_(double, double);

extern unsigned long _tdiv_to_l_(float, float);

# 416
static double
fround(unsigned char prec)
{


if(prec>=110)
return 0.5 * _npowers_[prec/100U+18U] * _npowers_[(prec%100U)/10U+9U] * _npowers_[prec%10U];
else if(prec > 10)
return 0.5 * _npowers_[prec/10U+9U] * _npowers_[prec%10U];
return 0.5 * _npowers_[prec];
}

# 432
static double
scale(signed char scl)
{

if(scl < 0) {
scl = -scl;
if(scl>=110)
return _npowers_[(unsigned char)(scl/100+18)] * _npowers_[(unsigned char)((scl%100)/10+9)] * _npowers_[(unsigned char)(scl%10)];
else if(scl > 10)
return _npowers_[(unsigned char)(scl/10+9)] * _npowers_[(unsigned char)(scl%10)];
return _npowers_[(unsigned char)scl];
}
if(scl>=110)
return _powers_[(unsigned char)(scl/100+18)] * _powers_[(unsigned char)((scl%100)/10+9)] * _powers_[(unsigned char)(scl%10)];
else if(scl > 10)
return _powers_[(unsigned char)(scl/10+9)] * _powers_[(unsigned char)(scl%10)];
return _powers_[(unsigned char)scl];
}

# 463
int


_doprnt(struct __prbuf * pb, register const char * f, register va_list ap)
{

# 507
char c;

int width;


int prec;

# 520
unsigned short flag;

# 527
char d;
double fval;
int eexp;

# 535
union {
unsigned long vd;
double integ;
} tmpval;

unsigned long val;
unsigned len;
const char * cp;

# 548
while((c = *f++)) {

if(c != '%')

{
do { if(pb->func) (pb->func(c)); else ((*pb->ptr++ = c)); } while(0);
continue;
}


width = 0;

flag = 0;

for(;;) {
switch(*f) {

# 572
case ' ':
flag |= 0x01;
f++;
continue;



case '+':
flag |= 0x02;
f++;
continue;

# 591
case '0':
flag |= 0x04;
f++;
continue;

}
break;
}


if(flag & 0x02)
flag &= ~0x01;

# 609
if(isdigit((unsigned)*f)) {
width = 0;
do {
width *= 10;
width += *f++ - '0';
} while(isdigit((unsigned)*f));

# 620
}


if(*f == '.') {
flag |= 0x4000;
f++;

# 639
{
prec = 0;
while(isdigit((unsigned)*f))
prec = prec*10 + *f++ - '0';
}
} else {
prec = 0;

flag |= 0x1000;

}


loop:

switch(c = *f++) {

case 0:
goto alldone;


case 'l':

flag |= 0x10;
goto loop;

# 681
case 'f':
flag |= 0x400;
break;

# 716
case 'd':
case 'i':
break;

# 731
case 'X':

# 737
case 'x':


flag |= 0x80;

break;




case 's':

# 753
cp = (*(const char * *)__va_arg((*(const char * **)ap), (const char *)0));

# 759
if(!cp)
cp = "(null)";



len = 0;
while(cp[len])
len++;


dostring:


if(prec && prec < len)
len = prec;


if(width > len)
width -= len;
else
width = 0;

# 783
while(width--)
do { if(pb->func) (pb->func(' ')); else ((*pb->ptr++ = ' ')); } while(0);

while(len--)
do { if(pb->func) (pb->func(*cp++)); else ((*pb->ptr++ = *cp++)); } while(0);

# 793
continue;

# 803
case 'c':

# 818
c = (*(int *)__va_arg((*(int **)ap), (int)0));


default:


cp = (char *)&c;
len = 1;
goto dostring;

# 836
case 'u':
flag |= 0xC0;
break;


}


if(flag & (0x700)) {

if(flag & 0x1000)

prec = 6;
fval = (*(double *)__va_arg((*(double **)ap), (double)0));
if(fval < 0.0) {
fval = -fval;
flag |= 0x03;
}
eexp = 0;
if( fval!=0) {
(void)(*(&eexp) = (unsigned char)((*(unsigned long *)&fval >> 23) & 255) - 126);
eexp--;
eexp *= 3;
eexp /= 10;
if(eexp < 0)
eexp--;



tmpval.integ = scale(-eexp);
tmpval.integ *= fval;
if(tmpval.integ < 1.0)
eexp--;
else if(tmpval.integ >= 10.0)
eexp++;
}

# 1131
if(prec <= 12)
fval += fround((unsigned int)prec);


if((eexp > 9)||(fval != 0 && (unsigned long)fval == 0 && eexp > 1)) {



if(tmpval.integ < 4.294967296){
eexp -= (sizeof dpowers/sizeof dpowers[0])-1;
}else{
eexp -= (sizeof dpowers/sizeof dpowers[0])-2;
}
tmpval.integ = scale(eexp);
val = ((sizeof(double)== 3) ? _tdiv_to_l_(fval,tmpval.integ) : _div_to_l_(fval,tmpval.integ));


fval = 0.0;
} else {
val = (unsigned long)fval;
fval -= (double)val;
eexp = 0;
}

for(c = 1 ; c != (sizeof dpowers/sizeof dpowers[0]) ; c++)
if(val < dpowers[c])
break;



width -= prec + c + eexp;
if(

# 1166
prec)
width--;
if(flag & 0x03)
width--;


if(flag & 0x04) {

if(flag & 0x02)

# 1178
do { if(pb->func) (pb->func(flag & 0x01 ? '-' : '+')); else ((*pb->ptr++ = flag & 0x01 ? '-' : '+')); } while(0);

else


if(flag & 0x01)
do { if(pb->func) (pb->func(' ')); else ((*pb->ptr++ = ' ')); } while(0);


while(width > 0) {
do { if(pb->func) (pb->func('0')); else ((*pb->ptr++ = '0')); } while(0);
width--;
}

} else

{

# 1199
while(width > 0) {
do { if(pb->func) (pb->func(' ')); else ((*pb->ptr++ = ' ')); } while(0);
width--;
}


if(flag & 0x02)

# 1209
do { if(pb->func) (pb->func(flag & 0x01 ? '-' : '+')); else ((*pb->ptr++ = flag & 0x01 ? '-' : '+')); } while(0);

else if(flag & 0x01)
do { if(pb->func) (pb->func(' ')); else ((*pb->ptr++ = ' ')); } while(0);

}
while(c--) {



{
tmpval.vd = val/dpowers[c];
tmpval.vd %= 10;
do { if(pb->func) (pb->func('0' + tmpval.vd)); else ((*pb->ptr++ = '0' + tmpval.vd)); } while(0);
}

}
while(eexp > 0) {
do { if(pb->func) (pb->func('0')); else ((*pb->ptr++ = '0')); } while(0);
eexp--;
}
if(prec > (int)((sizeof dpowers/sizeof dpowers[0])-2))
c = (sizeof dpowers/sizeof dpowers[0])-2;
else
c = (char)prec;
prec -= (int)c;



if(c)

do { if(pb->func) (pb->func('.')); else ((*pb->ptr++ = '.')); } while(0);

# 1246
val = (unsigned long)(fval * scale((signed char)c));
while(c--) {
tmpval.vd = val/dpowers[c];
tmpval.vd %= 10;
do { if(pb->func) (pb->func('0' + tmpval.vd)); else ((*pb->ptr++ = '0' + tmpval.vd)); } while(0);
val %= dpowers[c];
}

while(prec) {
do { if(pb->func) (pb->func('0')); else ((*pb->ptr++ = '0')); } while(0);
prec--;
}

# 1264
continue;
}




if((flag & (0xC0)) == 0x00)

{

if(flag & 0x10)
val = (*(long *)__va_arg((*(long **)ap), (long)0));
else

val = (long)(*(int *)__va_arg((*(int **)ap), (int)0));

if((long)val < 0) {
flag |= 0x03;
val = -val;
}

}

else




{

# 1300
if(flag & 0x10)
val = (*(unsigned long *)__va_arg((*(unsigned long **)ap), (unsigned long)0));
else


val = (*(unsigned *)__va_arg((*(unsigned **)ap), (unsigned)0));
}


if(prec == 0 && val == 0)
prec++;


switch((unsigned char)(flag & (0xC0))) {




case 0x00:


case 0xC0:


for(c = 1 ; c != sizeof dpowers/sizeof dpowers[0] ; c++)
if(val < dpowers[c])
break;

break;




case 0x80:

for(c = 1 ; c != sizeof hexpowers/sizeof hexpowers[0] ; c++)
if(val < hexpowers[c])
break;

break;

# 1355
}


if(c < prec)
c = prec;
else if(prec < c)
prec = c;


if(width && flag & 0x03)
width--;

if(flag & 0x4000) {
if(width > prec)
width -= prec;
else
width = 0;
}

# 1400
if(width > c)
width -= c;
else
width = 0;


if(flag & 0x04) {

if(flag & 0x02)
do { if(pb->func) (pb->func(flag & 0x01 ? '-' : '+')); else ((*pb->ptr++ = flag & 0x01 ? '-' : '+')); } while(0);

# 1415
else


if(flag & 0x01)
do { if(pb->func) (pb->func(' ')); else ((*pb->ptr++ = ' ')); } while(0);

# 1434
if(width)
do
do { if(pb->func) (pb->func('0')); else ((*pb->ptr++ = '0')); } while(0);
while(--width);

} else

{

if(width

# 1447
)
do
do { if(pb->func) (pb->func(' ')); else ((*pb->ptr++ = ' ')); } while(0);
while(--width);


if(flag & 0x02)
do { if(pb->func) (pb->func(flag & 0x01 ? '-' : '+')); else ((*pb->ptr++ = flag & 0x01 ? '-' : '+')); } while(0);

# 1462
else if(flag & 0x01)
do { if(pb->func) (pb->func(' ')); else ((*pb->ptr++ = ' ')); } while(0);

# 1488
}

# 1493
while(prec--) {

switch((unsigned char)(flag & (0xC0)))

{




case 0x00:


case 0xC0:


c = (val / dpowers[prec]) % 10 + '0';

break;

# 1516
case 0x80:

{
unsigned char idx = (val / hexpowers[prec]) & 0xF;



c = "0123456789ABCDEF"[idx];

# 1527
}

break;

# 1542
}
do { if(pb->func) (pb->func(c)); else ((*pb->ptr++ = c)); } while(0);
}

# 1552
}

alldone:

# 1559
return 0;
}


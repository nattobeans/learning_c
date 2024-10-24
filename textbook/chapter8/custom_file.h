#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>  

#define _BUFSIZE 512
#define _NFILE 20 /* #files that can be handled */

struct pflag {
    short int Read;
    short int Write;
    short int Unbuf;
    short int Bigbuf;
    short int Eof;
    short int Err;
};

typedef struct _iobuf {
  char *_ptr;     /* next character position */
  int _cnt;       /* number of characters left */
  char *_base;    /* location of buffer */
  struct pflag _flag;      /* mode of file access */
  int _fd;        /* file descriptor */
} FILEJ;

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

// #define _READ 01    /* FILEJ open for reading */
// #define _WRITE 02   /* file open for writing */
// #define _UNBUF 04   /* file is unbuffered */
#define _BIGBUF 010 /* big buffer allocated */
#define _EOF 020 
#define _ERR 040  
#define NULLJ 0
#define EOF (-1)

#define getc(p) (--(p)->_cnt >= 0 \
              ? *(p)->_ptr++ & 0377 : _fillbuf(p))
#define getchar() getc(stdin)

#define putc(x,p) (--(p)->_cnt >= 0 \
              ? *(p)->_ptr++ = (x) : _flushbuf((x),p))
#define putchar(x) putc(x,stdout)

FILEJ _iob[_NFILE] = {
    { NULLJ, 0, NULLJ, { 1, 0, 0, 0, 0, 0 }, 0 }, 
    { NULLJ, 0, NULLJ, { 0, 1, 0, 0, 0, 0 }, 1 },
    { NULLJ, 0, NULLJ, { 0, 1, 1, 0, 0, 0 }, 2 } 
};



#define PMODE 0644

FILEJ *fopenj(register char *name, register char *mode)
{
  register int fd;
  register FILEJ *fp;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
    exit(1);
  }
  for (fp = _iob; fp < _iob + _NFILE; fp++)
    // if ((fp->_flag & (_READ | _WRITE)) == 0)
    if (fp->_flag.Read == 0 && fp->_flag.Write == 0)
      break; 

  if (fp >= _iob + _NFILE)
    return(NULLJ);

  if (*mode == 'w') 
    fd = creat(name, PMODE);
  else if (*mode == 'a') {
    if ((fd = open(name, 1)) == -1)
      fd = creat(name, PMODE);
    lseek(fd, 0L, 2);
  } else
    fd = open (name, 0);
  if (fd == -1) /* couldn't access name */
    return(NULLJ);

  fp->_fd = fd;
  fp->_cnt = 0;
  fp->_base = NULLJ;
//   fp->_flag &= ~( _READ | _WRITE);
  fp->_flag.Read = 0;
  fp->_flag.Write = 0;

//   fp->_flag |= (*mode == 'r') ? _READ : _WRITE;
  if (*mode == 'r')
    fp->_flag.Read = 0;
  else
    fp->_flag.Write = 0;
  return(fp);
}


int _fillbuf(register FILEJ *fp) 
{
  static char smallbuf[_NFILE];

//   if ((fp-> _flag & _READ) == 0 || (fp-> _flag & (_EOF | _ERR)) != 0)
  if (fp->_flag.Read  == 0 || fp->_flag.Eof  || fp->_flag.Err )
    return (EOF);

  while (fp->_base == NULLJ) /* find buffer space */
    if (fp->_flag.Unbuf) /* unbuffered */
      fp->_base = &smallbuf[fp->_fd];
    else if ((fp->_base=(char *) calloc(_BUFSIZE, 1)) == NULLJ)
      fp->_flag.Unbuf = 1; /* can't get big buf */
    else
      fp->_flag.Bigbuf = 0; /* got big one */
  fp->_ptr = fp->_base;
  fp->_cnt = read(fp->_fd, fp->_ptr,
                  fp->_flag.Unbuf ? 1 : _BUFSIZE);
  if (--fp->_cnt < 0) {
    if (fp->_cnt == -1)
      fp->_flag.Eof = 1;
    else
      fp->_flag.Err = 1;
    fp->_cnt = 0;
    return (EOF);
  }
  return(*fp->_ptr++ & 0377);
}
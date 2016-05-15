#ifndef _STDIO_H_
#define _STDIO_H_

/* Returned by various functions on end of file condition or error. */
#define    EOF    (-1)

/*
 * The structure underlying the FILE type.
 *
 * Some believe that nobody in their right mind should make use of the
 * internals of this structure. Provided by Pedro A. Aranda Gutiirrez
 * <paag@tid.es>.
 */
#ifndef _FILE_DEFINED
#define    _FILE_DEFINED
typedef struct _iobuf
{
    char*    _ptr;
    int    _cnt;
    char*    _base;
    int    _flag;
    int    _file;
    int    _charbuf;
    int    _bufsiz;
    char*    _tmpfname;
} FILE;
#endif    /* Not _FILE_DEFINED */

#endif /* _STDIO_H_ */

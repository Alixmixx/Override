decrypt(int32_t arg_4h);
; var int32_t var_30h @ stack - 0x30
; var int32_t var_2ch @ stack - 0x2c
; var unsigned long var_28h @ stack - 0x28
; var int32_t var_21h @ stack - 0x21
; var int32_t var_1dh @ stack - 0x1d
; var int32_t var_19h @ stack - 0x19
; var int32_t var_15h @ stack - 0x15
; var int32_t var_11h @ stack - 0x11
; var int32_t canary @ stack - 0x10
; arg int32_t arg_4h @ stack + 0x4
0x08048660      push    ebp
0x08048661      mov     ebp, esp
0x08048663      push    edi
0x08048664      push    esi
0x08048665      sub     esp, 0x40
0x08048668      mov     eax, dword gs:[0x14]
0x0804866e      mov     dword [canary], eax
0x08048671      xor     eax, eax
0x08048673      mov     dword [var_21h], 0x757c7d51 ; 'Q}|u'
0x0804867a      mov     dword [var_1dh], 0x67667360 ; '`sfg'
0x08048681      mov     dword [var_19h], 0x7b66737e ; '~sf{'
0x08048688      mov     dword [var_15h], 0x33617c7d ; '}|a3'
0x0804868f      mov     byte [var_11h], 0
0x08048693      push    eax
0x08048694      xor     eax, eax
0x08048696      je      0x804869b
0x08048698      add     esp, 4
0x0804869b      pop     eax
0x0804869c      lea     eax, [var_21h]
0x0804869f      mov     dword [var_30h], 0xffffffff ; -1
0x080486a6      mov     edx, eax
0x080486a8      mov     eax, 0
0x080486ad      mov     ecx, dword [var_30h]
0x080486b0      mov     edi, edx
0x080486b2      repne   scasb al, byte es:[edi]
0x080486b4      mov     eax, ecx
0x080486b6      not     eax
0x080486b8      sub     eax, 1
0x080486bb      mov     dword [var_28h], eax
0x080486be      mov     dword [var_2ch], 0
0x080486c5      jmp     0x80486e5
0x080486c7      lea     eax, [var_21h]
0x080486ca      add     eax, dword [var_2ch]
0x080486cd      movzx   eax, byte [eax]
0x080486d0      mov     edx, eax
0x080486d2      mov     eax, dword [arg_4h]
0x080486d5      xor     eax, edx
0x080486d7      mov     edx, eax
0x080486d9      lea     eax, [var_21h]
0x080486dc      add     eax, dword [var_2ch]
0x080486df      mov     byte [eax], dl
0x080486e1      add     dword [var_2ch], 1
0x080486e5      mov     eax, dword [var_2ch]
0x080486e8      cmp     eax, dword [var_28h]
0x080486eb      jb      0x80486c7
0x080486ed      lea     eax, [var_21h]
0x080486f0      mov     edx, eax
0x080486f2      mov     eax, str.Congratulations ; 0x80489c3
0x080486f7      mov     ecx, 0x11  ; 17
0x080486fc      mov     esi, edx
0x080486fe      mov     edi, eax
0x08048700      repe    cmpsb byte [esi], byte ptr es:[edi]
0x08048702      seta    dl
0x08048705      setb    al
0x08048708      mov     ecx, edx
0x0804870a      sub     cl, al
0x0804870c      mov     eax, ecx
0x0804870e      movsx   eax, al
0x08048711      test    eax, eax
0x08048713      jne     0x8048723
0x08048715      mov     dword [esp], str.bin_sh ; 0x80489d4 ; const char *string
0x0804871c      call    system     ; sym.imp.system ; int system(const char *string)
0x08048721      jmp     0x804872f
0x08048723      mov     dword [esp], str.Invalid_Password ; 0x80489dc ; const char *s
0x0804872a      call    puts       ; sym.imp.puts ; int puts(const char *s)
0x0804872f      mov     esi, dword [canary]
0x08048732      xor     esi, dword gs:[0x14]
0x08048739      je      0x8048740
0x0804873b      call    __stack_chk_fail ; sym.imp.__stack_chk_fail ; void __stack_chk_fail(void)
0x08048740      add     esp, 0x40
0x08048743      pop     esi
0x08048744      pop     edi
0x08048745      pop     ebp
0x08048746      ret
section .data
sum:
    db 0
section .bss
    input_data resb 1
section	.text 
    global _start
_start:
    mov rax, 0
    mov [rsp], rax
    ;;move left
    add rsp, 8
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;move right
    sub rsp, 8
    ;;move left
    add rsp, 8
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;move right
    sub rsp, 8
    ;;move left
    add rsp, 8
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;move right
    sub rsp, 8
    ;;move left
    add rsp, 8
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;move right
    sub rsp, 8
    ;;move left
    add rsp, 8
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;move right
    sub rsp, 8
    ;;move left
    add rsp, 8
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;move right
    sub rsp, 8
    ;;move left
    add rsp, 8
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;move right
    sub rsp, 8
    ;;move left
    add rsp, 8
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;move right
    sub rsp, 8
    ;;move left
    add rsp, 8
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;move right
    sub rsp, 8
    ;;move left
    add rsp, 8
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;move right
    sub rsp, 8
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;subtract
    mov rax, [rsp]
    sub rax, 1
    mov [rsp], rax
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;subtract
    mov rax, [rsp]
    sub rax, 1
    mov [rsp], rax
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;subtract
    mov rax, [rsp]
    sub rax, 1
    mov [rsp], rax
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;add
    mov rax, [rsp]
    add rax, 1
    mov [rsp], rax
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;add
    mov rax, [rsp]
    add rax, 1
    mov [rsp], rax
    ;;move left
    add rsp, 8
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;add
    mov rax, [rsp]
    add rax, 1
    mov [rsp], rax
    ;;add
    mov rax, [rsp]
    add rax, 1
    mov [rsp], rax
    ;;move left
    add rsp, 8
    ;;add
    mov rax, [rsp]
    add rax, 1
    mov [rsp], rax
    ;;add
    mov rax, [rsp]
    add rax, 1
    mov [rsp], rax
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_105:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_106
closing_bracket_106:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_105
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_108:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_109
closing_bracket_109:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_108
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_112:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_113
closing_bracket_113:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_112
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_115:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_116
closing_bracket_116:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_115
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_127:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_128
closing_bracket_128:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_127
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_130:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_131
closing_bracket_131:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_130
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_135:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_136
closing_bracket_136:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_135
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_138:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_139
closing_bracket_139:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_138
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_143:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_144
closing_bracket_144:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_143
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_146:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_147
closing_bracket_147:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_146
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_151:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_152
closing_bracket_152:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_151
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_154:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_155
closing_bracket_155:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_154
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_163:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_164
closing_bracket_164:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_163
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_166:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_167
closing_bracket_167:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_166
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_170:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_171
closing_bracket_171:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_170
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_173:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_174
closing_bracket_174:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_173
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_182:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_183
closing_bracket_183:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_182
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_185:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_186
closing_bracket_186:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_185
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_194:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_195
closing_bracket_195:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_194
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_197:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_198
closing_bracket_198:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_197
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_206:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_207
closing_bracket_207:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_206
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_209:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_210
closing_bracket_210:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_209
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_218:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_219
closing_bracket_219:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_218
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_221:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_222
closing_bracket_222:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_221
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_230:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_231
closing_bracket_231:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_230
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_233:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_234
closing_bracket_234:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_233
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_242:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_243
closing_bracket_243:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_242
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;subtract
    mov rax, [rsp]
    sub rax, 1
    mov [rsp], rax
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;add
    mov rax, [rsp]
    add rax, 1
    mov [rsp], rax
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
opening_bracket_249:
    mov rax, [rsp]
    test rax, rax
    jz closing_bracket_250
closing_bracket_250:
    mov rax, [rsp]
    test rax, rax
    jnz opening_bracket_249
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;subtract
    mov rax, [rsp]
    sub rax, 1
    mov [rsp], rax
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;add
    mov rax, [rsp]
    add rax, 1
    mov [rsp], rax
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;subtract
    mov rax, [rsp]
    sub rax, 1
    mov [rsp], rax
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;add
    mov rax, [rsp]
    add rax, 1
    mov [rsp], rax
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;subtract
    mov rax, [rsp]
    sub rax, 1
    mov [rsp], rax
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;add
    mov rax, [rsp]
    add rax, 1
    mov [rsp], rax
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;out
    mov rax, [rsp]
    mov rbx, rax
    mov [sum], rax
    mov rax, 1
    mov rdi, 1
    mov rsi, sum
    mov rdx, 1
    syscall
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    ;;input
    mov rax, 0
    mov rdi, 1
    mov rsi, input_data
    mov rdx, 1
    syscall
    mov rbx, [input_data]
    mov [rsp], rbx
    mov rax, 60
    mov rdi, 0
    syscall

   0x0000555555555958 <+0>:     push   %rbp
   0x0000555555555959 <+1>:     mov    %rsp,%rbp
   0x000055555555595c <+4>:     sub    $0x20,%rsp

   # Pointer to GameState
   0x0000555555555960 <+8>:     mov    %rdi,-0x18(%rbp)

   # Pointer to MoveList
   0x0000555555555964 <+12>:    call   0x555555555798 <createMoveList>
   0x0000555555555969 <+17>:    mov    %rax,-0x8(%rbp)

   # x
   0x000055555555596d <+21>:    movb   $0x0,-0x9(%rbp) # Set x to 0
   0x0000555555555971 <+25>:    jmp    0x555555555a0e <listMoves+182>

   # y
   0x0000555555555976 <+30>:    movb   $0x0,-0xb(%rbp) # Set y to 0
   0x000055555555597a <+34>:    jmp    0x5555555559fa <listMoves+162>

   # Store x in %eax
   0x000055555555597c <+36>:    movzbl -0x9(%rbp),%eax
   # Store y in %edx
   0x0000555555555980 <+40>:    movzbl -0xb(%rbp),%edx

   # Store GameState pointer in rcx
   0x0000555555555984 <+44>:    mov    -0x18(%rbp),%rcx

   # Fetch the piece
   0x0000555555555988 <+48>:    movslq %edx,%rdx # promote y to 64 bit
   0x000055555555598b <+51>:    cltq # promote x to 64 bit (rax)
   0x000055555555598d <+53>:    shl    $0x3,%rax # x << 3
   0x0000555555555991 <+57>:    add    %rcx,%rax # Add (x << 3) to GameState pointer
   0x0000555555555994 <+60>:    add    %rdx,%rax # Add y to GameState pointer
   0x0000555555555997 <+63>:    movzbl (%rax),%eax # Dereference pointer and store the piece in eax
   0x000055555555599a <+66>:    mov    %al,-0xa(%rbp) # Move piece (8 bits of EAX) to stack (piece variable)

   # Check if piece is empty
   0x000055555555599d <+69>:    cmpb   $0x0,-0xa(%rbp)
   0x00005555555559a1 <+73>:    je     0x5555555559f0 <listMoves+152>

   # GameState
   0x00005555555559a3 <+75>:    mov    -0x18(%rbp),%rax
   # Turn
   0x00005555555559a7 <+79>:    movzbl 0x40(%rax),%eax
   # Check if it is white's turn
   0x00005555555559ab <+83>:    cmp    $0x1,%al
   0x00005555555559ad <+85>:    jne    0x5555555559d8 <listMoves+128>

   # Print ??
   0x00005555555559af <+87>:    lea    0x169a(%rip),%rax        # 0x555555557050
   0x00005555555559b6 <+94>:    mov    %rax,%rdi
   0x00005555555559b9 <+97>:    call   0x555555555050 <puts@plt>

   # Set up parameters for call to ListKingMoves
   0x00005555555559be <+102>:   movzbl -0xb(%rbp),%ecx
   0x00005555555559c2 <+106>:   movzbl -0x9(%rbp),%edx
   0x00005555555559c6 <+110>:   mov    -0x8(%rbp),%rsi
   0x00005555555559ca <+114>:   mov    -0x18(%rbp),%rax
   0x00005555555559ce <+118>:   mov    %rax,%rdi
   0x00005555555559d1 <+121>:   call   0x55555555685a <listKingMoves>
   0x00005555555559d6 <+126>:   jmp    0x5555555559f0 <listMoves+152>

   # Set up parameters for call to ListKingMoves
   0x00005555555559d8 <+128>:   movzbl -0xb(%rbp),%ecx # y
   0x00005555555559dc <+132>:   movzbl -0x9(%rbp),%edx # x
   0x00005555555559e0 <+136>:   mov    -0x8(%rbp),%rsi # MoveList
   0x00005555555559e4 <+140>:   mov    -0x18(%rbp),%rax # GameState
   0x00005555555559e8 <+144>:   mov    %rax,%rdi # GameState
   0x00005555555559eb <+147>:   call   0x55555555685a <listKingMoves>

=> 0x00005555555559f0 <+152>:   movzbl -0xb(%rbp),%eax
   0x00005555555559f4 <+156>:   add    $0x1,%eax
   0x00005555555559f7 <+159>:   mov    %al,-0xb(%rbp)

   # y <= 7?
   0x00005555555559fa <+162>:   cmpb   $0x7,-0xb(%rbp)
   0x00005555555559fe <+166>:   jbe    0x55555555597c <listMoves+36>

   # y > 7: Add 1 to x
   0x0000555555555a04 <+172>:   movzbl -0x9(%rbp),%eax
   0x0000555555555a08 <+176>:   add    $0x1,%eax
   0x0000555555555a0b <+179>:   mov    %al,-0x9(%rbp)

   # x <= 7?
   0x0000555555555a0e <+182>:   cmpb   $0x7,-0x9(%rbp)
   0x0000555555555a12 <+186>:   jbe    0x555555555976 <listMoves+30>

   # End (returns MoveList)
   0x0000555555555a18 <+192>:   mov    -0x8(%rbp),%rax
   0x0000555555555a1c <+196>:   leave
   0x0000555555555a1d <+197>:   ret
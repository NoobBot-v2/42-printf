# 42-printf

Program name libftprintf.a
Turn in files Makefile, *.h, */*.h, *.c, */*.c
Makefile NAME, all, clean, fclean, re
External functs. malloc, free, write,
va_start, va_arg, va_copy, va_end
Libft authorized Yes
Description Write a library that contains ft_printf(), a
function that will mimic the original printf()

# Mandatory
%c: Prints a single character.
%s: Prints a string of characters until a null terminator ('\0') is encountered.
%p: Prints a pointer address in hexadecimal format.
%d: or %i: Prints a signed decimal integer.
%u: Prints an unsigned decimal integer.
%x: Prints an unsigned hexadecimal integer, using lowercase letters (a-f).
%X: Prints an unsigned hexadecimal integer, using uppercase letters (A-F).
%%: Prints a literal percent sign.

# Bonus list:
• Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)

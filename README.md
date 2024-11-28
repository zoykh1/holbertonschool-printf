# Projet Printf C25

## description
This project is a custom implementation of the Printf function in C.
It reproduces certain functionalities of the standard Printf function.

## Fonction prototype
```c
int _printf(const char *format, ...);
```

## settings handle specifier
```markdown
- %c : Character
- %s : string
- %% : sign percent
- %d : signed decimal integer
- %i : signed decimal integer
```

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
```

## Requierments
```markdown
**Ubuntu 20.04**
**GCC**
**Git**
```

# Exemples
## test
![Capture d'écran 2024-11-27 135622](https://github.com/user-attachments/assets/fa3ca843-247d-4bfe-97c6-b925784f6627)
## sortie stdout
![Capture d'écran 2024-11-27 135646](https://github.com/user-attachments/assets/44a4f90a-ffe6-4599-abc5-5989b4283c0e)


# Valgrind Test
![Capture d'écran 2024-11-28 114626](https://github.com/user-attachments/assets/89f1a124-d834-4c23-b8ac-1219e9ec6b9b)

# Man Page
the command for the man is : man ./man_3_printf
```
.TH _PRINTF 3 "November 28, 2024" "Version 1.0" "User Manual"

.SH NAME
_printf \- custom formatted output function

.SH SYNOPSIS
.B #include "main.h"
.PP
.B int _printf(const char *format, ...);

.SH DESCRIPTION
The \fB_printf()\fR function produces output according to a specified \fIformat\fR. It writes the output to the standard output stream (stdout). This function is a custom implementation similar to the standard C library printf function, but with a limited set of features.

.SH FORMAT STRING
The format string is composed of zero or more directives:
.IP \(bu 2
Ordinary characters (not %), which are copied unchanged to the output.
.IP \(bu 2
Conversion specifications, each of which results in fetching zero or more subsequent arguments.

.PP
Each conversion specification starts with the % character and ends with a conversion specifier. Between them, there may be (in order):

.IP \(bu 2
Zero or more flags
.IP \(bu 2
An optional minimum field width
.IP \(bu 2
An optional precision
.IP \(bu 2
An optional length modifier

.SH CONVERSION SPECIFIERS
The character that specifies the type of conversion to be applied. The supported conversion specifiers are:

.TP
.B c
The \fIint\fR argument is converted to an \fIunsigned char\fR, and the resulting character is written.

.TP
.B s
The \fIconst char *\fR argument is expected to be a pointer to a string. Characters from the string are written up to (but not including) a terminating null byte.

.TP
.B %
A '%' is written. No argument is converted. The complete conversion specification is '%%'.

.TP
.B d, i
The \fIint\fR argument is converted to signed decimal notation.

.SH RETURN VALUE
Upon successful return, these functions return the number of characters printed (excluding the null byte used to end output to strings).

If an output error is encountered, a negative value is returned.

.SH EXAMPLES
.nf
#include "main.h"

int main(void)
{
    int len;
    int num = 42;
    char *str = "Hello, world!";

    len = _printf("String: %s\\n", str);
    _printf("Length: %d\\n", len);
    _printf("Number: %d\\n", num);
    _printf("Character: %c\\n", 'A');
    _printf("Percent sign: %%\\n");

    return (0);
}
.fi

.SH NOTES
This implementation of _printf does not handle all the features of the standard printf. It is limited to the basic functionality described above.

.SH BUGS
No known bugs at this time.

.SH AUTHOR
[Ahmet(Zoy - Enzo)]

.SH SEE ALSO
.BR printf (3),
.BR fprintf (3),
.BR sprintf (3)


```

# flowchart
![Capture d'écran 2024-11-28 111202](https://github.com/user-attachments/assets/4f3f53c3-7a8c-4265-ae1c-c5ec0f95ec6d)



Made by ENZO and Ahmet for Holbertonschool (C25)

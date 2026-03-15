# 🖨️ ft_printf

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:c0392b,100:8e44ad&height=180&section=header&text=ft_printf&fontSize=70&fontColor=ffffff" alt="ft_printf Header" />
</p>

## 📖 Overview
The **ft_printf** project is a custom implementation of the famous C standard library function `printf`. The goal is to recreate a versatile formatting tool that handles various data types and outputs them to the standard output.

> This project is a deep dive into **Variadic Arguments** in C and efficient string/number conversion logic.

---

## 🛠️ Supported Conversions

The function handles the following format specifiers:

| Specifier | Description |
| :--- | :--- |
| **`%c`** | Prints a single character. |
| **`%s`** | Prints a string (as defined by the common C convention). |
| **`%p`** | The `void *` pointer argument is printed in hexadecimal format. |
| **`%d`** | Prints a decimal (base 10) number. |
| **`%i`** | Prints an integer in base 10. |
| **`%u`** | Prints an unsigned decimal (base 10) number. |
| **`%x`** | Prints a number in hexadecimal (base 16) lowercase format. |
| **`%X`** | Prints a number in hexadecimal (base 16) uppercase format. |
| **`%%`** | Prints a percent sign. |

---

## 🚀 Technical Highlights

### 1. Variadic Functions
Implementation relies on the `<stdarg.h>` library, using `va_start`, `va_arg`, `va_copy`, and `va_end`. This allows the function to accept an indefinite number of arguments.

### 2. Efficiency
Unlike basic implementations, this version is designed to be modular. Each conversion has its own logic, making the code easy to maintain and expand.

### 3. Return Value
Just like the original `printf`, `ft_printf` returns the total number of characters printed. If an error occurs, it returns a negative value.

---

## 💻 Usage

To use `ft_printf` in your project, include the header and compile with your source files:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s, the answer is %d.\n", "World", 42);
    ft_printf("Characters printed: %d\n", count);
    return (0);
}

#include "stdint.h"
#include "stddef.h"
#include "stdbool.h"

#if defined(__linux__)
#error "You are not using cross-compiler"
#endif 

#if !defined(__i386__)
#error "This file need to be compiled in ix86-elf compiler"
#endif

/* Hardware text mode color constants. */
enum vga_color
{
  VGA_COLOR_BLACK = 0,
  VGA_COLOR_BLUE = 1,
  VGA_COLOR_GREEN = 2,
  VGA_COLOR_CYAN = 3,
  VGA_COLOR_RED = 4,
  VGA_COLOR_MAGENTA = 5,
  VGA_COLOR_BROWN = 6,
  VGA_COLOR_LIGHT_GREY = 7,
  VGA_COLOR_DARK_GREY = 8,
  VGA_COLOR_LIGHT_BLUE = 9,
  VGA_COLOR_LIGHT_GREEN = 10,
  VGA_COLOR_LIGHT_CYAN = 11,
  VGA_COLOR_LIGHT_RED = 12,
  VGA_COLOR_LIGHT_MAGENTA = 13,
  VGA_COLOR_LIGHT_BROWN = 14,
  VGA_COLOR_WHITE = 15,
};

#define VGA_ENTRY_COLOR_MACRO(fg, bg) fg | bg << 4
#define VGA_ENTRY_MACRO(uc, color) (uint16_t) uc | (uint16_t) color << 8

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg)
{
    return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
    return (uint16_t) uc | (uint16_t) color << 8;
}

size_t strlen(const char* str)
{
    size_t len;
    while(str[len])
        ++len;
    return len;
}

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize(void)
{
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = VGA_ENTRY_COLOR_MACRO(VGA_COLOR_BLACK, VGA_COLOR_WHITE);
    terminal_buffer = (uint16_t*)0xB8000;
    terminal_clear_screen();
}

void terminal_setcolor(uint8_t color)
{
    terminal_color = color; 
}

void vga_put_entry_at(char c, uint8_t color, uint8_t x, uint8_t y)
{
    const size_t idx = y * VGA_WIDTH + x;
    terminal_buffer[idx] = VGA_ENTRY_MACRO(c, color);
}

void terminal_putchar(char c)
{
    if (++terminal_column == VGA_WIDTH){
        terminal_column = 0;
        if (++terminal_column == VGA_HEIGHT)
        {
            terminal_clear_screen();
            terminal_row = 0;
        }
    }
        
}

void terminal_clear_screen(void)
{
    uint16_t* buff_ptr = terminal_buffer;
    const uint16_t SIZE_BUFF = VGA_HEIGHT * VGA_WIDTH;
    const uint16_t entry_pattern = VGA_ENTRY_MACRO(' ', terminal_color); 
    for (size_t pos = 0; pos < VGA_HEIGHT * VGA_WIDTH; ++pos)
    {
        *(buff_ptr++) = entry_pattern;
    }
}

void terminal_write(const char* data, size_t size) 
{
  for (size_t i = 0; i < size; i++)
    terminal_putchar(data[i]);
}
 
void terminal_writestring(const char* data) 
{
  terminal_write(data, strlen(data));
}
 
void kernel_main(void) 
{
  /* Initialize terminal interface */
  terminal_initialize();
 
  /* Newline support is left as an exercise. */
  terminal_writestring("Hello, kernel World!\n");
}
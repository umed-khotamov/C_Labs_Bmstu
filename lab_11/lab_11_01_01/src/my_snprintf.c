#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "my_snprintf.h"

void reverse(char *str, int len)
{
    char temp;

    for (int i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void parse_int_arg(int value, size_t size, char *str, size_t *index, size_t *char_counter)
{
    size_t temp_counter = *char_counter;
    size_t temp_index = *index;
    char buff[100];
    
    size_t buff_index = 0;

    if (value < 0)
    {
        value *= -1;
        if (temp_index < size - 1 && size != 0 && str != NULL)
        {
            str[temp_index] = '-';
            temp_index++;
        }
        temp_counter++;
    }   
    if (value == 0 && temp_index < size - 1 && size != 0 && str != NULL)
    {
        str[temp_index] = '0';
        temp_index++;
        temp_counter++;
    }
    while (value != 0)
    {
        char rest = value % 10 + '0';

        value /= 10;

        buff[buff_index++] = rest;
    }
    reverse(buff, buff_index);

    for (size_t i = 0; i < buff_index; i++)
    {
        if (temp_index < size - 1 && size != 0 && str != NULL)
        {
            str[temp_index] = buff[i];
            temp_index++;
        }

        temp_counter++;
    }
    *index = temp_index;
    *char_counter = temp_counter;
}

void parse_str_arg(char *string, size_t size, char *str, size_t *index, size_t *char_counter)
{
    size_t temp_counter = *char_counter;
    size_t temp_index = *index;

    size_t i = 0;
    for (; string[i] != '\0'; i++)
    {
        if (temp_index < size - 1 && size != 0 && str != NULL)
        {
            str[temp_index] = string[i];
            temp_index++;
        }
        temp_counter++;
    }
    
    *index = temp_index;
    *char_counter = temp_counter;
}

int my_snprintf(char *str, size_t size, char *format, ...)
{
    size_t char_counter = 0;
    size_t index = 0;
    char *ch = NULL;

    char *string = NULL;
    int value = 0;
    
    va_list arg;
    va_start(arg, format);

    for (ch = format; *ch != '\0'; ch++)
    {
        if (*ch == '%')
        {
            ch++;
            if (*ch == 'h')
                ch++;
            if (*ch == 'd' || *ch == 's' || *ch == 'c')
            {
                switch (*ch)
                {
                    case 'd':
                        value = va_arg(arg, int);
                        parse_int_arg(value, size, str, &index, &char_counter);
                        break;
                    case 's':
                        string = va_arg(arg, char *);
                        parse_str_arg(string, size, str, &index, &char_counter);
                        break;
                    case 'c':
                        value = va_arg(arg, int);
                        if (index < size - 1 && size != 0 && str != NULL)
                        {
                            str[index] = value;
                            index++;
                        }
                        char_counter++;
                        break;
                }
                ch++;
            }
        }
        if (*ch == '\0')
            break;

        if (*ch != '%' && index < size - 1 && size != 0 && str != NULL)
        {
            str[index] = *ch;
            index++;
        }
        char_counter++;
        if (*ch == '%')
        {
            ch--;
            char_counter--;
        }
    }
    if (str != NULL)
        str[index] = '\0';
    va_end(arg);

    return char_counter;
}

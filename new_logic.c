//1) check if leftover_buf has value, if yes, go to 2) else got to 4)
//2) check if a new line is found in leftover_buf, if found, go to 3) else go to 4)
//3) return that new line and store the leftover_buf and return to 1)

//4) If no new line or no leftover, read for more data into read_buf
//   If read returns > 0, recombine into leftover_buf, if read returns 0, go to 5
//5) Read returned 0, EOF reached, check if current leftover_buf contains '\n' 
//   and return that, else check subject

//BONUS
//change leftover_buf into char *leftover_buf[FD]
//where #define FD 1024

#define BUFFER 42
#define FD 1024

int ft_strlen(char *s1)
{
    int count;

    count = 0;
    while (s1[count] != '\0')
        count++;
    return (count);
}

char *ft_substring(char *s1, int start, int len)//to convert int to size_t
{
    char *substring;
    int index;

    index = 0;
    substring = (char *)malloc(len + 1);
    if (!substring)
        return ('\0');//to change to NULL
    while (index < len)
    {
        substring[index] = s1[start + index];
        index++;
    }
    substring[index] = '\0';
    return (substring);
}

char *ft_return_line(char *remainder_buffer)
{
    int index;//to convert to size_t
    char *new_line;
    char *temp_buffer;

    index = 0;
    while (remainder_buffer[index] != '\n')
        index++;
    new_line = ft_substring(remainder_buffer, 0, index);
    temp_buffer = ft_substring(remainder_buffer, index, ft_strlen(remainder_buffer) - index);
    free (remainder_buffer);
    remainder_buffer = ft_substring(temp_buffer, 0 , ft_strlen(temp_buffer));
    free (temp_buffer);
    return (new_line);
}

//ssize_t read(int fd, void buf[.count], size_t count);
char *ft_read()
{

}

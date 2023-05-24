#ifndef STRING_UTILS_H
#define STRING_UTILS_H

int _string_length(char *s);
char *_concat_strings(char *dest, char *src);
unsigned int _check_space(char *s);
char **_string_tokens(char *str);
void _print_string(char *str);
int _write_char(char c);
int custom_atoi(char *s);
char *_copy_string(char *dest, char *src);
int check_for_delim(char c, const char *delim);
char *_tokenize_string(char *src, const char *delim);
void handle_ctrlc(int signum);
ssize_t user_command(char **str);
char *_duplicate_string(char *str);

#endif /* STRING_UTILS_H */


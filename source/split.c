#include "../includes/push_swap.h"

static int	count_words(char *s, char c) {
	int	count = 0;
	bool inside_word = false;

	while (*s) {
		// Ignora os delimitadores no início
		while (*s == c)
			++s;
		if (*s) {
			++count;
			inside_word = true;
		}
		// Conta as palavras
		while (*s && *s != c) {
			// Ignora as aspas
			if (*s == '"') {
				inside_word = !inside_word;
				++s;
				continue;
			}
			++s;
		}
		// Ignora os delimitadores no final
		while (*s == c)
			++s;
	}
	return count;
}

static char	*get_next_word(char *s, char c) {
	static int	cursor = 0;
	char		*next_word;
	int			len = 0;
	int			i = 0;

	// Ignora os delimitadores no início
	while (s[cursor] == c)
		++cursor;
	// Calcula o comprimento da palavra
	while ((s[cursor + len] != c || s[cursor + len - 1] == '"') && s[cursor + len])
		++len;
	// Aloca memória para a palavra
	next_word = malloc((size_t)(len + 1));
	if (!next_word)
		return (NULL);
	// Copia a palavra para a nova string
	while ((s[cursor] != c || s[cursor - 1] == '"') && s[cursor]) {
		if (s[cursor] == '"') {
			++cursor;
			continue;
		}
		next_word[i++] = s[cursor++];
	}
	next_word[i] = '\0';
	// Atualiza o cursor
	while (s[cursor] == c)
		++cursor;
	return next_word;
}

char **split(char *s, char c) {
	int		words_count;
	char	**result_array;
	int		i = 0;

	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 1));
	if (!result_array)
		return (NULL);
	while (words_count-- > 0) {
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
	return (result_array);
}
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "libft.h"

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hayint;
	size_t	needint;

	hayint = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[hayint] != 0 && hayint < len)
	{
		needint = 0;
		while (haystack[hayint + needint] == needle[needint]
			&& needle[needint] != 0 && needint + hayint < len)
			needint++;
		if (needint == strlen(needle))
			return ((char *)&haystack[hayint]);
		hayint++;
	}
	return (NULL);
}
char	*substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		x;

	i = start;
	x = 0;
	if (!s)
		return (NULL);
	if (len > strlen(s))
		len = strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str || !s)
		return (NULL);
	while (i <= strlen(s) && len > x)
	{
		str[x] = s[i];
		x++;
		i++;
	}
	str[x] = '\0';
	return (str);
}
char	*strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(strlen(s1) + strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
        str[j++] = s1[i++];
    i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
int	checker(char c, char const *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s2[i++] == c)
			return (1);
	}
	return (0);
}
char	*strtrim(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	j = strlen(s1);
	while (s1[i] && checker(s1[i], s2))
		i++;
	while (j > i && checker(s1[j - 1], s2))
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	while (i < j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
int	len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
char	*inttostr(int n, int *f)
{
	int		leng;
	char	*str;

	leng = len(n);
	str = (char *)malloc((sizeof(char) * leng) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*f = -1;
		str[0] = '-';
	}
	str[leng] = 0;
	return (str);
}
char	*f_itoa(int n)
{
	char	*str;
	int		i;
	int		f;

	f = 1;
	i = len(n);
	str = inttostr(n, &f);
	if (!str)
		return (NULL);
	if (n == 0)
	{
		*str = '0';
		return (str);
	}
	while (n)
	{
		str[--i] = '0' + f * (n % 10);
		n /= 10;
	}
	return (str);
}
char	*strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	len = strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
void	striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f (i, &s[i]);
		i++;
	}
}
t_list	*lstnew(void *content)
{
	t_list	*src;

	src = (t_list *) malloc(sizeof(t_list));
	if (!src)
		return (NULL);
	src -> content = content;
	src -> next = NULL;
	return (src);
}
void	lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}
t_list	*lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*final;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	final = *lst;
	while (final-> next)
	{
		final = final -> next;
	}
	final -> next = new;
}
void	lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	lst->content = NULL;
	lst->next = NULL;
	free(lst);
	lst = NULL;
}


char    f(unsigned int f_n, char f_a)
{
    f_n = 0;
    if (f_n == 0)
        f_a = 'a';
    return (f_a);
}
void    f1(unsigned int f_n, char *f_a)
{
    f_n = 0;
    if (f_n == 0)
        *f_a = 'a';
}
void    f3(void *f_a)
{
    char    *content;
    content = (char *)f_a;
    *content = 'a';
}
int compare_lists(t_list    *head1, t_list *head2) {
    t_list *t1;
    t_list *t2;
    t1=head1;t2 = head2;
    if(t1==NULL && t2==NULL)
        return 1;
    if(t1 != NULL && t2 == NULL)
        return 0;
    if(t1 == NULL && t2 != NULL)
        return 0;
    else
    {
        while(t1->next != NULL && t2->next != NULL)
        {
            if(t1->content == t2->content)
            {
                t1 = t1->next;
                t2 = t2->next;
            }
            else return 0;
        }
        if(t1->next == NULL && t2->next == NULL)
            return 1;
        else return 0;
    }

}
void print_lst(char *str) {
    printf("%s", str);
}

void    printokko(int a)
{
    if (a == 1){
        printf("\033[1;32m"); 
        printf("OK  "); 
        printf("\033[0m");
    }
    else if (a == 0){
        printf("\033[1;31m"); 
        printf("KO  "); 
        printf("\033[0m");
    }
}
void    test_ft_isalnum(int c)
{
    if((ft_isalnum(c) > 0 && isalnum(c) > 0) || (ft_isalnum(c) == 0 && isalpha(c) == 0))
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %d  -> Oluşan Sonuç: %d    ", isalnum(c), ft_isalnum(c));
    }
}
void    test_ft_isalpha(int c)
{
    if((ft_isalpha(c) > 0 && isalpha(c) > 0) || (ft_isalpha(c) == 0 && isalpha(c) == 0))
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %d  -> Oluşan Sonuç: %d    ", isalpha(c), ft_isalpha(c));
    }
}
void    test_ft_isascii(int c)
{
    if((ft_isascii(c) > 0 && isascii(c) > 0) || (ft_isascii(c) == 0 && isascii(c) == 0))
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %d  -> Oluşan Sonuç: %d    ", isascii(c), ft_isascii(c));
    }
}
void    test_ft_isdigit(int c)
{
    if((ft_isdigit(c) > 0 && isdigit(c) > 0) || (ft_isdigit(c) == 0 && isdigit(c) == 0))
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %d  -> Oluşan Sonuç: %d    ", isdigit(c), ft_isdigit(c));
    }
}
void    test_ft_isprint(int c)
{
    if((ft_isprint(c) > 0 && isprint(c) > 0) || (ft_isprint(c) == 0 && isprint(c) == 0))
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %d  -> Oluşan Sonuç: %d    ", isprint(c), ft_isprint(c));
    }
}
void    test_ft_tolower(int c)
{
    if((ft_tolower(c) > 0 && tolower(c) > 0) || (ft_tolower(c) == 0 && tolower(c) == 0))
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %d  -> Oluşan Sonuç: %d    ", tolower(c), ft_tolower(c));
    }
}
void    test_ft_toupper(int c)
{
    if((ft_toupper(c) > 0 && toupper(c) > 0) || (ft_toupper(c) == 0 && toupper(c) == 0))
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %d  -> Oluşan Sonuç: %d    ", toupper(c), ft_toupper(c));
    }
}
void    test_ft_strlen(const char *c)
{
    if((ft_strlen(c) > 0 && strlen(c) > 0) || (ft_strlen(c) == 0 && strlen(c) == 0))
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %zu  -> Oluşan Sonuç: %zu    ", strlen(c), ft_strlen(c));
    }
}
void    test_ft_strchr(const char *str, int c)
{
    const char *array_test_strchr = strchr(str, c);
    const char *array_test_ft_strchr = ft_strchr(str, c);

    if(array_test_ft_strchr == array_test_strchr)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s    ", array_test_strchr, array_test_ft_strchr);
    }
}
void    test_ft_strrchr(const char *str, int c)
{
    const char *str2 = str;
    const char *array_test_strrchr = strrchr(str, c);
    const char *array_test_ft_strrchr = ft_strrchr(str2, c);

    if(array_test_ft_strrchr == array_test_strrchr)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s    ", array_test_strrchr, array_test_ft_strrchr);
    }
}
void    test_ft_strncmp(const char *str1, const char *str2, size_t c)
{
    if((ft_strncmp(str1, str2, c) > 0 && strncmp(str1, str2, c) > 0) || (ft_strncmp(str1, str2, c) < 0 && strncmp(str1, str2, c)) || (ft_strncmp(str1, str2, c) == 0 && strncmp(str1, str2, c) == 0))
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %d  -> Oluşan Sonuç: %d    ", strncmp(str1, str2, c), ft_strncmp(str1, str2, c));
    }
}
void    test_ft_memset(int c, size_t n)
{
    char s[10];
    char s1[10];
    memset(s, 'B', 10);
    memset(s1, 'B', 10);

    memset(s, c, n);
    ft_memset(s1, c, n);

    if (!memcmp(s, s1, 10))
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s    ", s, s1);
    }
}
void    test_ft_bzero()
{
    char s[10];
    memset(s, 'B', 10);

    ft_bzero(s, 3);

    if (!memcmp(s, "\0\0\0BBBBBBB", 10))
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: NULL -> Oluşan Sonuç: %s    ", s);
    }
}
void    test_ft_memchr(const void *str, int c, size_t n)
{
    const char *array_test_memchr = memchr(str, c, n);
    const char *array_test_ft_memchr = ft_memchr(str, c, n);

    if(array_test_ft_memchr == array_test_memchr)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s    ", array_test_memchr, array_test_ft_memchr);
    }
}
void    test_ft_memcmp(const void *str1, const void *str2, size_t c)
{
    if((ft_memcmp(str1, str2, c) > 0 && memcmp(str1, str2, c) > 0) || (ft_memcmp(str1, str2, c) < 0 && memcmp(str1, str2, c)) || (ft_memcmp(str1, str2, c) == 0 && strncmp(str1, str2, c) == 0))
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %d  -> Oluşan Sonuç: %d    ", memcmp(str1, str2, c), ft_memcmp(str1, str2, c));
    }
}
void    test_ft_memcpy()
{
   char dest[20];
   char src[10];
   char dest1[20];
   strcpy(dest, "     BAHCE");
   strcpy(src, "FENER");
   strcpy(dest1, "     BAHCE");
   memcpy(dest, src, 5);
   ft_memcpy(dest1, src, 5);
    
    if(strcmp(dest, dest1) == 0)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s  ", dest, dest1);
    }
}
void    test_ft_memmove()
{
   char dest[20];
   char src[10];
   char dest1[20];
   strcpy(dest, "MR.EMRE");
   strcpy(src, "MR.KAAN");
   strcpy(dest1, "MR.EMRE");
   memmove(dest, src, 7);
   ft_memmove(dest1, src, 7);
    
    if(strcmp(dest, dest1) == 0)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s  ", dest, dest1);
    }
}
void    test_ft_strlcpy()
{
    size_t c = 5;
    char dest_strlcpy[10] = "aaaa";
    char dest_strlcpy1[10] = "aaaa";
    const char src_strlcpy[10] = "test";
    if(ft_strlcpy(dest_strlcpy1, src_strlcpy , c) == strlcpy(dest_strlcpy, src_strlcpy, c)  && strcmp(dest_strlcpy, dest_strlcpy1) == 0)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %zu ve %s  -> Oluşan Sonuç: %zu ve %s   ", strlcpy(dest_strlcpy, src_strlcpy, c), dest_strlcpy, ft_strlcpy(dest_strlcpy1, src_strlcpy, c), dest_strlcpy1);
    }
}
void    test_ft_strnstr(const char *big_strnstr, const char *big_strnstr1, const char *little_strnstr, size_t c)
{
    char *ptr1 = ft_strnstr(big_strnstr1, little_strnstr, c);
    char *ptr = strnstr(big_strnstr, little_strnstr, c);
    if(strcmp(ptr1, ptr) == 0)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s   ", ptr, ptr1);
    }
}
void    test_ft_atoi(const char *array_atoi)
{
    int rslt_ft_atoi = ft_atoi(array_atoi);
    int rslt_atoi = atoi(array_atoi);
    if(rslt_atoi == rslt_ft_atoi)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %d  -> Oluşan Sonuç: %d   ", rslt_atoi, rslt_ft_atoi);
    }
}
void    test_ft_strlcat()
{
    size_t c = 20;
    char dest_strlcat[20] = "Fener";
    char dest_strlcat1[20] = "Fener";
    const char src_strlcat[20] = "Bahce";
    if(ft_strlcat(dest_strlcat1, src_strlcat , c) == strlcat(dest_strlcat, src_strlcat, c)  && strcmp(dest_strlcat, dest_strlcat1) == 0)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %zu ve %s  -> Oluşan Sonuç: %zu ve %s   ", strlcat(dest_strlcat, src_strlcat, c), dest_strlcat, ft_strlcat(dest_strlcat1, src_strlcat, c), dest_strlcat1);
    }
}
void    test_ft_calloc(size_t num, size_t size)
{
    char *t;
    char *t1;
    t = calloc(num, size);
    t1 = ft_calloc(num, size);
    if(memcmp(t, t1, size * num) == 0)
        printokko(1);
    else
    {
        printokko(0);
        printf("  :   ft_calloc fonksiyonun çalışmıyor");
    }

}
void    test_ft_strdup(const char *s)
{
    char *t_strdup = "aaaa";
    char *t_strdup1 = "bbbb";
    t_strdup = strdup(s);
    t_strdup1 = ft_strdup(s);
    if(strcmp(t_strdup, t_strdup1) == 0)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s   ", t_strdup, t_strdup1);
    }

}
void    test_ft_substr(const char *s_substr, unsigned int start, size_t len)
{
    char *t_substr = "aaaa";
    char *t_substr1 = "bbbb";
    t_substr = substr(s_substr, start, len);
    t_substr1 = ft_substr(s_substr, start, len);
    if(strcmp(t_substr, t_substr1) == 0)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s   ", t_substr, t_substr1);
    }

}
void    test_ft_strjoin(const char *s_strjoin, const char *s_strjoin1)
{
    char *t_strjoin = "aaaa";
    char *t_strjoin1 = "bbbb";
    t_strjoin = strjoin(s_strjoin, s_strjoin1);
    t_strjoin1 = ft_strjoin(s_strjoin, s_strjoin1);
    if(strcmp(t_strjoin, t_strjoin1) == 0)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s   ", t_strjoin, t_strjoin1);
    }

}
void    test_ft_strtrim(const char *s_strtrim, const char *s_strtrim_set)
{
    char *t_strtrim;
    char *t_strtrim1;
    t_strtrim = "aaaa";
    t_strtrim1 = "bbbb";
    t_strtrim = strtrim(s_strtrim, s_strtrim_set);
    t_strtrim1 = ft_strtrim(s_strtrim, s_strtrim_set);
    if(strcmp(t_strtrim, t_strtrim1) == 0)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s   ", t_strtrim, t_strtrim1);
    }
}
void    test_ft_itoa(int num_atoi)
{
    char    *result_itoa1;
    char    *result_itoa;
    result_itoa = "aaaa";
    result_itoa1 = "bbbb";
    result_itoa1 = ft_itoa(num_atoi); 
    result_itoa = f_itoa(num_atoi);
    if(strcmp(result_itoa, result_itoa1) == 0)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s   ", result_itoa, result_itoa1);
    }
}
void    test_ft_strmapi(char const *s_strmapi, char (*f_test_strmapi)(unsigned int, char))
{
    char    *result_strmapi1;
    char    *result_strmapi;
    result_strmapi = "aaaa";
    result_strmapi1 = "bbbb";
    result_strmapi1 = ft_strmapi(s_strmapi, f_test_strmapi); 
    result_strmapi = strmapi(s_strmapi, f_test_strmapi);
    if(strcmp(result_strmapi1 , result_strmapi) == 0)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: %s  -> Oluşan Sonuç: %s   ", result_strmapi, result_strmapi1);
    }
}
void    test_ft_lstnew(void *content_lstnew, void *content_lstnew1)
{
    t_list *result_lstnew1;
    t_list *result_lstnew;
    result_lstnew1 = ft_lstnew(content_lstnew1);
    result_lstnew = lstnew(content_lstnew);
    if(compare_lists(result_lstnew1, result_lstnew) == 1)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: ");
        ft_lstiter(result_lstnew, (void *)print_lst);   
        printf("-> Oluşan Sonuç: ");
        ft_lstiter(result_lstnew1, (void *)print_lst);
    }
}
void    test_ft_lstadd_front()
{
    t_list *result_lstadd_front1;
    t_list *result_lstadd_front;
    result_lstadd_front1 = ft_lstnew("BAHCE");
    result_lstadd_front = lstnew("BAHCE");
    ft_lstadd_front(&result_lstadd_front1, ft_lstnew("FENER"));
    lstadd_front(&result_lstadd_front, ft_lstnew("FENER"));
    if(compare_lists(result_lstadd_front1 , result_lstadd_front) == 1)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: ");
        ft_lstiter(result_lstadd_front, (void *)print_lst);   
        printf("-> Oluşan Sonuç: ");
        ft_lstiter(result_lstadd_front1, (void *)print_lst);
    }
}
void    test_ft_lstsize()
{
    t_list  *lst_size_node;
    int result_lstsize;
    lst_size_node = ft_lstnew("test");
    ft_lstadd_front(&lst_size_node, ft_lstnew("test"));
    result_lstsize = ft_lstsize(lst_size_node);

    if(result_lstsize == 2)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: 2 ");   
        printf("-> Oluşan Sonuç: %d", result_lstsize);
    }
}
void    test_ft_lstlast()
{
    t_list *result_lstlast1;
    t_list *result_lstlast;
    result_lstlast1 = ft_lstnew("BAHCE");
    result_lstlast = lstnew("BAHCE");
    ft_lstadd_front(&result_lstlast1, ft_lstnew("FENER"));
    lstadd_front(&result_lstlast, lstnew("FENER"));
    result_lstlast1 = ft_lstlast(result_lstlast1);
    result_lstlast = lstlast(result_lstlast);
    if(compare_lists(result_lstlast1 , result_lstlast) == 1)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: ");
        ft_lstiter(result_lstlast, (void *)print_lst);   
        printf("-> Oluşan Sonuç: ");
        ft_lstiter(result_lstlast1, (void *)print_lst);
    }
}
void    test_ft_lstadd_back()
{
    t_list *result_lstadd_back1;
    t_list *result_lstadd_back;
    result_lstadd_back1 = ft_lstnew("FENER");
    result_lstadd_back = lstnew("FENER");
    ft_lstadd_back(&result_lstadd_back1, ft_lstnew("BAHCE"));
    lstadd_back(&result_lstadd_back, ft_lstnew("BAHCE"));
    if(compare_lists(result_lstadd_back1 , result_lstadd_back) == 1)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: ");
        ft_lstiter(result_lstadd_back, (void *)print_lst);   
        printf("-> Oluşan Sonuç: ");
        ft_lstiter(result_lstadd_back1, (void *)print_lst);
    }
}
void    test_ft_lstiter()
{
    t_list *node;
    t_list *node1;
    node = ft_lstnew("test");
    node1 = ft_lstnew("aaaa");
    if(compare_lists( node1, node) == 1)
        printokko(1);
    else
    {
        printokko(0);
        printf("===-> Beklenen Sonuç: ");
        ft_lstiter(node1, (void *)print_lst);   
        printf("-> Oluşan Sonuç: ");
        ft_lstiter(node, (void *)print_lst);
    }
}

int main()
{
    printf("\033[0;36m"); 
    printf("        /\\//\\\\/\\MANDATORY PART/\\//\\\\/\\\n\n"); 
    printf("\033[0m");


    printf("ft_islanum : ");
    test_ft_isalnum('a');
    test_ft_isalnum('B');
    test_ft_isalnum(15);
    test_ft_isalnum(-2147483648);
    test_ft_isalnum(+2147483647);
    test_ft_isalnum('-');
    test_ft_isalnum(' ');
    printf("\n");

    printf("ft_isalpha : ");
    test_ft_isalpha('a');
    test_ft_isalpha('A');
    test_ft_isalpha(10);
    test_ft_isalpha('-');
    test_ft_isalpha(' ');
    printf("\n");

    printf("ft_isascii : ");
    test_ft_isascii('a');
    test_ft_isascii('A');
    test_ft_isascii(1907);
    test_ft_isascii(' ');
    printf("\n");

    printf("ft_isdigit : ");
    test_ft_isdigit('a');
    test_ft_isdigit('A');
    test_ft_isdigit(9);
    test_ft_isdigit(' ');
    test_ft_isdigit('-');
    printf("\n");

    printf("ft_isprint : ");
    test_ft_isprint('a');
    test_ft_isprint('A');
    test_ft_isprint(10);
    test_ft_isprint('-');
    test_ft_isprint('0');
    printf("\n");

    printf("ft_tolower : ");
    test_ft_tolower('a');
    test_ft_tolower('B');
    test_ft_tolower(1);
    test_ft_tolower('-');
    test_ft_tolower(' ');
    printf("\n");

    printf("ft_toupper : ");
    test_ft_toupper('a');
    test_ft_toupper('B');
    test_ft_toupper(1);
    test_ft_toupper('-');
    test_ft_toupper(' ');
    printf("\n");

    printf("ft_strlen  : ");
    test_ft_strlen("DENEME");
    test_ft_strlen("");
    test_ft_strlen("123");
    test_ft_strlen("-+'%+&+%");
    printf("\n");

    printf("ft_strchr  : ");
    test_ft_strchr("https://www.42istanbul.com.tr/tr/", '.');
    test_ft_strchr("", '.');
    test_ft_strchr("testTESTtest", '.');
    test_ft_strchr("\0", '.');
    test_ft_strchr("TEST tes tEST", ' ');
    test_ft_strchr("TEST tes tEST", 1);
    printf("\n");

    printf("ft_strrchr : ");
    test_ft_strrchr("https://www.42istanbul.com.tr/tr/", '.');
    test_ft_strrchr("", '.');
    test_ft_strrchr("testTESTtest", '.');
    test_ft_strrchr("\0", '.');
    test_ft_strchr("TEST tes tEST", ' ');
    test_ft_strrchr("TEST tes tEST", 1);
    printf("\n");

    printf("ft_strncmp : ");
    test_ft_strncmp("hello", "hello", 5);
    test_ft_strncmp("hell", "hello", 5);
    test_ft_strncmp("", "", 5);
    test_ft_strncmp("hello", "hello", 0);
    test_ft_strncmp("", "hello", 0);
    test_ft_strncmp("hello", "HELLO", 5);
    test_ft_strncmp("12", "12", 5);
    printf("\n");

    printf("ft_memset  : ");
    test_ft_memset('a', 3);
    test_ft_memset('a', 0);
    test_ft_memset(' ', 5);
    test_ft_memset(1, 4);
    test_ft_memset('o', 1);
    test_ft_memset('+', 5);
    printf("\n");

    printf("ft_bzero   : ");
    test_ft_bzero();
    printf("\n");

    printf("ft_memchr  : ");
    test_ft_memchr("https://www.42istanbul.com.tr/tr/", '.', 33);
    test_ft_memchr("", '.', 1);
    test_ft_memchr("testTESTtest", '.', 12);
    test_ft_memchr("\0", '.', 1);
    test_ft_memchr("TEST tes tEST", ' ', 13);
    test_ft_memchr("TEST tes tEST", 1, 13);
    test_ft_memchr("test\0\0.\0", '.', 4);
    printf("\n");

    printf("ft_memcmp  : ");
    test_ft_memcmp("hello", "hello", 5);
    test_ft_memcmp("hell", "hello", 5);
    test_ft_memcmp("", "", 5);
    test_ft_memcmp("hello\0\0\0", "hello", 0);
    test_ft_memcmp("", "hello", 0);
    test_ft_memcmp("hello", "HELLO", 5);
    test_ft_memcmp("12", "12", 5);
    printf("\n");

    printf("ft_memcpy  : ");
    test_ft_memcpy();
    printf("\n");

    printf("ft_memmove : ");
    test_ft_memmove();
    printf("\n");

    printf("ft_strlcpy : ");
    test_ft_strlcpy();
    printf("\n");

    printf("ft_strnstr : ");
    test_ft_strnstr("HELLO WORLD", "HELLO WORLD", "WORLD", 11);
    test_ft_strnstr("42Istanbul", "42Istanbul", "I", 10);
    test_ft_strnstr("42Istanbul", "42Istanbul", "", 10);
    test_ft_strnstr("42Istanbul", "42Istanbul", "", 0);
    printf("\n");

    printf("ft_strlcat : ");
    test_ft_strlcat();
    printf("\n");

    printf("ft_atoi    : ");
    test_ft_atoi("123");
    test_ft_atoi("-054");
    test_ft_atoi("\t\v\f\r\n \f-06050");
    test_ft_atoi("\t\v\f\r\n \f- \f\t\n\r    06050");
    test_ft_atoi("\e06050");
    test_ft_atoi("-123sksk kskskd kdkdkdk kdskdk");
    test_ft_atoi("2147483647");
    test_ft_atoi("-2147483648");
    test_ft_atoi("9223372036854775807");
    test_ft_atoi("-9223372036854775808");
    test_ft_atoi("+11");
    printf("\n");

    printf("ft_calloc  : ");
    test_ft_calloc(4, 20);
    test_ft_calloc(1, sizeof(int));
    test_ft_calloc(0, 0);
    printf("\n");

    printf("ft_strdup  : ");
    test_ft_strdup("deneme");
    test_ft_strdup("HAHAHA \0 tu me vois pas !");
    test_ft_strdup("");
    test_ft_strdup("NULL");
    printf("\n");

    printf("\033[0;36m"); 
    printf("\n        /\\//\\\\/\\SECOND PART/\\//\\\\/\\\n\n"); 
    printf("\033[0m");

    printf("ft_substr  : ");
    test_ft_substr("substr function Implementation", 7, 12);
    test_ft_substr("i just want this part #############", 0, 22);
    test_ft_substr("i just want this part #############", 5, 20);
    test_ft_substr("", 5, 0);
    test_ft_substr("all of this !", 0, strlen("all of this !"));
    printf("\n");

    printf("ft_strjoin : ");
    test_ft_strjoin("FENER", "BAHCE");
    printf("\n");

    printf("ft_strtrim : ");
    test_ft_strtrim("hellomerhabahello", "hello");
    test_ft_strtrim("   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ", "Hello \t  Please\n Trim me !");
    test_ft_strtrim("", "");
    printf("\n");

    printf("ft_split   : ");
    printf("\n");

    printf("ft_itoa    : ");
    test_ft_itoa(1907);
    test_ft_itoa(-1907);
    test_ft_itoa(2147483647);
    test_ft_itoa(-2147483648);
    printf("\n");

    printf("ft_strmapi : ");
    test_ft_strmapi("test", f);
    printf("\n");

    printf("ft_striteri:");
    printf("\033[0;36m"); 
    printf(" TEK BAŞINA TEST EDİLMELİ"); 
    printf("\033[0m");
    printf("\n");

    printf("ft_putchar_fd : ");
    printf("\033[0;36m"); 
    printf(" TEK BAŞINA TEST EDİLMELİ"); 
    printf("\033[0m");
    printf("\n");

    printf("ft_putstr_fd  : ");
    printf("\033[0;36m"); 
    printf(" TEK BAŞINA TEST EDİLMELİ"); 
    printf("\033[0m");
    printf("\n");

    printf("ft_putendl_fd : ");
    printf("\033[0;36m"); 
    printf(" TEK BAŞINA TEST EDİLMELİ"); 
    printf("\033[0m");
    printf("\n");

    printf("ft_putnbr_fd  : ");
    printf("\033[0;36m"); 
    printf(" TEK BAŞINA TEST EDİLMELİ"); 
    printf("\033[0m");
    printf("\n");

    printf("\033[0;36m"); 
    printf("\n        /\\//\\\\/\\BONUS PART/\\//\\\\/\\\n\n"); 
    printf("\033[0m");

    printf("ft_lstnew        : ");
    test_ft_lstnew("test", "test");
    test_ft_lstnew("", "");
    printf("\n");

    printf("ft_lstadd_front  : ");
    test_ft_lstadd_front();
    printf("\n");

    printf("ft_lstsize       : ");
    test_ft_lstsize();
    printf("\n");

    printf("ft_lstlast       : ");
    test_ft_lstlast();
    printf("\n");

    printf("ft_lstadd_back   : ");
    test_ft_lstadd_back();
    printf("\n");

    printf("ft_lstdelone     : ");
    printf("\n");

    printf("ft_lstclear      : ");
    printf("\n");

    printf("ft_lstiter       : ");
    test_ft_lstiter();
    printf("\n");

    printf("ft_lstmap        : ");
    printf("\n");

}

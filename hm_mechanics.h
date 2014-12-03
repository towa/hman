#include <stdio.h>
#include <string.h>

struct hm_word
{
	char word[1024];
	char word_alt[1024];
	char underscore[1024];
	char wrongchars[1024];
	int life;
};

void initunderscore(struct hm_word *w)
{	
	int len = strlen((*w).word);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		(*w).underscore[i] = '_';
	}
}

void trychar(struct hm_word *w,char c[])
{
	int haschar = 0;
	int len = strlen((*w).word);
	int pos = strcspn((*w).word,c);
	while (pos != len)
	{
		(*w).word[pos] = '_';
		(*w).underscore[pos] = c[0];
		pos = strcspn((*w).word,c);
		haschar++;
	}
	if (haschar == 0)
	{
		(*w).life--;
		strcat((*w).wrongchars,c);
	}
}

int gamestatus(struct hm_word *w)
{
	if (strcmp((*w).word_alt,(*w).underscore) == 0)
	{
		return 1;
	} else if ((*w).life < 1)
	{
		return -1;
	} else {
		return 0;
	}
}

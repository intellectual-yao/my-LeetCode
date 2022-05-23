/*int romanToInt(char * s)      //指针版本
{
	int count = 0;
	while (*s)
    {
		if (*s == 'V')         count += 5;
		else if (*s == 'L')    count += 50;
		else if (*s == 'D')    count += 500;
		else if (*s == 'M')    count += 1000;
		else if (*s == 'I')			//处理题目给定条件
			count = (*(s + 1) == 'V' || *(s + 1) == 'X') ? count - 1 : count + 1;
		else if (*s == 'X')
			count = (*(s + 1) == 'L' || *(s + 1) == 'C') ? count - 10 : count + 10;
		else
			count = (*(s + 1) == 'D' || *(s + 1) == 'M') ? count - 100 : count + 100;
		s++;
	}
	return count;
}*/

int romanToInt(char * s)        //数组版本
{
	int count = 0, i = 0;
	while (s[i])
    {
		if (s[i] == 'V')         count += 5;
		else if (s[i] == 'L')    count += 50;
		else if (s[i] == 'D')    count += 500;
		else if (s[i] == 'M')    count += 1000;
		else if (s[i] == 'I')			//处理题目给定条件 
			count = (s[i + 1] == 'V' || s[i + 1] == 'X') ? count - 1 : count + 1;
		else if (s[i] == 'X')
			count = (s[i + 1] == 'L' || s[i + 1] == 'C') ? count - 10 : count + 10;
		else
			count = (s[i + 1] == 'D' || s[i + 1] == 'M') ? count - 100 : count + 100;
		i++;
	}
	return count;
}

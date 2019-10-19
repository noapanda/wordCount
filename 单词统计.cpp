int word_count(char *str)  
{   
        char *s=str;
        int count = 0;
        
        while(*s)//将分割符全部转换为空格 
        {
        	if (*s<'0' || (*s>'9' && *s<'a') || *s>'z')
        	{
        		*s=' ';
        	}
        	s ++;
        }
        char seg[] = " "; /*分隔符这里为逗号comma，分隔符可以为你指定的，如分号，空格等*/
		char charlist[50][50]={""};/*指定分隔后子字符串存储的位置，这里定义二维字符串数组*/
        int i = 0;
        char *substr= strtok(str, seg);/*利用现成的分割函数,substr为分割出来的子字符串*/
  
        while (substr != NULL) {  
				strcpy(charlist[i],substr);/*把新分割出来的子字符串substr拷贝到要存储的charlsit中*/
				i++;
                 
                substr = strtok(NULL,seg);/*在第一次调用时，strtok()必需给予参数str字符串，
				往后的调用则将参数str设置成NULL。每次调用成功则返回被分割出片段的指针。*/	
        } 
        int j=0;
				
		for(j = 0; j < i; j++)
		{
			char *p = charlist[j];//子字符串的首地址 
			int cou = 0;
			int k=0;
			while(*p)
			{
				if(*p>='a' && *p<='z')//判断是否为英文字母 
				    cou++;	
				p ++;
				k ++;
				if(k == 4 && cou < 4)//查找到第四个字符，仍不满足至少以4个英文字母开头 
				    break;
				if(cou == 4)//满足至少以4个英文字母开头 
				{
					count ++;
					break;
				}
			}
		}
	return count;
}

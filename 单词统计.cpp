int word_count(char *str)  
{   
        char *s=str;
        int count = 0;
        
        while(*s)//���ָ��ȫ��ת��Ϊ�ո� 
        {
        	if (*s<'0' || (*s>'9' && *s<'a') || *s>'z')
        	{
        		*s=' ';
        	}
        	s ++;
        }
        char seg[] = " "; /*�ָ�������Ϊ����comma���ָ�������Ϊ��ָ���ģ���ֺţ��ո��*/
		char charlist[50][50]={""};/*ָ���ָ������ַ����洢��λ�ã����ﶨ���ά�ַ�������*/
        int i = 0;
        char *substr= strtok(str, seg);/*�����ֳɵķָ��,substrΪ�ָ���������ַ���*/
  
        while (substr != NULL) {  
				strcpy(charlist[i],substr);/*���·ָ���������ַ���substr������Ҫ�洢��charlsit��*/
				i++;
                 
                substr = strtok(NULL,seg);/*�ڵ�һ�ε���ʱ��strtok()����������str�ַ�����
				����ĵ����򽫲���str���ó�NULL��ÿ�ε��óɹ��򷵻ر��ָ��Ƭ�ε�ָ�롣*/	
        } 
        int j=0;
				
		for(j = 0; j < i; j++)
		{
			char *p = charlist[j];//���ַ������׵�ַ 
			int cou = 0;
			int k=0;
			while(*p)
			{
				if(*p>='a' && *p<='z')//�ж��Ƿ�ΪӢ����ĸ 
				    cou++;	
				p ++;
				k ++;
				if(k == 4 && cou < 4)//���ҵ����ĸ��ַ����Բ�����������4��Ӣ����ĸ��ͷ 
				    break;
				if(cou == 4)//����������4��Ӣ����ĸ��ͷ 
				{
					count ++;
					break;
				}
			}
		}
	return count;
}

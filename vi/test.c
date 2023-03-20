#include <stdio.h>
#include <string.h>
int main(){
	char str[100];

	while(1){
		printf("SSAFY_ECHOBOT >> ");
		scanf("%s",str);
		char temp[100];
		strcpy(temp,str);
		
		int size=strlen(str);

		for(int i=0;i<size;i++){
			if(str[i]>='a'&&str[i]<='z')
				str[i]-='a'-'A';
		}

		if(strcmp(str,"EXIT")==0||strcmp(str,"BYE")==0){
			break;
		}
		printf("%s\n",temp);
	}
	

	return 0;
}

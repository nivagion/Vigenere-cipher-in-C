#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdint.h>
#include <ctype.h>
#include <string.h>

int main() {
	char whatToDo;
	char plain[1000];
	char tempkey[1000];
	printf("encrypt(e), decrypt(d), plaintext/ecrypted text: , key:\n");
	scanf("%c\n",&whatToDo);
	scanf("%[^\n]\n",plain);
	scanf("%[^\n]",tempkey);

	for(int i=0;i<strlen(plain);i++){
	    plain[i]=tolower(plain[i]);
	}
	for(int i=0;i<strlen(tempkey);i++){
	    tempkey[i]=tolower(tempkey[i]);
	}

	char keystream[1000];
//printf("size of %d\n",strlen(tempkey));
	for(int i=0, b=0;i<1000;i++){//set keystream
	    keystream[i]=tempkey[b];
	    b++;
	    if(b>=strlen(tempkey))b=0;
	}
	char table[26][26];
	for(int i=0;i<26;i++){
	    for(int j=0;j<26;j++){
	        table[i][j]=(char)((j+i)%26 + 97);
	    }
	}

	//we have table, plaintext and keystream
	//only thing remaining is cipher
	char cipher[1000];
	if(whatToDo=='e'){
		for(int i=0;i<strlen(plain);i++){
			if(plain[i]!=' '){
				cipher[i]=table [ (int)plain[i]-97 ] [ (int)keystream[i]-97 ];
			}
			else{
				cipher[i]=' ';
			}
		}
	}
	else if(whatToDo=='d'){
	    for(int i=0;i<strlen(plain);i++){
	        if(plain[i] == ' ') {
	            cipher[i] = ' ';
	        } else {
	            for(int j=0;j<26;j++){
	                if(table[(int)keystream[i]-97][j] == plain[i]){
	                    cipher[i] = (char)(j + 97);
	                    break;
	                }
	            }
	        }
	    }
	}
	else{printf("error\n");}
	

	for(int i=0;i<strlen(plain);i++){
		printf("%c",cipher[i]);
	}

/*for(int i=0;i<26;i++){
    for(int j=0;j<26;j++){
        printf("%c",table[i][j]);
    }
    printf("\n");
}*/

//printf("%s\n",keystream );

    return 0;
} 

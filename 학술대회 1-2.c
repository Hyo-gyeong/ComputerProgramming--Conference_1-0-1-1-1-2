#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 두개의 문자들 연속을 표현한 단축문자열을 출력하고 그 길이를 반환한다. 
int solution(char *s)
{
    int i, k;
    int count = 1; //한 종류 쌍의 개수
    int kinds = 1;//종류
	int overOne = 0;
	int num = 0;

    for (k = 0; s[k] !='\0'; k++);
    
    if (k % 2 == 0){//짝수일 때
        for (i = 0; i <= k-2; i += 2) {
            if (s[i] == s[i+2] && s[i+1] == s[i+3]) {//일치 - 일치
				count++;
			}
			else if (s[i+2] == '\0'){ // 마지막 두 쌍
				if (count > 1){
					printf("%d%c%c",count, s[i], s[i+1]);
					num += 3;
				}
				else {
					printf("%c%c", s[i], s[i+1]);
					num += 2;
				}
				return num;				
			}
            else { //불일치
				kinds++;
                if (count < 2) {//한 쌍
                    printf("%c%c", s[i], s[i+1]);
					num += 2;
				}
                else {//여러쌍
					printf("%d%c%c", count, s[i], s[i+1]);
					num += 3;
				}
				count = 1;
			}
		}   
	}
	else if (k % 2 == 1) {//홀 수 일때
		for (i = 0; i < k-2 ; i += 2) {
            if (s[i] == s[i+2] && s[i+1] == s[i+3]) {//일치 - 일치
                count++;
			}
			else if (s[i+3] == '\0'){ // 마지막 세개
				if (count > 1){
					printf("%d%c%c%c", count, s[i], s[i+1], s[i+2]);
					num += 4;
				}
				else {
					printf("%c%c%c", s[i], s[i+1], s[i+2]);
					num += 3;
				}
				return num;
            }
            else { //불일치
				kinds++;
                if (count == 1){ //한 쌍
                    printf("%c%c", s[i], s[i+1]);
					num += 2;
				}
                else { //여러쌍
					printf("%d%c%c", count, s[i], s[i+1]);
					num += 3;
				}
				count = 1;
			}
		} 
	}
}

int main(void)
{
	char s[1001];
	scanf("%s", s);
	printf("\n%d\n", solution(s));
}
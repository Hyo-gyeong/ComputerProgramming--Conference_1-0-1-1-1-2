#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// �ΰ��� ���ڵ� ������ ǥ���� ���๮�ڿ��� ����ϰ� �� ���̸� ��ȯ�Ѵ�. 
int solution(char *s)
{
    int i, k;
    int count = 1; //�� ���� ���� ����
    int kinds = 1;//����
	int overOne = 0;
	int num = 0;

    for (k = 0; s[k] !='\0'; k++);
    
    if (k % 2 == 0){//¦���� ��
        for (i = 0; i <= k-2; i += 2) {
            if (s[i] == s[i+2] && s[i+1] == s[i+3]) {//��ġ - ��ġ
				count++;
			}
			else if (s[i+2] == '\0'){ // ������ �� ��
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
            else { //����ġ
				kinds++;
                if (count < 2) {//�� ��
                    printf("%c%c", s[i], s[i+1]);
					num += 2;
				}
                else {//������
					printf("%d%c%c", count, s[i], s[i+1]);
					num += 3;
				}
				count = 1;
			}
		}   
	}
	else if (k % 2 == 1) {//Ȧ �� �϶�
		for (i = 0; i < k-2 ; i += 2) {
            if (s[i] == s[i+2] && s[i+1] == s[i+3]) {//��ġ - ��ġ
                count++;
			}
			else if (s[i+3] == '\0'){ // ������ ����
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
            else { //����ġ
				kinds++;
                if (count == 1){ //�� ��
                    printf("%c%c", s[i], s[i+1]);
					num += 2;
				}
                else { //������
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
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//��������ͳ���ļ��е��ʵĸ���
void CountW(char* file) {
	FILE* fp;
	char buffer[1024];//����һ�����ַ����Ļ����
	char c;
	int bufferlen = 0;
	int LastComma = 0;//������ʾ��һ���Ƿ��ǿո�����Ƕ��ţ��ǵĻ�Ϊ1������Ϊ0
	int WordCount = 0;//ͳ�Ƶ���������ʼֵΪ1
	int i;
	if ((fp = fopen(file, "r")) == NULL) { //�ж��ļ��Ƿ�Ϊ��
		printf("�ļ����ܴ�\n");
		exit(0);
	}
	while (fgets(buffer, 1000, fp) != NULL) {
		bufferlen = strlen(buffer);
		for (i = 0; i < bufferlen; i++) {
			c = buffer[i];
			if (c == ' ' || c == ',') { //�жϿո�Ͷ���
				if (LastComma == 0) {
					WordCount++;
				}
				LastComma = 1;
			} else if (c != '\n' && c != '\r') {
				LastComma = 0;
			}

		}
		if (LastComma == 0)
			WordCount++;
		LastComma = 1;
	}
	fclose(fp);
	printf("������Ϊ��%d\n", WordCount);//��ӡ������
}
//��������ͳ���ļ��е��ַ���
void CountC(char* file) {
	FILE* fp;
	int CharCount = 0;
	fp = fopen(file, "r");
	char a;
	if (NULL == (fp = fopen(file, "r"))) {
		printf("�ļ�Ϊ��");
	}
	while (!feof(fp)) {
		a = fgetc(fp);
		CharCount++;
	}

	fclose(fp);
	printf("�ַ���Ϊ:%d ", CharCount - 1);
}

int main(int argc, char* argv[]) {
	FILE* fp;
	while (1) {
		if ((fp = fopen(argv[2], "r")) == NULL) {
			printf("û�и��ļ�\n\n\n");
			scanf("%s%s%s", argv[0], argv[1], argv[2]);
			continue;
		} else if (!strcmp(argv[1], "-w")) {
			CountW(argv[2]);
		} else if (!strcmp(argv[1], "-c")) {
			CountC(argv[2]);
		}
		printf("\n\n");
		scanf("%s%s%s", argv[0], argv[1], argv[2]);
	}
	return 0;
}


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//函数用于统计文件中单词的个数
void CountW(char* file) {
	FILE* fp;
	char buffer[1024];//设置一个放字符串的缓冲池
	char c;
	int bufferlen = 0;
	int LastComma = 0;//用来表示上一个是否是空格或者是逗号，是的话为1，否则为0
	int WordCount = 0;//统计单词数，初始值为1
	int i;
	if ((fp = fopen(file, "r")) == NULL) { //判断文件是否为空
		printf("文件不能打开\n");
		exit(0);
	}
	while (fgets(buffer, 1000, fp) != NULL) {
		bufferlen = strlen(buffer);
		for (i = 0; i < bufferlen; i++) {
			c = buffer[i];
			if (c == ' ' || c == ',') { //判断空格和逗号
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
	printf("单词数为：%d\n", WordCount);//打印单词数
}
//函数用于统计文件中的字符数
void CountC(char* file) {
	FILE* fp;
	int CharCount = 0;
	fp = fopen(file, "r");
	char a;
	if (NULL == (fp = fopen(file, "r"))) {
		printf("文件为空");
	}
	while (!feof(fp)) {
		a = fgetc(fp);
		CharCount++;
	}

	fclose(fp);
	printf("字符数为:%d ", CharCount - 1);
}

int main(int argc, char* argv[]) {
	FILE* fp;
	while (1) {
		if ((fp = fopen(argv[2], "r")) == NULL) {
			printf("没有该文件\n\n\n");
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


#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct {
	char m_code[3];
	unsigned char m_width, m_height;
	unsigned char m_type;			// 0: unsigned char image, 1: float image
	unsigned char m_reserved;

	unsigned char m_data[100][100];
} Image;

int ReadHGU1(FILE *fp, Image *pImage);
int WriteHGU1(FILE *fp, Image *pImage);
void DisplayImage(Image *pImage);
void LogImage(Image *pImage, char *fileName);

int main(int argc, char *argv[])
{
	if(argc < 2){
		printf("Usage: %s <.hgu1 filename>\n", argv[0]);
		return -1;
	}
	
	char header[9] = { 0 };
	FILE *fp = fopen(argv[1], "rb");
	if(fp == NULL){
		printf("Failed to open %s.\n", argv[1]);
		return -1;
	}
	fread(header, 1, 8, fp);		// read file header "HGU1"
	printf("header = %s\n", header);
	
	FILE *out = fopen("Z:\\backup.hgu1", "wb");
	fwrite(header, 1, 8, out);

    Image image;
    int n = 0;
	while(ReadHGU1(fp, &image)){
		printf("image %d:\n", n++);
		
		WriteHGU1(out, &image);
		fflush(out);

		DisplayImage(&image);
		LogImage(&image, "Z:\\image.csv");

		printf("Press Enter to Continue...");
		getchar();
	}

	fclose(fp);
	
	return 0;
}

void DisplayImage(Image *pImage)
{
	printf("code = [%s], width = %d, height = %d, type = %d, reserved = %d\n", pImage->m_code, pImage->m_width, pImage->m_height, pImage->m_type, pImage->m_reserved);

	for(int y = 0; y < pImage->m_height; y++){
		for(int x = 0; x < pImage->m_width; x++)
			printf("%3d ", pImage->m_data[y][x]);
		printf("\n");
	}
	
	printf("\n");
}

void LogImage(Image *pImage, char *fileName)
{
	FILE *fp = fopen(fileName, "w");
	if (fp == NULL){
		printf("Failed to open %s to write.\n", fileName);
		return;
	}

	fprintf(fp, "code = [%s], width = %d, height = %d, type = %d, reserved = %d\n", pImage->m_code, pImage->m_width, pImage->m_height, pImage->m_type, pImage->m_reserved);

	for (int y = 0; y < pImage->m_height; y++){
		for (int x = 0; x < pImage->m_width; x++)
			fprintf(fp, "%3d,", pImage->m_data[y][x]);
		fprintf(fp, "\n");
	}

	fprintf(fp, "\n");

	fclose(fp);
}

int ReadHGU1(FILE *fp, Image *pImage)
{
	int ret = fread(pImage->m_code, 1, 2, fp);
	if(ret < 2)
		return FALSE;
		
	pImage->m_code[2] = 0;
	fread(&pImage->m_width, 1, 1, fp);
	fread(&pImage->m_height, 1, 1, fp);
	fread(&pImage->m_type, 1, 1, fp);
	fread(&pImage->m_reserved, 1, 1, fp);

	for(int y = 0; y < pImage->m_height; y++)
		fread(pImage->m_data[y], 1, pImage->m_width, fp);

	return TRUE;
}

int WriteHGU1(FILE *fp, Image *pImage)
{
	fwrite(pImage->m_code, 1, 2, fp);
	fwrite(&pImage->m_width, 1, 1, fp);
	fwrite(&pImage->m_height, 1, 1, fp);
	fwrite(&pImage->m_type, 1, 1, fp);
	fwrite(&pImage->m_reserved, 1, 1, fp);

	for(int y = 0; y < pImage->m_height; y++)
		fwrite(pImage->m_data[y], 1, pImage->m_width, fp);

	return TRUE;
}


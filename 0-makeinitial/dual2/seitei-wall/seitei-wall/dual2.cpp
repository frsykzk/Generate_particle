#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <omp.h> 
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <chrono>

#define IN_FILE_1 "initialwall.txt"
#define IN_FILE_2 "seitei.txt"
#define OUT_FILE "initial.txt"

int main() {


	FILE* in1;
	FILE* in2;
	FILE* out;

	int nPwall = 0;
	int nPsolid = 0;
	int nP = 0;

	if (fopen_s(&out, OUT_FILE, "a") != 0) {
		printf("initial.txt���J���܂���\n");
	}
	else {
		if (fopen_s(&in2, IN_FILE_2, "r") != 0) {
			printf("seitei.txt���J���܂���\n");
		}
		else {
			if (fopen_s(&in1, IN_FILE_1, "r") != 0) {
				printf("initialwall.txt���J���܂���\n");
			}
			else {
//////////////////////////////////////////////////////////////////////////////���q���ǂݍ���
				fscanf_s(in1, "%d", &nPwall);
				fscanf_s(in2, "%d", &nPsolid);
				nP = nPwall + nPsolid;
				fprintf_s(out, "%d\n", nP);
				printf("�Ǘ��q�F%d��\n�ő̗��q�F%d��\n�����q%�F%d��\n", nPwall, nPsolid, nP);
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////��
				for (int i = 0; i < nPwall; i++) {
					int a[1];
					float b[11];
					int c[1];
					float g[1];
					fscanf_s(in1, " %d %d %f %f %f %f %f %f %f", &a[0], &c[0], &b[0], &b[1], &b[2], &b[8], &b[9], &b[10], &g[0]);
					fprintf_s(out, " %d %d %f %f %f %f %f %f %f\n", a[0], c[0], b[0], b[1], b[2], b[8], b[9], b[10], g[0]);
				}
//////////////////////////////////////////////////////////////////////////////
			}
			fclose(in1);
//////////////////////////////////////////////////////////////////////////////�ő�
			for (int j = 0; j < nPsolid; j++) {
				int a[1];
				float b[11];
				int c[1];
				float g[1];
				fscanf_s(in2, " %d %d %f %f %f %f %f %f %f", &a[0], &c[0], &b[0], &b[1], &b[2], &b[8], &b[9], &b[10], &g[0]);
				fprintf_s(out, " %d %d %f %f %f %f %f %f %f\n", a[0], c[0], b[0], b[1], b[2], b[8], b[9], b[10], g[0]);
			}
		}
		fclose(in2);
//////////////////////////////////////////////////////////////////////////////
	}
	fclose(out);

	printf("end\n");

	return 0;
}
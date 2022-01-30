#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool id_is_valid(char * NumberID);

bool id_is_valid(char * NumberID){
	int Isummary = 0;
	int IsIdCalc = 0;

	for(int loop=0; loop < strlen(NumberID); loop++){
		Isummary++;
		int INumOneTime = NumberID[loop] - '0';
		int dataLoop = INumOneTime * Isummary;
		int loop_array[2] = {dataLoop, 0};
		if (dataLoop > 9){
			char data[10];
			sprintf(data, "%d", loop_array[0]);
			for(int SecondLoop = 0; SecondLoop < strlen(data); SecondLoop++){
				int CalcNum = data[SecondLoop] - '0';
				loop_array[1] += CalcNum;
			}
		IsIdCalc += loop_array[1];
		}else
			IsIdCalc += INumOneTime * Isummary;
		if (Isummary == 2)
			Isummary = 0;
	}

	if(IsIdCalc % 10 == 0)
		return true;
	else
		return false;
}

int main(int argc, char * argv []){
   	char SNumberID[9];
   	strncpy(SNumberID, argv[1], sizeof(SNumberID));
   	if(id_is_valid(SNumberID) == true 
   		&& strlen(SNumberID) == 9)
   		printf("Number ID %s is valid !", SNumberID);
   	else
   		printf("Number ID %s is invalid !", SNumberID);
	return 0;
}

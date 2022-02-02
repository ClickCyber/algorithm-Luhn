#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define AlgoLuhn 10
#define MaxSize 9
const bool IdIsValid(char * NumberID);
bool IdIsValid(char * NumberID){
	int Isummary = 0;
	int IsIdCalc = 0;
	for(int i=0; i < strlen(NumberID); i++){
		Isummary++;
		char data[10];
		int INumOneTime = NumberID[i] - '0';
		int DuobleLoop = INumOneTime * Isummary;
		if (DuobleLoop > MaxSize){
		sprintf(data, "%d", DuobleLoop);
		for(int SecondLoop = 0; SecondLoop < strlen(data); SecondLoop++){
			IsIdCalc += data[SecondLoop] - '0';
		}
		}else
			IsIdCalc += INumOneTime * Isummary;
		(Isummary == 2) ? Isummary = 0 : Isummary;
	}
	return IsIdCalc % AlgoLuhn == 0;
}

int main(int argc, char * argv []){
   	char SNumberID[MaxSize];
   	strncpy(SNumberID, argv[1], sizeof(SNumberID));
   	if(IdIsValid(SNumberID) == true 
   		&& strlen(SNumberID) == MaxSize)
   		printf("Number ID %s is valid !", SNumberID);
   	else
   		printf("Number ID %s is invalid !", SNumberID);
	return 0;
}

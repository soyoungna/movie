typedef struct movInfo;
void* mv_genMvInfo(char* name, float score, int runTime, char* country);
void mv_print(void* obj);
int mv_printAll(void* obj, void* arg);
float mv_getScore(void* obj);
int mv_getRunTime(void* obj);
char* mv_getName(void* obj);
char* mv_getCountry(void* obj);


#include <iostream> 

using namespace std;

//指针函数 -- 函数的返回值是一个指针
int* ResultInt(int In_Num)
{
	static int NumArr[] = { 1,2,3,4,5 };
	return &NumArr[In_Num];
}

float* CampareResult(float* In_Num1, float* In_Num2)
{
	return *In_Num1 > *In_Num2 ? In_Num1 : In_Num2;
}

//函数指针 -- 指向函数的指针变量
int (*P)(int, int);

int AddP(int In_Num1, int In_Num2)
{
	return In_Num1 + In_Num2;
}

//函数指针数组 -- 存储函数指针的数组
int (*Func[3])(int);

int AddP1(int In_Num)
{
	printf("AddP1调用了\n");
	return In_Num;
}
int AddP2(int In_Num)
{
	printf("AddP2调用了\n");
	return In_Num;
}
int AddP3(int In_Num)
{
	printf("AddP3调用了\n");
	return In_Num;
}

//指向函数指针数组的指针
int(*(*Ptr)[2])(int);

int main()
{
	//指针函数 -- 函数的返回值是一个指针
	int Temp_Num1 = 3;
	int* TempP = ResultInt(Temp_Num1);
	printf("指针函数返回的值：Num = %d\n", *TempP);

	//函数指针
	P = AddP;
	//P = &AddP;
	P(100,200);

	//函数指针数组
	Func[0] = AddP1;
	Func[1] = AddP2;
	Func[2] = AddP3;

	Func[0](0);
	Func[1](1);
	Func[2](2);


	//指向函数指针数组的指针  -- 对比二维数组（指向数组的指针）
	//Ptr[0][0] = Func[0];
	//Ptr[0][1] = Func[1];
	//Ptr[1][0] = Func[2];

	//printf("Ptr[0][0] = %p", Ptr[0][0]);
	//printf("Ptr[0][0] = %p", Ptr[0][1]);
	//printf("Ptr[0][0] = %p", Ptr[1][0]);

	int ArrOne1[2] = { 1,2 };
	int ArrOne2[2] = { 1,2 };
	int ArrOne3[2] = { 1,2 };
	int* ArrP[] = { ArrOne1,ArrOne2, ArrOne3};

	printf("ArrP[0] = %d\n", ArrP[0][0]);
	printf("ArrP[1] = %d\n", ArrP[1][1]);
	printf("ArrP[2] = %d\n", ArrP[2][0]);

	return 0;
}
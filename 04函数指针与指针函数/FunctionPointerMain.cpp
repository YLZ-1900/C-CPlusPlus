
#include <iostream> 

using namespace std;

//ָ�뺯�� -- �����ķ���ֵ��һ��ָ��
int* ResultInt(int In_Num)
{
	static int NumArr[] = { 1,2,3,4,5 };
	return &NumArr[In_Num];
}

float* CampareResult(float* In_Num1, float* In_Num2)
{
	return *In_Num1 > *In_Num2 ? In_Num1 : In_Num2;
}

//����ָ�� -- ָ������ָ�����
int (*P)(int, int);

int AddP(int In_Num1, int In_Num2)
{
	return In_Num1 + In_Num2;
}

//����ָ������ -- �洢����ָ�������
int (*Func[3])(int);

int AddP1(int In_Num)
{
	printf("AddP1������\n");
	return In_Num;
}
int AddP2(int In_Num)
{
	printf("AddP2������\n");
	return In_Num;
}
int AddP3(int In_Num)
{
	printf("AddP3������\n");
	return In_Num;
}

//ָ����ָ�������ָ��
int(*(*Ptr)[2])(int);

int main()
{
	//ָ�뺯�� -- �����ķ���ֵ��һ��ָ��
	int Temp_Num1 = 3;
	int* TempP = ResultInt(Temp_Num1);
	printf("ָ�뺯�����ص�ֵ��Num = %d\n", *TempP);

	//����ָ��
	P = AddP;
	//P = &AddP;
	P(100,200);

	//����ָ������
	Func[0] = AddP1;
	Func[1] = AddP2;
	Func[2] = AddP3;

	Func[0](0);
	Func[1](1);
	Func[2](2);


	//ָ����ָ�������ָ��  -- �Աȶ�ά���飨ָ�������ָ�룩
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

#include <iostream>

using namespace std;

//����ģ�� 
template<typename T>
void Print(T In_Name)    // ���õ�ʱ�����ģ�庯��: void Print(���� In_Name){}
{
	cout << "����ģ��: In_Name = " << In_Name << endl;
}

template<typename T1, typename T2>
bool Campare(T1 In_Num1, T2 In_Num2)
{
	return In_Num1 > In_Num2 ? In_Num1 : In_Num2;
}

//��ģ��
template<class T>
class BaseActor
{
protected:
	T BaseName;
public:
	BaseActor(){}
	BaseActor(T In_BaseName)
	{
		BaseName = In_BaseName;
		cout << "����: In_BaseName = " << BaseName << endl;
	}
public:
	virtual void BeginPlay(T In_BaseName);
};

template<class T>
void BaseActor<T>::BeginPlay(T In_BaseName)
{
	cout << "���ࣺBeginPlay--InBaseName = " << In_BaseName << endl;
}

template<class T1, class T2>
class AActor :public BaseActor<T1>
{
private:
	T2 ActorName;
public:
	AActor(){}
	AActor(T1 In_BaseName, T2 In_ActorName) :BaseActor<T1>(In_BaseName)
	{
		ActorName = In_ActorName;
		cout << "�����ࣺ In_ActorName = " << ActorName << endl;
	}

public:
	virtual void BeginPlay(T2 In_BaseName) override;
};

template<class T1, class T2>
void AActor<T1, T2>::BeginPlay(T2 In_BaseName)
{
	cout << "�����ࣺ BeginPlay--In_ActorName = " << In_BaseName << endl;
}

template<typename T1, typename T2>
void Print(BaseActor<T1>& In_Base, T2 In_BaseName)
{
	In_Base.BeginPlay(In_BaseName);
}

int main()
{
	// ����ģ��
	string Str = "YLZ";
	Print(Str);
	int Code = 1001;
	Print<int>(Code);

	char Num1 = 'a', Num2 = 'c';
	cout << Campare<char>(Num1, Num2) << endl;

	// ��ģ��
	BaseActor<string> Base("Base-YLZ");
	Print(Base,"1");

	AActor<string, string>Actor("Actor-YLZ", "1001");
	Print(Actor,"2");

	return 0;
}
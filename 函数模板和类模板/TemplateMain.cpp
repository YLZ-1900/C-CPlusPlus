
#include <iostream>

using namespace std;

//函数模板 
template<typename T>
void Print(T In_Name)    // 调用的时候会变成模板函数: void Print(类型 In_Name){}
{
	cout << "函数模板: In_Name = " << In_Name << endl;
}

template<typename T1, typename T2>
bool Campare(T1 In_Num1, T2 In_Num2)
{
	return In_Num1 > In_Num2 ? In_Num1 : In_Num2;
}

//类模板
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
		cout << "基类: In_BaseName = " << BaseName << endl;
	}
public:
	virtual void BeginPlay(T In_BaseName);
};

template<class T>
void BaseActor<T>::BeginPlay(T In_BaseName)
{
	cout << "基类：BeginPlay--InBaseName = " << In_BaseName << endl;
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
		cout << "派生类： In_ActorName = " << ActorName << endl;
	}

public:
	virtual void BeginPlay(T2 In_BaseName) override;
};

template<class T1, class T2>
void AActor<T1, T2>::BeginPlay(T2 In_BaseName)
{
	cout << "派生类： BeginPlay--In_ActorName = " << In_BaseName << endl;
}

template<typename T1, typename T2>
void Print(BaseActor<T1>& In_Base, T2 In_BaseName)
{
	In_Base.BeginPlay(In_BaseName);
}

int main()
{
	// 函数模板
	string Str = "YLZ";
	Print(Str);
	int Code = 1001;
	Print<int>(Code);

	char Num1 = 'a', Num2 = 'c';
	cout << Campare<char>(Num1, Num2) << endl;

	// 类模板
	BaseActor<string> Base("Base-YLZ");
	Print(Base,"1");

	AActor<string, string>Actor("Actor-YLZ", "1001");
	Print(Actor,"2");

	return 0;
}
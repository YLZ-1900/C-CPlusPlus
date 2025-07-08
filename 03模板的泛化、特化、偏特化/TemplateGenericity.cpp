
#include <iostream>

using namespace std;

#define API_YLZ
#define GENERATED_BODY_YLZ()

// 函数模板、函数模板特化
template<typename T1, typename T2>
void Print(T1 In_Num1, T2 In_Num2)
{
	cout << "函数模板：In_Num1 + In_Num2 = " << In_Num1 + In_Num2 << endl;
}

// 这里是函数重载，不是函数模板偏特化，函数模板不支持偏特化
template<typename T>
void Print(T In_Num1, int In_Num2)
{
	cout << "函数重载：In_Num1 + In_Num2 = " << In_Num1 + In_Num2 << endl;
}

// 函数模板特化是全特化
template<>
void Print(int In_Num1, int In_Num2)
{
	cout << "函数模板特化：In_Num1 + In_Num2 = " << In_Num1 + In_Num2 << endl;
}

// 类模板 -- 全特化、偏特化
template<class T1, class T2>
class API_YLZ Base
{
	GENERATED_BODY_YLZ()
protected:
	T1 Name;
	T2 Code;
public:
	Base()
	{
		Name = 0;
		Code = 0.0f;
	}
	Base(T1 In_Name, T2 In_Code);

	virtual void Tick(float DeltaSeconds);
};

template<class T1, class T2>
Base<T1, T2>::Base(T1 In_Name, T2 In_Code)
{
	Name = In_Name;
	Code = In_Code;
}

template<class T1, class T2>
void Base<T1, T2>::Tick(float DeltaSeconds)
{
	cout << "Base::Tick" << endl;
}

// 全特化
template<>
class API_YLZ Base<int, float>
{
	GENERATED_BODY_YLZ()
protected:
	int GName;
	float GScore;

public:
	Base()
	{
		GName = 0;
		GScore = 0.0f;
	}
	Base(int In_GName, float In_GScore)
	{
		GName = In_GName;
		GScore = In_GScore;

		cout << "全特化Base构造函数调用了" << endl;
	}

	virtual void Tick(float DeltaSeconds)
	{
		cout << "全特化:Base::Tick" << endl;
	}
};

// 偏特化
template <class T>
class API_YLZ Base <T, int>
{
	GENERATED_BODY_YLZ()
protected:
	T TName;
	int GScore;
public:
	Base() {}
	Base(T In_TName, int In_GScore);

	virtual  void Tick(float DeltaSeconds)
	{
		cout << "偏特化：Base::Tick" << endl;
	}
};

template <class T>
Base<T, int>::Base(T In_TName, int In_GScore)
{
	TName = In_TName;
	GScore = In_GScore;
	cout << "Base偏特化构造函数被调用了!" << endl;
}

// 继承全特化
template <class T>
class API_YLZ AActor : public Base<int, float>
{
	GENERATED_BODY_YLZ()
protected:
	T ActorName;
	float ActorScore;
public:
	AActor() {}
	AActor(int In_BaseName, float In_BaseScore, T In_ActorName, float In_ActorScore) :Base<int, float>(In_BaseName, In_BaseScore)
	{
		this->ActorName = In_ActorName;
		this->ActorScore = In_ActorScore;
		cout << "AActor构造函数被调用了!" << endl;
	}

	virtual  void Tick(float DeltaSeconds) override;
};

template <class T>
void AActor<T>::Tick(float DeltaSeconds)
{
	cout << "继承全特化：AActor::Tick" << endl;
}

// 继承偏特化
template <class T>
class API_YLZ AActorOffset : public Base<T, int>
{
	GENERATED_BODY_YLZ()
protected:
	T ActorOffsetName;
	float ActorOffsetScore;
public:
	AActorOffset() {}
	AActorOffset(T In_BaseName, int In_BaseScore, T In_ActorName, float In_ActorScore) :Base<T, int>(In_BaseName, In_BaseScore)
	{
		this->ActorOffsetName = In_ActorName;
		this->ActorOffsetScore = In_ActorScore;
		cout << "AActorOffset构造函数被调用了!" << endl;
	}

	virtual  void Tick(float DeltaSeconds)
	{
		cout << "继承偏特化：AActor::Tick" << endl;
	}
};

template <typename T1, typename T2>
void Print(Base<T1, T2>* In_Base)
{
	In_Base->Tick(1);
}

int main()
{
	Print(100, 200);

	Base<string, double> TempBase1("YLZ", 3.14f);
	Print(&TempBase1);

	Base<int, float> TempBase2;
	Print(&TempBase2);

	AActor<int> Actor(100, 3.14f, 200, 6.18f);
	Print<int, float>(&Actor);

	AActorOffset<double> ActorOffset(100.34f, 314, 200, 6.18f);
	Print(&ActorOffset);

	return 0;
}
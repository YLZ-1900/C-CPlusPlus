
#include <iostream>

using namespace std;

#define API_YLZ
#define GENERATED_BODY_YLZ()

// ����ģ�塢����ģ���ػ�
template<typename T1, typename T2>
void Print(T1 In_Num1, T2 In_Num2)
{
	cout << "����ģ�壺In_Num1 + In_Num2 = " << In_Num1 + In_Num2 << endl;
}

// �����Ǻ������أ����Ǻ���ģ��ƫ�ػ�������ģ�岻֧��ƫ�ػ�
template<typename T>
void Print(T In_Num1, int In_Num2)
{
	cout << "�������أ�In_Num1 + In_Num2 = " << In_Num1 + In_Num2 << endl;
}

// ����ģ���ػ���ȫ�ػ�
template<>
void Print(int In_Num1, int In_Num2)
{
	cout << "����ģ���ػ���In_Num1 + In_Num2 = " << In_Num1 + In_Num2 << endl;
}

// ��ģ�� -- ȫ�ػ���ƫ�ػ�
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

// ȫ�ػ�
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

		cout << "ȫ�ػ�Base���캯��������" << endl;
	}

	virtual void Tick(float DeltaSeconds)
	{
		cout << "ȫ�ػ�:Base::Tick" << endl;
	}
};

// ƫ�ػ�
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
		cout << "ƫ�ػ���Base::Tick" << endl;
	}
};

template <class T>
Base<T, int>::Base(T In_TName, int In_GScore)
{
	TName = In_TName;
	GScore = In_GScore;
	cout << "Baseƫ�ػ����캯����������!" << endl;
}

// �̳�ȫ�ػ�
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
		cout << "AActor���캯����������!" << endl;
	}

	virtual  void Tick(float DeltaSeconds) override;
};

template <class T>
void AActor<T>::Tick(float DeltaSeconds)
{
	cout << "�̳�ȫ�ػ���AActor::Tick" << endl;
}

// �̳�ƫ�ػ�
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
		cout << "AActorOffset���캯����������!" << endl;
	}

	virtual  void Tick(float DeltaSeconds)
	{
		cout << "�̳�ƫ�ػ���AActor::Tick" << endl;
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
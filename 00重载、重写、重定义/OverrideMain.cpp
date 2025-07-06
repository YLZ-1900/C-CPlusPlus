
#include <iostream>

using namespace std;

#define API_Override
#define GENERATED_BODY_Override

// ��������

void Print(int In_Num)
{
	printf("In_Num = %d\n", In_Num);
}

void Print(float In_Num)
{
	printf("In_Num = %f\n", In_Num);
}

void Print(string In_Num)
{
	printf("In_Num = %s\n", In_Num.c_str());
}

// ������д

class API_Override Object
{
	GENERATED_BODY_Override
public:
	Object(){}

	virtual void ObjectPrint();

	void GeneratedObject()
	{
		printf("ͨ������(Object)��������\n");
	}

};
void Object::ObjectPrint()
{
	printf("���û��ຯ����Object::ObjectPrint()\n");
}

class API_Override AActor :public Object
{
	GENERATED_BODY_Override
public:
	AActor(){}

	// ��д
	virtual void ObjectPrint() override
	{
		printf("���������ຯ����AActor::ObjectPrint()\n");
	}

	// �ض���
	void GeneratedObject()
	{
		printf("ͨ��������(AActor)��������\n");
	}
};

// �����ض���

class API_Override UActorComponent :public Object
{
	GENERATED_BODY_Override
public:
	UActorComponent(){}

	// ��д
	virtual void ObjectPrint() override
	{
		printf("���������ຯ����UActorComponent::ObjectPrint()\n");
	}

	// �ض���
	void GeneratedObject()
	{
		printf("ͨ��������(UActorComponent)��������\n");
	}
};

void Print(Object* In_Object)
{
	// ���벻ͬ���͵��ò�ͬ����ķ���
	In_Object->ObjectPrint();
	// ֻ���û���ķ���
	In_Object->GeneratedObject();
}

int main()
{
	// ��������
	int Num1 = 1001;
	Print(Num1);

	string Num2 = "YLZ";
	Print(Num2);

	// ������д���ض���
	Object Temp_Object;
	AActor Temp_AActor;
	UActorComponent Temp_ActorComponent;
	Print(&Temp_Object);
	Print(&Temp_AActor);
	Print(&Temp_ActorComponent);

	return 0;
}

#include <iostream>

using namespace std;

#define API_Override
#define GENERATED_BODY_Override

// 函数重载

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

// 函数重写

class API_Override Object
{
	GENERATED_BODY_Override
public:
	Object(){}

	virtual void ObjectPrint();

	void GeneratedObject()
	{
		printf("通过基类(Object)生成物体\n");
	}

};
void Object::ObjectPrint()
{
	printf("调用基类函数：Object::ObjectPrint()\n");
}

class API_Override AActor :public Object
{
	GENERATED_BODY_Override
public:
	AActor(){}

	// 重写
	virtual void ObjectPrint() override
	{
		printf("调用派生类函数：AActor::ObjectPrint()\n");
	}

	// 重定义
	void GeneratedObject()
	{
		printf("通过派生类(AActor)生成物体\n");
	}
};

// 函数重定义

class API_Override UActorComponent :public Object
{
	GENERATED_BODY_Override
public:
	UActorComponent(){}

	// 重写
	virtual void ObjectPrint() override
	{
		printf("调用派生类函数：UActorComponent::ObjectPrint()\n");
	}

	// 重定义
	void GeneratedObject()
	{
		printf("通过派生类(UActorComponent)生成物体\n");
	}
};

void Print(Object* In_Object)
{
	// 传入不同类型调用不同的类的方法
	In_Object->ObjectPrint();
	// 只调用基类的方法
	In_Object->GeneratedObject();
}

int main()
{
	// 函数重载
	int Num1 = 1001;
	Print(Num1);

	string Num2 = "YLZ";
	Print(Num2);

	// 函数重写、重定义
	Object Temp_Object;
	AActor Temp_AActor;
	UActorComponent Temp_ActorComponent;
	Print(&Temp_Object);
	Print(&Temp_AActor);
	Print(&Temp_ActorComponent);

	return 0;
}
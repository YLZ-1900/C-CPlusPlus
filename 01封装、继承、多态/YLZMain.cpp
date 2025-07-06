
#include <iostream>
using namespace std;

#define API_YLZMain
#define YLZ_GENERATED_BODY()

//C++基础特性：
//封装
//继承
//多态：函数调用的多种形态
//静态多态：函数重载
//动态的多态：父类 / 基类的指针或引用调用重写虚函数
//1、父类指针或者引用指向父类，调用的就是父类的虚函数
//2、父类指针或者引用指向子类，调用的就是子类的虚函数

//封装 将数据和方法结合在一起，隐藏对象的属性和实现细节，仅对外公开接口来和对象进行交互
class API_YLZMain YLZBase
{
	YLZ_GENERATED_BODY()
private:
	string BaseID;

public:
	YLZBase(){}
	YLZBase(string In_BaseID)
		:BaseID(In_BaseID)
	{}
	~YLZBase() {};
public:
	virtual void YLZBeginPlay()
	{
		cout << "YLZBase::YLZBeginPlay" << endl;
	}
};

//继承 
class API_YLZMain YLZDerived :virtual public YLZBase
{
	YLZ_GENERATED_BODY()
private:
	string DerivedID;

public :
	YLZDerived(){}
	//派生类构造函数
	YLZDerived(string In_BaseID, string In_DerivedID) :YLZBase(In_BaseID)
	{
		DerivedID = In_DerivedID;
	}
	~YLZDerived() {}

public:
	virtual void YLZBeginPlay() override
	{
		cout << "YLZDerived::YLZBeginPlay" << endl;
	}
};

class API_YLZMain YLZDerivedCode :virtual public YLZBase
{
	YLZ_GENERATED_BODY()
private:
	string DerivedCode;

public:
	YLZDerivedCode() {}
	//派生类构造函数
	YLZDerivedCode(string In_BaseID, string In_DerivedCode) :YLZBase(In_BaseID)
	{
		DerivedCode = In_DerivedCode;
	}
	~YLZDerivedCode() {}
public:
	virtual void YLZBeginPlay() override
	{
		cout << "YLZDerivedCode::YLZBeginPlay" << endl;
	}
};

//多继承  虚拟继承可以解决菱形继承的二义性和数据冗余的问题
class API_YLZMain YLZMultiInheritance : public YLZDerived, public YLZDerivedCode
{
	YLZ_GENERATED_BODY()
private:
	string MultiInheritanceID;

public:
	YLZMultiInheritance(){}
	//派生类构造函数
	YLZMultiInheritance(string In_BaseID,string In_DerivedID,string In_DerivedCode,string In_MultiInheritanceID)
		:YLZBase(In_BaseID), YLZDerived("Z", In_DerivedID),YLZDerivedCode("Y", In_DerivedCode), MultiInheritanceID(In_MultiInheritanceID)
	{}
public:
	virtual void YLZBeginPlay() override
	{
		cout << "YLZMultiInheritance::YLZBeginPlay" << endl;
	}
};

//多态
void YLZPrintf(YLZBase& In_Base)
{
	In_Base.YLZBeginPlay();
}

void YLZPrintf(YLZBase* In_Base)
{
	In_Base->YLZBeginPlay();
}

int main()
{
	YLZBase Base("Base");
	YLZDerived Derived("DerivedBase", "Derived");
	YLZDerivedCode DerivedCode("BaseDerivedCode", "Derived");
	YLZMultiInheritance MultiInheritance = YLZMultiInheritance("MI_Base", "MI_Derived", "MI_DerivedCode", "MI_MiltiInheritance");

	YLZPrintf(Base);
	YLZPrintf(Derived);
	YLZPrintf(DerivedCode);
	YLZPrintf(MultiInheritance);

	return 0;
}
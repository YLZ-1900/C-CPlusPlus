
#include <iostream>
using namespace std;

#define API_YLZMain
#define YLZ_GENERATED_BODY()

//C++�������ԣ�
//��װ
//�̳�
//��̬���������õĶ�����̬
//��̬��̬����������
//��̬�Ķ�̬������ / �����ָ������õ�����д�麯��
//1������ָ���������ָ���࣬���õľ��Ǹ�����麯��
//2������ָ���������ָ�����࣬���õľ���������麯��

//��װ �����ݺͷ��������һ�����ض�������Ժ�ʵ��ϸ�ڣ������⹫���ӿ����Ͷ�����н���
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

//�̳� 
class API_YLZMain YLZDerived :virtual public YLZBase
{
	YLZ_GENERATED_BODY()
private:
	string DerivedID;

public :
	YLZDerived(){}
	//�����๹�캯��
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
	//�����๹�캯��
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

//��̳�  ����̳п��Խ�����μ̳еĶ����Ժ��������������
class API_YLZMain YLZMultiInheritance : public YLZDerived, public YLZDerivedCode
{
	YLZ_GENERATED_BODY()
private:
	string MultiInheritanceID;

public:
	YLZMultiInheritance(){}
	//�����๹�캯��
	YLZMultiInheritance(string In_BaseID,string In_DerivedID,string In_DerivedCode,string In_MultiInheritanceID)
		:YLZBase(In_BaseID), YLZDerived("Z", In_DerivedID),YLZDerivedCode("Y", In_DerivedCode), MultiInheritanceID(In_MultiInheritanceID)
	{}
public:
	virtual void YLZBeginPlay() override
	{
		cout << "YLZMultiInheritance::YLZBeginPlay" << endl;
	}
};

//��̬
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
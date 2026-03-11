#include<iostream>
using namespace std;

//抽象不同零件类
class CPU
{
public:
	virtual void calculate() = 0;
};
class VideoCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};


class computer
{
public:
	computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void work()
	{
		m_cpu->calculate();
		m_mem->storage();
		m_vc->display();
	}
	~computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_cpu;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_cpu;
			m_mem = NULL;
		}
	}

private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};

//具体厂商
class InterCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "inter calculate" << endl;
	}
};

class InterVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "inter display" << endl;
	}
};
class InterMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "inter storage" << endl;
	}
};
//lenovo
class lenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "lenovo calculate" << endl;
	}
};

class lenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "lenovo display" << endl;
	}
};
class lenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "lenovo storage" << endl;
	}
};

void test01()
{
	CPU* InterlCPU = new InterCPU;
	VideoCard* interCard = new InterVideoCard;
	Memory* intermem = new InterMemory;
	//第一台电脑组装
	computer* computer1 = new computer(InterlCPU, interCard, intermem);
	computer1->work();
	delete computer1;
	

	//第2台电脑组装
	computer* computer2 = new computer(new lenovoCPU, new lenovoVideoCard,new lenovoMemory);
	computer2->work();
	delete computer1;
}



int main()
{
	test01();



	system("pause");
	return 0;
}
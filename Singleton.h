

//需要手动释放单例
#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton *GetInstance()
	{
		return const_cast <Singleton *>(m_Instance);
	}

	static void DestoryInstance()
	{
		if (m_Instance != NULL )
		{
			delete m_Instance;
			m_Instance = NULL ;
		}
	}

	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton(){ m_Test = 10; }
	static const Singleton *m_Instance;
	int m_Test;
};

const Singleton *Singleton ::m_Instance = new Singleton();

//非new出来的单例
class Singleton
{
public:
	static Singleton *GetInstance()
	{
		static Singleton m_Instance;
		return &m_Instance;
	}

	int GetTest()
	{
		return m_Test++;
	}

private:
	Singleton(){ m_Test = 10; };
	int m_Test;
};


//继承并在子类析构中释放单例本身
class Singleton
{
public:
	static Singleton *GetInstance()
	{
		return m_Instance;
	}

	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton(){ m_Test = 10; }
	static Singleton *m_Instance;
	int m_Test;

	// This is important
	class GC
	{
	public :
		~GC()
		{
			// We can destory all the resouce here, eg:db connector, file handle and so on
			if (m_Instance != NULL )
			{
				cout<< "Here is the test" <<endl;
				delete m_Instance;
				m_Instance = NULL ;
			}
		}
	};
	static GC gc;
};



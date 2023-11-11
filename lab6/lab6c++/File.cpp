
#include"File.h"

File::File(char* _filename)
{
	strncpy_s(filename, _filename, 80);
	fstr = new fstream;
	maxpos = 0;
}

int File::Open()//создание нового бинарного файла 
{
	fstr->open(filename, ios::in | ios::out | ios::binary | ios::app);
	if (!fstr->is_open())return -1;
	return 0;
}

int File::OpenText()
{
	str.open(filename, ios::in | ios::out | ios::app);
	if (!str.is_open())return -1;
	return 0;
}
void File::CloseText()
{
	str.close();
}
const char* File::GetFileName()
{
	return this->filename;
}

int File::Read(List<WallClock> &p)
{
	int i = 0;
	if (!(fstr->is_open()))cout << "error";
	fstr->clear();
	fstr->seekp(0, ios_base::beg);
	WallClock s;
	while (fstr->read(reinterpret_cast<char*>(&s), sizeof(WallClock)))
	{
		p.push_back(s);
		i++;
	}
	fstr->clear();
	return 0;
}

void File::Add(List<WallClock>& data)
{
	for (int i = 0; i < data.GetSize(); i++)
	{
		fstr->seekp(0, ios_base::end);
		fstr->write(reinterpret_cast<char*>(&data[i]), sizeof(WallClock));
		fstr->flush();//This effectively means that all unwritten characters in the buffer are written to its controlled output sequence as soon as possible
	}
}
int File::Readtext(List<WallClock>& data)
{
	int i = 0,per;
	char strc[255];
	bool m;
	WallClock Per;
	while (!str.eof())
	{
		str>>strc;
		if (str.eof())break;
		data.push_back(Per);
		data[i].SetBrend(strc);
		str>>strc;
		data[i].SetMaterial(strc);
		str>>(m);
		data[i].SetMayatnic(m);
		str>>(per);
		data[i].SetTime(per);
		i++;
	}
	return 0;
}
void File::Addtext(List<WallClock>& data)
{
	Remote();
	int time;
	char* sv;
	bool p;
	sv= new char[255];
	for (int i = 0; i < data.GetSize(); i++)
	{
		sv = data[i].GetBrend();
		str<<(sv)<<endl;
		sv = data[i].GetMaterial();
		str<<(sv) << endl;
		p = data[i].Getmayatnic();
		str<<(p) << endl;
		time = data[i].GetTime();
		str<<(time) << endl;
	}
}


int  File::Cleartext()
{
	str.open(filename,ios::out);
	if (!str.is_open())return -1;
	return 0;
}

void File::Remote()
{
	fstr->seekg(0, ios_base::beg);
	fstr->seekp(0, ios_base::beg);
	fstr->clear();//переводит поток в нормальное состояние(очищает флаги ошибок)
}
File::~File()
{
	fstr->close();
	delete fstr;
}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


                 //SUBJECTS


class Subject
{
	int jid;
	char jname[30];
	public:
	Subject()
	{
		jid=0;
		strcpy(jname,"null");
	}
	void jinput()
	{
		cout<<"\nEnter the subject ID:";
		cin>>jid;
		cout<<"Enter the subject name:";
		cin.ignore();
		cin.getline(jname,29);
	}
	void getsubject(int);
	void joutput()
	{
		cout<<jid<<".     "<<jname<<endl;
	}
	void jstore();
	void jread();
	void jsearch(int);
	void jupdate(int);
	void jerase(int);
};
void Subject::jstore()
{
	jinput();
	ofstream fout("Subject.dat",ios::app|ios::binary);
	if(!fout)
	{
		cout<<"No subject file found to store data";
	}
	else
	{
		fout.write((char*)this,sizeof(*this));
	}
	fout.close();

}
void Subject::jread()
{
	ifstream fin("Subject.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No subject file found to read";
		return;
	}
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		joutput();
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}
void Subject::jsearch(int rid)
{
	ifstream fin("Subject.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No subject file found to read to search";
		return;
	}
	int f=0;
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(rid==jid)
		{
			f=1;
			joutput();
		}
		fin.read((char*)this,sizeof(*this));
	}
	if(f==0)
	{
		cout<<"No such ID of subject exists";
	}
	fin.close();
}
void Subject::jupdate(int rid)
{
	ifstream fin("Subject.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No subject file found to read to update";
		return;
	}
	char ch;
	ofstream fout("subjecttemp.dat",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(rid==jid)
		{
			joutput();
			cout<<endl;
			cout<<"Do you want to change SUBJECT ID,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new ID:";
			cin>>jid;
			}
			cout<<"Do you want to change SUBJECT NAME,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new NAME:";
			cin.ignore();
			cin.getline(jname,29);
			}
		}
		fout.write((char*)this,sizeof(*this));
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
	remove("Subject.dat");
	rename("subjecttemp.dat","Subject.dat");
}
void Subject::jerase(int rid)
{
	ifstream fin("Subject.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No  subject file found to read to erase data";
		return;
	}
	ofstream fout("subtemp.dat",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(rid!=jid)
		{
			fout.write((char*)this,sizeof(*this));
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
	remove("Subject.dat");
	rename("subtemp.dat","Subject.dat");
	cout<<"Record Deleted Successfully";
}
void Subject::getsubject(int rid)
{
	ifstream fin("Subject.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No subject file found to read";
		return;
	}
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(rid==jid)
		{
			cout<<jname<<"    ";
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}



             //SPORTS


class Sport
{
	int gid;
	char gname[30];
	public:
	Sport()
	{
		gid=0;
		strcpy(gname,"null");
	}
	void ginput()
	{
		cout<<"Enter the sports ID:";
		cin>>gid;
		cout<<"Enter the sports NAME:";
		cin.ignore();
		cin.getline(gname,29);
	}
	void getsport(int);
	void goutput()
	{
		cout<<gid<<".     "<<gname<<endl;
	}
	void gstore();
	void gread();
	void gsearch(int sid);
	void gupdate(int sid);
	void gerase(int sid);
};
void Sport::getsport(int sid)
{
	ifstream fin("Sport.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No sports file found to read";
		return;
	}
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(sid==gid)
		{
			cout<<gname<<"    ";
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}
void Sport::gerase(int sid)
{
	ifstream fin("Sport.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No  sports file found to read to erase data";
		return;
	}
	ofstream fout("sptemp.dat",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(sid!=gid)
		{
			fout.write((char*)this,sizeof(*this));
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
	remove("Sport.dat");
	rename("sptemp.dat","Sport.dat");
	cout<<"Record Deleted Successfully";
}
void Sport::gupdate(int sid)
{
	ifstream fin("Sport.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No sports file found to read to update";
		return;
	}
	char ch;
	ofstream fout("sporttemp.dat",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(sid==gid)
		{
			goutput();
			cout<<endl;
			cout<<"Do you want to change SPORTS ID,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new ID:";
			cin>>gid;
			}
			cout<<"Do you want to change SPORTS NAME,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new NAME:";
			cin.ignore();
			cin.getline(gname,29);
			}
		}
		fout.write((char*)this,sizeof(*this));
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
	remove("Sport.dat");
	rename("sporttemp.dat","Sport.dat");
}
void Sport::gsearch(int sid)
{
	ifstream fin("Sport.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No sports file found to read to search";
		return;
	}
	int f=0;
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(sid==gid)
		{
			f=1;
			goutput();
		}
		fin.read((char*)this,sizeof(*this));
	}
	if(f==0)
	{
		cout<<"No such ID of game exists";
	}
	fin.close();	
}
void Sport::gstore()
{
	ginput();
	ofstream fout("Sport.dat",ios::app|ios::binary);
	if(!fout)
	{
		cout<<"No sports file found to store data";
	}
	else
	{
		fout.write((char*)this,sizeof(*this));
	}
	fout.close();
}
void Sport::gread()
{
	ifstream fin("Sport.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No sports file found to read";
		return;
	}
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		goutput();
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}




                 //STUDENTS


class Student:public Sport
{
	int srn;
	int standard;
	int id;
	char name[30];
	char mname[30];
	char pname[30];
	char address[80];
	char gender[20];
	char contact_no[20];
	float per;
	int games[3];
	public:
	Student()
	{
		srn=0;
		standard=0;
		id=0;
		strcpy(name,"null");
		strcpy(address,"null");
		strcpy(gender,"null");
		strcpy(contact_no,"null");
		per=0.0;
	}
	void input();
	void output();
	int tempsrn();
	void store();
	void read();
	void search(int);
	void update(int);
	void erase(int);
	void toppers();
};
void Student::toppers()
{
	ifstream fin("Student.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No student file found to read to search toppers";
		return;
	}
	int f=0;
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(per>=90)
		{
			f++;
			cout<<"\n\nCLASS->"<<"\t\t"<<"NAME->"<<"\t\t\t"<<"PERCENTAGE->";
			cout<<"\n"<<standard<<"\t\t"<<name<<"\t\t"<<per<<"%";
		}
		fin.read((char*)this,sizeof(*this));
	}
	if (f==0)
	{
		cout<<"No student scored 90% and higher"<<endl;
	}
	fin.close();		
}
void Student::erase(int sr)
{
	ifstream fin("Student.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No  student file found to read to erase data";
		return;
	}
	ofstream fout("sctemp.dat",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(sr!=srn)
		{
			fout.write((char*)this,sizeof(*this));
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
	remove("Student.dat");
	rename("sctemp.dat","Student.dat");
	cout<<"Record Deleted Successfully";
}
void Student::update(int sr)
{
	ifstream fin("Student.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No student file found to read to update";
		return;
	}
	char ch;
	ofstream fout("schtemp.dat",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(sr==srn)
		{
			output();
			cout<<endl;
			cout<<"Do you want to change STUDENT'S STANDARD,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new STANDARD:";
			cin>>standard;
			}
			cout<<"Do you want to change STUDENT'S ID,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new ID:";
			cin>>id;
			}
			cout<<"Do you want to change STUDENT'S NAME,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new NAME:";
			cin.ignore();
			cin.getline(name,29);
			}
			cout<<"Do you want to change STUDENT'S MOTHER'S NAME,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new MOTHER'S NAME:";
			cin.ignore();
			cin.getline(mname,29);
			}
			cout<<"Do you want to change STUDENT'S FATHER'S NAME,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new FATHER'S NAME:";
			cin.ignore();
			cin.getline(pname,29);
			}
			cout<<"Do you want to change STUDENT'S ADDRESS,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new ADDRESS:";
			cin.ignore();
			cin.getline(address,79);
			}
			cout<<"Do you want to change STUDENT'S GENDER,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new GENDER:";
			cin.ignore();
			cin.getline(gender,19);
			}
			cout<<"Do you want to change STUDENT'S CONTACT NUMBER,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new CONTACT NUMBER:";
			cin.ignore();
			cin.getline(contact_no,19);
			}
			cout<<"Do you want to change STUDENT'S PERCENTAGE,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new PERCENTAGE:";
			cin>>per;
			}
			cout<<"Do you want to change STUDENT'S SPORTS,press 'y'for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
				cout<<"\nSelect the NEW SPORTS for student(MAX 3 could be selected,else press 0):"<<endl;
	            gread();
				cout<<endl;
				for(int i=0;i<3;i++)
				{
					cout<<"Enter student's sports choice:";
					cin>>games[i];
				}
			}
		}
		fout.write((char*)this,sizeof(*this));
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
	remove("Student.dat");
	rename("schtemp.dat","Student.dat");
}
void Student::search(int sr)
{
	ifstream fin("Student.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No student file found to read to search";
		return;
	}
	int f=0;
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(sr==srn)
		{
			f=1;
			output();
		}
		fin.read((char*)this,sizeof(*this));
	}
	if(f==0)
	{
		cout<<"No such S.RN of student exists";
	}
	fin.close();
}

void Student::read()
{
	ifstream fin("Student.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No student file found to read";
		return;
	}
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		output();
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}
void Student::store()
{
	srn=tempsrn();
	cout<<"S.RN::"<<srn;
	input();
	ofstream fout("Student.dat",ios::app|ios::binary);
	if(!fout)
	{
		cout<<"No student file found to store data";
	}
	else if(srn!=0)
	{
		fout.write((char*)this,sizeof(*this));
	}
	else
	{
		cout<<"Addmission number of student can never be zero";
	}
	fout.close();
}
int Student::tempsrn()
{
	int tempsrn=0;
	ifstream fin("Student.dat",ios::in|ios::binary);
	if(!fin)
	{
		fin.close();
		
		return tempsrn;
	}
	else
	{
		while(!fin.eof())
		{
				tempsrn++;
				fin.read((char*)this,sizeof(*this));
		}
		fin.close();
		return tempsrn;
	}
}
void Student::input()
{
	cout<<"\nEnter the STANDARD of student:";
	cin>>standard;
	cout<<"Enter the ID of student:";
	cin>>id;
	cout<<"Enter the NAME of student:";
	cin.ignore();
	cin.getline(name,29);
	cout<<"Enter MOTHER'S NAME of student:";
	cin.getline(mname,29);
	cout<<"Enter FATHER'S NAME of student:";
	cin.getline(pname,29);
	cout<<"Enter the ADDRESS of student:";
	cin.getline(address,79);
	cout<<"Enter the GENDER of student:";
	cin.getline(gender,19);
	cout<<"Enter the CONTACT NUMBER os student:";
	cin.getline(contact_no,19);
	cout<<"Enter the PERCENTAGE of student:";
	cin>>per;
	cout<<"\nSelect the SPORTS for student(MAX 3 could be selected,else select 0):"<<endl;
	gread();
	cout<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<"Enter student's sports choice:";
		cin>>games[i];
	}
}
void Student::output()
{
	cout<<endl;
	cout<<"\n************************ STUDENT DETAILS **************************"<<endl;
	cout<<"\nS.RN.                     :"<<srn;
	cout<<"\nSTANDARD                  :"<<standard;
	cout<<"\nID                        :"<<id;
	cout<<"\nNAME                      :"<<name;
	cout<<"\nMOTHER'S NAME             :"<<mname;
	cout<<"\nFATHER'S NAME             :"<<pname;
	cout<<"\nADDRESS                   :"<<address;
	cout<<"\nGENDER                    :"<<gender;
	cout<<"\nCONTACT NUMBER            :"<<contact_no;
	cout<<"\nPERCENTAGE                :"<<per<<"%";
	cout<<"\nSPORTS                    :";
	for(int i=0;i<3;i++)
	{
		getsport(games[i]);
	}
	cout<<"\n-------------------------------------------------------------------";
}	



                   //TEACHER


class Teacher:public Subject
{
	int trn;
	char name[30];
	char mname[30];
	char pname[30];
	char address[80];
	char gender[20];
	char cont_no[30];
	float salary;
	int subject[8];
	public:
	Teacher()
	{
		trn=0;
		strcpy(name,"null");
		strcpy(mname,"null");
		strcpy(pname,"null");
		strcpy(address,"null");
		strcpy(gender,"null");
		strcpy(cont_no,"null");
		salary=0.0;
	}
	void tinput();
	void toutput();
	int temptrn();
	void tstore();
	void tread();
	void tsearch(int);
	void tupdate(int);
	void terase(int);
};
void Teacher::terase(int tr)
{
	ifstream fin("Teacher.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No teacher file found to read to erase data";
		return;
	}
	ofstream fout("tetemp.dat",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(tr!=trn)
		{
			fout.write((char*)this,sizeof(*this));
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
	remove("Teacher.dat");
	rename("tetemp.dat","Teacher.dat");
	cout<<"Record Deleted Successfully";
}
void Teacher::tupdate(int tr)
{
	ifstream fin("Teacher.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No teacher file found to read to update";
		return;
	}
	char ch;
	ofstream fout("teachtemp.dat",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(tr==trn)
		{
			toutput();
			cout<<endl;
			cout<<"Do you want to change TEACHER'S NAME,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new NAME:";
			cin.ignore();
			cin.getline(name,29);
			}
			cout<<"Do you want to change TEACHER'S MOTHER'S NAME,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new MOTHER'S NAME:";
			cin.ignore();
			cin.getline(mname,29);
			}
			cout<<"Do you want to change TEACHER'S FATHER'S NAME,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new FATHER'S NAME:";
			cin.ignore();
			cin.getline(pname,29);
			}
			cout<<"Do you want to change TEACHER'S ADDRESS,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new ADDRESS:";
			cin.ignore();
			cin.getline(address,79);
			}
			cout<<"Do you want to change TEACHER'S GENDER,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new GENDER:";
			cin.ignore();
			cin.getline(gender,19);
			}
			cout<<"Do you want to change TEACHER'S CONTACT NUMBER,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new CONTACT NUMBER:";
			cin.ignore();
			cin.getline(cont_no,29);
			}
			cout<<"Do you want to change TEACHER'S SALARY,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new SALARY:";
			cin>>salary;
			}
			cout<<"Do you want to change TEACHER'S SUBJECTS,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
				cout<<"\nSelect the NEW SUBJECTS taught by teacher(MAX 4 could be selected,else press 0):"<<endl;
	            jread();
	            cout<<endl;
	            for(int i=0;i<4;i++)
	            {
		        cout<<"Enter teachers' subject choice:";
		        cin>>subject[i];
	            }
			}
		}
		fout.write((char*)this,sizeof(*this));
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
	remove("Teacher.dat");
	rename("teachtemp.dat","Teacher.dat");
}
void Teacher::tsearch(int tr)
{
	ifstream fin("Teacher.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No  teacher file found to read to search";
		return;
	}
	int f=0;
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(tr==trn)
		{
			f=1;
			toutput();
		}
		fin.read((char*)this,sizeof(*this));
	}
	if(f==0)
	{
		cout<<"No such ID of teacher exists";
	}
	fin.close();
}
void Teacher::tread()
{
	ifstream fin("Teacher.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No teacher file found to read";
		return;
	}
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		toutput();
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}
void Teacher::tstore()
{
	trn=temptrn();
	cout<<"ID::"<<trn;
	tinput();
	ofstream fout("Teacher.dat",ios::app|ios::binary);
	if(!fout)
	{
		cout<<"No  teacher file found to store data";
	}
	else if(trn!=0)
	{
		fout.write((char*)this,sizeof(*this));
	}
	else
	{
		cout<<"ID of teacher can never be zero";
	}
	fout.close();
}
int Teacher::temptrn()
{
	int temptrn=0;
	ifstream fin("Teacher.dat",ios::in|ios::binary);
	if(!fin)
	{
		fin.close();
		return temptrn;
	}
	else
	{
		while(!fin.eof())
		{
				temptrn++;
				fin.read((char*)this,sizeof(*this));
		}
		fin.close();
		return temptrn;
	}
}
void Teacher::toutput()
{
	cout<<endl;
	cout<<"\n\n*********************TEACHER'S DETAILS ****************************"<<endl;
	cout<<"\nID                        :"<<trn;
	cout<<"\nNAME                      :"<<name;
	cout<<"\nMOTHER'S NAME             :"<<mname;
	cout<<"\nFATHER'S NAME             :"<<pname;
	cout<<"\nADDRESS                   :"<<address;
	cout<<"\nGENDER                    :"<<gender;
	cout<<"\nCONTACT NUMBER            :"<<cont_no;
	cout<<"\nSALARY                    :"<<"Rs."<<salary;
	cout<<"\nSUBJECT TAKEN             :";
	for(int i=0;i<4;i++)
	{
		getsubject(subject[i]);
	}
	cout<<"\n-------------------------------------------------------------------";
}
void Teacher::tinput()
{
	cout<<"\nEnter the NAME of teacher:";
	cin.getline(name,29);
	cout<<"Enter MOTHER'S NAME of teacher:";
	cin.getline(mname,29);
	cout<<"Enter FATHER'S NAME of teacher:";
	cin.getline(pname,29);
	cout<<"Enter the ADDRESS of teacher:";
	cin.getline(address,79);
	cout<<"Enter the GENDER of teacher:";
	cin.getline(gender,19);
	cout<<"Enter the CONTACT NUMBER of teacher:";
	cin.getline(cont_no,29);
	cout<<"Enter the SALARY of teacher:";
	cin>>salary;
	cout<<"\nSelect the SUBJECT taught by teacher(MAX 4 could be selected,else press 0):"<<endl;
	jread();
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<"Enter teachers' subject choice:";
		cin>>subject[i];
	}
}



                     //OFFICE



class Office
{
	int orn;
	char position[30];
	char name[30];
	char mname[30];
	char pname[30];
	char address[80];
	char gender[20];
	char cont_no[30];
	float salary;
	public:
	Office()
	{
		orn=0;
		strcpy(position,"null");
		strcpy(name,"null");
		strcpy(mname,"null");
		strcpy(pname,"null");
		strcpy(address,"null");
		strcpy(gender,"null");
		strcpy(cont_no,"null");
		salary=0.0;
	}
	public:
	void oinput();
	void ooutput();
	int temporn();
	void ostore();
	void oread();
	void find(int);
	void oupdate(int);
	void oerase(int);

};
void Office::oerase(int r)
{
	ifstream fin("Office.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No staff memeber file found to read to erase data";
		return;
	}
	ofstream fout("otemp.dat",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(r!=orn)
		{
			fout.write((char*)this,sizeof(*this));
		}
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
	remove("Office.dat");
	rename("otemp.dat","Office.dat");
	cout<<"Record Deleted Successfully";

}
void Office::oupdate(int r)
{
	ifstream fin("Office.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No staff member file found to read to update";
		return;
	}
	char ch;
	ofstream fout("officetemp.dat",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(r==orn)
		{
			ooutput();
			cout<<endl;
			cout<<"Do you wantto change STAFF MEMBER'S POSITION,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new POSITION:";
			cin.ignore();
			cin.getline(position,29);
			}
			cout<<"Do you want to change STAFF MEMBER's NAME,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new NAME:";
			cin.ignore();
			cin.getline(name,29);
			}
			cout<<"Do you want to change STAFF MEMBER'S MOTHER'S NAME,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new MOTHER'S NAME:";
			cin.ignore();
			cin.getline(mname,29);
			}
			cout<<"Do you want to change STAFF MEMBER'S FATHER'S NAME,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new FATHER'S NAME:";
			cin.ignore();
			cin.getline(pname,29);
			}
			cout<<"Do you want to change STAFF MEMBER'S ADDRESS,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new ADDRESS:";
			cin.ignore();
			cin.getline(address,79);
			}
			cout<<"Do you want to change STAFF MEMBER'S GENDER,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new GENDER:";
			cin.ignore();
			cin.getline(gender,19);
			}
			cout<<"Do you want to change STAFF MEMBER'S CONTACT NUMBER,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new CONTACT NUMBER:";
			cin.ignore();
			cin.getline(cont_no,29);
			}
			cout<<"Do you want to change STAFF MEMBER'S SALARY,press 'y' for yes and 'n' for no:"<<endl;
			cin>>ch;
			if(ch=='y')
			{
			cout<<"Enter the new SALARY:";
			cin>>salary;
			}
			fout.write((char*)this,sizeof(*this));
		    fin.read((char*)this,sizeof(*this));
	    }
	    fin.close();
		fout.close();
		remove("Office.dat");
		rename("officetemp.dat","Office.dat");
    }
}
void Office::find(int r)
{
	ifstream fin("Office.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No  staff member file found to read to search";
		return;
	}
	int f=0;
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(r==orn)
		{
			f=1;
			ooutput();
		}
		fin.read((char*)this,sizeof(*this));
	}
	if(f==0)
	{
		cout<<"No such ID of staff member exists";
	}
	fin.close();
}
void Office::oread()
{
	ifstream fin("Office.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"No staff member file found to read";
		return;
	}
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		ooutput();
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}
void Office::ostore()
{
	orn=temporn();
	cout<<"ID::"<<orn;
	oinput();
	ofstream fout("Office.dat",ios::app|ios::binary);
	if(!fout)
	{
		cout<<"No  staff member file found to store data";
	}
	else if(orn!=0)
	{
		fout.write((char*)this,sizeof(*this));
	}
	else
	{
		cout<<"ID of staff member can never be zero";
	}
	fout.close();
}
int Office::temporn()
{
	int temporn=0;
	ifstream fin("Office.dat",ios::in|ios::binary);
	if(!fin)
	{
		fin.close();
		return temporn;
	}
	else
	{
		while(!fin.eof())
		{
				temporn++;
				fin.read((char*)this,sizeof(*this));
		}
		fin.close();
		return temporn;
	}
}
void Office::ooutput()
{
	cout<<endl;
	cout<<"\n\n******************STAFF MEMBER'S DETAILS ****************************"<<endl;;
	cout<<"\nID                        :"<<orn;
	cout<<"\nPOSITION                  :"<<position;
	cout<<"\nNAME                      :"<<name;
	cout<<"\nMOTHER'S NAME             :"<<mname;
	cout<<"\nFATHER'S NAME             :"<<pname;
	cout<<"\nADDRESS                   :"<<address;
	cout<<"\nGENDER                    :"<<gender;
	cout<<"\nCONTACT NUMBER            :"<<cont_no;
	cout<<"\nSALARY                    :"<<"Rs."<<salary;
	cout<<"\n-------------------------------------------------------------------";
}
void Office::oinput()
{
	cout<<"\nEnter the POSITION of office staff member:";
	cin.getline(position,29);
	cout<<"Enter the NAME of office staff member:";
	cin.getline(name,29);
	cout<<"Enter MOTHER'S NAME of office staff member:";
	cin.getline(mname,29);
	cout<<"Enter FATHER'S NAME of office staff member:";
	cin.getline(pname,29);
	cout<<"Enter the ADDRESS of office staff member:";
	cin.getline(address,79);
	cout<<"Enter the GENDER of office staff member:";
	cin.getline(gender,19);
	cout<<"Enter the CONTACT NUMBER of office staff memeber:";
	cin.getline(cont_no,29);
	cout<<"Enter the SALARY of office staff member:";
	cin>>salary;
}




int main()
{
	Student s;
	Sport g;
	Teacher t;
	Subject j;
	Office o;
	int rn;
	int ch;
	system("Cls");
	do
	{
	start:
	system("Cls");
	cout<<"\t\t\t------------------------------"<<endl;
	cout<<"\t\t\t| SCHOOL MANAGEMENT SYSTEM   |"<<endl;
	cout<<"\t\t\t------------------------------"<<endl;
	cout<<"\t\t\t   Please select one option"<<endl;
	cout<<endl;
	cout<<"\n1. STUDENT INFORMATION\n2. TEACHER INFORMATION\n3. OFFICE STAFF INFORMATION\n4. TOPPERS'S LIST\n5. SPORTS FILE\n6. SUBJECTS FILE\n7. EXIT"<<endl;
	cout<<"\nEnter your choice-> ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			do
			{
				system("Cls");
				cout<<endl;
				cout<<"\t\t\t-------------------------"<<endl;
				cout<<"\t\t\t|    STUDENT RECORDS    |"<<endl;
				cout<<"\t\t\t-------------------------"<<endl;
				cout<<"\n\t\t\tPlease select one option"<<endl;
				cout<<endl;
				cout<<"\n1. ADD  \t2. READ\n3. SEARCH\t4. UPDATE\n5. DELETE\t6. BACK TO MAIN MENU\n7. EXIT"<<endl;
				cout<<"\n\nEnter your choice-> ";
				cin>>ch;
				switch(ch)
				{
					case 1:s.store();
					break;
					case 2:s.read();
					break;
					case 3:
					cout<<"Enter the STUDENT'S S.RN. to SEARCH the record:";
					cin>>rn;
					s.search(rn);
					break;
					case 4:
					cout<<"Enter the STUDENT'S S.RN. to UPDATE the record:";
					cin>>rn;
					s.update(rn);
					break;
					case 5:
					cout<<"Enter the STUDENT'S S.RN. to DELETE the record:";
					cin>>rn;
					s.erase(rn);
					break;
					case 6:
					goto start;
					break;
					case 7:
					exit(0);
					break;
					default:
					cout<<"\nWRONG CHOICE!! PLEASE SELECT FROM THE ABOVE OPTIONS ONLY..."<<endl;
				}
				cout<<"\nPRESS ANY KEY TO CONTINUE.....";
				getch();
			} while (ch!=0);
		
		case 2:
			do
			{
				system("Cls");
				cout<<endl;
				cout<<"\t\t\t---------------------------"<<endl;
				cout<<"\t\t\t|    TEACHERS' RECORDS    |"<<endl;
				cout<<"\t\t\t---------------------------"<<endl;
				cout<<"\n\t\t\t Please select one option"<<endl;
				cout<<endl;
				cout<<"\n1. ADD  \t2. READ\n3. SEARCH\t4. UPDATE\n5. DELETE\t6. BACK TO MAIN MENU\n7. EXIT"<<endl;
				cout<<"\n\nEnter your choice-> ";
				cin>>ch;
				switch(ch)
				{
					case 1:t.tstore();
					break;
					case 2:t.tread();
					break;
					case 3:
					cout<<"Enter the TEACHER'S ID to SEARCH the record:";
					cin>>rn;
					t.tsearch(rn);
					break;
					case 4:
					cout<<"Enter the TEACHER'S ID to UPDATE the record:";
					cin>>rn;
					t.tupdate(rn);
					break;
					case 5:
					cout<<"Enter the TEACHER'S ID to DELETE the record:";
					cin>>rn;
					t.terase(rn);
					break;
					case 6:
					goto start;
					break;
					case 7:
					exit(0);
					break;
					default:
					cout<<"\nWRONG CHOICE!! PLEASE SELECT FROM THE ABOVE OPTIONS ONLY..."<<endl;
				}
				cout<<"\nPRESS ANY KEY TO CONTINUE.....";
				getch();
			} while (ch!=0);
		
		
		case 3:
			do
			{
				system("Cls");
				cout<<endl;
				cout<<"\t\t\t--------------------------------"<<endl;
				cout<<"\t\t\t|     OFFICE STAFF'S RECORDS   |"<<endl;
				cout<<"\t\t\t--------------------------------"<<endl;
				cout<<"\n\t\t\t    Please select one option"<<endl;
				cout<<endl;
				cout<<"\n1. ADD  \t2. READ\n3. SEARCH\t4. UPDATE\n5. DELETE\t6. BACK TO MAIN MENU\n7. EXIT"<<endl;
				cout<<"\n\nEnter your choice-> ";
				cin>>ch;
				switch(ch)
				{
					case 1:o.ostore();
					break;
					case 2:o.oread();
					break;
					case 3:
					cout<<"Enter the STAFF'S ID to SEARCH the record:";
					cin>>rn;
					o.find(rn);
					break;
					case 4:
					cout<<"Enter the STAFF'S ID to UPDATE the record:";
					cin>>rn;
					o.oupdate(rn);
					break;
					case 5:
					cout<<"Enter the STAFF'S ID to DELETE the record:";
					cin>>rn;
					o.oerase(rn);
					break;
					case 6:
					goto start;
					break;
					case 7:
					exit(0);
					break;
					default:
					cout<<"\nWRONG CHOICE!! PLEASE SELECT FROM THE ABOVE OPTIONS ONLY..."<<endl;
				}
				cout<<"\nPRESS ANY KEY TO CONTINUE.....";
				getch();
			} while (ch!=0);


		case 4:
			system("Cls");
			cout<<endl;
			cout<<"\t\t\t------------------------"<<endl;
			cout<<"\t\t\t|     TOPPER'S LIST    |"<<endl;
			cout<<"\t\t\t------------------------"<<endl;
			cout<<endl;
			s.toppers();
			cout<<"\n\nPRESS ANY KEY TO CONTINUE.....";
			getch();
			goto start;
			break;

		case 5:
			do
			{
				system("Cls");
				cout<<endl;
				cout<<"\t\t\t-------------------------"<<endl;
				cout<<"\t\t\t|      SPORTS FILE      |"<<endl;
				cout<<"\t\t\t-------------------------"<<endl;
				cout<<"\n\t\t\tPlease select one option"<<endl;
				cout<<endl;
				cout<<"\n1. ADD  \t2. READ\n3. SEARCH\t4. UPDATE\n5. DELETE\t6. BACK TO MAIN MENU\n7. EXIT"<<endl;
				cout<<"\n\nEnter your choice-> ";
				cin>>ch;
				switch(ch)
				{
					case 1:g.gstore();
					break;
					case 2:g.gread();
					break;
					case 3:
					cout<<"Enter the SPORTS ID to SEARCH the record:";
					cin>>rn;
					g.gsearch(rn);
					break;
					case 4:
					cout<<"Enter the SPORTS ID to UPDATE the record:";
					cin>>rn;
					g.gupdate(rn);
					break;
					case 5:
					cout<<"Enter the SPORTS ID to DELETE the record:";
					cin>>rn;
					g.gerase(rn);
					break;
					case 6:
					goto start;
					break;
					case 7:
					exit(0);
					break;
					default:
					cout<<"\nWRONG CHOICE!! PLEASE SELECT FROM THE ABOVE OPTIONS ONLY..."<<endl;
				}
				cout<<"\nPRESS ANY KEY TO CONTINUE.....";
				getch();
			} while (ch!=0);


		case 6:
			do
			{
				system("Cls");
				cout<<endl;
				cout<<"\t\t\t-----------------------"<<endl;
				cout<<"\t\t\t|    SUBJECTS FILE    |"<<endl;
				cout<<"\t\t\t-----------------------"<<endl;
				cout<<"\n\t\t\tPlease select one option"<<endl;
				cout<<endl;
				cout<<"\n1. ADD  \t2. READ\n3. SEARCH\t4. UPDATE\n5. DELETE\t6. BACK TO MAIN MENU\n7. EXIT"<<endl;
				cout<<"\n\nEnter your choice-> ";
				cin>>ch;
				switch(ch)
				{
					case 1:j.jstore();
					break;
					case 2:j.jread();
					break;
					case 3:
					cout<<"Enter the SUBJECT ID to SEARCH the record:";
					cin>>rn;
					j.jsearch(rn);
					break;
					case 4:
					cout<<"Enter the SUBJECT ID to UPDATE the record:";
					cin>>rn;
					j.jupdate(rn);
					break;
					case 5:
					cout<<"Enter the SUBJECT ID to DELETE the record:";
					cin>>rn;
					j.jerase(rn);
					break;
					case 6:
					goto start;
					break;
					case 7:
					exit(0);
					break;
					default:
					cout<<"\nWRONG CHOICE!! PLEASE SELECT FROM THE ABOVE OPTIONS ONLY..."<<endl;
				}
				cout<<"\nPRESS ANY KEY TO CONTINUE.....";
				getch();
			} while (ch!=0);


		case 7:
		exit(0);
		break;
		default:
		cout<<"\nWRONG CHOICE!! PLEASE SELECT FROM THE ABOVE OPTIONS ONLY..."<<endl;
	}
	}while(ch!=0);
}

#include<iostream>
#include<conio.h>
using namespace std;

class task{
public:
	int starting_time;  //in se ta ro karadam int chon warning midad
	int ending_time;
	int compliting_time;
	char    task_name;
	char    requiriment_task[10];
	int number_of_requiriment;
	task* next;

	task()
	{
		starting_time = 0;
		ending_time = 100;
		compliting_time = 1000;
		task_name = '#';
		number_of_requiriment = 0;
		next = NULL;

	}
};

int ending[1000];
int k = 0;
int tedad;
int  num_max = 0;
task * head = NULL;
task * h = NULL;
task * T = NULL;
task *m = NULL;
task arr[1000];


void calculatoin(task[], int);
void critical_path(task[], int);
void   sort(int[], int);
int Max();
int find_path(task[]);

int main()
{

	cout << "enter number of tasks:";
	cin >> tedad;


	task a;
	/*	task b;
	task c;
	task d;
	task e;
	task f;
	task g;
	task h;
	task i;*/
	for (int i = 0; i < tedad; i++)
	{
		cout << endl << "enter name of task"<<i<<":";
		cin >> a.task_name;
		cout << endl << "enter number of requirment & name:";
		cin >> a.number_of_requiriment;
		if (a.number_of_requiriment == 0)
			a.requiriment_task[0] = '0';
		for (int j = 0; j < a.number_of_requiriment; j++)
			cin >> a.requiriment_task[j];
		cout << endl << "enter time for completing:";
		cin >> a.compliting_time;
		arr[i] = a;
	}

	/*a.compliting_time = 8;
	b.compliting_time = 10;
	c.compliting_time = 8;
	d.compliting_time = 9;
	e.compliting_time = 5;
	f.compliting_time = 3;
	g.compliting_time = 2;
	h.compliting_time = 4;
	i.compliting_time = 3;


	a.task_name = 'a';
	a.requiriment_task[0] = '0';
	a.number_of_requiriment = 0;  //ezafe
	b.task_name = 'b';
	b.requiriment_task[0] = '0';
	b.number_of_requiriment = 0;  //ezafe
	c.task_name = 'c';
	c.requiriment_task[0] = 'a';
	c.requiriment_task[1] = 'b';
	c.number_of_requiriment = 2;
	d.task_name = 'd';
	d.requiriment_task[0] = 'a';
	d.number_of_requiriment = 1;
	e.task_name = 'e';
	e.requiriment_task[0] = 'b';
	e.number_of_requiriment = 1;
	f.task_name = 'f';
	f.requiriment_task[0] = 'c';
	f.requiriment_task[1] = 'd';
	f.number_of_requiriment = 2;
	g.task_name = 'g';
	g.requiriment_task[0] = 'd';
	g.number_of_requiriment = 1;
	h.task_name = 'h';
	h.requiriment_task[0] = 'f';
	h.requiriment_task[1] = 'g';
	h.number_of_requiriment = 2;
	i.task_name = 'i';
	i.requiriment_task[0] = 'e';
	i.requiriment_task[1] = 'f';
	i.number_of_requiriment = 2;


	*/



	calculatoin(arr, tedad);

	cout << endl;
	cout << "    start time" << "  complete time" << "  end time" << "  requirment(s)" << endl;
	for (int u = 0; u < tedad; u++){
		ending[u] = arr[u].ending_time;
		cout << arr[u].task_name << ":       ";
		cout << arr[u].starting_time << "           ";
		cout << arr[u].compliting_time << "            ";
		cout << arr[u].ending_time << "        ";
		for (int i = 0; i < arr[u].number_of_requiriment; i++)
			cout << arr[u].requiriment_task[i] << ",";
		cout << "-" << endl;
	}




	critical_path(arr, tedad);


	_getch();


}

void calculatoin(task arr[], int number)
{




	for (int i = 0; i < number; i++)
	{


		if (arr[i].requiriment_task[0] == '0')

		{
			arr[i].ending_time = arr[i].compliting_time;
		}

	}                                                                       //mohasebe zaman shoroh baraye taskhay bedoon pishniaz

	for (int i = 0; i < number; i++)
	{
		if (arr[i].requiriment_task[0] != '0')                               //mohasebe zaman shoroh baraye taskhay ba pishniaz-taghir

		{

			int num = arr[i].number_of_requiriment;
			int count = 1;


			if (num == 1)                                 // pishniaz yedooneh-taghir
			{


				for (int k = 0; k < number; k++)
				{

					if (arr[k].task_name == arr[i].requiriment_task[0])
					{
						arr[i].starting_time = arr[k].ending_time;
						arr[i].ending_time = arr[i].starting_time + arr[i].compliting_time;
					}
				}

			}
			else                                                                 //bishtar az yedooneh
			{

				int start_temp = 0;
				while (count - 1 != num)
				{

					start_temp = arr[i].starting_time;
					char* temp = arr[i].requiriment_task;
					char  tasknum = temp[count - 1];
					for (int j = 0; j < number; j++)
					{
						if (arr[j].task_name == tasknum && start_temp < arr[j].ending_time)
							arr[i].starting_time = arr[j].ending_time;
					}


					count++;
				}
				arr[i].ending_time = arr[i].starting_time + arr[i].compliting_time;
			}

		}

	}
}

void   sort(int a[], int f)
{

	for (int y = f; y > 0; y--)
	{

		for (int x = 0; x < y; x++)
		{

			if (a[x] < a[x + 1])
			{
				int temp;
				temp = a[x];
				a[x] = a[x + 1];
				a[x + 1] = temp;


			}

		}
	}
}

int Max()
{

	int x = ending[num_max++];


	for (int q = 0; q < tedad; q++)
	{

		if (arr[q].ending_time == x)
		{
			return q;
		}

	}


}

int find_path(task parr2[])
{


	if (head != NULL)
	{

		//	m = head;
		//	while (m->next != NULL)
		//	{
		//		m = m->next;
		//	}
		if (m->requiriment_task[0] == '0')
		{

			cout << endl << "-----------critical path---------" << endl << endl << endl;
			m = head;
			while (m != NULL)
			{
				cout << m->task_name << endl;
				m = m->next;
			}
			return 0;
		}
		//}
	}
	if (head == NULL)

	{

		k = Max();
		//cout << k << endl;
		head = &parr2[k];
		h = head;
		T = head;
		m = head;
		find_path(parr2);
	}
	else
	{

		if (T = h)
		{
			int j;
			j = Max();
			h->next = &parr2[j];

			h = h->next;

			for (int s = 0; s < m->number_of_requiriment; s++)
			{
				if (h->task_name == m->requiriment_task[s])
				{
					T = h;
					m->next = h;
					m = m->next;
				}



			}
			find_path(parr2);

		}

		else{
			int J;
			J = Max();
			//cout << J << endl;
			T->next = &parr2[J];
			h = T->next;
			for (int s = 0; s < T->number_of_requiriment; s++)
			{

				if (h->task_name == T->requiriment_task[s])
				{
					T = h;
					cout << T->task_name << endl;
				}

				find_path(parr2);

			}





		}


	}

}

void critical_path(task parr[], int n)

{
	sort(ending, n);
	find_path(parr);

}

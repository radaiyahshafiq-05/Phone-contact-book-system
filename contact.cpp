#include<iostream>
#include<fstream>
#include <sstream>

using namespace std;

struct Node
{
	string name;
	long int phone_number;
	Node *next;
	Node *prev;
};

class ContactBook
{
	Node *head;
	Node *tail;
	string x;
	long int y;
	public:
		ContactBook()
		{
			head=tail=NULL;
			x="";
			y=0;
		}
   void CreateNode()
    {
    string name;
    long int phone_number;

    cout << "Name of Contact: ";
    cin >> name;

    cout<<"Phone Number (Digits Only, e.g., 1234567890): ";

    while (!(cin >> phone_number))
        {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input! Phone number must be numeric. Try again: ";
    }

    Node* temp = head;
    while (temp != NULL)
        {
        if(temp->name == name)
        {
            cout << "Error: A contact with this name already exists!" << endl;
            return;
        }
        else
       {

        if (temp->phone_number == phone_number) {
            cout << "Error: A contact with this phone number already exists!" << endl;
            return;
        }
       }
        temp = temp->next;
    }


    Node* newNode=new Node;
    newNode->name=name;
    newNode->phone_number=phone_number;
    newNode->next =NULL;
    newNode->prev= NULL;

    if (head == NULL) {
    head = tail = newNode;
}
else
{
    temp =tail;

    temp->next=newNode;

    newNode->prev=temp;
    tail=newNode;
}



    cout<<"Contact Added Successfully!" << endl;
}

    	void Display()
    	{
	    	Node *temp=head;
	    	int count=0;

	    	if(temp==NULL)
	    	{
		    	cout<<"  No Contacts... Please Add Some Contacts"<<endl;
		    	cout<<"  Thanks"<<endl;
	    	}
	    	else
	    	{
	    		BubbleSort();
	    		cout<<"  Name: "<<"      Number: \n"<<endl;
	        	while(temp!=NULL)
	        	{
	        	    count++;
		        	cout<<"  "<<temp->name;
		        	cout<<"          "<<temp->phone_number<<endl;
    		    	temp=temp->next;
	        	}
	        	cout<<"  Total contacts: "<<count<<endl;
	    	}
    	}

    	void Search()
    	{
    		bool check=false;

	    	Node *temp=head;

	    	cout<<"***********"<<endl;
	    	cout<<"  Press 1 if you want to Search By Name."<<endl;
	    	cout<<"  Press 2 if you want to Search By Number."<<endl;

	    	char choice;
	    	cout<<"  Enter the Command(1 or 2): ";
	    	cin>>choice;

	    	if(choice=='1' && temp!=NULL)
	    	{
	    		cout<<"  Enter the Name to Search: ";
	    		cin>>x;

		    	while(temp!=NULL)
		    	{
		        	if(temp->name==x)
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"  Name: "<<temp->name<<endl;
		        		cout<<"  Phone Number:"<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		check=true;
		        		break;
		        	}

		        	temp=temp->next;
	        	}
	        	if(check==false)
	        	{
	        		cout<<"  Name Not Found"<<endl;
				}
	    	}
	    	else if(choice=='2')
	    	{
	    		cout<<"  Enter the Number to Search: ";
	    		cin>>y;

	    		while(temp!=NULL)
	    		{
	    	    	if(temp->phone_number==y)
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"  Name: "<<temp->name<<endl;
		        		cout<<"  Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		check=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
				if(check==false)
				{
					cout<<"  Number Not Found"<<endl;
				}
	    	}
	    }

void DeleteAllContacts()

	    {
	        char confirm;
	        cout<<"Are you sure you want to delete all contacts:\n";
	        cout<<"press '1' for yes\npress '2' for no\n";
	        cin>>confirm;

	        if(confirm=='1')
            {


	    	Node *temp=head;
	    	Node *temp2;
	    	if(head==NULL)
	    	{
	    		cout<<"  Already Contact Book is Empty"<<endl;
	    		cout<<"***********"<<endl;
			}
			else
			{
				while(temp!=NULL)
				{
					temp2=temp;
					temp=temp->next;
					delete temp2;
				}

				head=tail=NULL;

				cout<<"  Successfully Deleted All Contacts"<<endl;
	    		cout<<"***********"<<endl;
			}

            }
            else if(confirm=='2')
            {

                cout<<"Exiting....";
                return;
            }
            else
            {

                cout<<"Invalid option";
                return;
            }
		}

		int DeleteContactBySearch()
    	{

	    	Node *temp=head;

	    	cout<<"***********"<<endl;
	    	cout<<"  Press 1 if you want to Search By name"<<endl;
	    	cout<<"  Press 2 if you want to Search By Number"<<endl;
	    	char choice;

	    	cout<<"  Enter choice: ";
	    	cin>>choice;

	     if (choice == '1')
    {
        bool check = false;
        cout << "  Enter the Name to Delete: ";
        cin >> x;

        while (temp != NULL)
        {
            if (temp->name == x)
            {
                cout << "***********" << endl;
                cout << "  Name: " << temp->name << endl;
                cout << "  Phone Number: " << temp->phone_number << endl;
                cout << "***********" << endl;
                check = true;
                break;
            }
            temp = temp->next;
        }

        if (check)
        {
            int choice2;
            cout << "  Press 1 to Delete the Contact: ";
            cin >> choice2;

            if (choice2 == 1)
            {
                if (temp == head && temp == tail) // only one node
                {
                    delete temp;
                    head = tail = NULL;
                }
                else if (temp == head)
                {
                    head = temp->next;
                    head->prev = NULL;
                    delete temp;
                }
                else if (temp == tail)
                {
                    tail = temp->prev;
                    tail->next = NULL;
                    delete temp;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }

                cout << "  Contact Deleted Successfully" << endl;
            }
        }
        else
        {
            cout << "  Contact with This Name Not Found." << endl;
        }
    }
    else if (choice == '2')
    {
        bool check = false;
        cout << "  Enter the Number to Delete: ";
        cin >> y;

        while (temp != NULL)
        {
            if (temp->phone_number == y)
            {
                cout << "***********" << endl;
                cout << "  Name: " << temp->name << endl;
                cout << "  Phone Number: " << temp->phone_number << endl;
                cout << "***********" << endl;
                check = true;
                break;
            }
            temp = temp->next;
        }

        if (check)
        {
            int choice3;
            cout << "  Press 1 to Delete the Contact: ";
            cin >> choice3;

            if (choice3 == 1)
            {
                if (temp == head && temp == tail)
                {
                    delete temp;
                    head = tail = NULL;
                }
                else if (temp == head)
                {
                    head = temp->next;
                    head->prev = NULL;
                    delete temp;
                }
                else if (temp == tail)
                {
                    tail = temp->prev;
                    tail->next = NULL;
                    delete temp;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }

                cout << "  Contact Deleted Successfully" << endl;
            }
        }
        else
        {
            cout << "  Contact with This Number Not Found." << endl;
        }
    }
    else
    {
        cout << "  Invalid choice entered." << endl;
    }

    return 0;
	    }





 void BubbleSort()
        {

        	Node *temp=head;
            Node *i,*j;
            string n;

            long int n2;

            if(temp=NULL)

            {
            	cout<<"  Empty contact Book"<<endl;
			}
			else
			{
                for(i=head;i->next!=NULL;i=i->next)
                {
                    for(j=i->next;j!=NULL;j=j->next)
                    {
                        if(i->name>j->name)
		                {
                            n=i->name;
                            i->name=j->name;
                            j->name=n;

                            n2=i->phone_number;
                            i->phone_number=j->phone_number;
                            j->phone_number=n2;
                        }
                    }
                }
            }
        }


 int EditContacts()
 {
    if (head == NULL) {
        cout << "Contact Book is empty!" << endl;
        return 0;
    }

    cout << "***********" << endl;
    cout << "  1. Search By Name" << endl;
    cout << "  2. Search By Number" << endl;
    cout << "Enter your choice: ";

    char choice;
    cin >> choice;

    Node* temp=head;
    bool found=false;
    string name;
     long int number;

    if (choice == '1') {
        cout << "Enter the Name to Edit: ";
        cin >> name;

        while (temp != NULL) {
            if (temp->name == name) {
                found = true;
                break;
            }
            temp = temp->next;
        }
    }
    else if (choice == '2')
        {
        cout << "Enter the Number to Edit: ";
        while (!(cin >> number)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input! Enter digits only: ";
        }

        while (temp != NULL)
            {
            if (temp->phone_number == number) {
                found = true;
                break;
            }
            temp = temp->next;
        }
    }
    else
        {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    if (!found)
        {
        cout << "Contact not found!" << endl;
        return 0;
    }


    cout << "***********" << endl;
    cout << "Current Name: " << temp->name << endl;
    cout << "Current Number: " << temp->phone_number << endl;
    cout << "***********" << endl;


    string newName;
    long int newNumber;

    cout<<"Enter New Name (or press Enter to keep current): ";
    cin.ignore();
    getline(cin, newName);

    cout << "Enter New Number (or 0 to keep current): ";
    while (!(cin >> newNumber)) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input! Enter digits only (or 0 to keep current): ";
    }


    if (!newName.empty()) {
        temp->name = newName;
    }
    if (newNumber != 0) {
        temp->phone_number = newNumber;
    }

    cout << "Contact updated successfully!" << endl;
    return 1;
}

void OflineSave()
    	{
    		Node *temp=head;
    		ofstream myfile ("contactbook.txt");
            if (myfile.is_open())
            {
            	while(temp!=NULL)
	        	{
	        	    myfile<<temp->name<<endl;
		        	myfile<<temp->phone_number<<endl;
    		    	temp=temp->next;
	        	}
                myfile.close();
                Show_menu();
            }
            else
            {
            	cout<<"  Thanks file is empty."<<endl;
			}
		}

		void reopenCB()
		{
			bool isEmpty;
			ifstream myfile ("contactbook.txt");
            if (myfile.is_open() & myfile.peek() != EOF)
            {
                int i=0;
                while(getline(myfile,x))
                {
                    if(i%2== 0)
					{
						if(head==NULL)
	                    {
    	                  Node *newer= new Node;
                          newer->name=x;

	                      newer->next=NULL;
	                      newer->prev==NULL;
	                      head=newer;
		                }
						else
						{
							Node *newer= new Node;

							newer->name=x;
							newer->next=NULL;

							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	temp->next=newer;
		                	newer->prev=temp;
						}
                    }
                   else
                    {
                    	Node *temp=head;
                    	if(temp->phone_number==0)
                    	{

                    		 stringstream convert(x);
			       	         convert>>y;
                             temp->phone_number=y;
						}
						else
						{
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}

		                	stringstream convert(x);
			       	        convert>>y;
		                	temp->phone_number=y;

						}

				    }
                    i++;
                }
            	myfile.close();
            }
            else
            {
            	cout<<"  File is Empty so Cannot open...Sorry"<<endl;
			}
		}

void Show_menu()
{
	cout<<"***********"<<endl;
	cout<<"  1. Add Contact"<<endl;
	cout<<"  2. Edit the Contact"<<endl;
	cout<<"  3. Delete Contact"<<endl;a
	cout<<"  4. Search Contact"<<endl;
	cout<<"  5. Display All Contacts"<<endl;
	cout<<"  6. Delete All Contacts"<<endl;
	cout<<"***********"<<endl;

	char choice ;
	cout<<"  Enter choice: ";
	cin>>choice;

	if(choice>='1' && choice<='6')
	{
		switch(choice)
		{

			case '1':
				CreateNode();
				OflineSave();
				break;

			case '2':
				EditContacts();
				OflineSave();
				break;


			case '3':
				DeleteContactBySearch();
				break;


			case '4':
				Search();
				break;

			case '5':
				Display();
				OflineSave();
				break;

			case '6':
				DeleteAllContacts();
				OflineSave();
				break;
		}
	}
	else
	{
		cout<<"  Invalid command! Please enter a number between 1 and 6."<<endl;
	}

	Show_menu();
}


};

int main()
{
    ContactBook cb;
    cb.reopenCB();
	string n;

	cout<<"  What is Your Name: ";
	cin>>n;

    cout<<"***********"<<endl;
	cout<<"  "<<n<<"  WELCOME TO CONTACTBOOK      "<<endl;
	cout<<"***********"<<endl;

	cb.Show_menu();

	return 0;
}


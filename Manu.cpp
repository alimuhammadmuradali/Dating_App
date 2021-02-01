#include<iostream>
int main()
{
   cout << endl;
   menu ();

}

void menu ()
   {
        cout << endl;
        selection = 0;
        cout << " Please choose from the following options - \n";
        cout << " 1. Set username and password.\n";
        cout << " 2. Set launch codes.\n";
        cout << " 3. Login.\n";
        cout << " 4. Enter launch codes.\n";
        cout << " 5. Exit.\n";
        cout << "\t";
        cin >> selection;

   if (selection == 1)
   {
       setpassword ();
   }
   else if (selection == 2)
   {
       setlaunch ();
   }
   else if (selection == 3)
   {
       login();
   }
   else if (selection == 4)
    {
       launch();
    }
   else if (selection == 5)
    {
      exit ();
    }
   }

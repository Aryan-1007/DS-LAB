#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int choice;
    string str;

    do
    {
        cout << "\n1.Check Palindrome\n2.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter string: ";
            cin >> str;

            deque<char> dq;

            for (char c : str)
                dq.push_back(c);

            bool isPal = true;

            while (dq.size() > 1)
            {
                if (dq.front() != dq.back())
                {
                    isPal = false;
                    break;
                }

                dq.pop_front();
                dq.pop_back();
            }

            if (isPal)
                cout << "Palindrome\n";
            else
                cout << "Not Palindrome\n";

            break;
        }
        }

    } while (choice != 2);

    return 0;
}
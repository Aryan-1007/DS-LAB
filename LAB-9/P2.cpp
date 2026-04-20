#include <iostream>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

int midSquare(int key, int digits)
{
    int sq = key * key;
    string s = to_string(sq);
    int len = s.length();
    int mid = len / 2;
    int start = mid - digits / 2;
    return stoi(s.substr(start, digits));
}

int folding(int key, int partSize)
{
    string s = to_string(key);
    int sum = 0;
    for (int i = 0; i < s.length(); i += partSize)
    {
        sum += stoi(s.substr(i, partSize));
    }
    return sum;
}

int h1(int key, int m)
{
    return key % m;
}

int h2(int key, int m)
{
    return 1 + (key % (m - 1));
}

int main()
{
    int choice;

    do
    {
        cout << "\n1.Division Method\n2.Multiplication Method\n3.Mid-Square & Folding\n4.Linear Probing\n5.Quadratic Probing\n6.Double Hashing\n7.Chaining\n8.Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int n, m;
            cout << "Enter number of keys: ";
            cin >> n;
            vector<int> keys(n);
            cout << "Enter keys: ";
            for (int i = 0; i < n; i++)
                cin >> keys[i];
            cout << "Enter table size: ";
            cin >> m;

            vector<vector<int>> table(m);
            for (int k : keys)
                table[k % m].push_back(k);

            for (int i = 0; i < m; i++)
            {
                cout << i << ": ";
                for (int x : table[i])
                    cout << x << " ";
                cout << endl;
            }
        }

        else if (choice == 2)
        {
            int n, m;
            double A;
            cout << "Enter number of keys: ";
            cin >> n;
            vector<int> keys(n);
            cout << "Enter keys: ";
            for (int i = 0; i < n; i++)
                cin >> keys[i];
            cout << "Enter table size: ";
            cin >> m;
            cout << "Enter A: ";
            cin >> A;

            for (int k : keys)
            {
                double val = k * A;
                double frac = val - (int)val;
                cout << k << " -> " << (int)(m * frac) << endl;
            }
        }

        else if (choice == 3)
        {
            int key, digits, partSize;
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter middle digits: ";
            cin >> digits;
            cout << "Mid-Square: " << midSquare(key, digits) << endl;
            cout << "Enter part size: ";
            cin >> partSize;
            cout << "Folding: " << folding(key, partSize) << endl;
        }

        else if (choice == 4)
        {
            int n, m;
            cout << "Enter number of keys: ";
            cin >> n;
            vector<int> keys(n);
            cout << "Enter keys: ";
            for (int i = 0; i < n; i++)
                cin >> keys[i];
            cout << "Enter table size: ";
            cin >> m;

            vector<int> table(m, -1);
            for (int k : keys)
            {
                int i = 0;
                while (table[(k + i) % m] != -1)
                    i++;
                table[(k + i) % m] = k;
            }

            for (int i = 0; i < m; i++)
                cout << i << ": " << table[i] << endl;
        }

        else if (choice == 5)
        {
            int n, m;
            cout << "Enter number of keys: ";
            cin >> n;
            vector<int> keys(n);
            cout << "Enter keys: ";
            for (int i = 0; i < n; i++)
                cin >> keys[i];
            cout << "Enter table size: ";
            cin >> m;

            vector<int> table(m, -1);
            for (int k : keys)
            {
                int i = 0;
                while (table[(k + i * i) % m] != -1)
                    i++;
                table[(k + i * i) % m] = k;
            }

            for (int i = 0; i < m; i++)
                cout << i << ": " << table[i] << endl;
        }

        else if (choice == 6)
        {
            int n, m;
            cout << "Enter number of keys: ";
            cin >> n;
            vector<int> keys(n);
            cout << "Enter keys: ";
            for (int i = 0; i < n; i++)
                cin >> keys[i];
            cout << "Enter table size: ";
            cin >> m;

            vector<int> table(m, -1);
            for (int k : keys)
            {
                int index = h1(k, m);
                int step = h2(k, m);
                int i = 0;
                while (table[(index + i * step) % m] != -1)
                    i++;
                table[(index + i * step) % m] = k;
            }

            for (int i = 0; i < m; i++)
                cout << i << ": " << table[i] << endl;
        }

        else if (choice == 7)
        {
            int n, m;
            cout << "Enter number of keys: ";
            cin >> n;
            vector<int> keys(n);
            cout << "Enter keys: ";
            for (int i = 0; i < n; i++)
                cin >> keys[i];
            cout << "Enter table size: ";
            cin >> m;

            vector<list<int>> table(m);
            for (int k : keys)
                table[k % m].push_back(k);

            for (int i = 0; i < m; i++)
            {
                cout << i << ": ";
                for (int x : table[i])
                    cout << x << " -> ";
                cout << "NULL" << endl;
            }
        }

    } while (choice != 8);
}
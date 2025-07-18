#include<bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j);
int optCost(int freq[], int i, int j)
{
    if (j < i)
        return 0;
    if (j == i)
        return freq[i];
    int fsum = sum(freq, i, j);
    int min = INT_MAX;
    for (int r = i; r <= j; ++r)
    {
        int cost = optCost(freq, i, r - 1) + optCost(freq, r + 1, j);
        if (cost < min)
            min = cost;
    }
    return min + fsum;
}

int optimalSearchTree(int keys[], int freq[], int n)
{
    return optCost(freq, 0, n - 1);
}
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int main()
{
    cout<<"**********************************"<<endl;
    cout<<"PRACTICAL NO: 8(D-18): OBST"<<endl;
    cout<<"Prepared By: Anushka Patil"<<endl;
    int number_of_keys;
    cout << "\nEnter number of keys : ";
    cin >> number_of_keys;
    int keys[number_of_keys];
    int freq[number_of_keys];
    cout << "\n";
    for (int i = 0; i < number_of_keys; ++i)
    {
        cout << "Enter key and frequency : ";
        cin >> keys[i] >> freq[i];
    }
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "\nCost of Optimal BST : " << optimalSearchTree(keys, freq, n) << "\n";
    cout<<"********************************";
    return 0;
}


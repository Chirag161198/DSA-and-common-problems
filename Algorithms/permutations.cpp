/* Permutations of distinct elements */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void permutate(stack<int> current, vector<int> elements, vector<stack<int>> &results)
{
    if (0 == elements.size())
    {
        results.push_back(current);
        return;
    }

    for (int i = 0; i < elements.size(); i++)
    {
        current.push(elements[i]);
        vector<int> temp;
        for (int j = 0; j < elements.size(); j++)
        {
            if (i != j)
                temp.push_back(elements[j]);
        }
        permutate(current, temp, results);
        current.pop();
    }
}

vector<vector<int>> generatePermutations(vector<int> elements)
{
    vector<stack<int>> resultsStack;
    permutate(stack<int>(), elements, resultsStack);
    vector<vector<int>> results(resultsStack.size());
    for (int i = resultsStack.size()-1; i >=0; i--)
    {
        while (!resultsStack[i].empty())
        {
            results[i].push_back(resultsStack[i].top());
            resultsStack[i].pop();
        }
    }
    return results;
}

int main()
{
    int sampleSpaceSize;
    cout << "Enter number of elements in sample space: ";
    cin >> sampleSpaceSize;

    vector<int> sampleSpace(sampleSpaceSize);

    cout << "Enter " << sampleSpaceSize << " element(s) space separated : ";
    for (int i = 0; i < sampleSpaceSize; i++)
        cin >> sampleSpace[i];

    cout << endl;
    vector<vector<int>> permutations = generatePermutations(sampleSpace);
    cout << "The permutation(s) is/are:" << endl;
    for (int i = 0; i < permutations.size(); i++)
    {
        for (int j=0;j<permutations[i].size();j++)
            cout << permutations[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
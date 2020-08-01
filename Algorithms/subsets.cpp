#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrackSubsets(vector<bool> subset, vector<vector<bool>> &results, int count = 0)
{
  results.push_back(subset);
  for (int i = count; i < subset.size(); i++)
  {
    subset[i] = true;
    backtrackSubsets(subset, results, i + 1);
    subset[i] = false;
  }
}

vector<vector<int>> generateSubsets(vector<int> sampleSpace)
{
  int sampleSpaceSize = sampleSpace.size();
  vector<bool> firstSubset(sampleSpaceSize, false);
  vector<vector<bool>> subsets;
  backtrackSubsets(firstSubset, subsets);
  vector<vector<int>> processedSubsets(subsets.size());
  for (int i = 0; i < subsets.size(); i++)
  {
    for (int j = 0; j < sampleSpaceSize; j++)
    {
      if (subsets[i][j])
        processedSubsets[i].push_back(sampleSpace[j]);
    }
  }
  return processedSubsets;
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
  vector<vector<int>> subsets = generateSubsets(sampleSpace);
  int n = subsets.size(), m;
  for (int i = 0; i < n; i++)
  {
    m = subsets[i].size();
    cout << "Subset " << i + 1 << " :";
    for (int j = 0; j < m; j++)
      cout << " " << subsets[i][j];
    cout << endl;
  }
}
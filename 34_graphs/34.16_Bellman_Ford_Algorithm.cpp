#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int numVertices, vector<vector<int>> &weightedEdges, int startNode)
{
    //weightedEdges inside vector will be a three value pair, source, dest, and it's weight

    vector<int> minDistance(numVertices, INT16_MAX);
    minDistance[startNode] = 0;

    for (int i = 0; i < numVertices - 1; i++)
    {
        for (auto edge : weightedEdges)
        {
            int val1 = minDistance[edge[1]];
            int val2 = minDistance[edge[0]] + edge[2];
            int ans = min(val1, val2);
            minDistance[edge[1]] = ans;
            // minDistance[edge[1]] = min(minDistance[edge[1]], minDistance[edge[0]] + edge[2]);
        }
    }

    return minDistance;
}

int main()
{
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<vector<int>> weightedEdges(numEdges);

    for (int i = 0; i < weightedEdges.size(); i++)
    {
        weightedEdges[i] = vector<int>(3);
        cin >> weightedEdges[i][0] >> weightedEdges[i][1] >> weightedEdges[i][2];
    }

    int startNode;
    cin >> startNode;

    for (auto i : bellmanFord(numVertices, weightedEdges, startNode))
        cout << i << " ";
}

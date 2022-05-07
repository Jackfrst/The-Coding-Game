#include <bits/stdc++.h>

using namespace std;

int minRefills(int dist, int tank, vector<int> & stops, int start, int count)
{
    if ((start + tank) >= dist)
    {
        return count;
    }
    if (stops.size() == 0)
    {
        return -1;
    }
    int old_start = start;
    for (int i = 0; i < stops.size(); i++)
    {
        if (stops[i] <= (start + tank))
        {
            old_start = stops[i];
        }
        else
        {
            if (i != 0)
            {
                stops.erase(stops.begin(), stops.begin() + i);
            }
            else
            {
                stops.erase(stops.begin());
            }
            return minRefills(dist, tank, stops, old_start, count+1);
        }
    }
    return (old_start + tank) >= dist ? count+1 : -1;
}

int calculateMinRefills(int dist, int tank, vector<int> & stops)
{
    return minRefills(dist, tank, stops, 0, 0);
}

int main()
{
    int total_distance = 0;
    cout << "Total Distance: ";
    cin >> total_distance;

    int tank_Size = 0;
    cout << "Tank Size: ";
    cin >> tank_Size;

    int stopsCount = 0;
    cout << "Number of Gas Station: ";
    cin >> stopsCount;

    cout << "Enter " << stopsCount << " Gas Station Distance:" << endl;
    vector<int> stops(stopsCount);
    for (size_t i = 0; i < stopsCount; ++i)
        cin >> stops.at(i);

    cout << "\n\nMinimum number of refills : " << calculateMinRefills(total_distance, tank_Size, stops) << "\n";

    return 0;
}

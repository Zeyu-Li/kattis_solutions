def main():
    n, m = map(int, input().split())
    while n != 0:
        durations = []
        for _ in range(n):
            _, _, start, duration = input().split()
            durations.append((int(start), int(start) + int(duration)))

        durations.sort()

        for _ in range(m):
            start, dur = map(int, input().split())
            end = start+dur
            count = 0
            for duration in durations:
                if (duration[0] <= start < duration[1] or duration[0] < end < duration[1] or (start < duration[0] and duration[1] <= end )): count+=1
                # if we pass the start break prematurely
                if end <= duration[0]: break

            print(count)

        n, m = map(int, input().split())
    return

if __name__ == "__main__":
    main()

# cpp before I had a headache
# #include <bits/stdc++.h>

# typedef long long ll;
# using namespace std;

# int main() {
#     int n, m;
#     while (1) {
#         cin >> n >> m;
#         if (n == 0) {
#             break;
#         }

#         vector<pair<int, int>> durations;
#         for (int i = 0; i < n; i++) {
#             int _a, start, duration;
#             cin >> _a >> _a >> start >> duration;
#             // cout << start << duration << endl;
#             durations.push_back({start, duration});
#         }

#         vector<pair<int, int>> queries;
#         for (int i = 0; i < m; i++) {
#             int start, duration;
#             cin >> start >> duration;
#             queries.push_back({start, duration});
#         }
#         for (int i = 0; i < m; i++) {
#             int count = 0;
#             // get all
#             int start = queries[i].first;
#             int duraction = queries[i].second;
#             for (int j = 0; j < n; j++) {
#                 // if started after or same as start and ends before the time period, increment count
#                 if (durations[j].first >= start && durations[j].first + durations[j].second < start + duraction) count++;
#             }

#             cout << count << '\n';
#         }
#     }
#     return 0;
# }

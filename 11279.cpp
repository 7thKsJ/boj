// solved_2008kb_20ms_44397137_384b


#include <cstdio>
#include <queue>
using namespace std;

priority_queue <int, vector <int>, less <int>> q;

int main() {
	int n, num;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num != 0) {
			q.push(num);
		}
		else {
			if (q.empty()) {
				printf("0\n");
			}
			else {
                printf("%d\n", q.top());
				q.pop();
			}
		}
	}
	return 0;
}